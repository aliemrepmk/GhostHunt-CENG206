#include "Score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    scorePlayer1 = 0;
    scorePlayer2 = 0;
    setPlainText(QString("Player 1: ") + QString::number(scorePlayer1) +
                 "\nPlayer 2: " + QString::number(scorePlayer2));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Score::increase(int player) {
    if (player == 1) {
        scorePlayer1++;
    } else if (player == 2) {
        scorePlayer2++;
    }

    setPlainText(QString("Player 1: ") + QString::number(scorePlayer1) +
                 "\nPlayer 2: " + QString::number(scorePlayer2));
}

int Score::getScore(int player) {
    if (player == 1) {
        return scorePlayer1;
    } else if (player == 2) {
        return scorePlayer2;
    }

    return 0;
}
