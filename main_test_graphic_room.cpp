#include <gtkmm/application.h>
#include "GraphicRoom.hpp"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv);
    GraphicRoom *groom = new GraphicRoom();
    return app->run(*groom);
    return 0;
}