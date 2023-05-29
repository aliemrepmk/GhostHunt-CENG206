#include "Score.h"
#include "Game.h"
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
extern Game *game;
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    scorePlayer1 = 0;
    scorePlayer2 = 0;

    QString player1Text = "Player 1: " + QString::number(scorePlayer1);
    QString player2Text = "Player 2: " + QString::number(scorePlayer2);

    QString htmlText = "<font color='yellow'>" + player1Text + "</font><br>"
                                                               "<font color='pink'>" + player2Text + "</font>";

    setHtml(htmlText);
    setFont(QFont("times", 16));
}

void Score::increase(int player) {
    if (player == 1) {
        scorePlayer1++;
    } else if (player == 2) {
        scorePlayer2++;
    }

    QString player1Text = "<font color='yellow'>Player 1: " + QString::number(scorePlayer1) + "</font>";
    QString player2Text = "<font color='pink'>Player 2: " + QString::number(scorePlayer2) + "</font>";
    setHtml(player1Text + "<br>" + player2Text);
    if (scorePlayer2 >= 6) {
        QMessageBox::information(nullptr, "Information", "Congratulations Player 2 Reached 6 Ghosts and Won.\nClick OK for the next game");
        game->setScene(game->main_scene);
    } else if (scorePlayer1 >= 6) {
        QMessageBox::information(nullptr, "Information", "Congratulations Player 1 Reached 6 Ghosts and Won.\nClick OK for the next game");
        game->setScene(game->main_scene);
    }
}

int Score::getScore(int player) {
    if (player == 1) {
        return scorePlayer1;
    } else if (player == 2) {
        return scorePlayer2;
    }

    return 0;
}
