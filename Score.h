#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem *parent = nullptr);

    void increase(int player);
    int getScore(int player);

private:
    int scorePlayer1;
    int scorePlayer2;
};

#endif // SCORE_H
