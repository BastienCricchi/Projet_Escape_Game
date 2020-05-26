#pragma once
#include "GraphicEnigma.hpp"
#include "Enigma.hpp"

class ControlEnigma {
 private:
    GraphicTextEnigma *vue_;
    Enigma<std::string,std::string,std::string> *model_;
 public:
    ControlEnigma(Enigma<std::string,std::string,std::string> *model, GraphicTextEnigma *vue):
        vue_{vue}, model_{model} {
        vue_->set_listener(std::bind(&ControlEnigma::try_key, this));
    }
    void try_key() {
        model_->try_key(vue_->get_entry());
    }
};