/************************************************
Title: main.cpp
Name: Rowan D'Ausilio & Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
Description: Main function file
************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "header.h"

using namespace std;

int main() {

	read_reservation();
	//create_reservation();

	pickup p1("Purple"), p2("Yellow"), p3("Red");
	compact c1("Green"), c2("Blue"), c3("Yellow");
	sedan s1("Red"), s2("Green"), s3("Blue");

	pickup parr[3] = { p1, p2, p3 };
	compact carr[3] = { c1, c2, c3 };
	sedan sarr[3] = { s1, s2, s3 };
	vehicle v;

	v.display(parr, carr, sarr);
	v.write_reservations(parr, carr, sarr);

	update_points(); // updates the seat_credits.txt file to reflect point changes

	return 0;
}
