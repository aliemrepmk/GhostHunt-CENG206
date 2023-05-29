#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <vector>

class Score : public QGraphicsTextItem {
public:
    Score(int numPlayers = 2, QGraphicsItem *parent = nullptr);
    void increase(int player, int points = 1);
    int getScore(int player);
private:
    std::vector<int> scores;
    int totalPlayers;
};

#endif // SCORE_H
