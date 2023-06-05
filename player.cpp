#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "qgraphicsitem.h"
#include "qnamespace.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/bullets/Sprites/PLAYER.png").scaled(100,100));
    //movie = new QMovie(":/bullets/Sprites/PLAYER.gif");
    //frame = movie->frameCount();
    //movie->start();
}

void Player::jump()
{
    int jumpHeight = 50;  // Altura máxima del salto
    int jumpDuration = 10;  // Duración total del salto en milisegundos
    int numSteps = 10;  // Número de pasos para el salto

    // Calcular la distancia vertical que se mueve en cada paso
    float verticalStep = static_cast<float>(jumpHeight) / numSteps;

    // Calcular el tiempo de cada paso
    float timeStep = static_cast<float>(jumpDuration) / numSteps;

    // Iniciar el temporizador para realizar los pasos del salto
    timer = new QTimer(this);
    timer->start(timeStep);

    connect(timer, &QTimer::timeout, this, [=]() {
        // Calcular la nueva posición vertical en función del tiempo actual
        float currentTime = timer->interval() * frame;
        float yPos = static_cast<float>(jumpHeight) - (verticalStep * frame) +
                     (4 * verticalStep / (jumpDuration * jumpDuration)) *
                         (currentTime - (jumpDuration / 2)) * (currentTime - (jumpDuration / 2));

        // Establecer la nueva posición vertical del jugador
        setY(yPos);

        // Incrementar el contador de frames
        frame++;

        // Detener el salto cuando se alcance la altura máxima
        if (frame >= numSteps) {
            timer->stop();
            frame = 0;
            // Aquí puedes realizar otras acciones después de que el jugador termine el salto
        }
        setY(0);

    });

    // Iniciar el salto
    frame = 0;
}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key()==Qt::Key_Up){
         if(pos().y()>0)
         setPos(x(), y()-10);
     }
     else if(event->key()==Qt::Key_Down){
         if(pos().y()+100<600)
         setPos(x(), y()+10);
     }
    else if (event->key() == Qt::Key_Space){
        // create a bullet

        Bullet * bullet1  = new Bullet();
        Bullet * bullet2 = new Bullet();
        bullet1->setPos(x()+30,y());
        bullet2->setPos(x()+70,y());
        scene()->addItem(bullet1);
        scene()->addItem(bullet2);
    }
    else if (event->key() == Qt::Key_F){
        // create a bullet

        Bullet * bullet1  = new Bullet();
        bullet1->setPos(x(),y());
        scene()->addItem(bullet1);
    }
    else if(event->key() == Qt::Key_P) {
         jump();
         //setPos(x()+10, y()-10);
         //setPos(x()-10, y()-10);
     }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
