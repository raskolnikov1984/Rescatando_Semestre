#ifndef ENEMY_H
#define ENEMY_H

#include "QGraphicsPixmapItem"
#include "qgraphicsitem.h"
#include "qobjectdefs.h"
#include <QGraphicsItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
