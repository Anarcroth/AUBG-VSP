#pragma once
#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <string>
#include <vector>

class Vehicle
{
public:
	Vehicle();
	void Add_New_Vehicle();
	inline bool Check_Year();
	bool Check_Producer();
	int Get_Year();
	bool Check_Vehicle_For_Spare_Parts();
	void Get_Vehicle_Data();

protected:
	//decleration of the producer list
	std::vector <std::string> Producer_List = { "Ford", "Opel", "Mercedes", "Toyota", "KIA", "AUDI" };
	std::string Producer;
	std::string Model;
	unsigned short int Year;
};
#endif // !_VEHICLE_H