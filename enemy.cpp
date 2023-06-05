#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include "qgraphicsitem.h"

extern Game *  game;
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //Set random position
    int random_number = rand() % 750;
    setPos(random_number,0);
    setPixmap(QPixmap(":/bullets/Sprites/BULLET_APPEL.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(60);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
