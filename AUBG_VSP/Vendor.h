#pragma once
#ifndef _VENDOR_H
#define _VENDOR_H

#include <string>
#include <vector>
#include <list>

class Vendor
{
public:
	Vendor();
	void Set_New_Vendor();

protected:
	std::string Name;
	std::string Address;
	std::string Phone;
	std::list <std::string> Delivery = { "Opel", "Ford" };
};
#endif // !_VENDOR_H
