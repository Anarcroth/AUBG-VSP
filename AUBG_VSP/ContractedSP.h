#pragma once
#ifndef _CONTRACTEDSP_H
#define _CONTRACTEDSP_H

#include "SparePart.h"
#include "Vendor.h"

class ContractedSP : public SparePart
{
public:
	ContractedSP();
	virtual float Price_Of_Repair();
	float Total_Price();
	void Time();
	virtual void Output_Details(); //Spare Part details, available qunatity, and location

protected:
	Vendor vendor;
	unsigned short int Time_Of_Delivery;
	double Delivery_Price = 20.54;

};
#endif // !_CONTRACTEDSP_H
