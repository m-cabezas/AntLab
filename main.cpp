#include "mainwindow.h"
#include "game.h"
#include "larva.h"
#include "worker.h"

#include <QApplication>
#include <map>
#include <string>


int main(int argc, char *argv[])
{

//    Worker worker("worker");
//    Larva larva("larva",5);

//    cout << "Worker : " << worker.getCurrentAge() << endl;
//    cout << "Larva : " << larva.getCurrentAge() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    new Game();
    w.show();
    new Game();

    return a.exec();
}
