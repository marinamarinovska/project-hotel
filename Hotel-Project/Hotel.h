#pragma once
#include <iostream>
#include "Room.h"
#include "Person.h"
#include<string.h>
#include<conio.h>
#pragma warning(disable : 4996)

#define max 100




//Class klient
class Guest
{
public:
	char name[100];
	char from[20];
	char to[20];
	//int booking_id; -идентификационен номер за резервация

};

class Hotel :protected Room
{
public:
	void checkIn();
	void availabilitRoom(); //getAvailRoom
	void reportGuest(char*); // search customer
	void checkOut(int);
	void greport(); //guestSummaryReport
};


void Hotel::greport() {

	if (scount == 0) {
		std::cout << "No Guest in Hotel " << std::endl;
	}
	for (int i = 0; i < scount; i++)
	{
		if (rooms[i].title == 1)
		{
			std::cout << "Enter your First Name : " << rooms[i].guest.name << std::endl;
			std::cout << " Room Number : " << rooms[i].roomNum << std::endl;
		}

	}

	getch();
}

//резервация на стая
void Hotel::checkIn()
{
	int i, found = 0, rnum;

	class Room room;
	std::cout << "Room number : " << std::endl;
	std::cin >> rnum;
	for (i = 0; i < scount; i++)
	{
		if (rooms[i].roomNum == rnum)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		if (rooms[i].title == 1)
		{
			std::cout << "Room is booked" << std::endl;
			getch();
			return;
		}

		//std::cout << "Enter booking id: " << std::endl;
		//std::cin >> rooms[i].guest.booking_id;

		std::cout << "Еnter your name : " << std::endl;
		std::cin >> rooms[i].guest.name;


		std::cout << "Enter From Date: " << std::endl;
		std::cin >> rooms[i].guest.from;

		std::cout << "Еnter data for stay :" << std::endl;
		std::cin >> rooms[i].guest.to;

		rooms[i].title = 1;

		std::cout << "Guest checked in successfully.." << std::endl;
		getch();
	}
}


//показва свободни стаи
void Hotel::availabilitRoom()
{
	int i, found = 0;
	for (i = 0; i < scount; i++)
	{
		if (rooms[i].title == 0)
		{
			showRoom(rooms[i]); // class Room
			std::cout << "Press enter for next room" << std::endl;
			found = 1;
			getch();
		}
	}
	if (found == 0)
	{
		std::cout << "All rooms are reserved" << std::endl;
		getch();
	}
}


//хотелът показва всички лица, които са резервирали стая
void Hotel::reportGuest(char* pname) // class Room searchguest
{
	int i, found = 0;
	for (i = 0; i < scount; i++)
	{
		if (rooms[i].title == 1 && stricmp(rooms[i].guest.name, pname) == 0)
		{
			std::cout << "Your name: " << rooms[i].guest.name << std::endl;


			std::cout << "Enter for next..." << std::endl;
			found = 1;
			getch();
		}
	}
	if (found == 0)
	{
		std::cout << "Guest is not found." << std::endl;
		getch();
	}
}


//сметката за разходите
void Hotel::checkOut(int roomNum)
{
	int i, found = 0, days, rno;
	float billAmount = 0;
	for (i = 0; i < scount; i++)
	{
		if (rooms[i].title == 1 && rooms[i].roomNum == roomNum)
		{
			//rnum = rooms[i].roomNum;
			found = 1;
			//getch();
			break;
		}
	}
	if (found == 1)
	{
		std::cout << "Enter Number of Days:" << std::endl;
		std::cin >> days;
		billAmount = days * rooms[i].rent;

		//cout << "\n\t CheckOut Details\n";
		std::cout << "Guest Name : " << rooms[i].guest.name << std::endl;
		std::cout << "Room Number : " << rooms[i].roomNum << std::endl;


		rooms[i].title = 0;
	}
	getch();
}
#pragma once
