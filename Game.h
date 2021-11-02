#ifndef GAME_H
#define GAME_H

#include"Glass.h"

class Game
{
private:
    int score;
    int level;
    int chances;
    Glass glasses[2];
public:
    Game(int level = 1);
    int getScore() const;
    int incScore();
    void selectGlass(int n);
    int getChances() const;
};

#endif // GAME_H
