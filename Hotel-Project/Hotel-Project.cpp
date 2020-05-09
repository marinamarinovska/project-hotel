#include <iostream>
#include "Hotel.h"
#include "Room.h" 
#include <fstream>
#include<conio.h>
#include "Hotel-Project.h"
#include <string>
#pragma warning(disable : 4996)

void main() {
	
	std::string line;
	std::ifstream in( "C:\\Proekti\\project-hotel\\Hotel-Project\\reservations.txt");

	while (std::getline(in, line)) { //LINE = ROOM	FROM DATE 	TO DATE 	NOTE	[Posleden tab]	GUEST
		int room, guest;
		std::string from_date, to_date, note;

		//if (in.is_open())
		//std::cout << in.rdbuf();
		size_t lasttab = line.find_last_of('\t'); // Poslednia tab
		size_t beforecomment = line.find_last_of('\t', lasttab);
		size_t beforedateto = line.find_last_of('\t', beforecomment);
		size_t beforedatefrom = line.find_last_of('\t', beforedateto);

		room = atoi(line.substr(0, beforedatefrom).c_str());
		from_date = line.substr(beforedatefrom, beforedateto).c_str();
		to_date = line.substr(beforedateto, beforecomment).c_str();

		std::cout << room << from_date << to_date << std::endl;

	}
	in.close();
}
		