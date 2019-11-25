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
	create_reservation();
	write_res_file();

	update_points(); // updates the seat_credits.txt file to reflect point changes -- make sure this is changed in function to the real txt file

	return 0;
}
