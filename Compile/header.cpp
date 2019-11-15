/************************************************
Title: header.cpp
Name: Rowan D'Ausilio & Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
Description: The file with all the fucntions and classes defined for
comp problem solving 2 project
************************************************/

#include <iostream>  // cin's and cout's
#include <iomanip>   // for printing things nicely
#include <fstream>   // needed for file I/O

using namespace std;

// struct representing a seat
struct seat{
	bool occupied; // boolean if the seat is occupied or not
	int pointVal;  // the point value of the seat
};

// class of vehicle
class vehicle {
	protected:
		string color;    // the identifying color of the vehicle
		seat seatArr[4]; // sets the array of seats to size 4
	public:
		void display(); // display vehicle
};

// class of pickup, inherits from vehicle
class pickup: public vehicle {
	private:
		seat frontSeat; // the front passenger seat of the truck
	public:
		pickup(string color){ // sets default values of a truck
			frontSeat.occupied = false;
			frontSeat.pointVal = 5;
			seatArr[0] = {frontSeat};
			this->color = color;
		}
};

// reservation strut
struct reservation {
	int res_number; // reservation number as an int
	string name;    // the name of the person
	int vehicle;    // the vehicle number
	int seat;       // the seat number
};

// class of compact car, inherits from vehicle
class compact: public vehicle {
	private:
		seat frontSeat, backLeft, backRight; // has three seats, front, and two back seats
	public:
		compact(string color){ // sets the default values of the compact
			frontSeat.occupied = false;
			backLeft.occupied = false;
			backRight.occupied = false;
			frontSeat.pointVal = 5;
			backLeft.pointVal = 3;
			backRight.pointVal = 3;
			seatArr[0] = frontSeat;
			seatArr[1] = backLeft;
			seatArr[2] = backRight;
			this ->color = color;
		}
};

// class of sedan car, inherits from vehicle
class sedan: public vehicle {
	private:
		seat frontSeat, backLeft, backRight, backMid; // has four seats, front and three back
	public:
		sedan(string color){ // sets the default value of the sedan
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
			this -> color = color;
		}
};

/*
 * vehicle::display()
 *
 *    input:       N/A
 *    output:      N/A
 *    description: displays the vehicles
 */
void vehicle::display(){
	for(int i = 0; i < 4; i++){

	}
}
