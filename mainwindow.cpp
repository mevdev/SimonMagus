#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete player; //QObject is memory managed.
}

void MainWindow::on_actionNew_Game_triggered()
{
    //new Game!
}


void MainWindow::on_yellowButton_clicked()
{
    playSound(yellow);
}

void MainWindow::on_redButton_clicked()
{
    playSound(red);
}

void MainWindow::on_greenButton_clicked()
{
    playSound(green);
}

void MainWindow::on_orangeButton_clicked()
{
    playSound(orange);
}
//////
void colorOffAll() {

    //set to '_off' suffix
}

//To control the led Green and Red brightness, just write a number 0 - 100 to the following files: (from jihad)

//root@rwtwenty:/opt/sbin# echo 0 > /sys/class/leds/green_led/brightness
//root@rwtwenty:/opt/sbin# echo 30 > /sys/class/leds/red_led/brightness

void colorOn(SimonColor simonColor) {
    switch(simonColor) {
        case red:
        break;
    case yellow:
        break;
    case green:
        break;
    case orange:
        break;
    }
}

void playSound(SimonColor simonColor) {
    QString soundPath;
    switch(simonColor) {
        case red:
        soundPath = "/Users/rlinnema/Desktop/simon_sounds/0_e.aiff";
        break;
    case yellow:
        soundPath = "/Users/rlinnema/Desktop/simon_sounds/1_a.aiff";
        break;
    case green:
        soundPath = "/Users/rlinnema/Desktop/simon_sounds/2_cs.aiff";
        break;
    case orange:
        soundPath = "/Users/rlinnema/Desktop/simon_sounds/3_e.aiff";
        break;
    }
    //play sound.
//    if(player == NULL) {
//        player = new QMediaPlayer;
//    } else {
//        player->stop();
//    }

//    player->setMedia(QUrl::fromLocalFile(soundPath));
//    player->setVolume(50);
//    player->play();
}



