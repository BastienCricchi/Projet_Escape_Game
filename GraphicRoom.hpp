#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <vector>
#include "Watcher.hpp"
#include "GraphicWall.hpp"

using std::vector;
class GraphicRoom: public Gtk::Window {
 private:
    Gtk::Box box_;
    vector<GraphicWall> walls_;
    Gtk::Image img_right_;
    Gtk::Image img_left_;
    Gtk::Button go_right_;
    Gtk::Button go_left_;
 public:
    void close() { hide(); }
   // void update(int info) override {}
    ~GraphicRoom() = default;
    GraphicRoom(): box_(Gtk::ORIENTATION_HORIZONTAL),
                   img_right_("./img/right_arrow.png"), img_left_("./img/left_arrow.png"),
                   go_right_(""), go_left_(""){
        go_right_.signal_clicked().connect(sigc::mem_fun(*this, &GraphicRoom::go_right_event));
        go_left_.signal_clicked().connect(sigc::mem_fun(*this, &GraphicRoom::go_left_event));
        go_right_.set_image(img_right_);
        go_left_.set_image(img_left_);
        go_right_.set_always_show_image(true);
        go_left_.set_always_show_image(true);

        box_.pack_start(go_left_);

        walls_.reserve(4);
        for (int i = 0; i < 4; ++i){
            walls_.push_back(GraphicWall(i));
            walls_[i].set_size_request(1000, 500);
            box_.pack_start(walls_[i]);
        }

        box_.pack_start(go_right_);

        add(box_);
        show_all_children();

        for (int i = 1; i < 4; ++i)
            walls_[i].set_visible(false);
   }


    void go_right_event(){
        for(int i = 0; i < 4; ++i){
            if(walls_[i].get_visible()){
                walls_[i].set_visible(false);
                if(i==3) walls_[0].set_visible(true);
                else walls_[i+1].set_visible(true);
                break;
            }
        }
    }
    void go_left_event(){
        for(int i = 0; i < 4; ++i){
            if(walls_[i].get_visible()){
                walls_[i].set_visible(false);
                if(i==0) walls_[3].set_visible(true);
                else walls_[i-1].set_visible(true);
                break;
            }
        }
    }
    GraphicWall& wall(int id) {
        return walls_[id];
    }
};