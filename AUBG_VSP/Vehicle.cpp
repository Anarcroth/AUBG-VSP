#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle()
{
	//the task did not specify to use constructors
	//but just to have them
}

void Vehicle::Add_New_Vehicle()
{
	cout << "Enter a vehicle Producer, Model of the vehicle, and the its year: " << endl;
	cout << "Producer: ";
	cin >> Producer;
	cout << "Model: ";
	cin >> Model;
	cout << "Year: ";
	cin >> Year;
	cout << "Your input is as follows: " << Producer << ", " << Model << ", " << Year << std::endl;
}

inline bool Vehicle::Check_Year()
{
	if ((Year > 1950) && (Year < 2016))
	{
		return true;
	}
	else
	{
		std::cout << "Sorry, We don't have Spare Parts for your Vehicle.\n";
		return false;
	}
}

bool Vehicle::Check_Producer()
{
	for (auto i = Producer_List.begin(); i != Producer_List.end(); i++) {
		if (Producer == *i)
		{
			cout << "There is such a Producer in the list.\n";
			return true;
		}
	}
	cout << "Sorry, there isn't such a Producer in the Producer List.\n";
	return false;
}

int Vehicle::Get_Year()
{
	return Year;
}

bool Vehicle::Check_Vehicle_For_Spare_Parts()
{
	if (Check_Producer())
	{
		if (Check_Year())
		{
			cout << "This Vehicle has spare parts!\n";
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Vehicle::Get_Vehicle_Data()
{
	cout << Producer << endl << Model << endl << Year << endl;
}
