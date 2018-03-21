#include <stdio.h>
#include <math.h>
#include "agm.h"

double agm(double a,double b){
    double anext =(a+b)/2,bnext = sqrt(a*b) ,cnext =(a-b)*0.5,dnext =(a-b)*0.5;
    for(int i=0;i<30;i++){
        double t =anext;
        anext = (anext +bnext)*0.5;
        bnext =sqrt(t*bnext);
	cnext =(anext-bnext)*0.5;
	dnext =(cnext*cnext)/(4*anext);
	if(cnext<=0.0){
	    break;
	}
	if(t==anext){
	    break;
	}
    }
    return anext;
}

/*int main()
{
	agm(7,1);
	return 0;
}*/	
