#include <iostream>
#include "ContractedSP.h"

using namespace std;

ContractedSP::ContractedSP()
{
}

float ContractedSP::Price_Of_Repair()
{
	PriceOfLabor = Price + ReplacementTime * 20;
	return PriceOfLabor;
}

float ContractedSP::Total_Price()
{
	return Total_SP_Price = Price + PriceOfLabor;
}

void ContractedSP::Time()
{
	cout << "The replacement time is: " << ReplacementTime << endl;
}

void ContractedSP::Output_Details()
{
	cout << "******Contracted Spare Part******\n";
	Time();
	cout << "The avaliable quantity of the specific Spare Part is: " << NumSpareParts << endl;
	cout << "The delivery price is: " << Delivery_Price << endl;
	cout << "ID: " << ID << endl << "Name: " << Name << endl << "Replacement Time: " << ReplacementTime << endl;
}

