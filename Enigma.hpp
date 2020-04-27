#pragma once
#include "Result.hpp"
#include "Key.hpp"

class Virtual_Enigma {
 protected:
    bool resolved_;

 public:
    Virtual_Enigma() {
        resolved_ = false;
    }
};

template <typename K, R>
class Enigma: Virtual_Enigma {
 private:
    Key<K> key_;
    Result<R> result_;

 public:
    Enigma(int k, int res): Virtual_Enigma(), key_{k}, result_{res} {}
    ~Enigma() = default;

    void set_key(Key<K> k) { key_ = k;}
    bool try_key(Key<K> k) {
        if (k == key_) return resolved_ = true;
        return false;
    }
    bool resolved() {return resolved_;}
    Result<R> result() { return result_;}
};
