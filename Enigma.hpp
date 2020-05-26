#pragma once
#include "Watched.hpp"
// #include "Result.hpp"
// #include "Key.hpp"

class VirtualEnigma {
 protected:
    bool resolved_;

 public:
    VirtualEnigma() {
        resolved_ = false;
    }
    bool resolved() {return resolved_;}
};

template <typename E, typename K,typename R>
class Enigma: public VirtualEnigma, public Watched<R> {
 private:
    // Key<K> key_;
    // Result<R> result_;
    E riddle_;
    K key_;
    R result_;
 public:
    Enigma(E e, K k, R res): VirtualEnigma(), riddle_{e}, key_{k}, result_{res} {}
    ~Enigma() = default;

    void set_key(K k) { key_ = k;}
    bool try_key(K k) {
        if (k == key_) {
          this->notif_watchers(result_);
          return resolved_ = true;
        }
        return false;
    }

    R result() { return result_;}
    E getRiddle() { return riddle_;}
};


class Enigma_Textual: public Enigma<std::string, std::string,std::string>
{

 public:
  Enigma_Textual(std::string riddle, std::string key, std::string result):
   Enigma(riddle, key, result){}
  ~Enigma_Textual() = default;
  
};


// VirtualEnigma* enigma_text_2_1 = new Enigma_Textual(
//   "Mon premier se trouve en abondance dans la nourriture de fast food\n"
//   "Mon second est au milieu de ton visage\n"
//   "Mon tout est un professeur de C++",
//   "granet",
//   "Bien joué"
// );