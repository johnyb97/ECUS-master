#ifndef _FONT_TYPES_LIB
	#define _FONT_TYPES_LIB

	#include <inttypes.h>

	typedef struct{
		char character;
		uint16_t width;
		uint16_t height;
		const struct{
			uint16_t left;
			uint16_t right;
			uint16_t top;
			uint16_t bottom;
		}padding;
		const uint8_t *const data;
	}font_char_t;

	typedef struct{
		const uint8_t offset;
		const font_char_t *const *const characters;
	}font_t;

#endif
	