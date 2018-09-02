// Copyright (c) 2017 Patrik Bachan
//
// GNU GENERAL PUBLIC LICENSE
//    Version 3, 29 June 2007
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "spi.h"
#include "misc.h"
#include "device.h"
#include "config.h"

const struct SPI_SLAVE *active_spi=NULL;

status_t spi_start(const struct SPI_SLAVE *spi)
{
	if(active_spi!=NULL)
		return STAT_ERR_NOT_FINISHED;

	active_spi=spi;
	active_spi->PORT->BSRR = BIT(active_spi->pin)<<GPIO_BSRR_BR_OFFSET;
	return STAT_OK;
}

status_t spi_end(void)
{
	if(active_spi==NULL)
		return STAT_ERR_NOT_STARTED;

	while(bit_get(active_spi->SPI->SR,SPI_SR_BSY)!=0)
		NOP;

	active_spi->PORT->BSRR = BIT(active_spi->pin)<<GPIO_BSRR_BS_OFFSET;
	active_spi=NULL;
	return STAT_OK;
}

void spi_init(SPI_TypeDef *spi, uint8_t prescaler)
{
	spi->CR1 = SPI_CR1_SSM | SPI_CR1_SSI | prescaler<<SPI_CR1_BR_Pos | SPI_CR1_MSTR;
	spi->CR2 = (uint32_t)7UL<<SPI_CR2_DS_Pos; //8bit frame size (DR must be accessed in 8bit mode - otherwise frame increases size to 16bit WTF ST?! WTF! )
	bit_set(spi->CR1, SPI_CR1_SPE);
}

status_t spi_write16(uint16_t data, uint8_t bits)
{
	if(active_spi==NULL)
		return STAT_ERR_NOT_STARTED;

	bit_mod(active_spi->SPI->CR2, SPI_CR2_DS_Msk, (bits-1)<<SPI_CR2_DS_Pos);

	while(bit_get(active_spi->SPI->SR,SPI_SR_BSY)!=0)
		NOP;

	if(bits<=8)
		active_spi->SPI->DR.B=data;
	else
		active_spi->SPI->DR.W=data;

	return STAT_OK;
}


//B - byte
//W - byte to write
//R - byte ro read

//spi_exchange usage example
//write_len = 3
//read_len = 5
//read_offset = 2
//(t)->
//B B B B B B B
//W W W
//    R R R R R

int8_t spi_exchange(const uint8_t *write_data, const uint8_t write_len, uint8_t *read_data,const uint8_t read_len,const uint8_t read_offset)
{
	if(active_spi==NULL)
		return SPI_ERR_NO_DEVICE_OPENED;

	volatile uint16_t dummy=0;

	uint8_t write_index=0;
	uint8_t read_index=0;

	uint8_t frames_total= MAX(write_len, read_len+read_offset);

	// uart_send_string_blocking(" RX LVL: ");
	// uart_send_string_blocking(itoa((active_spi->SPI->SR&SPI_SR_FRLVL_Msk)>>SPI_SR_FRLVL_Pos,2));
	// uart_send_string_blocking(" ");

	while(write_index!=frames_total || read_index!=frames_total)
	{
		if(write_index<frames_total)
		{
			if(bit_get(active_spi->SPI->SR,SPI_SR_TXE))
			{
				if(write_data!=NULL && write_index<write_len)
				{
					active_spi->SPI->DR.B=write_data[write_index];
					// uart_send_string_blocking(UART_EX1, "W->");
				}
				else
				{
					active_spi->SPI->DR.B=0;
					// uart_send_string_blocking(UART_EX1, "0->");
				}
				write_index++;
			}
		}
		// else
			// uart_send_string_blocking(UART_EX1, "TNE");

		if(bit_get(active_spi->SPI->SR,SPI_SR_RXNE))
		{
			if(read_data!=NULL && read_index>=read_offset)
			{
				read_data[read_index-read_offset]=active_spi->SPI->DR.B;
				dummy=read_data[read_index-read_offset];
				// uart_send_string_blocking(UART_EX1, "R<-");
				// uart_send_string_blocking(UART_EX1, itoa(dummy,4));
				// uart_send_byte_blocking(UART_EX1, '\n');	
			}
			else
			{
				dummy=active_spi->SPI->DR.B;
				(void)dummy;
				// uart_send_string_blocking(UART_EX1, "D<-");
			}

			read_index++;
		}
		// else
			// uart_send_string_blocking(UART_EX1, "RE");

		// uart_send_string_blocking(UART_EX1, "\n");

	// uart_send_string_blocking(UART_EX1, " RX LVL: ");
	// uart_send_string_blocking(UART_EX1, itoa((active_spi->SPI->SR&SPI_SR_FRLVL_Msk)>>SPI_SR_FRLVL_Pos,2));
	// uart_send_byte_blocking(UART_EX1, '\n');	
	}
	// uart_send_byte_blocking(UART_EX1, ' ');

	return 0;
}

//interrupt handler
