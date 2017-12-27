/* Stock class definition. This file presents Stock's interface without revealing the 
implementation of Stock's member functions, which are defined in Stock.cpp 
Also uses inclusion guards to prevent multiple inclusions of header file */

#ifndef Stock_H
#define Stock_H
#include<string>
#include<iostream>

class Stock
{
    public:
        Stock(const std::string& ="NTU", const std::string& ="Nanyang Ave",double=1,double=0.01); //ctor
        virtual ~Stock(); //dtor

        std::string getName() const;  //accessor, return company name

        std::string getAddress() const;	//accessor, return company address

        double getSpot() const;	//accessor, return stock spot price

        double getVol() const;	//accessor, return stock volatility

        static int getNumberOfStock();	//accessor return number of stock

        void setName(const std::string& name);	//mutator, set company name

        void setAddress(const std::string& address);	//mutator, set company address

        void setSpot(double spot);	//mutator, validate and set spot price

        void setVol(double vol);	//mutator, validate and set stock volatility

        void print() const;		//output stock details

    private:
        std::string name;	//company name
        std::string address;	//company address
        double spot;	//stock spot price
        double vol;	//stock volatility
        static int numberOfStock; //number of objects instantiated
};//end class Stock

#endif // STOCK_H
