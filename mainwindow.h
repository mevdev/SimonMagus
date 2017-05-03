#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMediaPlayer>
#include <QProcess>
#include "game.h"

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
    void on_actionNew_Game_triggered();
    void on_yellowButton_clicked();
    void on_redButton_clicked();
    void on_greenButton_clicked();
    void on_orangeButton_clicked();

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

    void colorOffAll();
    void colorOn(SimonColor simonColor);
    //Button buttonForColor(SimonColor simonColor);
    void startGame();
    void loseGame();
    //
    void playSound(SimonColor simonColor);

};

#endif // MAINWINDOW_H
