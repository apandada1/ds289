#include <stdio.h>
#include <math.h>
#include "agm.h"
double AGM(double a, double b)
{
	double a_=a,b_=b;
	double am,gm;
	am=(a+b)/2,gm=sqrt(a*b);
	double diff=(am-gm)/2;
	
	if (diff==0)
		return (a+b)/2;
	else
		{
			int i=0;
			for(;i<30;i++)
				{
					am=(a+b)/2;
					gm=sqrt(a*b);
					diff=pow(diff,2)/(4*am);
					if (diff<=0.0 || am==gm || a==am || b==gm)
						break;
					a=am,b=gm;
					
				}
		}
	return am;	
}
