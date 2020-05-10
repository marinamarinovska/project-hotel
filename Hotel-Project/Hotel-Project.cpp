#include <iostream>
#include <fstream>
#include<conio.h>
#include "Hotel-Project.h"
#include <vector>
#include <istream>
#pragma warning(disable : 4996)

struct Reservation {
	int room;
	char* date_from;
	char* date_to;
	char* note;
	int guests;
};

struct Room {
	int room;
	int guests;
};
struct Reservations {
	int room, guest;
	std::string from_date, to_date, note;
};

void readReservation();
std::vector<Room> readRooms();
std::vector<Reservations> readReservations();

void main() {
	std::vector<Room> rooms = readRooms();
	//std::vector<Reservations> reservation = readReservation();
}

void readReservation()
{
	std::vector<Reservations> reservation = readReservations();
}

std::vector<Room> readRooms() {
	std::vector<Room> rooms;
	char*  line;
	std::ifstream in(".\\rooms.txt");
	// тъй като теста ми беше със стринг, сега ще го преработя с char*, затова на този етап дава грешки 
	while (std::getline(in, line)) {
		int nom, guests;

		size_t lasttab = line.find_last_of('\t');

		nom = atoi(line.substr(0, lasttab).c_str());
		int len = line.length() - lasttab - 1;
		guests = atoi(line.substr(lasttab + 1, len).c_str());


		Room cur_room;
		cur_room.room = nom;
		cur_room.guests = guests;

		rooms.push_back(cur_room);
	}
	in.close();
	return rooms;
}
		
std::vector<Reservations> readReservations(){
	std::vector<Reservations> reservation;
	char*  line;
	std::ifstream in(".\\reservations.txt");

	while (std::getline(in, line)) {
		int room, guest;
		char* from_date, to_date, note;
		//100	2020-05-06	2020-05-13	2 with kid	3
		//012(3)  456789[10]123(4) 56789[20]1234(5) 6789[30]12345(6) 7    [38]
		//4 14 25 36
		size_t lasttab = line.find_last_of('\t'); // Poslednia tab

		size_t beforecomment = line.find_last_of('\t', lasttab - 1);
		size_t beforedateto = line.find_last_of('\t', beforecomment - 1);
		size_t beforedatefrom = line.find_last_of('\t', beforedateto - 1);

		room = atoi(line.substr(0, beforedatefrom).c_str());
		int len = beforedateto - beforedatefrom - 1;
		from_date = line.substr(beforedatefrom + 1, len).c_str();
		len = beforecomment - beforedateto - 1;
		to_date = line.substr(beforedateto + 1, len).c_str();
		len = lasttab - beforecomment - 1;
		note = line.substr(beforecomment + 1, len).c_str();
		len = line.length() - lasttab - 1;
		guest = atoi(line.substr(lasttab + 1, len).c_str());

		//std::cout << room << from_date << to_date << note << guest << std::endl;
		
		
		Reservations cur_reserve;
		cur_reserve.room = room;
		cur_reserve.guest = guest;
		cur_reserve.from_date = from_date;
		cur_reserve.to_date = to_date;
		cur_reserve.note = note;

		reservation.push_back(cur_reserve);
	}
	in.close();
	return reservation;
	
}


void main() {
	std::ifstream infile("reservations.txt", std::ifstream::binary);
	std::ofstream outfile("newReservations.txt", std::ofstream::binary);
	infile.seekg(0, infile.end);
	long size = infile.tellg();
	infile.seekg(0);
	char* buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size)
	delete[] buffer;

	outfile.close();
	infile.close();
	return;
}