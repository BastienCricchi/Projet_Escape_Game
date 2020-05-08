#pragma once
// #include "Result.hpp"
// #include "Key.hpp"

class Virtual_Enigma {
 protected:
    bool resolved_;

 public:
    Virtual_Enigma() {
        resolved_ = false;
    }
    bool resolved() {return resolved_;}
};

template <typename K,typename R>
class Enigma: public Virtual_Enigma {
 private:
    // Key<K> key_;
    // Result<R> result_;
    K key_;
    R result_;
 public:
    Enigma(K k, R res): Virtual_Enigma(), key_{k}, result_{res} {}
    ~Enigma() = default;

    void set_key(K k) { key_ = k;}
    bool try_key(K k) {
        if (k == key_) return resolved_ = true;
        return false;
    }

    R result() { return result_;}
};


class Enigma_Textual: public Enigma<std::string,std::string>
{
private:
  std::string riddle_;

 public:
  Enigma_Textual(std::string riddle, std::string key, std::string result):
   Enigma(key, result),
   riddle_{riddle}
   {}
  ~Enigma_Textual() = default;
  
};

Virtual_Enigma* enigma_text_1_1 = new Enigma_Textual(
  "Plus je suis chaud, plus je suis frais...\n Que suis-je ?",
  "pain",
  "Bien joué"
);

Virtual_Enigma* enigma_text_2_1 = new Enigma_Textual(
  "Mon premier se trouve en abondance dans la nourriture de fast food\n"
  "Mon second est au milieu de ton visage\n"
  "Mon tout est un professeur de C++",
  "granet",
  "Bien joué"
);