/************************************************
Title: header.h
Name: Rowan D'Ausilio & Satyendra Emani
Class: CPET-321
Date: Nov 13, 2019
Description: The function prototypes and class prototypes for project 2
************************************************/

#ifndef COMPILE_HEADER_H_
#define COMPILE_HEADER_H_

struct seat;
struct reservation;
class vehicle;
class pickup;
class compact;
class sedan;

void display(pickup*, compact*, sedan*);
void read_reservation();
void write_reservations();

#endif /* COMPILE_HEADER_H_ */
