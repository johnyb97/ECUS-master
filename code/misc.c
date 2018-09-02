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

#include "misc.h"
#include "config.h"
#include <string.h>
#include <math.h>

#ifdef _LOCAL_BOOL_USED
	#warning "local BOOL definition used"
#endif

#define STATUS_NOT_ERR(func) (func >= STAT_OK)

void dummy_assert(void *arg)
{
	UNUSED(arg);
	while(1)
		NOP;
}


// uint8_t wait_timeout(volatile uint8_t *port, uint8_t mask, uint8_t timeout, uint8_t high)
// {
// 	uint8_t counter;
// 	for(counter=0;
// 		((!(*port & mask) && high ) || //high level stop
// 		((*port & mask) && !high )) //low level stop
// 		&& counter!=timeout ;counter++)
//
// 		NOP;
// 	if(counter==timeout)
// 		return 1;
//
// 	else
// 		return 0;
// }
//
// uint8_t wait_timeout_simple(volatile uint8_t *port, uint8_t mask)
// {
// 	return wait_timeout(port,mask,255,1);
// }

uint32_t reduce(uint32_t value, uint8_t decrease) //correct rounding, not just cropping
{
	uint16_t dec=1;
	for(;decrease>1;decrease--)//calculate divider
		dec*=10;

	if (value/dec%10 > 4)//round
		return value/(10*dec)+1;
	else
		return value/(10*dec);
}

char char_buffer[BUFF_SIZE] = {0};


// char* stoa(const char *str)
// {
// 	uint8_t length;
// 	for(length=0;str[length]!='\0' && length<BUFF_SIZE-1;length++)
// 		char_buffer[length]=str[length];
// 	char_buffer[length]='\0';
// 	return char_buffer;
// }

// char* ctoa(char c)
// {
// 	char_buffer[0]=c;
// 	char_buffer[1]='\0';
// 	return char_buffer;
// }

char* itoa_dec_fill_append(char *output, int32_t val,int32_t min,char filler,uint8_t decimals, uint8_t base)
{
	char buffer[32];
	char *num_start=itoa_dec_fill_extbuff(buffer, val, min, filler, decimals, base);
	return stpcpy(output, num_start);
}

char* itoa_dec_fill_extbuff(char *buffer, int32_t val,int32_t min,char filler,uint8_t decimals, uint8_t base)//coverts number to string with defined base and minimal digit, char fillers
{

	uint8_t i = 31; //max characters
	uint8_t negative=0;

	buffer[i--]='\0';

	if (val==0)
	{
		buffer[i--]='0';
	}

	else
	{
		if(val<0)
		{
			negative=1;
			val=-val;
		}
		for (; (val && i); --i, val /= base)
		{
			if(30-i==decimals && decimals!=0 )
				buffer[i--]='.';

			buffer[i] = "0123456789abcdef"[val % base];
		}

	}

	if(30-i<=decimals)
	{
		for(;30-i<decimals;)
			buffer[i--]='0';
		buffer[i--]='.';
		buffer[i--]='0';
	}

	if(negative)
		buffer[i--]='-';

	for (; min+i>30; --i)
		buffer[i] = filler;

	return &buffer[i+1];
}

char* ftoa(char *output, float val, uint8_t min_length, uint8_t decimals, char filler)
{
	char *cursor=output;

	uint8_t i_min_length=min_length;
	if(decimals>0)
	{
		if(i_min_length>1+decimals)
			i_min_length-=1+decimals;
		else
			i_min_length=0;
	}

	// Extract integer part
	int32_t ipart = (int32_t)val;
 
	// Extract floating part
	float fpart = val - (float)ipart;

	if(fpart<0)//we don't wanna negative sign behind decimal dot
		fpart=-fpart;
 
	// convert integer part to string
	cursor = itoa_dec_fill_append(cursor, ipart, i_min_length, filler, 0, 10);
 
	// check for display option after point
	if (decimals != 0)
	{
		*(cursor++) = '.';  // add dot (overwrites terminating \0)
 
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * decadic_multiplier(decimals);
 
		cursor = itoa_dec_fill_append(cursor, (int32_t)fpart, decimals, '0', 0, 10);
	}
	return output;
}

#warning "delay loops uncalibrated!"
void delay_us(uint16_t delay)
{
	delay=(delay*8);
	while(delay--) {;NOP;NOP;NOP;}
}//dont try to optimize, it's calibrated! (gcc -O2)


void delay_ms(uint16_t delay) //calibrated using oscope
{
	while(delay--) delay_us(1000);
}

uint8_t str_match(uint8_t *A, uint8_t *B, uint8_t size)
{
	for(uint8_t i=0;i<size; i++)
		if(A[i]!=B[i])
			return 0;
	return 1;
}

//hack, yay!
typedef uint8_t** ptr_array_iterator_t;

//pointer to array of pointers
bool ptr_array_next(void ***ptr ,size_t size){

	ptr_array_iterator_t i = (ptr_array_iterator_t)*ptr;
	if(*(i+size) != NULL)
	{
		i += size;
		*ptr = (void**)i; 
		return true;
	}
	else
		return false;
}