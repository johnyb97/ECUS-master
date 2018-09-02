#include "dent_pot.h"

void dent_pot_process(dent_pot_t *pot)
{
	bool misaligned = true;

	for(uint8_t idx=0; pot->slot_positions[idx]!=-1; idx++)
	{
		int16_t min = (int16_t)pot->slot_positions[idx] - pot->slot_tolerance; 
		int16_t max = (int16_t)pot->slot_positions[idx] + pot->slot_tolerance;
		if(*pot->data > min && *pot->data < max)
		{
			//found matching slot
			if(idx != pot->current_slot)
			{
				//slot is different than previous
				misaligned = false;
				pot->current_slot = idx;	
				if(pot->callback != NULL)
					pot->callback(pot->current_slot);
				break;
			}
		}
	}
	pot->misaligned = misaligned;
}

