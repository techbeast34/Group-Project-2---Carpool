/*********************
Name: Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
**********************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct seat{
	bool occupied;
	int pointVal;
};

class vehicle {
	protected:
		string color;
	public:
		void display();
};


class pickup: public vehicle {

};

struct reservation {
	int res_number;
	string name;
	int vehicle;
	int seat;
};
