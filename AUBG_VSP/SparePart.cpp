#include <iostream>
#include <vector>
#include "SparePart.h"

using namespace std;

SparePart::SparePart()
{
	//the task did not specify to use constructors
	//but just to have them
}

void SparePart::Add_Spare_Part()
{
	cout << "Please enter an ID, Name, Price, Time for the Replacement, and The Number of Spare Parts for the spare part: " << endl;
	cout << "ID: ";
	cin >> ID;
	cout << "Name: ";
	cin >> Name;
	cout << "Price: ";
	cin >> Price;
	cout << "Time for Replacement (in hours): ";
	cin >> ReplacementTime;
	cout << "Number of Spare Parts: ";
	cin >> NumSpareParts;
}

void SparePart::Current_Spare_Part_Addition()
{
	cout << "Name: ";
	cin >> Name;
}

bool SparePart::Show_Warranty()
{
	if (vehicle.Get_Year() > 2012)
	{
		cout << "The Warranty for the repair of the Vehicle is 3 years.\n";
		return true;
	}
	else
	{
		cout << "The Warranty for the repair of the Vehicle is 3 months.\n";
		return false;
	}
}

float SparePart::Price_Of_Repair()
{
	return 0;
}

bool SparePart::SparePart_List_Check()
{
	for (auto i = SpareParts_List.begin(); i != SpareParts_List.end(); i++)
	{
		if (Name == *i)
		{
			cout << "The Spare Part is in the list!\n";
			return true;
		}
	}
	return false;
}

int SparePart::Get_NumSpareParts()
{
	return NumSpareParts;
}

void SparePart::Add_Qunatity_To_Parts()
{
	cout << "How much would you like to add?" << endl;
	cin >> Quantity_Input;
	NumSpareParts += Quantity_Input;
	cout << "There are " << NumSpareParts << " " << Name << "'s in total.\n";
}

void SparePart::Draw_Quantity_From_Parts()
{
	cout << "How much would you like to withdraw?" << endl;
	cin >> Quantity_Input;
	NumSpareParts -= Quantity_Input;
	if (NumSpareParts <= 0)
	{
		cout << "The quantity of the Spare Part has been depleted.\n";
	}
	else
	{
		cout << "There are " << NumSpareParts << " " << Name << "'s left.\n";
	}
}

void SparePart::Output_Details()
{
}

bool SparePart::Substitute()
{
	return 0;
	//define to use one spare part of one producer and model
	//for another producer and model
}