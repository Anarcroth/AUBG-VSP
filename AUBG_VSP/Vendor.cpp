#include <iostream>

#include "Vendor.h"

using namespace std;

Vendor::Vendor()
{
}

void Vendor::Set_New_Vendor()
{
	cout << "Please enter Vendor name, phone, and address: \n";
	cout << "Name: ";
	cin >> Name;
	cout << "Phone: ";
	cin >> Phone;
	cout << "Addres: ";
	cin >> Address;
}