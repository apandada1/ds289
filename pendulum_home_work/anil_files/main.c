#include<stdio.h>
#include<math.h>
#include<agm.h>
#include<ellint.h>

typedef struct _PendulumData {
    double gOverL;
    double g;
    double L;
} PendulumData;

void fn(double t, double *y, int m, void *udat, double *s_out)
{
    PendulumData *p;
    p = (PendulumData *)udat;
    s_out[0] = y[1];
    s_out[1] = -(p->gOverL) *sin(y[0]);
}

int main(int numc,char *numc[]){
	double degree ,radian,L =1.0,g=9.80665,numeric=0,analytic,step_size,difference;
	radian = (M_PI*degree)/180;
	step_size =1/2000;
	while(radian!<0){
		radian = stepRK4(step_size,radian);
		numeric = numeric + step_size;
	}
	numeric = numeric + (step_size/2);
	analytic = ellint(radian);
	difference = numeric - analytic;
	printf("NUMERICAL_TIME = %lf\n",numeric);
	printf("ANALYTICAL_TIME = %lf\n",analytic);
	printf("DIFFERENCE_TIME = %lf\n",difference);
	return 0;
}
