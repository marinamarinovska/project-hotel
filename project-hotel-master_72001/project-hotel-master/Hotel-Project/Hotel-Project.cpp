#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <vector>
#include <istream>
#include "Room.h"
#include "Reservation.h"

std::vector<Reservation> reservations;
std::vector<Room> rooms;

void optionsMenu();
void exit();

void main() 
{
	rooms = readRooms();
	optionsMenu();
	exit();
}

void optionsMenu()
{
	bool isOpen = false;
	char command[50];
	do {
		std::cout << "Type a command" << std::endl;
		std::cin >> command;
		if (std::strcmp(command, "open") == 0) {
			isOpen = true;
			reservations = readReservations();
		}
		else if (std::strcmp(command, "checkin") == 0 && isOpen) {
			reservations = newReservation(reservations);
		}
		else if (std::strcmp(command, "checkout") == 0 && isOpen) {
			reservations = removeReservation(reservations);
		}
		else if (std::strcmp(command, "clear") == 0) {
			system("cls");
		}
		else if (std::strcmp(command, "list") == 0) {
			printReservations(reservations);
		}
		else if (std::strcmp(command, "help") == 0) {
			std::cout << "Here are list of commands that you can use:" << std::endl << std::endl;
			if (!isOpen)
			{
				std::cout << "open - This will open reservations file" << std::endl;
			}
			else
			{
				std::cout << "checkin - This will add new reservation" << std::endl;
				std::cout << "checkout - This will checkout reservation" << std::endl;
				std::cout << "availability - This will check availability for date" << std::endl;
				std::cout << "unavailable - This will mark room as reserved" << std::endl;
				std::cout << "save - This will save all reservations" << std::endl;
				std::cout << "list - This will print all reservations" << std::endl;
			}
			std::cout << "clear - This will clear the terminal" << std::endl;
			std::cout << "help - This will show this screen" << std::endl;
			std::cout << "exit - This will close the app" << std::endl;
		}
		else if (std::strcmp(command, "save") == 0) {
			saveReservations(reservations);
		}
	} while (std::strcmp(command, "exit") != 0);
}

void exit()
{
	char myChoise;
	do {
		std::cout << "Do you want to save your reservations? Y/N?" << ::std::endl;
		std::cin >> myChoise;
	} while (myChoise != 'Y' && myChoise != 'y' && myChoise != 'N' && myChoise != 'n');

	if (myChoise == 'Y' || myChoise == 'y') {
		saveReservations(reservations);
	}
	else {
		std::cout << "Your reservation is not save." << std::endl;
	}
}