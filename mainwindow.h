#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pushButton_2_clicked();
    void on_yellowButton_clicked();
    void on_redButton_clicked();
    void on_greenButton_clicked();
    void on_orangeButton_clicked();

private:
    Ui::MainWindow *ui;

    void colorOffAll();
    void colorOn(SimonColor simonColor);
    Button buttonForColor(SimonColor simonColor);
    void startGame();
    void loseGame();
    //
    void playSound(SimonColor simonColor);
};

#endif // MAINWINDOW_H
