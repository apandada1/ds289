#include <stdio.h>
#include <math.h>
#include "agm.h"

double ellint(double o){
    double k =sin(o/2);
    double final =agm(1+k,1-k);
    double final1 =M_PI/(2*final);
    //printf("analytic time = %lf\n",final1);
    return final1;
}
/*int main(){
        double s =ellint(1);
	printf("s =%lf",s);
        return 0;
}*/
