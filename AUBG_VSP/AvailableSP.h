#pragma once
#ifndef _AVAILABLESP_H
#define _AVAILABLESP_H

#include <string>
#include "SparePart.h"

class AvailableSP : public SparePart
{
public:
	AvailableSP();
	virtual float Price_Of_Repair();
	float Total_Price();
	void Time();
	virtual void Output_Details(); //Spare Part details, available qunatity, and location

protected:
	std::string Location = "Blagoevgrad";

};
#endif // !_AVAILABLESP_H