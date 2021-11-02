#include<iostream>
#include<stdlib.h>
#include "Game.h"
using namespace std;

Game::Game(int level)
{
    this->level = level;
    switch (level) {
    case 1: chances = 5;break;
    case 2: chances = 4;break;
    case 3: chances = 3;break;
    case 4: chances = 2;break;
    case 5: chances = 1;break;
    default: chances = 0;break;
    }
    score = 0;
    if (chances % 2 == 0) {
        glasses[0].setBreakable('y');
        glasses[1].setBreakable('n');
    }
    else {
        glasses[1].setBreakable('y');
        glasses[0].setBreakable('n');
    }
}
int Game::getScore() const {
    return score;
}
int Game::incScore() {
    switch (level) {
    case 1: score += 5;return 5;
    case 2: score += 10;return 10;
    case 3: score += 20;return 20;
    case 4: score += 30;return 30;
    case 5: score += 50;return 50;
    }
}
void Game::selectGlass(int n) {
    if (glasses[n].getBreakable() == 'n') {
        int inc = incScore();
        cout << "\tGreat Job!\t+" << inc << endl << endl;
        chances = -1;
    }
    else {
        --chances;
        if (chances % 2 == 0) {
            glasses[0].setBreakable('y');
            glasses[1].setBreakable('n');
        }
        else {
            glasses[1].setBreakable('y');
            glasses[0].setBreakable('n');
        }
        cout << "\tGlass Broke :(" << endl << endl;
        if (chances > 0) {
            cout << "\tTry Again! " << chances << " chances remaining..." << endl << endl;
        }
        else {
            cout << "\tSorry! No chances left." << endl << endl;
        }
    }
}
int Game::getChances() const {
    return chances;
}
