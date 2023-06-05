#include "score.h"
#include <QFont>
#include "qgraphicsitem.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initilize the score to 0
    score=0;
    //draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
}

int Score::getScore()
{
    return score;
}
