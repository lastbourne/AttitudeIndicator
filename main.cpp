#include <QGuiApplication>


#include "simulator.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    Simulator sim;

    return app.exec();
}
