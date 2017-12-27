// This file contains implementations of the function prototyped in GaussianDistribution.h"
#include "GaussianDistribution.h"
#include <math.h>
#include <iostream>

double gaussianDistribution(double x){

	double erf;
	double z=fabs(x/sqrt(2.0));	
    double t=1.0/(1+0.5*z);
    double index=(-1)*pow(z,2)-1.26551223+1.00002368*t+0.37409196*pow(t,2)+0.09678418*pow(t,3)-0.18628806*pow(t,4)+0.27886807*pow(t,5)-1.13520398*pow(t,6)+1.48851587*pow(t,7)-0.82215223*pow(t,8)+0.17087277*pow(t,9);
    
	erf=1-t*exp(index);	

	if(x<0) erf*=(-1); //handle negative case

    return ((1+erf)/2);
}
