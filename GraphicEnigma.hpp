#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <string>
#include <iomanip>
#include "Watcher.hpp"

using std::string;
class GraphicVirtualEnigma: public Gtk::Box{
public:
    GraphicVirtualEnigma(): Gtk::Box(Gtk::ORIENTATION_VERTICAL){}
};

template <typename E, typename K,typename R>
class GraphicEnigma: public GraphicVirtualEnigma, public Watcher<R> {
public:
    GraphicEnigma(): GraphicVirtualEnigma() {}
};

class GraphicTextEnigma: public GraphicEnigma<string, string, string> {
 private:
    Gtk::Box box_button_;
    Gtk::Button try_;
    Gtk::Entry txt_riddle_;
    Gtk::Entry txt_answer_;
 public:
    void update(string res) override{
        Glib::ustring ustr =Glib::ustring::format(std::fixed, std::setprecision(2), res);
        txt_riddle_.set_text(ustr);
    }
    string get_entry() {
        const char* strChar = txt_answer_.get_text().c_str();
        string str(strChar);
        return str;
     }

    void set_listener(std::function<void(void)> f) {
        try_.signal_clicked().connect([=](){f();});
    }
    GraphicTextEnigma(string riddle): 
                    box_button_(Gtk::ORIENTATION_HORIZONTAL),
                    try_("Try answer") {

        // set_size_request(200, 50);
        txt_riddle_.set_text(riddle);
        txt_answer_.set_text("");
        // txt_answer_.select_region(0, txt_answer_.get_text_length());

        box_button_.pack_start(try_);

        pack_start(txt_riddle_);
        pack_start(txt_answer_);
        pack_start(box_button_);

        // add(*this);
        // show_all_children();
    }
};