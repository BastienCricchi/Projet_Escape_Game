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
    E riddle_;
    K key_;
    R result_;
 public:
    Enigma(E e, K k, R res): VirtualEnigma(), riddle_{e}, key_{k}, result_{res} {}
    ~Enigma() = default;

    //void set_key(K k) { key_ = k;}
    
    bool try_key(K k) {
        if (k == key_) {
          this->notif_watchers(result_);
          return resolved_ = true;
        }
        return false;
    }

    E get_riddle(){ return riddle_;}

    R get_result() { return result_;}
};


//Modèle singleton
class Enigma_1_1 : public Enigma<std::string,std::string,std::string>
{
private:
  Enigma_1_1(): Enigma{
    "Plus je suis chaud, plus je suis frais... Que suis-je ?",
    "pain",
    "Bien joué"
  } {};

  Enigma_1_1(Enigma_1_1 const&);     // Don't Implement
  void operator=(Enigma_1_1 const&); // Don't implement

public:
  static Enigma_1_1* get_instance(){
    static Enigma_1_1 instance;
    return &instance;
  }
};


class Enigma_1_2 : public Enigma<std::string,std::string,std::string>
{
private:
  Enigma_1_2(): Enigma{
    "Mon premier se trouve en abondance dans la nourriture de fast food\n"
    "Mon second est au milieu de ton visage\n"
    "Mon tout est un professeur de C++",
    "granet",
    "Bien joué"
  } {}

  Enigma_1_2(Enigma_1_2 const&);     // Don't Implement
  void operator=(Enigma_1_2 const&); // Don't implement

public:
  static Enigma_1_2* get_instance(){
    static Enigma_1_2 instance;
    return &instance;
  }
};
