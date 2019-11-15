/*********************
Name: Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
**********************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <iterator>
#include "header.h"

using namespace std;

struct seat{
	bool occupied;
	int pointVal;
};

class vehicle {
	protected:
		string color;
		seat seatArr[4];
	public:
		void display(pickup*, compact*, sedan*);
};


class pickup: public vehicle {
	private:
		seat frontSeat;
	public:
		pickup(string color){
			frontSeat.occupied = false;
			frontSeat.pointVal = 5;
			seatArr[0] = {frontSeat};
			this->color = color;
		}
};

struct reservation {
	int res_number;
	string name;
	int vehicle;
	int seat;
};

class compact: public vehicle {
	private:
		seat frontSeat, backLeft, backRight;
	public:
		compact(){
			frontSeat.occupied = false;
			backLeft.occupied = false;
			backRight.occupied = false;
			frontSeat.pointVal = 5;
			backLeft.pointVal = 3;
			backRight.pointVal = 3;
			seatArr[0] = frontSeat;
			seatArr[1] = backLeft;
			seatArr[2] = backRight;
		}
};

class sedan: public vehicle {
	private:
		seat frontSeat, backLeft, backRight, backMid;
	public:
		sedan(){
			frontSeat.occupied = false;
			backLeft.occupied = false;
			backRight.occupied = false;
			backMid.occupied = false;
			frontSeat.pointVal = 5;
			backLeft.pointVal = 2;
			backRight.pointVal = 2;
			backMid.pointVal = 1;
			seatArr[0] = frontSeat;
			seatArr[1] = backLeft;
			seatArr[2] = backRight;
			seatArr[3] = backMid;
		}
};

void vehicle::display(pickup truckArr[], compact compArr[], sedan sedArr[]){
	cout << " Truck  | Compact  |   Sedan  " << endl;
	cout << "--------+----------+----------" << endl;
	cout << setw(8) << truckArr[0].color << "|" << setw(10) << compArr[0].color << "|" << setw(10) << sedArr[0].color << endl;

	cout << "[-] ";
	if(truckArr[0].seatArr[0].occupied)
		cout << "[X] " << "|";
	else
		cout << "[5] " << "|";

	cout << " [-] ";
	if(compArr[0].seatArr[0].occupied)
		cout << "[X]  " << "|";
	else
		cout << "[5]  " << "|";

	cout << " [-]";
	if(sedArr[0].seatArr[0].occupied)
		cout << "   [X]" << endl;
	else
		cout << "   [5]" << endl;

}
