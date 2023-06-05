#ifndef TIMER_H
#define TIMER_H

#include "qdatetime.h"
#include "qmainwindow.h"
#include "qobjectdefs.h"
#include <QObject>
#include <QGraphicsTextItem>
#include <QTime>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>


class Timer: public QGraphicsTextItem,  public QMainWindow
{
    Q_OBJECT
public:
    Timer(QGraphicsItem * parent=0)
    {
        // Crear la etiqueta para mostrar el tiempo
        timerLabel = new QLabel(this);
        timerLabel->setAlignment(Qt::AlignCenter);
        QFont font("Arial", 20, QFont::Bold);
        timerLabel->setFont(font);
        timerLabel->setText("60");  // Iniciar en 60 segundos
        setCentralWidget(timerLabel);

//        // Crear el temporizador
//        timer = new QTimer(this);
//        connect(timer, &QTimer::timeout, this, &Timer::updateTimer);
//        timer->start(1000);  // Actualizar el tiempo cada segundo

        // Iniciar el juego
        // ...

        // Establecer la duración total del juego en 60 segundos
        gameDuration = 60;
    }

private slots:
    void updateTimer()
    {
        // Actualizar el tiempo restante en la etiqueta
        gameDuration--;
        timerLabel->setText(QString::number(gameDuration));

        // Verificar si se ha alcanzado el final del juego
        if (gameDuration <= 0) {
            endGame();
        }
    }

    void endGame()
    {
        // Detener el temporizador y realizar acciones de fin de juego
        timer->stop();

        // ...
    }

private:
    QLabel *timerLabel;
    QTimer *timer;
    int gameDuration;
};
#endif // TIMER_H
