#pragma once

class Enigma {
 private:
    int key_;
    int result_;
    bool resolved_;
 public:
    Enigma(int k, int res): key_{k}, result_{res} {
        resolved_ = false;
    }
    ~Enigma() = default;

    void set_key(int k) { key_ = k;}
    bool try_key(int k) {
        if (k == key_) return resolved_ = true;
        return false;
    }
    bool resolved() {return resolved_;}
    int result() { return result_;}
};
