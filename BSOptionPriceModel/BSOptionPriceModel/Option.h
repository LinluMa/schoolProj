/* Option class definition. This file presents Option's interface without revealing the 
implementation of Option's member functions, which are defined in Option.cpp 
Also uses inclusion guards to prevent multiple inclusions of header file */

#ifndef OPTION_H
#define OPTION_H

#include "GaussianDistribution.h"
#include "Stock.h"

class Option
{
    public:
        Option(double,double,double, Stock*); //ctor

        virtual ~Option(); //dtor

        double getCall() const; //accessor, return call price

        double getPut() const; //accessor, return put price

        void setD1();	//mutator, set valid d1 value

        void setD2();	//mutator, set valid d2 value

        void calculateCall();	//calculate call price

        void calculatePut();	//calculate put price

        void print() const;		//output option details

    private:
        double strike;	//strike price
        double r;	//risk free interest rate
        double expire; //time to maturity in years
        double d1;	//intermediate variable
        double d2;	//intermediate variable
        double c;	//call price
        double p;	//put price
        Stock* s;	//pointer to underlying stock

};

#endif // OPTION_H
