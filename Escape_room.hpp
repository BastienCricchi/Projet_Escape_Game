#pragma once

#include <vector>
#include "Room.hpp"

class Escape_room {
 private:
  std::vector<Room*> rooms_ ;
  std::vector<Room*>::iterator current_room_;
 public:
  Escape_room(){
    rooms_.push_back(Room_1::get_instance());
    rooms_.push_back(Room_2::get_instance());
    current_room_ = rooms_.begin();
  }
  ~Escape_room() = default;

  Room* get_current_room(){
    return *current_room_;
  }

  void next_room(){
    if (current_room_ != rooms_.end())
     current_room_++;
  }
};