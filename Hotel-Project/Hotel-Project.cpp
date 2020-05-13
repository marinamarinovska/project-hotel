#include <iostream>
#include <fstream>
#include<conio.h>
#include <time.h>
#include <vector>
#include <istream>
#pragma warning(disable : 4996)

struct Reservation {
	int room;
	time_t date_from;
	time_t date_to;
	char* note;
	int guests;
};

struct Room {
	int room;
	int guests;
};

std::vector<Room> readRooms();
std::vector<Reservation> readReservations();

void main() {
	std::vector<Room> rooms = readRooms();
	char command[50];
	do {
		std::cout << "Type a command" << std::endl;
		std::cin >> command;
		if (std::strcmp(command, "open") == 0) {
			std::vector<Reservation> reservation = readReservations();
		}
		if (std::strcmp(command, "clear") == 0) {
			system("cls");
		}
		if (std::strcmp(command, "help") == 0) {
			std::cout << "Here are list of commands that you can use:" << std::endl << std::endl;
			std::cout << "open - This will open default file for all reservations" << std::endl;
			std::cout << "clear - This will clear the terminal" << std::endl;
			std::cout << "help - This will show this screen" << std::endl;
			std::cout << "exit - This will close the app" << std::endl;
		}
	} while (std::strcmp(command, "exit") > 0);
}

std::vector<Room> readRooms() {
	std::vector<Room> rooms;
	char line[150];
	std::ifstream in(".\\rooms.txt");
	bool isFirstLine = true;

	while (in.getline(line, sizeof(line))) {
		if (isFirstLine == true) {
			isFirstLine = false;
			continue;
		}
		char* param;
		param = strtok(line, "\t");
		int countParams = 0, nom = 0, guests = 0;
		while (param != NULL) {
			if (countParams == 0) nom = atoi(param);
			if (countParams == 1) guests = atoi(param);
			param = strtok(NULL, "\t");
			countParams++;
		}

		Room cur_room;
		cur_room.room = nom;
		cur_room.guests = guests;

		rooms.push_back(cur_room);
	}
	in.close();
	return rooms;
}
		
std::vector<Reservation> readReservations(){
	std::vector<Reservation> reservation;
	char line[150];
	std::ifstream in(".\\reservations.txt");
	bool isFirstLine = true;

	while (in.getline(line, sizeof (line))) {
		if (isFirstLine == true) {
			isFirstLine = false;
			continue;
		}
		int room = 0, guest = 0;
		time_t from_date;
		time_t to_date;
		char note[50];
		char* param;
		int countParams = 0;
		param = strtok(line, "\t"); 
		while(param != NULL) {
			if (countParams == 0) room = atoi(param);
			if (countParams == 1) {
				struct tm tmdate = { 0 };
				tmdate.tm_year = atoi(&param[0]) - 1900;
				tmdate.tm_mon = atoi(&param[5]) - 1;
				tmdate.tm_mday = atoi(&param[8]);
				from_date = mktime(&tmdate);
			}
			//if (countParams == 1) strcpy(from_date, param);
			if (countParams == 2) {
				struct tm tmdate = { 0 };
				tmdate.tm_year = atoi(&param[0]) - 1900;
				tmdate.tm_mon = atoi(&param[5]) - 1;
				tmdate.tm_mday = atoi(&param[8]);
				to_date = mktime(&tmdate);
			}
			//if (countParams == 2) strcpy(to_date, param);
			if (countParams == 3) strcpy(note, param);
			if (countParams == 4) guest = atoi(param);

			param = strtok(NULL, "\t");
			countParams++;
		}

		std::cout << room << from_date << to_date << note << guest << std::endl;
		
		
		Reservation cur_reserve;
		cur_reserve.room = room;
		cur_reserve.guests = guest;
		cur_reserve.date_from = from_date;
		cur_reserve.date_to = to_date;
		cur_reserve.note = note;

		reservation.push_back(cur_reserve);
	}
	in.close();
	return reservation;
}

//
//void main() {
//	std::ifstream infile(".\\reservations.txt", std::ifstream::binary);
//	std::ofstream outfile(".\\newReservations.txt", std::ofstream::binary);
//	infile.seekg(0, infile.end);
//	long size = infile.tellg();
//	infile.seekg(0);
//	char* buffer = new char[size];
//	infile.read(buffer, size);
//	outfile.write(buffer, size)
//	delete[] buffer;
//
//	outfile.close();
//	infile.close();
//	return;
//
//
//
//	FILE* pFile;
//	pFile = fopen(".\\reservations.txt", "r");
//	if (pFile == NULL)
//	{
//		printf("Error opening file");
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		/* file operations here */
//	}
//	return ;
//}