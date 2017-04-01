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
}

void MainWindow::on_actionNew_Game_triggered()
{
    //new Game!
}


void MainWindow::on_yellowButton_clicked()
{

}

void MainWindow::on_redButton_clicked()
{

}

void MainWindow::on_greenButton_clicked()
{

}

void MainWindow::on_orangeButton_clicked()
{

}
//////
void colorOffAll() {

}

void colorOn(SimonColor simonColor) {

}



