#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>
#include "Hotel.h"
#include "Guest.h"

#pragma warning(disable : 4996)
#define max 100

class Room
{
public:
	char type;
	char beds;
	int roomNum; 
	int rent;
	int title; // status

	class Guest guest; //class customer cust
	class Room addRoom(int);
	void searchRoom(int);
	void deleteRoom(int);
	void showRoom (Room); // display room

};

//Globalna deklaraciq
class Room rooms[max];
int scount = 0;


Room Room::addRoom(int rnum)
{
	class Room room;
	room.roomNum = rnum; //rno - rnum
	std::cout << "Type Room (S/N) : " << std::endl;
	std::cin >> room.type;
	std::cout << "Number of beds(B/S) : " << std::endl;
	std::cin >> room.beds;
	std::cout << "Price for one day: " << std::endl;
	std::cin >> room.rent;
	room.title = 0;

	std::cout << "Room Added Successfully!" << std::endl;
	getch();
	return room;
}


void Room::searchRoom(int rnum)
{
	int i, found = 0;
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
		std::cout << "Room Details" << std::endl;
		if (rooms[i].title == 1)
		{
			std::cout << "Room is Reserved" << std::endl;
		}
		else
		{
			std::cout << "Room is available" << std::endl;
		}
		showRoom(rooms[i]);
		getch();
	}
	else
	{
		std::cout << "Room not found" << std::endl;
		getch();
	}
}

void Room::showRoom(Room tempRoom)
{
	std::cout << "Room Number: " << tempRoom.roomNum << std::endl;
	std::cout << "Type Room " << tempRoom.type << std::endl;
	std::cout << "Number of beds " << tempRoom.beds << std::endl;
	std::cout << "Price for one day: " << tempRoom.rent << std::endl;
}

void roomManag()  // manageRooms
{
	class Room room;
	int option, rnum, i, flag = 0;
	char ch;
	do
	{
		system("cls");
		std::cout << " Manage Room " << std::endl;
		std::cout << "Add Room" << std::endl;
		std::cout << "Search Room" << std::endl;
		std::cout << "Back " << std::endl;
		std::cout << "Enter Option: " << std::endl;
		std::cin >> option;


		//превключване
		switch (option)
		{
		case 1:
			std::cout << "Enter Room Number: " << std::endl;
			std::cin >> rnum;
			i = 0;
			for (i = 0; i < scount; i++)
			{
				if (rooms[i].roomNum == rnum)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				std::cout << "Room Number is turned" << std::endl;
				flag = 0;
				getch();
			}
			else
			{
				rooms[scount] = room.addRoom(rnum);
				scount++;
			}
			break;
		case 2:
			std::cout << "Enter room number: " << std::endl;
			std::cin >> rnum;
			room.searchRoom(rnum);
			break;
		case 3:
			//nishto
			break;
		default:
			std::cout << "Please Enter your correct option" << std::endl;
			break;
		}
	} while (option != 3);
}
#pragma once
