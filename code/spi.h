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

#ifndef _SPI_LIB
	#define _SPI_LIB

	#include "config.h"
	#include "misc.h"
	#include <inttypes.h>

	status_t spi_start(const struct SPI_SLAVE *spi);
	status_t spi_end(void);
	void spi_init(SPI_TypeDef *spi, uint8_t prescaler);
	status_t spi_write16(uint16_t data, uint8_t bits);
	int8_t spi_exchange(const uint8_t *write_data, const uint8_t write_len, uint8_t *read_data,const uint8_t read_len,const uint8_t read_offset);

	#define SPI_W		1
	#define SPI_R		2 //do not use as standalone
	#define SPI_RW		(SPI_R|SPI_W)

	enum{
		SPI_PSC_2=0,
		SPI_PSC_4,
		SPI_PSC_8,
		SPI_PSC_16,
		SPI_PSC_32,
		SPI_PSC_64,
		SPI_PSC_128,
		SPI_PSC_256
	}SPI_PSC;

	enum{
		SPI_ERR_DEVICE_OPENED=-1,
		SPI_ERR_NO_DEVICE_OPENED=-2
	};//spi errors


#endif