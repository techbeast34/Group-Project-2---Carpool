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
 * vehicle::occupySeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: OCCUPY CAR SEAT! WE ARE THE 99%!
 */
void vehicle::occupySeat(int seat){
	seatArr[seat].occupied = true;
}

/*
 * vehicle::freeSeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: The 1% freed a seat.
 */
void vehicle::freeSeat(int seat){
	seatArr[seat].occupied = false;
}


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
	for (int i = 0; i < 3; i++) {
		cout << setw(8) << truckArr[i].color << "|" << setw(10)
				<< compArr[i].color << "|" << setw(10) << sedArr[i].color
				<< endl;

		cout << "[-] ";
		if (truckArr[i].seatArr[0].occupied)
			cout << "[X] " << "|";
		else
			cout << "[5] " << "|";

		cout << " [-] ";
		if (compArr[i].seatArr[0].occupied)
			cout << "[X]  " << "|";
		else
			cout << "[5]  " << "|";

		cout << " [-]";
		if (sedArr[i].seatArr[0].occupied)
			cout << "   [X]" << endl;
		else
			cout << "   [5]" << endl;

		//------


		cout << setw(8) << "" << "|";
		if (compArr[i].seatArr[1].occupied)
			cout << " [X] ";
		else
			cout << " [3] ";

		if (compArr[i].seatArr[2].occupied)
			cout << "[X]  " << "|";
		else
			cout << "[3]  " << "|";

		//-------
		if (sedArr[i].seatArr[1].occupied)
			cout << " [X]";
		else
			cout << " [2]";

		if (sedArr[i].seatArr[2].occupied)
			cout << "[X]";
		else
			cout << "[1]";

		if (sedArr[i].seatArr[3].occupied)
			cout << "[X]" << endl;
		else
			cout << "[2]" << endl;

	}
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
			<< " Res number: " << Reservation_Records[7].res_number
			<< " Seat number: " << Reservation_Records[7].seat
			<< " Vehicle number: " << Reservation_Records[7].vehicle << endl;

}

/*
 * write_reservations()
 *
 *    input:       Array of reservations
 *    output:      NA
 *    description: outputs the reservation information to the file
 */

// TODO - edit for the vehicle descriptor
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
						<< " Point val: "
						<< Reservation_Records[count].point_val
						<< " Res number: "
						<< Reservation_Records[count].res_number;
				if (Reservation_Records[count].seat == 5) {
					outFile << " No seat assigned.";
				} else {
					outFile << Reservation_Records[count].seat;
				}
				if (Reservation_Records[count].vehicle == 9) {
					outFile << " No vehicle assigned." << endl;
				} else {
					outFile << Reservation_Records[count].vehicle;
				}
			}
		} else {
			cout << "Unable to open output file." << endl;
		}
	} else {
		cout << "Entered password was incorrect. Returning to menu.";
		return;
		// TODO - return to menu here
	}

}
