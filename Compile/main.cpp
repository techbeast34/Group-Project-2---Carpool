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
#include <stdlib.h>
#include "header.h"

using namespace std;

int main() {

	bool flag = false;
	int menu_sel;

	read_reservation();

	while (flag == false) { // loop to keep the program going

		cout << "Reservation System Main Menu:" << endl;
		cout << "Enter function wanted:" << endl;
		cout << "1. Create a reservation   2. Display all vehicles        3. Modify a reservation" << endl;
		cout << "4. Delete a reservation   5. Print Vehicle assignments   6. Reservation print (admin only)" << endl;
		cout << "7. End program." << endl;

		cout << endl;

		cout << "Function: ";
		cin >> menu_sel;
		cin.ignore();

		switch (menu_sel) {

		case 1:
			create_reservation();
			break;
		case 2:
			display_all();
			break;
		case 3:
			modify_reservation();
			break;
		case 4:
			delete_reservation();
			break;
		case 5:
			print_veh_file();
			break;
		case 6:
			write_res_file();
			break;
		case 7:
			exit(0);
			break;
		}
	}

	update_points();

	return 0;
}
