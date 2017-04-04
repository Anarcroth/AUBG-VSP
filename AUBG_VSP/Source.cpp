//AUBG Vehicles Spare Parts

#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h"
#include "SparePart.h"
#include "Vendor.h"
#include "AvailableSP.h"
#include "ContractedSP.h"

using namespace std;

void SparePartCalc(SparePart *S)
{
	
	std::cout << "\nThe avaliable quantity of the specific Spare Part is: " << S->Get_NumSpareParts() << endl;
	S->Show_Warranty();
	std::cout << "The price of your repair is: " << S->Price_Of_Repair() << endl;
	std::cout << "Would you like to add or withdraw from the given quantity?" << endl;
	std::cout << "'Y' for Add / 'N' for Withdraw / 'P' for doing nothing: " << endl;

	char User_Answer;
	std::cin >> User_Answer;

	if (toupper(User_Answer) == 'Y')
	{
		S->Add_Qunatity_To_Parts();
	}
	else if (toupper(User_Answer) == 'N')
	{
		S->Draw_Quantity_From_Parts();
	}
}

void SparePartAdd_Take(SparePart *S)
{
	std::cout << "\nYou have added a new Spare Part.\n";
	std::cout << "Would you like to add or withdraw from the given quantity?" << endl;
	std::cout << "'Y' for Add / 'N' for Withdraw / 'P' for doing nothing: " << endl;
	char User_Answer;
	std::cin >> User_Answer;

	if (toupper(User_Answer) == 'Y')
	{
		S->Add_Qunatity_To_Parts();
	}
	else if (toupper(User_Answer) == 'N')
	{
		S->Draw_Quantity_From_Parts();
	}
}

void Add_Spare_Part_And_PushBack(SparePart *ptr, vector <pair <SparePart*, int>> &spr)
{
	ptr->Add_Spare_Part();
	spr.push_back(pair <SparePart*, int>(ptr, ptr->Get_NumSpareParts()));
}

void merge(vector <float> &a, vector <size_t> &tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
		{
			tmpArray[tmpPos++] = a[leftPos++];
		}
		else
		{
			tmpArray[tmpPos++] = a[rightPos++];
		}
	}
	while (leftPos <= leftEnd)
	{
		tmpArray[tmpPos++] = a[leftPos++];
	}
	while (rightPos <= rightEnd)
	{
		tmpArray[tmpPos++] = a[rightPos++];
	}
	for (int i = 0; i < numElements; i++, rightEnd--)
	{
		a[rightEnd] = tmpArray[rightEnd];
	}
}

void mergeSort2(vector <float> &a, vector <size_t> &tmpArray, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort2(a, tmpArray, left, center);
		mergeSort2(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

void mrgsrt(vector <float> &a)
{
	vector <size_t> TmpArr(a.size());
	mergeSort2(a, TmpArr, 0, a.size() - 1);
}

float binarySRT(vector <float> &v, int lower, int upper, float answer)
{
	int pos;
	pos = (lower + upper) / 2;

	while ((v[pos] != answer) && (lower <= upper))
	{
		if (v[pos] > answer)
		{
			upper = pos - 1;
		}
		else
		{
			lower = pos + 1;
		}
		pos = (lower + upper) / 2;
	}
	if (lower <= upper)
	{
		return pos;
	}
	else
	{
		cout << "Your designated price is not in the list!\n";
		return 0;
	}
}

int main()
{
	//user is asked whether or not to add a vehicle
	cout << "Welcome to AUBG's Vehicle Spare Parts Store.\n";
	cout << "Would you like to add a vehicle?\n";
	cout << "Y / N: ";
	unsigned char User_Answer;
	cin >> User_Answer;

	vector <pair <SparePart*, int>> Spare_Part_List;

	Vehicle Vehicle1;
	vector <Vehicle*> Vehicles_With_SpareParts;

	if (toupper(User_Answer) == 'Y')
	{
		//the class accesses the class Vehicle through the decleration of an object in class SparePart
		Vehicle1.Add_New_Vehicle();
		if (Vehicle1.Check_Vehicle_For_Spare_Parts())
		{
			//here the vehicles are stored if they have spare parts
			Vehicles_With_SpareParts.push_back(&Vehicle1);
		}
	}

	//user is asked to wether to add a spare part
	cout << "Would you like to add a spare part?\n";
	cout << "Y / N: ";
	cin >> User_Answer;
	float answer;

	SparePart SparePart1;
	SparePart *Spare_Part_Pointer = NULL;

	while (toupper(User_Answer) == 'Y')
	{
		if (toupper(User_Answer) == 'Y')
		{
			cout << "\nPlease specify what kind of spare part do you wish to add?\n";
			SparePart1.Current_Spare_Part_Addition();

			cout << "Do you want to use a contracted spare part(1) or an available one(2)?\n";
			cin >> answer;

			AvailableSP *Available_SP1 = new AvailableSP;
			ContractedSP *Contracted_SP1 = new ContractedSP;

			if (SparePart1.SparePart_List_Check())
			{

				if (answer == 2)
				{
					Spare_Part_Pointer = Available_SP1;
					Add_Spare_Part_And_PushBack(Spare_Part_Pointer, Spare_Part_List);
					SparePartCalc(Spare_Part_Pointer);
				}
				else if (answer == 1)
				{
					Spare_Part_Pointer = Contracted_SP1;
					Add_Spare_Part_And_PushBack(Spare_Part_Pointer, Spare_Part_List);
					SparePartCalc(Spare_Part_Pointer);
				}
			}
			else
			{
				if (answer == 2)
				{
					Spare_Part_Pointer = Available_SP1;
					Add_Spare_Part_And_PushBack(Spare_Part_Pointer, Spare_Part_List);
					SparePartAdd_Take(Spare_Part_Pointer);
				}
				else if(answer == 1)
				{
					Spare_Part_Pointer = Contracted_SP1;
					Add_Spare_Part_And_PushBack(Spare_Part_Pointer, Spare_Part_List);
					SparePartAdd_Take(Spare_Part_Pointer);
				}
			}
		}

		cout << "Would you like to add another spare part?\n";
		cin >> User_Answer;
	}

	cout << "\nWould you like to add a new Vendor?\n";
	cout << "Y / N: ";
	cin >> User_Answer;

	vector<Vendor*> vendor;
	Vendor Vendor1;
	if (toupper(User_Answer) == 'Y')
	{
		Vendor1.Set_New_Vendor();
		vendor.push_back(&Vendor1);
		cout << "\nYou added a new vendor!\n";
	}
	
	cout << "Would you like to see a list of the available spare parts?\n";
	cout << "Y / N: ";
	cin >> User_Answer;
	if (toupper(User_Answer) == 'Y')
	{
		for (int i = 0; i < Spare_Part_List.size(); i++) 
		{
			if (Spare_Part_List[i].first != NULL) 
			{
				Spare_Part_Pointer = Spare_Part_List[i].first;
				Spare_Part_Pointer->Output_Details();
				Vehicle1.Get_Vehicle_Data();
				cout << endl;
			}
		}
	}

	cout << "Do you want to make a request for a Spare Part? \n";
	cout << "Y / N: ";

	vector <float> V_Of_Prices(10);

	cin >> User_Answer;
	if (toupper(User_Answer) == 'Y')
	{
		cout << "Please enter the maximum price you \nare willing to pay (price of labor + price of the part): ";
		cin >> answer;

		for (int i = 0; i < Spare_Part_List.size(); i++)
		{
			if (Spare_Part_List[i].first != NULL)
			{
				V_Of_Prices.push_back(Spare_Part_List[i].first->Price_Of_Repair());	
			}
		}
		//merge sort
		mrgsrt(V_Of_Prices);
		int binary_sort_pos = binarySRT(V_Of_Prices, 0, 11, answer);
		if (binary_sort_pos != 0)
		{
			for (int j = 0; j < Spare_Part_List.size(); j++)
			{
				if ((Spare_Part_List[j].first != NULL) && (V_Of_Prices.at(binary_sort_pos) = Spare_Part_List[j].first->Price_Of_Repair()))
				{
					cout << "Your available and affordable Spare Parts are: \n";
					Spare_Part_List[j].first->Output_Details();
					Vehicle1.Get_Vehicle_Data();
					cout << "Do you wish to buy this part?\nY / N: ";
					cin >> User_Answer;
					if (toupper(User_Answer) == 'Y')
					{
						Spare_Part_List[j].first->Draw_Quantity_From_Parts();
					}
				}
			}				
		}
		
	}

	delete Spare_Part_Pointer;
	Spare_Part_List.clear();
	vendor.clear();
	Vehicles_With_SpareParts.clear();

	cout << "\nThank you for visiting us!\n";

	return 0;
}