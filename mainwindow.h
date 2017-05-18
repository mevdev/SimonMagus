#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMediaPlayer>
#include <QProcess>
#include <QDebug>
#include "game.h"
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_leftButton_pressed();

    void on_leftButton_released();

    void on_topButton_pressed();

    void on_topButton_released();

    void on_rightButton_pressed();

    void on_rightButton_released();

    void on_bottomButton_pressed();

    void on_bottomButton_released();

private:
    Ui::MainWindow *ui;
    //QMediaPlayer player;

    Game *game;

    void colorOffAll();
    void colorOn(SimonColor simonColor);
    //Button buttonForColor(SimonColor simonColor);
    void startGame();
    void loseGame();

    void doGameAnimation();
    //
    void playSound(SimonColor simonColor);
    void resizeButtons();

    void on_actionNew_Game_triggered();
    void yellowTap();
    void redTap();
    void greenTap();
    void orangeTap();

protected:
  virtual void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
