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
		std::cout << "Hotel " << std::endl;
		std::cout << "1) Manage Rooms" << std::endl;
		std::cout << "2) Check in Room" << std::endl;
		std::cout << "3) Available Rooms" << std::endl;
		std::cout << "4) Search with your name" << std::endl;
		std::cout << "5) Check out Room" << std::endl;
		std::cout << "6) Àll guests in Hotel" << std::endl;
		std::cout << "9) Exit" << std::endl;
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