#include "simulator.h"

Simulator::Simulator(QObject *parent) : QObject(parent)
{
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));

    object = component.create();
    right = up = true;
    left = down = false;

    connect(&timer, &QTimer::timeout, this, &Simulator::simulate);
    timer.start(300);

}

void Simulator::simulate()
{
    if(up)
    {
        attitude++;
        if (attitude == 100)
        {
            up = false;
            down = true;
        }

    }else if(down)
    {
            attitude--;
            if(attitude == -100)
            {
                up = true;
                down = false;
            }
    }

    if(right)
    {
        roll++;
        if (roll == 90)
        {
            right = false;
            left = true;
        }

    }else if(left)
    {
            roll--;
            if(roll == 0)
            {
                right = true;
                left = false;
            }
    }

    object->setProperty("attitude", attitude);
    object->setProperty("roll", roll);
}
