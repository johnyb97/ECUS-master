#ifndef _DENT_POT_LIB
	#define _DENT_POT_LIB

	#include "misc.h"
	#include <inttypes.h>

	typedef struct{
		void (*callback)(uint8_t slot);
		volatile uint16_t *data;
		const int16_t *slot_positions;
		const uint16_t slot_tolerance;
		const uint8_t slots;
		uint8_t current_slot;
		bool misaligned;

	}dent_pot_t;

	void dent_pot_process(dent_pot_t *pot);

#endif