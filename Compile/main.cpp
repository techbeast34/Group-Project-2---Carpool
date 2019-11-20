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

int main(){

	read_reservation();
	write_reservations();

	pickup parr[3];
	compact carr[3];
	sedan sarr[3];
	vehicle v;

	pickup p1("Red"), p2("Green"), p3("Blue");
	compact c1("Red"), c2("White"), c3("Black");
	sedan s1("Red"), s2("Teal"), s3("Wood");

	parr[0] = p1; parr[1] = p2; parr[2] = p3;
	carr[0] = c1; carr[1] = c2; carr[2] = c3;
	sarr[0] = s1; sarr[1] = s2; sarr[2] = s3;

	v.display(parr, carr, sarr);



	return 0;
}
