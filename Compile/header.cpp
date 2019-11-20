/************************************************
 Title: header.cpp
 Name: Rowan D'Ausilio & Satyendra Emani
 Class: CPET-321
 Date: Nov 13, 2019
 Description: The file with all the fucntions and classes defined for
 comp problem solving 2 project
 ************************************************/

#include "header.h"
#include <iostream>  // cin's and cout's
#include <iomanip>   // for printing things nicely
#include <fstream>   // needed for file I/O
#include <cstdlib>   // needed for exit()

using namespace std;

reservation Reservation_Records[24];

/*
 * vehicle::display()
 *
 *    input:       N/A
 *    output:      N/A
 *    description: displays the vehicles
 */
void vehicle::display(pickup truckArr[], compact compArr[], sedan sedArr[]) {
	cout << " Truck  | Compact  |   Sedan  " << endl;
	cout << "--------+----------+----------" << endl;
	cout << setw(8) << truckArr[0].color << "|" << setw(10) << compArr[0].color
			<< "|" << setw(10) << sedArr[0].color << endl;

	cout << "[-] ";
	if (truckArr[0].seatArr[0].occupied)
		cout << "[X] " << "|";
	else
		cout << "[5] " << "|";

	cout << " [-] ";
	if (compArr[0].seatArr[0].occupied)
		cout << "[X]  " << "|";
	else
		cout << "[5]  " << "|";

	cout << " [-]";
	if (sedArr[0].seatArr[0].occupied)
		cout << "   [X]" << endl;
	else
		cout << "   [5]" << endl;
}

/*
 * read_reservation()
 *
 *    input:       N/A
 *    output:      An array of reservations with the people and point values filled in
 *    description: reads the file of people and assigns their names and point values with default
 *                 values for everything else
 */
void read_reservation() {

	string first_name;
	string last_name;

	ifstream inFile;
	inFile.open("seat_credits.txt"); // the name of the file is hardcoded

	if (inFile.fail()) {
		cout << "\nThe file could not be read. Program terminated. \n" << endl;
		exit(1);
	} else {
		cout << "The file was read successfully. Reservation list being made."
				<< endl;
	}

	for (int count = 0; count < 24; count++) {

		getline(inFile, first_name, ' '); // read up to the first space and set to first name
		getline(inFile, last_name, ' '); // read last name
		inFile >> Reservation_Records[count].point_val;
		inFile.ignore();
		Reservation_Records[count].name = first_name + ' ' + last_name;
		Reservation_Records[count].res_number = count;
		Reservation_Records[count].seat = 5; // default; handled in an if later
		Reservation_Records[count].vehicle = 9; // default, handled in an if later
	}

	inFile.close();

	// TODO - Remove these next couple lines for final. They're there for testing
	cout << "Test print: " << "Name: " << Reservation_Records[0].name
			<< " Point val: " << Reservation_Records[0].point_val
			<< " Res number: " << Reservation_Records[0].res_number << endl;
	cout << "Test print: " << "Name: " << Reservation_Records[7].name
			<< " Point val: " << Reservation_Records[7].point_val
			<< " Res number: " << Reservation_Records[7].res_number << endl;

}

/*
 * write_reservations()
 *
 *    input:       Array of reservations
 *    output:      NA
 *    description: outputs the reservation information to the file
 */

// TODO - add the vehicle descriptor
void write_reservations() {

	string admin_password = "password";
	string entered_password;

	cout << "Enter administrator password: ";
	cin >> entered_password;

	if (entered_password == admin_password) {
		ofstream outFile("all_reservations.txt");
			if (outFile.is_open()) {
				for (int count = 0; count < 24; count++) {
					outFile << "Name: " << Reservation_Records[count].name
							<< " Point val: " << Reservation_Records[count].point_val
							<< " Res number: " << Reservation_Records[count].res_number
							<< endl;
				}
			}
			else {
				cout << "Unable to open output file." << endl;
			}
	}
	else {
		cout << "Entered password was incorrect. Returning to menu.";
		return;
		// TODO - return to menu here
	}


}
