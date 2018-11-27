#ifndef SCORE_H
#define SCORE_H


class Score
{
private:
    int number; // number that increases when mario kills enemy
    int totalScore,   // total score
        bestScore;     // best score overall



public:
    Score()
    {
        scoreFile.open("scores.txt");
        if (!scoreFile)
        {
            cout << "File not found ";
            return -1;
        }
        scoreFile >> totalScore >> bestScore;

        scoreFile.close();
    }
//mutators
    void setScore(int tScore, int bScore, int num)
    {
        number = num;
        totalScore = tScore;
        bestScore = bScore;
    }

// getters
    int getScore(int num)
    {
        switch (num)
        {
        case 1:
            {
                return tScore;
            }
        case 2:
            {
               return bScore;
            }
    }
    void changeScore(int,string)    // should have a counter when mario kills enemy
    {

    }
    void storeScores();     // stores the score that mario gets

};

#endif // SCORE_H




