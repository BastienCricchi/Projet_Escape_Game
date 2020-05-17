#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <vector>
#include <string>
#include "Watcher.hpp"

class GraphicWall: public Gtk::Box {
 private:
    Gtk::Entry text_;
 public:
    GraphicWall(int id): Gtk::Box(Gtk::ORIENTATION_HORIZONTAL){
        text_.set_text("Wall "+std::to_string(id));
        pack_start(text_);

    }
    
};