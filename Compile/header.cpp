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

pickup p1("Purple"), p2("Yellow"), p3("Red");
compact c1("Green"), c2("Blue"), c3("Yellow");
sedan s1("Red"), s2("Green"), s3("Blue");

pickup parr[3] = { p1, p2, p3 };
compact carr[3] = { c1, c2, c3 };
sedan sarr[3] = { s1, s2, s3 };
vehicle v;

/*
 * vehicle::occupySeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: OCCUPY CAR SEAT! WE ARE THE 99%!
 */
void vehicle::occupySeat(int seat) {
	seatArr[seat].occupied = true;
}

/*
 * vehicle::freeSeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: The 1% freed a seat.
 */
void vehicle::freeSeat(int seat) {
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
		cout << setw(8) << truckArr[i].color << "|" << setw(10) << compArr[i].color << "|" << setw(10)
				<< sedArr[i].color << endl;

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

		if (sedArr[i].seatArr[3].occupied)
			cout << "[X]";
		else
			cout << "[1]";

		if (sedArr[i].seatArr[2].occupied)
			cout << "[X]" << endl;
		else
			cout << "[2]" << endl;

	}
}

// TODO Remove this - A function for testing display
void test_dispaly() {
	v.display(parr, carr, sarr);
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
		cout << "The file was read successfully. Reservation list being made." << endl;
	}

	for (int count = 0; count < 24; count++) {

		getline(inFile, first_name, ' '); // read up to the first space and set to first name
		getline(inFile, last_name, ' '); // read last name
		inFile >> Reservation_Records[count].point_val;
		inFile.ignore();
		Reservation_Records[count].name = first_name + ' ' + last_name;
		Reservation_Records[count].res_number = count;
		Reservation_Records[count].seat = 5; // default; handled in an if later
		Reservation_Records[count].vehicle_color = " Car not assigned."; // default, handled in an if later
		Reservation_Records[count].vehicle_type = "Car not assigned."; // default, handled later
	}

	inFile.close();
}

/*
 * write_reservations()
 *
 *    input:       The truck, compact and sedan arrays
 *    output:      NA
 *    description: outputs the reservation information to the file
 */

void vehicle::write_reservations(pickup truckArr[], compact compArr[], sedan sedArr[]) {

	string admin_password = "password";
	string entered_password;

	cout << "Enter administrator password: ";
	cin >> entered_password;

	if (entered_password == admin_password) {
		ofstream outFile("all_reservations.txt");
		if (outFile.is_open()) {

			outFile << "-- Pickup Truck Assignments -- " << endl;

			for (int i = 0; i < 3; i++) {
				outFile << truckArr[i].color << " pickup: " << endl;
				if (truckArr[i].seatArr[0].occupied) { // seat occupied
					outFile << "Front seat: "; // TODO
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}
				outFile << endl;
			}

			outFile << "-- Compact Car Assignments -- " << endl;

			for (int i = 0; i < 3; i++) {
				outFile << compArr[i].color << " compact:" << endl;
				if (compArr[i].seatArr[0].occupied) {
					outFile << "Front seat: "; // TODO
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}

				if (compArr[i].seatArr[1].occupied) {
					outFile << "Left back seat: "; // TODO
				} else {
					outFile << "Left back seat: Unassigned." << endl;
				}

				if (compArr[i].seatArr[2].occupied) {
					outFile << "Right back seat: "; // TODO
				} else {
					outFile << "Right back seat: Unassigned." << endl;
				}
				outFile << endl;
			}

			outFile << "-- Sedan Assignments -- " << endl;

			for (int i = 0; i < 3; i++) {
				outFile << sedArr[i].color << " sedan:" << endl;
				if (sedArr[i].seatArr[0].occupied) {
					outFile << "Front seat: "; // TODO
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[1].occupied) {
					outFile << "Left back seat: "; // TODO
				} else {
					outFile << "Left back seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[3].occupied) {
					outFile << "Middle back seat: "; // TODO
				} else {
					outFile << "Middle back seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[2].occupied) {
					outFile << "Right back seat: "; // TODO
				} else {
					outFile << "Right back seat: Unassigned." << endl;
				}
				outFile << endl;
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

void write_res_file() {
	v.write_reservations(parr, carr, sarr);
}

/*
 * create_reservation()
 *
 *    input:       NA
 *    output:      NA
 *    description: Finds the person in the database and edits the car that they are in as well
 *                 as the seat they are going to sit in
 */

void create_reservation() {
	string passenger_first; // user entered person's name
	string passenger_last;  // user entered last name
	string passenger_name;  // full name
	char menu_sel;          //menu select
	char submenu_sel;       // sub menu select
	char seat_sel;          // seat selection
	string car_color;       // car color
	bool nameMatch = false;

	cout << "Enter passenger's name to create the reservation: ";
	cin >> passenger_first >> passenger_last;
	passenger_name = passenger_first + " " + passenger_last;

	for (int count = 0; count < 24; count++) {
		if (passenger_name == Reservation_Records[count].name) {
			cout << Reservation_Records[count].name << " has " << Reservation_Records[count].point_val << " points."
					<< endl;
			nameMatch = true;

			if (Reservation_Records[count].point_val == 0) {
				cout << "ERROR: No points. Find your own transportation." << endl;
			} else {
				v.display(parr, carr, sarr);
				cout << "Do you want to select by (C)ategory, or by (S)pecific seat?" << endl;
				cin >> menu_sel;
				cin.ignore();

				bool match = false;
				bool colorMatch = false;

				switch (menu_sel) {
				case 'c':
				case 'C': {
					cout << "What seat do you want? (F)ront, (B)ack, or (M)iddle?" << endl; //TODO: add error checks to make sure they have enough points.
					cin >> submenu_sel;
					cin.ignore();
					switch (submenu_sel) {
					case 'f':
					case 'F': {
						if (Reservation_Records[count].point_val >= 5) {
							for (int i = 0; (i < 3) && !match; i++) {
								if (!parr[i].seatArr[0].occupied && !match) { // assign to pickup
									parr[i].occupySeat(0);
									Reservation_Records[count].vehicle_color = parr[i].color;
									Reservation_Records[count].vehicle_type = "Pickup";
									match = true;
								} else if (!carr[i].seatArr[0].occupied && !match) {
									carr[i].occupySeat(0);
									Reservation_Records[count].vehicle_color = carr[i].color;
									Reservation_Records[count].vehicle_type = "Compact";
									match = true;
								} else if (!sarr[i].seatArr[0].occupied && !match) {
									sarr[i].occupySeat(0);
									Reservation_Records[count].vehicle_color = sarr[i].color;
									Reservation_Records[count].vehicle_type = "Sedan";
									match = true;
								}
							}
							if (match) {
								Reservation_Records[count].seat = 0; // set to front seat
								Reservation_Records[count].point_val -= 5; //TODO: change these to veharr[i].seatArr[i].pointVal for maintainability
							}
						} else {
							cout << "ERROR! Not enough points for a front seat." << endl;
						}

					}
						break;
					case 'b':
					case 'B': {
						if (Reservation_Records[count].point_val >= 3) {
							for (int i = 0; (i < 3) && !match; i++) {
								if (!carr[i].seatArr[1].occupied && !match) {
									carr[i].occupySeat(1);
									Reservation_Records[count].point_val -= 3;
									Reservation_Records[count].seat = 1;
									Reservation_Records[count].vehicle_color = carr[i].color;
									Reservation_Records[count].vehicle_type = "Compact";
									match = true;
								} else if (!carr[i].seatArr[2].occupied && !match) {
									carr[i].occupySeat(2);
									Reservation_Records[count].point_val -= 3;
									Reservation_Records[count].seat = 2;
									Reservation_Records[count].vehicle_color = carr[i].color;
									Reservation_Records[count].vehicle_type = "Compact";
									match = true;
								} else if (!sarr[i].seatArr[1].occupied && !match) {
									sarr[i].occupySeat(1);
									Reservation_Records[count].point_val -= 2;
									Reservation_Records[count].seat = 1;
									Reservation_Records[count].vehicle_color = sarr[i].color;
									Reservation_Records[count].vehicle_type = "Sedan";
									match = true;
								} else if (!sarr[i].seatArr[2].occupied && !match) {
									sarr[i].occupySeat(2);
									Reservation_Records[count].point_val -= 2;
									Reservation_Records[count].seat = 2;
									Reservation_Records[count].vehicle_color = sarr[i].color;
									Reservation_Records[count].vehicle_type = "Sedan";
									match = true;
								}
							}
						} else {
							cout << "ERROR! Not enough points for a back seat." << endl;
						}

					}
						break;
					case 'm':
					case 'M': {
						if (Reservation_Records[count].point_val >= 1) {
							for (int i = 0; (i < 3) && !match; i++) {
								if (!sarr[i].seatArr[3].occupied && !match) {
									Reservation_Records[count].point_val -= 1;
									Reservation_Records[count].seat = 3;
									Reservation_Records[count].vehicle_color = sarr[i].color;
									Reservation_Records[count].vehicle_type = "Sedan";
									sarr[i].occupySeat(3);
									match = true;
								}
							}
						} else {
							cout << "ERROR! Not enough points for a middle seat." << endl;
						}
					}
						break;

					}
					break; // submenu case end
				}
				case 's':
				case 'S': {

					//TODO: add error checks to ensure the user has enough points
					cout << "Which car type? (P)ickup, (C)ompact, or (S)edan? ";
					cin >> submenu_sel;
					cin.ignore();
					switch (submenu_sel) {
					case 'p':
					case 'P': {
						cout << "Which color? ";
						getline(cin, car_color);
						for (int i = 0; i < 3 && !colorMatch; i++) {
							if (parr[i].color == car_color) {
								colorMatch = true;
								if (!parr[i].seatArr[0].occupied && !match
										&& (Reservation_Records[count].point_val >= 5)) {
									parr[i].occupySeat(0);
									Reservation_Records[count].point_val -= 5;
									Reservation_Records[count].seat = 0; // set to front seat
									Reservation_Records[count].vehicle_color = parr[i].color;
									Reservation_Records[count].vehicle_type = "Pickup."; // set assigned vehicle to color pickup
									match = true;
									v.display(parr, carr, sarr);
								} else
									cout << "ERROR! Seat not available, or you don't have enough points." << endl;
								return;
							}

						}
						if (!colorMatch) {
							cout << "ERROR! Car not found." << endl;
						}

					}
						break;
					case 'c':
					case 'C': {
						cout << "Which color? ";
						getline(cin, car_color);
						for (int i = 0; i < 3 && !colorMatch; i++) {
							if (car_color == carr[i].color) {
								colorMatch = true;
								cout << "Which seat? (F)ront or (B)ack? ";
								cin >> seat_sel;
								cin.ignore();
								switch (seat_sel) {
								case 'f':
								case 'F': {
									if (!carr[i].seatArr[0].occupied && !match
											&& (Reservation_Records[count].point_val >= 5)) {
										carr[i].occupySeat(0);
										Reservation_Records[count].point_val -= 5;
										Reservation_Records[count].seat = 0; // set to front seat
										Reservation_Records[count].vehicle_color = carr[i].color;
										Reservation_Records[count].vehicle_type = "Compact";
										match = true;
									} else
										cout << "ERROR! Seat not available, or you don't have enough points." << endl;
								}
									break;
								case 'b':
								case 'B': {
									if (!carr[i].seatArr[1].occupied && !match
											&& (Reservation_Records[count].point_val >= 3)) {
										carr[i].occupySeat(1);
										Reservation_Records[count].point_val -= 3;
										Reservation_Records[count].seat = 1; // set to back-l seat
										Reservation_Records[count].vehicle_color = carr[i].color;
										Reservation_Records[count].vehicle_type = "Compact";
										match = true;
									} else if (!carr[i].seatArr[2].occupied && !match) {
										carr[i].occupySeat(2);
										Reservation_Records[count].seat = 2; // set to back-r seat
										Reservation_Records[count].vehicle_color = carr[i].color;
										Reservation_Records[count].vehicle_type = "Compact";
										Reservation_Records[count].point_val -= 3;
										match = true;
									} else
										cout << "ERROR! Seat not available, or you don't have enough points." << endl;
								}
									break;
								}
							}
						}
						if (!colorMatch) {
							cout << "ERROR! Car not found." << endl;
						}
					}
						break;
					case 's':
					case 'S':
						cout << "Which color? ";
						getline(cin, car_color);
						for (int i = 0; i < 3 && !colorMatch; i++) {
							if (car_color == sarr[i].color) {
								colorMatch = true;
								cout << "Which seat? (F)ront, (B)ack, or (M)iddle?" << endl;
								cin >> seat_sel;
								cin.ignore();
								switch (seat_sel) {
								case 'f':
								case 'F':
									if (!sarr[i].seatArr[0].occupied && !match
											&& (Reservation_Records[count].point_val >= 5)) {
										sarr[i].occupySeat(0);
										Reservation_Records[count].seat = 0;
										Reservation_Records[count].vehicle_color = sarr[i].color;
										Reservation_Records[count].vehicle_type = "Sedan";
										Reservation_Records[count].point_val -= 5;
										match = true;
									} else
										cout << "ERROR! Seat not available, or you don't have enough points." << endl;
									break;
								case 'b':
								case 'B':
									if (!sarr[i].seatArr[1].occupied && !match
											&& (Reservation_Records[count].point_val >= 2)) {
										sarr[i].occupySeat(1);
										Reservation_Records[count].seat = 1;
										Reservation_Records[count].vehicle_color = sarr[i].color;
										Reservation_Records[count].vehicle_type = "Sedan";
										Reservation_Records[count].point_val -= 2;
										match = true;
									} else if (!carr[i].seatArr[2].occupied && !match
											&& (Reservation_Records[count].point_val >= 2)) {
										sarr[i].occupySeat(2);
										Reservation_Records[count].seat = 2;
										Reservation_Records[count].vehicle_color = sarr[i].color;
										Reservation_Records[count].vehicle_type = "Sedan";
										Reservation_Records[count].point_val -= 2;
										match = true;
									} else
										cout << "ERROR! Seat not available, or you don't have enough points." << endl;
									break;
								case 'm':
								case 'M':
									if (!sarr[i].seatArr[3].occupied && !match
											&& (Reservation_Records[count].point_val >= 1)) {
										sarr[i].occupySeat(3);
										Reservation_Records[count].seat = 3;
										Reservation_Records[count].vehicle_color = sarr[i].color;
										Reservation_Records[count].vehicle_type = "Sedan";
										Reservation_Records[count].point_val -= 1;
										match = true;
									} else
										cout << "ERROR! Seat not available, or you don't have enough points." << endl;
									break;
								}
							}
						}
						if (!colorMatch) {
							cout << "ERROR! Car not found." << endl;
						}
					}
				}
					break;
				}
				v.display(parr, carr, sarr);
			}
		}
	}
	if (!nameMatch) {
		cout << "ERROR: Name entered not in database." << endl;
		cout << "Name entered was: " << passenger_name << endl;
		v.display(parr, carr, sarr);
	}
// for loop to go through database

	return;
}

/*
 * modify_reservations()
 *
 *    input:       NA
 *    output:      NA
 *    description: modifies the reservation by the reservation number
 */

void modify_reservation() {
	int number; // user entered reservation number
	string car;
	//int seat_number, current_seat;
	char car_type;
	bool colorMatch = false;
	bool match = false;
	char seat_sel;
	string car_color;

	cout << "Enter reservation number. ";
	cin >> number;
	cin.ignore();

	for (int count = 0; count < 24; count++) {
		if (number == Reservation_Records[count].res_number) { // its a match

			if (Reservation_Records[count].seat == 0) {
				Reservation_Records[count].point_val = Reservation_Records[count].point_val + 5;

				if (Reservation_Records[count].vehicle_type == "Pickup") { // pickup front seats
					if (Reservation_Records[count].vehicle_color == "Purple") {
						parr[0].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Yellow") {
						parr[1].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Red") {
						parr[2].seatArr[0].occupied = false;
					}
				} else if (Reservation_Records[count].vehicle_type == "Compact") { // compact car front seats
					if (Reservation_Records[count].vehicle_color == "Green") {
						carr[0].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Blue") {
						carr[1].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Yellow") {
						carr[2].seatArr[0].occupied = false;
					}
				} else if (Reservation_Records[count].vehicle_type == "Sedan") { // secan front seats
					if (Reservation_Records[count].vehicle_color == "Red") {
						sarr[0].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Green") {
						sarr[1].seatArr[0].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Blue") {
						sarr[2].seatArr[0].occupied = false;
					}
				}

			} else if (Reservation_Records[count].seat == 1) {
				if (Reservation_Records[count].vehicle_type == "Compact") {
					Reservation_Records[count].point_val = Reservation_Records[count].point_val + 3;

					if (Reservation_Records[count].vehicle_type == "Compact") { // compact car front seats
						if (Reservation_Records[count].vehicle_color == "Green") {
							carr[0].seatArr[1].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Blue") {
							carr[1].seatArr[1].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Yellow") {
							carr[2].seatArr[1].occupied = false;
						}
					} else {
						Reservation_Records[count].point_val = Reservation_Records[count].point_val + 2;
						if (Reservation_Records[count].vehicle_color == "Red") {
							sarr[0].seatArr[1].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Green") {
							sarr[1].seatArr[1].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Blue") {
							sarr[2].seatArr[1].occupied = false;
						}

					}
				} else if (Reservation_Records[count].seat == 2) {
					if (Reservation_Records[count].vehicle_type == "Compact") {
						Reservation_Records[count].point_val = Reservation_Records[count].point_val + 3;

						if (Reservation_Records[count].vehicle_color == "Green") {
							carr[0].seatArr[2].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Blue") {
							carr[1].seatArr[2].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Yellow") {
							carr[2].seatArr[2].occupied = false;
						}
					}

					else {
						Reservation_Records[count].point_val = Reservation_Records[count].point_val + 2;
						if (Reservation_Records[count].vehicle_color == "Red") {
							sarr[0].seatArr[2].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Green") {
							sarr[1].seatArr[2].occupied = false;
						} else if (Reservation_Records[count].vehicle_color == "Blue") {
							sarr[2].seatArr[2].occupied = false;
						}

					}
				} else {
					Reservation_Records[count].point_val = Reservation_Records[count].point_val + 1;
					if (Reservation_Records[count].vehicle_color == "Red") {
						sarr[0].seatArr[3].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Green") {
						sarr[1].seatArr[3].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Blue") {
						sarr[2].seatArr[3].occupied = false;
					}
				}
			}

			cout << "What car type? (P)ickup, (C)ompact, or (S)edan? ";
			cin >> car_type;
			cin.ignore();
			switch (car_type) {
			case 'p':
			case 'P':
				cout << "Which color? ";
				getline(cin, car_color);
				for (int i = 0; i < 3 && !colorMatch; i++) {
					if (parr[i].color == car_color) {
						colorMatch = true;
						if (!parr[i].seatArr[0].occupied && !match && (Reservation_Records[count].point_val > 5)) {
							parr[i].occupySeat(0);
							Reservation_Records[count].point_val -= 5;
							Reservation_Records[count].seat = 0; // set to front seat
							Reservation_Records[count].vehicle_color = parr[i].color;
							Reservation_Records[count].vehicle_type = "Pickup"; // set assigned vehicle to color pickup
							match = true;
							v.display(parr, carr, sarr);
						} else
							cout << "ERROR! Seat not available, or you don't have enough points." << endl;
						return;
					}
					if (!colorMatch) {
						cout << "ERROR! Car not found." << endl;
					}
				}
				break;
			case 'c':
			case 'C':
				cout << "Which color? ";
				getline(cin, car_color);
				for (int i = 0; i < 3 && !colorMatch; i++) {
					if (car_color == carr[i].color) {
						colorMatch = true;
						cout << "Which seat? (F)ront or (B)ack? ";
						cin >> seat_sel;
						cin.ignore();
						switch (seat_sel) {
						case 'f':
						case 'F': {
							if (!carr[i].seatArr[0].occupied && !match && (Reservation_Records[count].point_val >= 5)) {
								carr[i].occupySeat(0);
								Reservation_Records[count].point_val -= 5;
								Reservation_Records[count].seat = 0; // set to front seat
								Reservation_Records[count].vehicle_color = carr[i].color;
								Reservation_Records[count].vehicle_type = "Compact";
								match = true;
							} else
								cout << "ERROR! Seat not available, or you don't have enough points." << endl;
						}
							break;
						case 'b':
						case 'B': {
							if (!carr[i].seatArr[1].occupied && !match && (Reservation_Records[count].point_val >= 3)) {
								carr[i].occupySeat(1);
								Reservation_Records[count].point_val -= 3;
								Reservation_Records[count].seat = 1; // set to back-l seat
								Reservation_Records[count].vehicle_color = carr[i].color;
								Reservation_Records[count].vehicle_type = "Compact";
								match = true;
							} else if (!carr[i].seatArr[2].occupied && !match) {
								carr[i].occupySeat(2);
								Reservation_Records[count].seat = 2; // set to back-r seat
								Reservation_Records[count].vehicle_color = carr[i].color;
								Reservation_Records[count].vehicle_type = "Compact";
								Reservation_Records[count].point_val -= 3;
								match = true;
							} else
								cout << "ERROR! Seat not available, or you don't have enough points." << endl;
						}
							break;
						}
					}
				}
				if (!colorMatch) {
					cout << "ERROR! Car not found." << endl;
				}

				break;
			case 's':
			case 'S':
				cout << "Which color? ";
				getline(cin, car_color);
				for (int i = 0; i < 3 && !colorMatch; i++) {
					if (car_color == sarr[i].color) {
						colorMatch = true;
						cout << "Which seat? (F)ront, (B)ack, or (M)iddle?" << endl;
						cin >> seat_sel;
						cin.ignore();
						switch (seat_sel) {
						case 'f':
						case 'F':
							if (!sarr[i].seatArr[0].occupied && !match && (Reservation_Records[count].point_val >= 5)) {
								sarr[i].occupySeat(0);
								Reservation_Records[count].seat = 0;
								Reservation_Records[count].vehicle_color = sarr[i].color;
								Reservation_Records[count].vehicle_type = "Sedan";
								Reservation_Records[count].point_val -= 5;
								match = true;
							} else
								cout << "ERROR! Seat not available, or you don't have enough points." << endl;
							break;
						case 'b':
						case 'B':
							if (!sarr[i].seatArr[1].occupied && !match && (Reservation_Records[count].point_val >= 2)) {
								sarr[i].occupySeat(1);
								Reservation_Records[count].seat = 1;
								Reservation_Records[count].vehicle_color = sarr[i].color;
								Reservation_Records[count].vehicle_type = "Sedan";
								Reservation_Records[count].point_val -= 2;
								match = true;
							} else if (!carr[i].seatArr[2].occupied && !match
									&& (Reservation_Records[count].point_val >= 2)) {
								sarr[i].occupySeat(2);
								Reservation_Records[count].seat = 2;
								Reservation_Records[count].vehicle_color = sarr[i].color;
								Reservation_Records[count].vehicle_type = "Sedan";
								Reservation_Records[count].point_val -= 2;
								match = true;
							} else
								cout << "ERROR! Seat not available, or you don't have enough points." << endl;
							break;
						case 'm':
						case 'M':
							if (!sarr[i].seatArr[3].occupied && !match && (Reservation_Records[count].point_val >= 1)) {
								sarr[i].occupySeat(3);
								Reservation_Records[count].seat = 3;
								Reservation_Records[count].vehicle_color = sarr[i].color;
								Reservation_Records[count].vehicle_type = "Sedan";
								Reservation_Records[count].point_val -= 1;
								match = true;
							} else
								cout << "ERROR! Seat not available, or you don't have enough points." << endl;
							break;
						}
					}
				}
				if (!colorMatch) {
					cout << "ERROR! Car not found." << endl;
				}
			}
		} else {
			cout << "ERROR: Reservation number does not exist." << endl;
		}
	}
}
/*
 * delete_reservations()
 *
 *    input:       NA
 *    output:      NA
 *    description: delete's the reservation from the database
 */

void delete_reservation() {
	int delete_res;

	cout << "Enter reservation to be deleted: ";
	cin >> delete_res;

	if (delete_res == 23) { // its the last value in the array
		return;
	}

	for (int count = 0; count < 24; count++) {
		if (Reservation_Records[count].res_number == delete_res) {
			Reservation_Records[count].seat = 5; // unassigned
			Reservation_Records[count].vehicle_color = " Car not assigned.";
			Reservation_Records[count].vehicle_type = " Car not assigned.";

// TODO - This should work unless the object in the array has to literally be deleted
		} else {
			cout << "ERROR: Reservation does not exist." << endl;
		}
	}
}
/*
 * update_points()
 *
 *    input:       NA
 *    output:      NA
 *    description: updates the point values in seat_credits.txt
 */
void update_points() {

	ofstream outFile("seat_credits2.txt"); // TODO -- change this to seat_credits.txt at the end
	if (outFile.is_open()) {
		for (int res = 0; res < 24; res++) {
			outFile << Reservation_Records[res].name << " " << Reservation_Records[res].point_val << endl;
		}
	} else {
		cout << "Unable to open output file." << endl;
	}
}

void test_print() {
	cout << Reservation_Records[0].name << "Point value " << Reservation_Records[0].point_val << " Seat number: "
			<< Reservation_Records[0].seat << " Vehicle: " << Reservation_Records[0].vehicle_color
			<< Reservation_Records[0].vehicle_type;
}
