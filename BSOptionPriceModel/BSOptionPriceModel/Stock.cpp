// This file contains implementations of the member functions prototyped in Stock.h"
#include "Stock.h"

int Stock::numberOfStock=0; //static variable count number of stocks

Stock::Stock(const std::string& name,const std::string& address, double spot, double vol)
{
    setName(name);
    setAddress(address);
    setSpot(spot);
    setVol(vol);
    numberOfStock++;
	//ctor
}

Stock::~Stock()
{
    //dtor
}

//accessor, return company name
std::string Stock::getName() const {
    return name;
}

//accessor, return company address
std::string Stock::getAddress() const {
    return address;
}

//accessor, return stock spot price
double Stock::getSpot() const {
    return spot;
}

//accessor, return stock volatility
double Stock::getVol() const {
    return vol;
}

//accessor return number of stock
int Stock::getNumberOfStock(){
    return numberOfStock;
}

//mutator, set company name
void Stock::setName(const std::string& name){
    this->name=name;
}

//mutator, set company address
void Stock::setAddress(const std::string& address){
    this->address=address;
}

//mutator, validate and set spot price
void Stock::setSpot(double spot) {
    this->spot=(spot>0)?spot:1;
}

//mutator, validate and set stock volatility
void Stock::setVol(double vol) {
    this->vol=(vol>0)?vol:0.01;
}

//output stock details
void Stock::print() const{
    std::cout<<"Name of company:     "<<name<<std::endl;
    std::cout<<"Address of company:  "<<address<<std::endl;
    std::cout<<"Stock spot price:    "<<spot<<std::endl;
    std::cout<<"Volatility of stock: "<<vol<<std::endl;
}