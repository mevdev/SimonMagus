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
        gameMode = modeStartup;
        simonFullCount = 2;
        simonSayingCount = 0; //
        simonReplyCount = 0;

        simonColorList.clear();
        generateListOfColors();
    }

    void Game::finishStartupAnimation() {
        gameMode = modeSimonSaying;
    }

    void Game::setGameMode(GameMode mode) {
        gameMode = mode;
    }

    void Game::generateListOfColors() {
        SimonColor colorNext;
        SimonColor colorLast;
        for(int i=0; i < 50; i++) {
            int rando = qrand() % 3; //number of colors
            colorNext = static_cast<SimonColor>(rando);
            if(colorNext != colorLast) {
                simonColorList.append(colorNext);
                colorLast = colorNext;
            }
        }
    }

    bool Game::isSimonSaying() {
        return (gameMode == modeSimonSaying);
    }

    bool Game::amIReplying() {
        return(gameMode == modeReplying);
    }

    bool Game::reply(SimonColor replyColor) {
        //is it the correct reply?
        if(simonColorList[simonReplyCount] == replyColor) {
            qDebug("reply");
            simonReplyCount += 1;
            if(simonReplyCount > simonFullCount){
                //next level?
                simonReplyCount = 0;
                simonSayingCount = 0;
                simonFullCount += 1;
                gameMode = modeSimonSaying;
                //how do we know?
            }
            return true; //also check the gameMode when you're back there. Hey hey. otehr header, hey.
        } else {
            //wrong
            gameMode = modeYouLost;
            qDebug("You lose!");
            return false;
        }
    }

    SimonColor Game::nextSimonSay() {
        qDebug("nextSimonSay");
            SimonColor heresAColor = simonColorList[simonSayingCount];
            simonSayingCount += 1;
            if(simonSayingCount > simonFullCount) {
                gameMode = modeReadyToReply;
                simonSayingCount = 0;
                simonReplyCount = 0;
            }
            return heresAColor;
    }

    GameMode Game::mode() {
        return gameMode;
    }
