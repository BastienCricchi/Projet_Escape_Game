#pragma once
#include <memory>
#include <vector>
#include "Enigma.hpp"


// Je suis pas sur de l'interet d'utiliser une unique_ptr pour next_room  
// -Quentin 

class Room {
 protected:
  // std::vector<Virtual_Enigma *> enigmas_;
  std::vector<Enigma<std::string,std::string,std::string> *> enigmas_;
 public:
  Room(){};

  // Virtual_Enigma* get_enigma(int enigma_id){
  //     return enigmas_[enigma_id];  
  // }

  Enigma<std::string,std::string,std::string>* get_enigma(int enigma_id){
      return enigmas_[enigma_id];  
  }

  bool is_cleared(){
    for(auto&& enigma : enigmas_)
      if (!enigma->resolved()) return false;
    return true;
  }
};

class Room_1: public Room
{
private:
  Room_1(){
    enigmas_.push_back(Enigma_1_1::get_instance());
  }
  Room_1(Room_1 const&);     // Don't Implement
  void operator=(Room_1 const&); // Don't implement

public:
  static Room_1* get_instance(){
    static Room_1 instance;
    return &instance;
  }

};

class Room_2: public Room
{
private:
  Room_2(){
    enigmas_.push_back(Enigma_1_2::get_instance());
  }
  Room_2(Room_2 const&);     // Don't Implement
  void operator=(Room_2 const&); // Don't implement

public:
  static Room_2* get_instance(){
    static Room_2 instance;
    return &instance;
  }

};
