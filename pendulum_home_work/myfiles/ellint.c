#include <stdlib.h>
#include <stdio.h>
#include "ellint.h"
double ellipk(double k)
{
	double value= PI/(2*AGM(1+k,1-k));
	return value; 
}
