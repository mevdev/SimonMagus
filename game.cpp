#include "game.h"

Game::Game()
{
    gameSetup();
}
    //gameModes
    //- - -
    //Setup Animation/new game
    //Hearing Simon
    //Replying to Simon
    //Next Level
    //    ||
    //Lose


    //.3s rate.
    //keep track of array

    void Game::gameSetup() {
        gameMode = startup;
        simonFullCount = 0;
        simonSayingCount = 0;
        replyCount = 0;

        simonColorList.clear();
        doStartupAnimation();
    }

    void Game::doStartupAnimation() {
        gameMode = simonSaying;
    }

    void Game::setGameMode(GameMode mode) {
        gameMode = mode;
    }

    void Game::generateListOfColors() {
        for(int i=0; i < 30; i++) {
            int rando = qrand() % 3; //number of colors
            simonColorList.append(static_cast<SimonColor>(rando));
        }
    }

    bool Game::isSimonSaying() {
        return (gameMode == simonSaying);
    }

    SimonColor Game::nextSimonSay() {
            SimonColor heresAColor = simonColorList[simonSayingCount];
            simonSayingCount += 1;
            if(simonSayingCount > simonFullCount) {
                gameMode = userReply;
                simonSayingCount = 0;
                replyCount = 0;
            }
            return heresAColor;
    }

    GameMode Game::mode() {
        return gameMode;
    }
