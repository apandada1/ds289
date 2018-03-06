#include <stdio.h>
#include <math.h>
#include "agm.h"
double AGM(double a, double b)
{
	double a_=a,b_=b;
	double diff=fabs(a-b)/2;
	if (diff==0)
		printf("AGM(%.10lf, %.10lf)= %.10lf\n",a,b,a);
	else
		{
			int i=0;
			double am,gm;
			for(;i<30;i++)
				{
					am=(a+b)/2;
					gm=sqrt(a*b);
					diff=fabs(am-gm)/2;
					a=am,b=gm;
					printf("%d: am=%.10lf     gm=%.10lf     diff=%.10lf\n",i+1,am,gm,diff);
					if (diff<=0.0000000001)
						break;
				}
			printf("AGM(%.10lf, %.10lf)= %.10lf\n",a_,b_,a);
		}
	return a;	
}
