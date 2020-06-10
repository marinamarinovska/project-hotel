#pragma once
#include <ctime>
#include <stdio.h>

char reservationsFile[] = ".\\reservations.txt";

struct Reservation {
	int room;
	time_t date_from;
	time_t date_to;
	char note[100];
	int guests;
};

std::vector<Reservation> readReservations() {
	std::vector<Reservation> reservation;
	char line[150];
	std::ifstream in(reservationsFile);

	while (in.getline(line, sizeof(line))) {
		int room = 0, guest = 0;
		time_t from_date = time(NULL);
		time_t to_date = time(NULL);
		char note[100];
		char* param;
		int countParams = 0;
		param = strtok(line, "\t");
		while (param != NULL) {
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


		Reservation cur_reserve;
		cur_reserve.room = room;
		cur_reserve.guests = guest;
		cur_reserve.date_from = from_date;
		cur_reserve.date_to = to_date;
		strcpy(cur_reserve.note, note);

		reservation.push_back(cur_reserve);
	}
	in.close();
	return reservation;
}

std::vector<Reservation> newReservation(std::vector<Reservation> reservations)
{
	int room, guests;
	time_t date_from, date_to;
	char note[100];
	char date[11];
	std::cout << "Enter room number" << std::endl;
	std::cin >> room;
	std::cout << "Enter check-in date in format YYYY-MM-DD" << std::endl;
	std::cin >> date;

	struct tm tmdate = { 0 };
	tmdate.tm_year = atoi(&date[0]) - 1900;
	tmdate.tm_mon = atoi(&date[5]) - 1;
	tmdate.tm_mday = atoi(&date[8]);
	date_from = mktime(&tmdate);

	std::cout << "Enter check-out date in format YYYY-MM-DD" << std::endl;
	std::cin >> date;


	struct tm tmDate = { 0 };
	tmDate.tm_year = atoi(&date[0]) - 1900;
	tmDate.tm_mon = atoi(&date[5]) - 1;
	tmDate.tm_mday = atoi(&date[8]);
	date_to = mktime(&tmDate);

	std::cout << "Enter a comment" << std::endl;
	getchar();
	fgets(note, 100, stdin);
	note[strcspn(note, "\r\n")] = 0;
	std::cout << "Enter number of guests" << std::endl;
	std::cin >> guests;

	char myChoise;
	do {
		std::cout << "Do you want to save your reservation? Y/N?" << ::std::endl;
		std::cin >> myChoise;
	} while (myChoise != 'Y' && myChoise != 'N' && myChoise != 'y' && myChoise != 'n');

	if (myChoise == 'y' || myChoise == 'Y') {
		Reservation tmpReserv;
		tmpReserv.room = room;
		tmpReserv.date_from = date_from;
		tmpReserv.date_to = date_to;
		strcpy(tmpReserv.note, note);
		tmpReserv.guests = guests;
		reservations.push_back(tmpReserv);
		std::cout << "Reservations is add successfully" << std::endl;
	}
	else {
		std::cout << "You canceled you reservation!" << std::endl;
	}
	return reservations;
}

void printReservations(std::vector<Reservation> reservations)
{
	for (auto& element : reservations)
	{
		char date_from[20];
		strftime(date_from, 20, "%Y-%m-%d", localtime(&element.date_from));
		char date_to[20];
		strftime(date_to, 20, "%Y-%m-%d", localtime(&element.date_from));
		printf("%d %s %s %s %d\n", element.room, date_from, date_to, element.note, element.guests);
	}
}

void saveReservations(std::vector<Reservation> reservations)
{
	std::ofstream outputfile(reservationsFile);
	for (auto& element : reservations)
	{
		char date_from[20];
		strftime(date_from, 20, "%Y-%m-%d", localtime(&element.date_from));
		char date_to[20];
		strftime(date_to, 20, "%Y-%m-%d", localtime(&element.date_from));
		outputfile << element.room << "\t" << date_from << "\t" << date_to << "\t" << element.note << "\t" << element.guests << "\n";
	}
	printf("Saved successfully!\n");
}

std::vector<Reservation> removeReservation(std::vector<Reservation> reservations)
{
	int room;
	int i = 0;

	std::cout << "Please enter room number\n";
	std::cin >> room;
	for (auto& element : reservations)
	{
		if (element.room == room)
		{
			reservations.erase(reservations.begin() + i);
		}
		else {
			i++;
		}
	}
	printf("Checkout successfully!\n");
	return reservations;
}