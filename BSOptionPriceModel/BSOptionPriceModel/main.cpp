//Client Program to test BS Option Pricing Model System after separating its interface from its implementation
//By Ma Linlu G1700302B

#include <iostream>
#include "Option.h"
#include "Stock.h"
#include "GaussianDistribution.h"
#include <limits>
#include <fstream>

using namespace std;

void writeToReport(Option* optionArray[], int arraySize){	//generate txt report
    cout<<"Report is output to OptionReport.txt"<<endl;
    freopen ("OptionReport.txt","w",stdout);
    cout<<"*************Option Price Report***************"<<endl;
    for(int i=0;i<arraySize;++i) {
            cout<<"Stock number "<<i+1<<endl;
            optionArray[i]->print();
    }
    fclose (stdout);
}

double isPositiveDouble(){   //check if input is positive double
    double num;
    cin >> num;
     while(!cin||num<=0){
        cin.clear();	// reset failbit
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');	//skip bad input
        cout<< "Input invalid, please enter a positive double"<<endl;	//ask to input again
        cin >>num;
        }
    return num;
}
int main()
{
    //object related variables
    string name;		//company name, using "_" to replace space
    string address;			//company address, using "_" to replace space
    double spot;		//stock spot price
    double strike;		//stock strike price
    double r;		//risk free interest rate
    double vol;			//stock Volatility
    double expire;		//time to maturity in years

    const int n = 100; //define the max number of element possible
    Option* optionArray[n]; //array of pointer to option

	cout<<"****Welcome to BS Option Pricing System****"<<endl;
    cout<<endl<<"Would you like to add a new stock? Yes: y/Y , No: anything else"<<endl;

    char condition; //condition variable to check terminate condition of while loop
    cin >>condition;
    int i=0; //number of stocks being added

    while(condition=='Y'||condition=='y'){
	//input variables
    cout<< "Enter stock name"<<endl;
    cin >>name;

    cout<< "Company address"<<endl;
    cin>>address;

    cout<< "Spot stock price"<<endl;
    spot=isPositiveDouble();

    cout<< "Option strike price"<<endl;
    strike=isPositiveDouble();

    cout<< "Risk free rate"<<endl;
    r=isPositiveDouble();

    cout<< "Volatility"<<endl;
    vol=isPositiveDouble();

    cout<< "Time until expire in number of year"<<endl;
    expire=isPositiveDouble();

	//create stock object
    Stock *pstock= new Stock(name,address,spot,vol);

	//check if number of stock input exceed limit of array 
    i=Stock::getNumberOfStock();
    if(i>n) {
            cout<<"Exceeded max number of stock allowed!"<<endl;
            break;
    }
	//assign option pointer
    optionArray[i-1]=new Option(strike,r,expire,pstock);

	//output option particulars
    optionArray[i-1]->print();

    cout<<endl<<"Would you like to add a new stock? Yes: y/Y , No: anything else"<<endl;
    cin >>condition;
    }

    cout <<"No more stock being added"<<endl;
    cout <<endl<<"Total number of stocks: "<<i<<endl;

    if (i!=0) writeToReport(optionArray,i);      //if no stock added, skip output to file

	system("pause");
    return 0;
}
