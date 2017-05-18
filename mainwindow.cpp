#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->horizontalWidget);
    ui->horizontalWidget->setStyleSheet("background-color:black;");
    ui->statusBar->hide();
    game = new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   //MainWindow::resizeEvent(event);
   // Your code here.
   resizeButtons();
}

void MainWindow::actionNewGame()
{
    //new Game!
    game->gameSetup();
    //QDebug("a newgame!");
    doGameAnimation();
}

void MainWindow::doGameAnimation() {
        //play all 4 right after each other.
        //
        redTap();
        sleep(400);

        yellowTap();
        sleep(300);

        greenTap();
        sleep(300);

        orangeTap();
        sleep(300);
        //
        redTap();
        yellowTap();
        greenTap();
        orangeTap();
        sleep(300);
        colorOffAll();
        game->finishStartupAnimation();
        startSimonSaying();
}

void MainWindow::startSimonSaying() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
        this, SLOT(simonSay()));
    timer->start(400);
}

void MainWindow::simonSay() {
    if(game->isSimonSaying()) {
        colorOffAll();
        SimonColor sayWhatNow = game->nextSimonSay();
        callColor(sayWhatNow);
        qDebug("say");
    } else {
        qDebug("now reply");
        timer->stop();
        delete timer;
        colorOffAll();
        game->setGameMode(modeReplying); //I think this is set in nextSimonSay anyway. but let's reset it anyway
    }
}

void MainWindow::reply(SimonColor replyColor) {
    bool noLose = game->reply(replyColor);

    if(game->isSimonSaying()) {
        startSimonSaying();
    }
    if(!noLose) { //yep I'm aware the wording is dumb.
        //you lose.
        doLoseAnimation();
    }
}

void MainWindow::doLoseAnimation() {
    //ok do stuff er whatever.
    doGameAnimation();
}

void MainWindow::yellowTap()
{
    ui->topButton->setChecked(true);
    playSound(yellow);
    if(game->amIReplying()) {
        reply(yellow);
    }
}

void MainWindow::redTap()
{
    ui->leftButton->setChecked(true);
    playSound(red);
    if(game->amIReplying()) {
        reply(red);
    }
}

void MainWindow::greenTap()
{
    ui->bottomButton->setChecked(true);
    playSound(green);
    if(game->amIReplying()) {
        reply(green);
    }
}

void MainWindow::orangeTap()
{
    ui->rightButton->setChecked(true);
    playSound(orange);
    if(game->amIReplying()) {
        reply(orange);
    }

}
//////
void MainWindow::colorOffAll() {
    //set to '_off' suffix
    ui->rightButton->setChecked(false);
    ui->leftButton->setChecked(false);
    ui->topButton->setChecked(false);
    ui->bottomButton->setChecked(false);
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
    QString gLed = "0";
    QString rLed = "0";
    QString sharedPath = "/Users/rlinnema/Documents/TestCode/SimonMagus/simon_sounds/";

    switch(simonColor) {
        case red:
        soundPath = sharedPath + "0_e.wav";
        rLed = "100";
        gLed = "0";
        break;
    case yellow:
        soundPath = sharedPath + "1_a.wav";
        rLed = "50";
        gLed = "50";
        break;
    case green:
        soundPath = sharedPath + "2_cs.wav";
        rLed = "0";
        gLed = "100";
        break;
    case orange:
        soundPath = sharedPath + "3_e.wav";
        rLed = "80";
        gLed = "20";
        break;
    }

    QProcess process;
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "afplay " + soundPath); //plays sound on a mac.

    //on-device
/*
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "aplay -vv " + soundPath);
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "echo "+ gLed + " > /sys/class/leds/green_led/brightness");
    process.startDetached("/bin/sh", QStringList()<< "-c"
                           << "echo "+ rLed + " > /sys/class/leds/red_led/brightness");
*/


    //aplay -vv audio.wav
   //also set light color!
    //root@rwtwenty:/opt/sbin# echo 0 > /sys/class/leds/green_led/brightness
    //root@rwtwenty:/opt/sbin# echo 30 > /sys/class/leds/red_led/brightness
    //rLed, gLed
    //To control the led Green and Red brightness, just write a number 0 - 100 to the following files: (from jihad)
}

void MainWindow::callColor(SimonColor simonColor) {
    switch(simonColor) {
        case red:
            redTap();
        break;
    case yellow:
            yellowTap();
        break;
    case green:
            greenTap();
        break;
    case orange:
            orangeTap();
        break;
    }
}

void MainWindow::on_leftButton_pressed()
{
    if(!game->isSimonSaying()) {
       redTap();
    }
}

void MainWindow::on_leftButton_released()
{
    //change back to normal background
    if(!game->isSimonSaying()) {
        ui->leftButton->setChecked(false);
    }
}



void MainWindow::on_topButton_pressed()
{
    if(!game->isSimonSaying()) {
        yellowTap();
    }
}

void MainWindow::on_topButton_released()
{
    if(!game->isSimonSaying()) {
    //change back to normal background.
        ui->topButton->setChecked(false);
    }
}

void MainWindow::on_rightButton_pressed()
{
    if(!game->isSimonSaying()) {
        orangeTap();
    }
}

void MainWindow::on_rightButton_released()
{
    if(!game->isSimonSaying()) {
        //change back to normal background.
        ui->rightButton->setChecked(false);
    }
}

void MainWindow::on_bottomButton_pressed()
{
    if(!game->isSimonSaying()) {
        greenTap();
    }
}



void MainWindow::on_bottomButton_released()
{
    if(!game->isSimonSaying()) {
        //change back to normal background.
        ui->bottomButton->setChecked(false);
    }
}

void MainWindow::resizeButtons() {

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
}

void MainWindow::sleep(int millis)
{
    QTime dieTime= QTime::currentTime().addMSecs(millis);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_centerButton_clicked()
{
    //cancel stuff? naw
    actionNewGame();
}
