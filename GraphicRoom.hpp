#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include "Watcher.hpp"

class GraphicRoom: public Gtk::Window {
 private:
    Gtk::Box box_;
    Gtk::Button go_right_;
    Gtk::Button go_left_;
 public:
    void close() { hide(); }
   // void update(int info) override {}
    ~GraphicRoom() = default;
    GraphicRoom(): box_(Gtk::ORIENTATION_HORIZONTAL),
                   go_right_("Right"), go_left_("Left"){
        set_size_request(200, 50);
        box_.pack_start(go_right_);
        box_.pack_start(go_left_);

        add(box_);
        show_all_children();
   }
};