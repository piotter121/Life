#include "zasady.h"

stan_kom zasady(int sasiedzi, stan_kom poprzedni) {
	if (poprzedni == MARTWA && sasiedzi == 3) {
		return ZYWA;
	} else 
		if (poprzedni == ZYWA) { 
			if (sasiedzi > 3 || sasiedzi < 2) 
				return MARTWA;
			else 
				return ZYWA;
		} else 
			return MARTWA;
}