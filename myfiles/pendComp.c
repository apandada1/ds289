#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ode.h"
#include "ellint.h"

typedef struct pendulumData{
	double g, L, gByL;
}PendulumData;

void slopeEval(double t, double *y, int m, void *udat, double *s_out)
{
	PendulumData *p;
	p=(PendulumData *)udat;
	s_out[0] = y[1]; 
	s_out[1] = -(p->gByL)*sin(y[0]);
}

int main(int argc, char *argv[])
{
	double L=1.0, g=9.80665;
	double T0, omega0, tStep,rkt,ellipt;
	double theta0_d=90.0, theta0, theta_sa;
	double t, y[2], ynext[2], ws[10];
	int i, nSteps= 2000;
	PendulumData pd;

	if(argc>1)
		theta0_d=atof(argv[1]);
	if(argc>2)
		L=atof(argv[2]);
	if(argc>3)
		g=atof(argv[3]);

	pd.L=L;
	pd.g=g;
	pd.gByL=g/L;
	theta0=theta0_d*M_PI/180; //radian conversion
	omega0=sqrt(pd.gByL);
	T0=2.0*M_PI/omega0;
	tStep=2.0*T0/nSteps;
	y[0]=theta0;
	y[1]=0.0;
	t=0.0;
	theta_sa=theta0;
	printf("%g %.16g\n",t,y[0],theta_sa);
	for(i=0;i<nSteps;i++)
	{
		stepRK4(t,y,2,slopeEval,&pd,ws,tStep,ynext);
		t+=tStep;
		y[0]=ynext[0];
		y[1]=ynext[1];
		theta_sa = theta0 * cos(omega0 * t);
        	printf("%g %.16g %.16g\n", t, y[0], theta_sa);
		if(y[0]==0)
		{
			rkt=4*(t-tStep);
			break;
		}
		else if(y[0]<0)
		{
			rkt=2*(2*t-tStep);
			break;
		}
	}
	ellipt=4*ellipk(sin(theta0/2))/omega0;
	printf("RK4 Time Period= %.10lf	\nElliptic Time= %.10lf\n",rkt,ellipt);
	printf("difference (RK4 Time - Elliptic Time) = %.10lf\n",rkt-ellipt);
	return 0;	
} 
