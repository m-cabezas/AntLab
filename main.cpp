#include "mainwindow.h"
#include "game.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    Game *game = new Game;
    game->initGame();
    CONFIG["lifeWorkere"] = 10;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
