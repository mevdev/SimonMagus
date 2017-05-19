#ifndef GAME_H
#define GAME_H
#include <QList>

enum SimonColor { red = 0, yellow = 1, green = 2, orange = 3 };
enum GameMode { modeStartup = 0, modeStopped = 1, modeSimonSaying = 2, modeReadyToReply = 3, modeReplying = 4, modeYouLost = 5 };

class Game
{
public:
    Game();
    GameMode gameMode;

    bool addUserReply(SimonColor simonColor);

    GameMode mode();
    void setGameMode(GameMode mode);
    void generateListOfColors();
    void gameSetup();
    void finishStartupAnimation();

    bool isSimonSaying();
    bool amIReplying();
    bool reply(SimonColor replyColor);
    SimonColor nextSimonSay();


    int simonFullCount; //the full amount of colors
    int simonSayingCount; //where simon is in saying.
    int simonReplyCount; //where user is at in the reply

    QList<SimonColor> simonColorList;

private:
    //array of current Simon level. (pregenerate?)
    //array of user progress when replying
    //QList  as container? QList<SimonColor>

    //CONSTANTS
    //speed of mp3s.
    //speed % increase for level
};

#endif // GAME_H
