#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "qgraphicsitem.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; // there is an external global object called game
Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/bullets/Sprites/BULLET_PENCIL.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
