#pragma once
#include <memory>
#include <vector>
#include "Enigma.hpp"


// Je suis pas sur de l'interet d'utiliser une unique_ptr pour next_room  
// -Quentin 

class Room {
 private:
  // Room *next_room_;
  std::vector<Virtual_Enigma *> enigmas_;
 public:
  Room(): 
  {
    // Initialiser les enigmes
  };
  ~Room();

  // void set_next_room(Room *next_room_ptr){
  //   next_room_ = next_room_ptr; 
  // }

  // Room* get_next_room(){
  //   return next_room_;
  // } 

  Virtual_Enigma* get_enigma(int enigma_id){
      return enigma_[enigma_id];  
  }

  bool is_cleared(){
    for(auto&& enigma : enigmas_)
      if (!enigma->resolved()) return false;
    return true;
  }
};


