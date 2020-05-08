#include <iostream>
#include "Person.h"
#include "Hotel.h"
#include "Room.h" 
#include<string.h>
#include<conio.h>

#pragma warning(disable : 4996)


int main()
{
	class Hotel hotel;
	int i, j, option, rnum;
	char ch;
	char guestname[100]; //custname

	system("cls");

	do 
	{
		system("cls");
		std::cout << " Hotel " << std::endl;
		std::cout << "Manage Rooms" << std::endl;
		std::cout << "Check in Room" << std::endl;
		std::cout << "Available Rooms" << std::endl;
		std::cout << "Search with your name" << std::endl;
		std::cout << "Check out Room" << std::endl;
		std::cout << "Àll guests in Hotel" << std::endl;
		std::cout << "Exit" << std::endl;
		std::cout << "Enter your option: " << std::endl;
		std::cin >> option;
		switch (option)
		{
		case 1:
			roomManag();
			break;
		case 2:
			if (scount == 0)
			{
				std::cout << "Rooms of this date is not available. Add the rooms first." << std::endl;
				getch();
			}
			else
				hotel.checkIn();
			break;
		case 3:
			if (scount == 0)
			{
				std::cout << "Rooms of this date is not available. Add the rooms first." << std::endl;
				getch();
			}
			else
				hotel.availabilitRoom();
			break;
		case 4:
			if (scount == 0)
			{
				std::cout << "Rooms of this date is not available. Add the rooms first." << std::endl;
				getch();
			}
			else
			{
				std::cout << "Enter your name: " << std::endl;
				std::cin >> guestname;
				hotel.reportGuest(guestname);
			}
			break;
		case 5:
			if (scount == 0)
			{
				std::cout << "Rooms of this date is not available. Add the rooms first." << std::endl;
				getch();
			}
			else
			{
				std::cout << "Enter Room Number : " << std::endl;
				std::cin >> rnum;
				hotel.checkOut(rnum);
			}
			break;
		case 6:
			hotel.greport();
			break;
		case 7:
			std::cout << "Ready" << std::endl;
			break;
		default:
			std::cout << "Please enter your correct option" << std::endl;
			break;
		}
	} while (option != 7);

	getch();
}