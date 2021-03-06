/************************************************
 Title: header.cpp
 Name: Rowan D'Ausilio & Satyendra Emani
 Class: CPET-321
 Date: Nov 13, 2019
 Description: The file with all the fucntions and classes defined for
 comp problem solving 2 project
 ************************************************/

#include "header.h"  // the header.h file
#include <iostream>  // cin's and cout's
#include <iomanip>   // for printing things nicely
#include <fstream>   // needed for file I/O
#include <cstdlib>   // needed for exit()

using namespace std;

reservation Reservation_Records[24]; // the array of all the reservations

pickup p1("Purple"), p2("Yellow"), p3("Red"); // pickup trucks initialized
compact c1("Green"), c2("Blue"), c3("Yellow"); // Compact cars initialized
sedan s1("Red"), s2("Green"), s3("Blue"); // sedans initialized

pickup parr[3] = { p1, p2, p3 }; // pickup array
compact carr[3] = { c1, c2, c3 }; // compact car array
sedan sarr[3] = { s1, s2, s3 }; // sedan array
vehicle v; // vehicle

/*
 * vehicle::print_vehicle_assign()
 *
 *    input:       the arrays of the truck, compact and sedans
 *    output:      N/A
 *    description: prints the people in the spesific vehicle requested and writes
 *    to a file called "color_vehicle.txt" with who is sitting in each seat in the
 *    vehicle
 */

void vehicle::print_vehicle_assign(pickup truckArr[], compact compArr[], sedan sedArr[]) {

	int menuSel = 0; // int to pick which cars
	int idx = 0; // index
	string filename; // the file name to be written

	cout << "Which vehicle assignments would you like to print?" << endl;

	cout << "(1) Purple Pickup" << endl;
	cout << "(2) Yellow Pickup" << endl;
	cout << "(3) Red Pickup" << endl;

	cout << "(4) Green Compact" << endl;
	cout << "(5) Blue Compact" << endl;
	cout << "(6) Yellow Compact" << endl;

	cout << "(7) Red Sedan" << endl;
	cout << "(8) Green Sedan" << endl;
	cout << "(9) Blue Sedan" << endl;
	cin >> menuSel;
	cin.ignore();

	if (menuSel >= 1 && menuSel <= 3) {
		idx = menuSel - 1;
		cout << "Assignments for " << truckArr[idx].color << " Pickup:" << endl;

		filename = truckArr[idx].color + "_pickup.txt";
		ofstream outFile(filename.c_str());

		if (truckArr[idx].seatArr[0].occupied) { // seat occupied
			outFile << "Front seat: ";
			cout << "Front seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == truckArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Pickup" && Reservation_Records[c].seat == 0) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Front seat: Unassigned." << endl;
			cout << "Front seat: Unassigned" << endl;
		}
	} else if (menuSel >= 4 && menuSel <= 6) {
		idx = menuSel - 4;
		cout << "Assignments for " << compArr[idx].color << " Compact:" << endl;

		filename = compArr[idx].color + "_compact.txt";
		ofstream outFile(filename.c_str());

		outFile << compArr[idx].color << " compact:" << endl;
		if (compArr[idx].seatArr[0].occupied) {
			outFile << "Front seat: ";
			cout << "Front seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == compArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Compact" && Reservation_Records[c].seat == 0) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Front seat: Unassigned." << endl;
			cout << "Front seat: Unassigned." << endl;
		}

		if (compArr[idx].seatArr[1].occupied) {
			outFile << "Left back seat: ";
			cout << "Left back seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == compArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Compact" && Reservation_Records[c].seat == 1) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Left back seat: Unassigned." << endl;
			cout << "Left back seat: Unassigned." << endl;
		}

		if (compArr[idx].seatArr[2].occupied) {
			outFile << "Right back seat: ";
			cout << "Right back seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == compArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Compact" && Reservation_Records[c].seat == 2) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Right back seat: Unassigned." << endl;
			cout << "Right back seat: Unassigned." << endl;
		}
	} else if (menuSel >= 7 && menuSel <= 9) {
		idx = menuSel - 7;
		cout << "Assignments for " << sedArr[idx].color << " Sedan:" << endl;

		filename = sedArr[idx].color + "_sedan.txt";
		ofstream outFile(filename.c_str());

		outFile << sedArr[idx].color << " sedan:" << endl;
		if (sedArr[idx].seatArr[0].occupied) {
			outFile << "Front seat: ";
			cout << "Front seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == sedArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 0) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Front seat: Unassigned." << endl;
			cout << "Front seat: Unassigned." << endl;
		}

		if (sedArr[idx].seatArr[1].occupied) {
			outFile << "Left back seat: ";
			cout << "Left back seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == sedArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 1) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Left back seat: Unassigned." << endl;
			cout << "Left back seat: Unassigned." << endl;
		}

		if (sedArr[idx].seatArr[3].occupied) {
			outFile << "Middle back seat: ";
			cout << "Middle back seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == sedArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 3) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Middle back seat: Unassigned." << endl;
			cout << "Middle back seat: Unassigned." << endl;
		}

		if (sedArr[idx].seatArr[2].occupied) {
			outFile << "Right back seat: ";
			cout << "Right back seat: ";
			for (int c = 0; c < 24; c++) {
				if (Reservation_Records[c].vehicle_color == sedArr[idx].color
						&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 2) {
					outFile << Reservation_Records[c].name << endl;
					cout << Reservation_Records[c].name << endl;
				}
			}
		} else {
			outFile << "Right back seat: Unassigned." << endl;
			cout << "Right back seat: Unassigned." << endl;
		}

	}

}

/*
 * vehicle::occupySeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: sets the car seat to occupied based on the number
 */
void vehicle::occupySeat(int seat) {
	seatArr[seat].occupied = true;
}

/*
 * vehicle::freeSeat()
 *
 *    input:       number of seat(front seat = 1, left back seat = 2, etc.)
 *    output:      N/A
 *    description: frees a car seat in the car
 */
void vehicle::freeSeat(int seat) {
	seatArr[seat].occupied = false;
}

/*
 * vehicle::display()
 *
 *    input:       pickup, compact, and sedan arrays
 *    output:      N/A
 *    description: displays the vehicles to the console "nicely"
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

/*
 * display_all()
 *
 *    input:       N/A
 *    output:      N/A
 *    description: calls the display function. this exists so that display can be called from
 *    main
 */
void display_all() {
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

	string first_name; // first name of person
	string last_name; // last name of person

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
		Reservation_Records[count].name = first_name + ' ' + last_name; // puts the first and last name together
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
					outFile << "Front seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == truckArr[i].color
								&& Reservation_Records[c].vehicle_type == "Pickup"
								&& Reservation_Records[c].seat == 0) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}
				outFile << endl;
			}

			outFile << "-- Compact Car Assignments -- " << endl;

			for (int i = 0; i < 3; i++) {
				outFile << compArr[i].color << " compact:" << endl;
				if (compArr[i].seatArr[0].occupied) {
					outFile << "Front seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == compArr[i].color
								&& Reservation_Records[c].vehicle_type == "Compact"
								&& Reservation_Records[c].seat == 0) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}

				if (compArr[i].seatArr[1].occupied) {
					outFile << "Left back seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == compArr[i].color
								&& Reservation_Records[c].vehicle_type == "Compact"
								&& Reservation_Records[c].seat == 1) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Left back seat: Unassigned." << endl;
				}

				if (compArr[i].seatArr[2].occupied) {
					outFile << "Right back seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == compArr[i].color
								&& Reservation_Records[c].vehicle_type == "Compact"
								&& Reservation_Records[c].seat == 2) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Right back seat: Unassigned." << endl;
				}
				outFile << endl;
			}
			outFile << "-- Sedan Assignments -- " << endl;

			for (int i = 0; i < 3; i++) {
				outFile << sedArr[i].color << " sedan:" << endl;
				if (sedArr[i].seatArr[0].occupied) {
					outFile << "Front seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == sedArr[i].color
								&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 0) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Front seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[1].occupied) {
					outFile << "Left back seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == sedArr[i].color
								&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 1) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Left back seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[3].occupied) {
					outFile << "Middle back seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == sedArr[i].color
								&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 3) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
				} else {
					outFile << "Middle back seat: Unassigned." << endl;
				}

				if (sedArr[i].seatArr[2].occupied) {
					outFile << "Right back seat: ";
					for (int c = 0; c < 24; c++) {
						if (Reservation_Records[c].vehicle_color == sedArr[i].color
								&& Reservation_Records[c].vehicle_type == "Sedan" && Reservation_Records[c].seat == 2) {
							outFile << Reservation_Records[c].name << endl;
						}
					}
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

	}
}

/*
 * write_res_file()
 *
 *    input:       NA
 *    output:      NA
 *    description: calls the write_reservations function. this function is so that it can be called
 *    from main
 */

void write_res_file() {
	v.write_reservations(parr, carr, sarr);
}

/*
 * print_veh_file()
 *
 *    input:       NA
 *    output:      NA
 *    description: calls the print_vehicle_assign function so that it can be
 *    called from main
 */

void print_veh_file() {
	v.print_vehicle_assign(parr, carr, sarr);
}

/*
 * create_reservation()
 *
 *    input:       NA
 *    output:      NA
 *    description: finds the person in the database and edits the car that they are in as well
 *                 as the seat they are going to sit in
 */

void create_reservation() {
	string passenger_first; // user entered person's name
	string passenger_last; // user entered last name
	string passenger_name; // full name
	char menu_sel; //menu select
	char submenu_sel; // sub menu select
	char seat_sel; // seat selection
	string car_color; // car color
	bool nameMatch = false; // name match boolean

	cout << "Enter passenger's name to create the reservation: ";
	cin >> passenger_first >> passenger_last;
	passenger_name = passenger_first + " " + passenger_last;

	for (int count = 0; count < 24; count++) {
		if (passenger_name == Reservation_Records[count].name) {
			cout << Reservation_Records[count].name << " has " << Reservation_Records[count].point_val << " points."
					<< endl;
			cout << "Reservation number is: " << Reservation_Records[count].res_number << endl;
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
					cout << "What seat do you want? (F)ront, (B)ack, or (M)iddle?" << endl;
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
								Reservation_Records[count].seat = 0;
								Reservation_Records[count].point_val -= 5;
							}
						} else {
							cout << "ERROR! Not enough points for a front seat." << endl;
						}

					}
						break;
					case 'b':
					case 'B': {
						if (Reservation_Records[count].point_val >= 2) {
							for (int i = 0; (i < 3) && !match; i++) {
								if ((!carr[i].seatArr[1].occupied && !match)
										&& Reservation_Records[count].point_val >= 3) {
									carr[i].occupySeat(1);
									Reservation_Records[count].point_val -= 3;
									Reservation_Records[count].seat = 1;
									Reservation_Records[count].vehicle_color = carr[i].color;
									Reservation_Records[count].vehicle_type = "Compact";
									match = true;
								} else if ((!carr[i].seatArr[2].occupied && !match)
										&& Reservation_Records[count].point_val >= 3) {
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
	char car_type; // the type of car they're in
	bool colorMatch = false; // if the color of the car matches
	bool match = false; // if the car matches
	bool resMatch = false; // if the reservation matches
	char seat_sel; // the selected seat char
	string car_color; // the color of the car

	cout << "Enter reservation number: ";
	cin >> number;
	cin.ignore();

	for (int count = 0; count < 24; count++) {
		if (number == Reservation_Records[count].res_number) { // its a match
			resMatch = true;
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
				} else if (Reservation_Records[count].vehicle_type == "Sedan") { // sedan front seats
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

				else if (Reservation_Records[count].vehicle_type == "Sedan") {
					Reservation_Records[count].point_val = Reservation_Records[count].point_val + 2;
					if (Reservation_Records[count].vehicle_color == "Red") {
						sarr[0].seatArr[2].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Green") {
						sarr[1].seatArr[2].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Blue") {
						sarr[2].seatArr[2].occupied = false;
					}

				}
			} else if (Reservation_Records[count].seat == 3) {
				Reservation_Records[count].point_val = Reservation_Records[count].point_val + 1;
				if (Reservation_Records[count].vehicle_color == "Red") {
					sarr[0].seatArr[3].occupied = false;
				} else if (Reservation_Records[count].vehicle_color == "Green") {
					sarr[1].seatArr[3].occupied = false;
				} else if (Reservation_Records[count].vehicle_color == "Blue") {
					sarr[2].seatArr[3].occupied = false;
				}
			}
			v.display(parr, carr, sarr);
			cout << Reservation_Records[count].name << " has " << Reservation_Records[count].point_val << " points."
					<< endl;
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
				}
				if (!colorMatch) {
					cout << "ERROR! Car not found." << endl;
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
		}
	}
	if (!resMatch) {
		cout << "ERROR: Reservation number does not exist." << endl;
	}
}
/*
 * delete_reservations()
 *
 *    input:       NA
 *    output:      NA
 *    description: delete's the reservation from the database and sets the reservations values
 *    back to default
 */

void delete_reservation() {
	int delete_res;
	bool resfound = false;

	cout << "Enter reservation to be deleted: ";
	cin >> delete_res;
	cin.ignore();

	if (delete_res == 23) { // its the last value in the array
		return;
	}

	for (int count = 0; count < 24; count++) {
		if (Reservation_Records[count].res_number == delete_res) {
			resfound = true;

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

				else if (Reservation_Records[count].vehicle_type == "Sedan") {
					Reservation_Records[count].point_val = Reservation_Records[count].point_val + 2;
					if (Reservation_Records[count].vehicle_color == "Red") {
						sarr[0].seatArr[2].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Green") {
						sarr[1].seatArr[2].occupied = false;
					} else if (Reservation_Records[count].vehicle_color == "Blue") {
						sarr[2].seatArr[2].occupied = false;
					}

				}
			} else if (Reservation_Records[count].seat == 3) {
				Reservation_Records[count].point_val = Reservation_Records[count].point_val + 1;
				if (Reservation_Records[count].vehicle_color == "Red") {
					sarr[0].seatArr[3].occupied = false;
				} else if (Reservation_Records[count].vehicle_color == "Green") {
					sarr[1].seatArr[3].occupied = false;
				} else if (Reservation_Records[count].vehicle_color == "Blue") {
					sarr[2].seatArr[3].occupied = false;
				}

			}

			Reservation_Records[count].seat = 5; // unassigned
			Reservation_Records[count].vehicle_color = " Car not assigned.";
			Reservation_Records[count].vehicle_type = " Car not assigned.";
		}
	}
	if (!resfound) {
		cout << "ERROR: Reservation does not exist." << endl;
	}
}

/*
 * update_points()
 *
 *    input:       NA
 *    output:      NA
 *    description: updates the point values in seat_credits2.txt. this can be changed if actually implemented for the rowing
 *    team. writes to a second file just so that in testing and debugging everyone's points don't get completely overwritten
 *    and or lost
 */

void update_points() {

	ofstream outFile("seat_credits2.txt"); // this can be changed if this was actually implemented
	if (outFile.is_open()) {
		for (int res = 0; res < 24; res++) {
			outFile << Reservation_Records[res].name << " " << Reservation_Records[res].point_val << endl;
		}
	} else {
		cout << "Unable to open output file." << endl;
	}
}

// this function just test prints
/*

void test_print() {
	cout << Reservation_Records[0].name << endl;
	cout << "Point value " << Reservation_Records[0].point_val << endl;
	cout << " Seat number: " << Reservation_Records[0].seat << endl;
	cout << " Vehicle: " << Reservation_Records[0].vehicle_color << Reservation_Records[0].vehicle_type << endl;
}
*/
