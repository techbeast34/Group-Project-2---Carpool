/************************************************
Title: header.h
Name: Rowan D'Ausilio & Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
Description: The function prototypes and class prototypes for project 2
************************************************/

#ifndef COMPILE_HEADER_H_
#define COMPILE_HEADER_H_

#include <string>
using namespace std;

// struct representing a seat
struct seat {
	bool occupied; // boolean if the seat is occupied or not
	int pointVal;  // the point value of the seat
};

class pickup;
class compact;
class sedan;

// class of vehicle
class vehicle {
protected:
	string color;    // the identifying color of the vehicle
	seat seatArr[4]; // sets the array of seats to size 4
public:
	void display(pickup parr[], compact carr[], sedan sarr[]);
	void write_reservations(pickup parr[], compact carr[], sedan sarr[]);
	void occupySeat(int num);
	void freeSeat(int num);
	friend void create_reservation();
};

// class of pickup, inherits from vehicle
class pickup: public vehicle {
private:
	seat frontSeat; // the front passenger seat of the truck
public:
	pickup(string color = "Invisible") { // sets default values of a truck
		frontSeat.occupied = false;
		frontSeat.pointVal = 5;
		seatArr[0] = frontSeat;
		this->color = color;
	}
};

// reservation strut
struct reservation {
	int res_number; // reservation number as an int
	int point_val;  // point value
	string name;    // the name of the person
	string vehicle;    // the vehicle string
	int seat;       // the seat number
};


// class of compact car, inherits from vehicle
class compact: public vehicle {
private:
	seat frontSeat, backLeft, backRight; // has three seats, front, and two back seats
public:
	compact(string color = "Invisible") { // sets the default values of the compact
		frontSeat.occupied = false;
		backLeft.occupied = false;
		backRight.occupied = false;
		frontSeat.pointVal = 5;
		backLeft.pointVal = 3;
		backRight.pointVal = 3;
		seatArr[0] = frontSeat;
		seatArr[1] = backLeft;
		seatArr[2] = backRight;
		this->color = color;
	}
};

// class of sedan car, inherits from vehicle
class sedan: public vehicle {
private:
	seat frontSeat, backLeft, backRight, backMid; // has four seats, front and three back
public:
	sedan(string color = "Invisible") { // sets the default value of the sedan
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
		this->color = color;
	}
};

void display(pickup parr[], compact carr[], sedan sarr[]);
void write_reservations(pickup parr[], compact carr[], sedan sarr[]);
void read_reservation();
void create_reservation();
void update_points();

#endif /* COMPILE_HEADER_H_ */
