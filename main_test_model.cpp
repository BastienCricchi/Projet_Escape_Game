#include <cstdlib>
#include <iostream>
#include <vector>
#include "Escape_room.hpp"

int main(int argc, char const *argv[])
{
  Escape_room* escape_room = new Escape_room();
  Enigma<std::string,std::string,std::string> *current_enigma;

  // Room* room = escape_room->get_current_room();
  // current_enigma = room->get_enigma(0);
  current_enigma = escape_room->get_current_room()->get_enigma(0);
  

  std::cout << "Première enigme :" << std::endl;

  std::cout << current_enigma->get_riddle() << std::endl;
  std::cout << "Ma réponse : 'pain'" << std::endl;
  current_enigma->try_key("pain");
  if (current_enigma->resolved()){
    std::cout  << current_enigma->get_result() << std::endl;
  }

  std::cout << "Deuxième enigme :" << std::endl;
  escape_room->next_room();
  current_enigma = escape_room->get_current_room()->get_enigma(0);

  std::cout << current_enigma->get_riddle() << std::endl;
  std::cout << "Ma réponse : 'granet'" << std::endl;
  current_enigma->try_key("granet");
  if (current_enigma->resolved()){
    std::cout  << current_enigma->get_result() << std::endl;
  }

  return 0;
}