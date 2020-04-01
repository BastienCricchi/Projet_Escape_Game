#pragma once

#include "Enigma.hpp"

class Room {
 private:
    std::unique_ptr<Room> next_room_;
    std::vector<Enigma> enigma_;
 public:
    Room();
    ~Room();
};
