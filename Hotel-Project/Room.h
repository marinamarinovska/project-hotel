#pragma once

struct Room {
	int room;
	int guests;
};

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