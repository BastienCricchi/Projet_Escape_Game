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
        Enigma_Textual* enigma_text_1_1 = new Enigma_Textual(
            "Plus je suis chaud, plus je suis frais...\n Que suis-je ?",
            "pain",
            "Bien joué"
        );
        GraphicTextEnigma* graph_enigma_text_1_1 = new GraphicTextEnigma(enigma_text_1_1->getRiddle());

        ControlEnigma *control_en1 = new ControlEnigma(enigma_text_1_1, graph_enigma_text_1_1);
        enigma_text_1_1->add_watcher(graph_enigma_text_1_1);
    }

    EscapeGame(GraphicRoom *groom, Room *room): groom_{groom}, room_{room}{}
};

int main(int argc, char *argv[])
{
    
    auto app = Gtk::Application::create(argc, argv);
    GraphicRoom *groom = new GraphicRoom();
    return app->run(*groom);
}