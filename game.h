#ifndef GAME_H
#define GAME_H


enum SimonColor { red = 0, yellow = 1, green = 2, orange = 3 };
enum GameMode { stopped, simonSaying, userReply, lost };

class Game
{
public:
    Game();

    bool addUserReply(SimonColor simonColor);

    QList<SimonColor> currentSimonColors(); //accessors
    GameMode currentGameMode();

    //How do I make reactive things for the UI?
    //Maybe a messaging class?

    int simonCount;
private:
    bool simonSayingNow;
    GameMode gameMode;
    //
    //array of current Simon level. (pregenerate?)
    //array of user progress when replying
    //QList  as container? QList<SimonColor>

    //CONSTANTS
    //speed of mp3s.
    //speed % increase for level
};

#endif // GAME_H
