#include "Score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ")+ QString::number(score));
<<<<<<< HEAD
    setDefaultTextColor(Qt::red);
=======
    setDefaultTextColor(Qt::blue);
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
