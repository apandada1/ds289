#include <stdlib.h>
#include <stdio.h>
#include "ellint.h"
double ellipk(double k)
{
	return AGM(1+k,1-k); 
}
int main(int argc, char *argv[])
{
	double k=0.64, ellint;
	if(argc>1)
		ellint=PI/(2*ellipk(atof(argv[1])));
	else
		ellint=PI/(2*ellipk(k));
	printf("Elliptic Integral= %.10lf\n",ellint);
	return 0;
}
