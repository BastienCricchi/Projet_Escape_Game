#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <vector>
#include "Enigma.hpp"
#include "GraphicEnigma.hpp"
#include "ControlEnigma.hpp"

class GraphicWall: public Gtk::Box{
 private:
    Gtk::Entry text_;
 public:
    GraphicWall(int id): Gtk::Box(Gtk::ORIENTATION_HORIZONTAL) {
    }
    
    void addEnigma(GraphicTextEnigma *graph_enigma_text) {
        add(*graph_enigma_text);
        show_all_children();
    }
};