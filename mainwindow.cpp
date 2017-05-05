#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->horizontalWidget);
    ui->horizontalWidget->setStyleSheet("background-color:black;");


}

MainWindow::~MainWindow()
{
    delete ui;
    //delete player; //QObject is memory managed.
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   //MainWindow::resizeEvent(event);
   // Your code here.
   qDebug("woo hoo works!");
   resizeButtons();
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
    int gLed = 0;
    int rLed = 0;

    switch(simonColor) {
        case red:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/0_e.wav";
        rLed = 100;
        gLed = 0;
        break;
    case yellow:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/1_a.wav";
        rLed = 50;
        gLed = 50;
        break;
    case green:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/2_cs.wav";
        rLed = 0;
        gLed = 100;
        break;
    case orange:
        soundPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/3_e.aiff";
        rLed = 80;
        gLed = 20;
        break;
    }

    QProcess process;
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "afplay " + soundPath); //plays sound on a mac.
    //exec
    //aplay -vv audio.wav

   //also set light color!

    //rLed, gLed
    //To control the led Green and Red brightness, just write a number 0 - 100 to the following files: (from jihad)
    //root@rwtwenty:/opt/sbin# echo 0 > /sys/class/leds/green_led/brightness
    //root@rwtwenty:/opt/sbin# echo 30 > /sys/class/leds/red_led/brightness


    //native qt play sound.
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

void MainWindow::resizeButtons() {
//    ui->bottomButton->setIconSize(ui->bottomButton->size());

    QSize topSize = ui->topButton->size();
    topSize.setWidth(topSize.width() - 10);
    topSize.setHeight(topSize.height() - 10);
    ui->topButton->setIconSize(topSize);

    QSize bottomSize = ui->bottomButton->size();
    bottomSize.setWidth(bottomSize.width() - 10);
    bottomSize.setHeight(bottomSize.height() - 10);
    ui->bottomButton->setIconSize(bottomSize);

    QSize centerSize = ui->centerButton->size();
    centerSize.setWidth(centerSize.width() - 10);
    centerSize.setHeight(centerSize.height() - 10);
    ui->centerButton->setIconSize(centerSize);

    QSize leftSize = ui->leftButton->size();
    leftSize.setWidth(leftSize.width() - 10);
    leftSize.setHeight(leftSize.height() - 10);
    ui->leftButton->setIconSize(leftSize);

    QSize rightSize = ui->rightButton->size();
    rightSize.setWidth(rightSize.width() - 10);
    rightSize.setHeight(rightSize.height() - 10);
    ui->rightButton->setIconSize(rightSize);

    qDebug("asdf");
}
