#ifndef PLAYER_H
#define PLAYER_H

#include "qgraphicsitem.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QGraphicsItem>
class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    bool end=false;
    int frame;
    QMovie *movie;
    QPixmap pixmap;
    QTimer *timer;
    void jump();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER_H
