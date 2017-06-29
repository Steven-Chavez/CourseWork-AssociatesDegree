//Name:Steven Chavez
//Email: schavez256@yahoo.com
//File: Driver.cpp

#include <iostream> 

using namespace std;

int main()
{
	//input variables
	double half_liter_pallet, full_liter_pallet;        //hL=half liter  fL=full liter 
												
	//constants
	const int CASES_PER_PALLET = 80, BOTTLES_PER_CASE = 24;
	const double LITER_PER_GALLON = 3.785;
	const double POUNDS_PER_GALLON = 8.34;
	const double POUNDS_PER_CONTAINER = 0.5 / 16;

	//output variables
	double half_liter_cases, full_liter_cases;
	double half_liter_servings, full_liter_servings;
	double total_bottles;
	double total_liters, total_gallons, total_pounds;         //t= total

	//other variables
	double half_liter_pallet_gallons;
	double full_liter_pallet_gallons;
	double bottle_weight, water_weight, total_bottle_weight;


	//COURSE HEADER
	cout << "\n NAME: Steven Chavez"
		<< "\n PROGRAM TITLE: P1 Cases of Water"
		<< "\n PROGRAM OBJECTIVE: The C++ Water & Ice Company"
		<< "\n wants a program so that their customers can input"
		<< "\n the number of half-liter and full-liter pallets "
		<< "\n they want and output total cases and servings"
		<< "\n for each drink and the total liters, gallons, and"
		<< "\n pounds for the entire order. \n\n";


	//INPUT
	//ask user to enter full and half liter pallets
	cout << " Please enter the number of pallets desired...";
	cout << "\n Half-Liter Pallets: ";
	cin >> half_liter_pallet;
	cout << " Full-Lter Pallets: ";
	cin >> full_liter_pallet;


	//EQUATIONS
	half_liter_cases = (half_liter_pallet * CASES_PER_PALLET);
	full_liter_cases = (full_liter_pallet * CASES_PER_PALLET);
	half_liter_servings = (half_liter_cases * BOTTLES_PER_CASE);
	full_liter_servings = (full_liter_cases * BOTTLES_PER_CASE);
	total_bottles = (CASES_PER_PALLET * BOTTLES_PER_CASE);

	//total Liter Calculation
	total_liters = (half_liter_pallet * total_bottles / 2) + (full_liter_pallet * total_bottles);

	//total Gallons Calculations
	half_liter_pallet_gallons = (total_bottles / 2) / (LITER_PER_GALLON);
	full_liter_pallet_gallons = (total_bottles / LITER_PER_GALLON);
	total_gallons = (half_liter_pallet * half_liter_pallet_gallons) + (full_liter_pallet * full_liter_pallet_gallons);

	//total pounds Calculations
	bottle_weight = (total_bottles * POUNDS_PER_CONTAINER);

	/* The equation bellow is important because because the weight of the
	bottles need to be accounted for each pallet the costumer enters into
	the program*/
	total_bottle_weight = (bottle_weight * half_liter_pallet) + (bottle_weight * full_liter_pallet);
	water_weight = (POUNDS_PER_GALLON * total_gallons);
	total_pounds = (total_bottle_weight + water_weight);


	//OUTPUT
	//Display half liter amounts to screen
	cout << "\n\n\n HALF LITER AMOUNTS ";
	cout << "\n cases = " << half_liter_cases;
	cout << "\n servings = " << half_liter_servings;

	//Display full liter amounts to screen
	cout << "\n\n FULL LITER AMOUNTS ";
	cout << "\n cases = " << full_liter_cases;
	cout << "\n servings = " << full_liter_servings;

	//Display Entire order results
	cout << "\n\n ENTIRE ORDER AMOUNTS ";
	cout << "\n liters = " << total_liters;

	// set precision for gallons and pounds to 2 for consistency 
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);

	cout << "\n gallons = " << total_gallons;
	cout << "\n pounds = " << total_pounds << "\n\n\n\n ";

	return 0;
}