#include <cstdlib>
#include <iostream>
#include "Enigma.hpp"

int main(int argc, char const *argv[])
{
  Enigma<std::string,std::string,std::string> *enigma_1_1, *enigma_1_2;

  enigma_1_1 = Enigma_1_1::get_instance();
  enigma_1_2 = Enigma_1_2::get_instance();

  std::cout << enigma_1_1->get_riddle() << std::endl;
  std::cout << "Ma réponse : 'pain'" << std::endl;
  enigma_1_1->try_key("pain");
  if (enigma_1_1->resolved()){
    std::cout  << enigma_1_1->get_result() << std::endl;
  }
  return 0;
}