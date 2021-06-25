#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QtQuick>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QTimer>

class Simulator : public QObject
{
    Q_OBJECT
public:
    explicit Simulator(QObject *parent = nullptr);
    QQmlEngine engine;
    QTimer timer;
    QObject *object;
    int roll = 0;
    int attitude = 0;

    bool up, down, left, right;
private slots:
    void simulate();

signals:

};

#endif // SIMULATOR_H
