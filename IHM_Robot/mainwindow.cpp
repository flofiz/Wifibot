#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrobot.h"
#include <QIcon>
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    robot = new MyRobot(this);
        connect(robot,SIGNAL(updateUI(data)),this,SLOT(updateLablelSpeed(data)));
        connect(robot,SIGNAL(updateUI(data)),this,SLOT(updateLablelBatterie(data)));
    ui->setupUi(this);
}

void MainWindow::setRobot(MyRobot* robot)
{
    this->robot = robot;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete robot;
}

void MainWindow::updateLabelSpeed(Data* data)
{
    qDebug() << "speed update";
    QString str;
    str.setNum(data->getSpeed());
    //ui->Speed->setText(str);
}

void MainWindow::updateLabelBatterie(Data* data)
{
    QString str;
    str.setNum(data->getBatLvl());
    //ui->Batterie->setText(str);
}

void MainWindow::on_TopArrow_pressed()
{
    robot->avancer();
}
void MainWindow::on_TopArrow_released(){
    robot->stop();
}

//void MainWindow::on_RightArrow_clicked()
void MainWindow::on_RightArrow_pressed()
{
    robot->droite();
}
void MainWindow::on_RightArrow_released(){
    robot->stop();
}

void MainWindow::on_BotArrow_pressed()
{
    robot->reculer();
}
void MainWindow::on_BotArrow_released(){
    robot->stop();
}

void MainWindow::on_LeftArrow_pressed()
{
    robot->gauche();
}
void MainWindow::on_LeftArrow_released(){
    robot->stop();
}

void MainWindow::on_power_off_clicked()
{
    robot->disConnect();
}

void MainWindow::on_power_on_clicked()
{
    robot->doConnect();
}

void MainWindow::on_progressBar_valueChanged(int value)
{

}

void MainWindow::on_Stop_pressed()
{
    robot->stop();
}
