#include "zasady.h"

cell_con rules(int neighbors, cell_con previous) {
	if (previous == DEAD && neighbors == 3) {
		return ALIVE;
	} else 
		if (previous == ALIVE) { 
			if (neighbors > 3 || neighbors < 2) 
				return DEAD;
			else 
				return ALIVE;
		} else 
			return DEAD;
}