#include <iostream>
#include "AvailableSP.h"

using namespace std;

AvailableSP::AvailableSP()
{
}

float AvailableSP::Price_Of_Repair()
{
	PriceOfLabor = Price + ReplacementTime * 20;
	return PriceOfLabor;
}

float AvailableSP::Total_Price()
{
	return Total_SP_Price = Price + PriceOfLabor;
}

void AvailableSP::Time()
{
	cout << "The replacement time is: " << ReplacementTime << endl;
}

void AvailableSP::Output_Details()
{
	cout << "******Available Spare Part******\n";
	Time();
	cout << "The avaliable quantity of the specific Spare Part is: " << NumSpareParts << endl;
	cout << "ID: " << ID << endl << "Name: " << Name << endl << "Replacement Time: " << ReplacementTime << endl << "Location: " << Location << endl;
}

