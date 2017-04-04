#pragma once
#ifndef _SPAREPART_H
#define _SPAREPART_H

#include <string>
#include <vector>
#include "Vehicle.h"

class SparePart
{
public:
	SparePart();
	void Add_Spare_Part();
	void Current_Spare_Part_Addition();
	bool Show_Warranty();
	virtual float Price_Of_Repair();
	bool SparePart_List_Check();
	int Get_NumSpareParts();
	void Add_Qunatity_To_Parts();
	void Draw_Quantity_From_Parts();
	virtual void Output_Details();
	bool Substitute();

protected:
	//added a list of spare parts for the check of the spare parts
	std::vector <std::string> SpareParts_List = { "Wipper", "Seat", "Wheel", "Mirror", "Pedal", "Belt" };
	std::string ID;
	std::string Name;
	std::string Description;
	//decleration of an object that is used to access class Vehicle
	Vehicle vehicle;
	float Price;
	float Total_SP_Price;
	int ReplacementTime;
	double PriceOfLabor;
	short int Quantity_Input;
	unsigned short int NumSpareParts;

};
#endif // !_SPAREPART_H