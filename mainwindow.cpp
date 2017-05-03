#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->horizontalWidget);
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
void MainWindow::colorOffAll() {

    //set to '_off' suffix
}

//To control the led Green and Red brightness, just write a number 0 - 100 to the following files: (from jihad)

//root@rwtwenty:/opt/sbin# echo 0 > /sys/class/leds/green_led/brightness
//root@rwtwenty:/opt/sbin# echo 30 > /sys/class/leds/red_led/brightness

void MainWindow::colorOn(SimonColor simonColor) {
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

void MainWindow::playSound(SimonColor simonColor) {
    QString soundPath;
    switch(simonColor) {
        case red:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/0_e.wav";
        break;
    case yellow:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/1_a.wav";
        break;
    case green:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/2_cs.wav";
        break;
    case orange:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/3_e.aiff";
        break;
    }

    QProcess process;
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "afplay " + soundPath); //plays sound on a mac.
    //exec
    //aplay -vv audio.wav

   //also set light color




    //not present fprintf("something something dark side"); //%s",soundPath.to);

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

void MainWindow::on_leftButton_pressed()
{

   ui->leftButton->setCheckable(true);
   ui->leftButton->setChecked(true);
   on_redButton_clicked();
}

void MainWindow::on_leftButton_released()
{
    //change back to normal background.
    ui->leftButton->setChecked(false);
}



void MainWindow::on_topButton_pressed()
{

    ui->topButton->setCheckable(true);
    ui->topButton->setChecked(true);
    on_yellowButton_clicked();
}

void MainWindow::on_topButton_released()
{
    //change back to normal background.
    ui->topButton->setChecked(false);

}

void MainWindow::on_rightButton_pressed()
{

    ui->rightButton->setCheckable(true);
    ui->rightButton->setChecked(true);
    on_orangeButton_clicked();
}

void MainWindow::on_rightButton_released()
{
    //change back to normal background.
    ui->rightButton->setChecked(false);

}

void MainWindow::on_bottomButton_pressed()
{
    ui->bottomButton->setChecked(true);
    ui->bottomButton->setCheckable(true);
    on_greenButton_clicked();
}

void MainWindow::on_bottomButton_released()
{
    //change back to normal background.
    ui->bottomButton->setChecked(false);

}
