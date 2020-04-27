#pragma once

#include "Enigma.hpp"

class Room {
 private:
    std::unique_ptr<Room> next_room_;
    std::vector<Virtual_Enigma *> enigma_;
 public:
    Room();
    ~Room();
};
