//
// Created by Megan Adamik on 11/27/18.
//

#ifndef SCORE_H
#define SCORE_H

#include <fstream>
#include <iostream>
#include "Enemy.h"

using namespace std;
class Score {
private:
    int number; // number that increases when mario kills enemy
    int totalScore,   // total score
            bestScore;     // best score overall



public:
    Score() {
        scoreFile.open("scores.txt");
        if (!scoreFile) {
            cout << "File not found ";
            return -1;
        }
        scoreFile >> totalScore >> bestScore;

        scoreFile.close();
    }

//mutators
    void setScore(int tScore, int bScore) {
        totalScore = getNum() + tScore;
        if (tScore > bScore) {
            bestScore = tScore;
        } else {
            bestScore = bScore;
        }
    }

    void setNum(int num){
        number = num;
    }


// getters
    int getNum(){
        return number;
    }
    int getScore(int num) {
        switch (num) {
            case 1: {
                return tScore;
            }
            case 2: {
                return bScore;
            }
        }
    }

    void changeScore(int, string)    // should have a counter when mario kills enemy
    {
        if (Enemy one hp == -1){
            setNum(800);
        }
        else if(isCollision(token, mario)){
            setNum(100);
        }
    }

    void storeScores();     // stores the score that mario gets
    };

#endif // SCORE_H