#include <gtkmm/application.h>
#include "GraphicRoom.hpp"
#include "Room.hpp"
#include "Enigma.hpp"
#include "GraphicEnigma.hpp"

class EscapeGame{
 private:
    GraphicRoom *groom_;
    Room *room_;
 public:
    void create_riddle1(){
        Enigma_1_1 *enigma11 = Enigma_1_1::get_instance();
        GraphicTextEnigma* graph_enigma_text_1_1 = new GraphicTextEnigma(enigma11->get_riddle());

        ControlEnigma *control_en1 = new ControlEnigma(enigma11, graph_enigma_text_1_1);
        enigma11->add_watcher(graph_enigma_text_1_1);
        groom_->wall(0).addEnigma(graph_enigma_text_1_1);
    }
    void create_riddle2(){
        Enigma_1_2 *enigma12 = Enigma_1_2::get_instance();
        GraphicTextEnigma* graph_enigma_text_1_2 = new GraphicTextEnigma(enigma12->get_riddle());

        ControlEnigma *control_en1 = new ControlEnigma(enigma12, graph_enigma_text_1_2);
        enigma12->add_watcher(graph_enigma_text_1_2);
        groom_->wall(1).addEnigma(graph_enigma_text_1_2);
    }

    EscapeGame(GraphicRoom *groom, Room *room): groom_{groom}, room_{room}{
        create_riddle1();
        create_riddle2();
    }
};

int main(int argc, char *argv[])
{
    
    auto app = Gtk::Application::create(argc, argv);
    GraphicRoom *groom = new GraphicRoom();
    Room *room = new Room();
    EscapeGame(groom, room);

    return app->run(*groom);
}