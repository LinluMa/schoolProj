// This file contains implementations of the member functions prototyped in Option.h"
#include "Option.h"
#include "Stock.h"
#include "GaussianDistribution.h"
#include <math.h>
#include <iostream>

Option::Option(double strike, double r, double expire, Stock* s)
{
    this->strike=strike;
    this->r=r;
    this->expire=expire;
    this->s=s;
    setD1();
    setD2();
    calculateCall();
    calculatePut();
    //ctor
}

Option::~Option()
{
    //dtor
}

double Option::getCall() const{		//accessor, return call price
    return c;
}

double Option::getPut() const{		//accessor, return put price
    return p;
}

void Option::setD1(){		//mutator, set valid d1 value
    double d1N=log(s->getSpot()/strike)+(r+0.5*s->getVol()*s->getVol())*expire;
    d1=d1N/(s->getVol()*sqrt(expire));
}
void Option::setD2(){		//mutator, set valid d2 value
    d2=d1-s->getVol()*sqrt(expire);
}

void Option::calculateCall(){		//calculate call price
    double g1= gaussianDistribution(d1);
    double g2= gaussianDistribution(d2);
    c=s->getSpot()*g1-strike*exp((-1)*r*expire)*g2;
	if(c<=0) c=0;
}
void Option::calculatePut(){		//calculate put price
    p=strike*exp((-1)*r*expire)-s->getSpot()+c;
	if(p<=0) p=0;
}

void Option::print() const{		//output option details
    s->print();
    std::cout<<"Strike price:            "<<strike<<std::endl;
    std::cout<<"Risk free interest rate: "<<r<<std::endl;
    std::cout<<"Expiration in years:     "<<expire<<std::endl;
    std::cout<<std::endl<<std::scientific<<"Call price:   "<<c<<std::endl; //set scientific display
    std::cout<<"Put price:    "<<p<<std::endl;
    std::cout.unsetf(std::ios_base::floatfield); //disable scientific mode 
    std::cout<<std::endl;
}

