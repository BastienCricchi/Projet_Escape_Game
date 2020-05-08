#pragma once

#include <vector>
#include "Room.hpp"
#define NUMBER_OF_ROOMS 3 

class Escape_room {
 private:
  std::vector<Room *> rooms_;
  Room* current_room;
 public:
  Escape_room(){

    std::vector<Virtual_Enigma *> enigmas_room_1 = {enigma_text_1_1};
    std::vector<Virtual_Enigma *> enigmas_room_2 = {enigma_text_2_1};

    rooms_.reserve(NUMBER_OF_ROOMS);
    Room *room1, *room2;

    room1 = new Room(room2, enigmas_room_1);
    room2 = new Room(NULL, enigmas_room_2);

  }
  ~Escape_room();
};