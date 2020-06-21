#include "mainwindow.h"

#include <QDebug>

#include "constants.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug("Начало работы!");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    qDebug("Вы нажали на 1.");
    _elevator.call(1);
}

void MainWindow::on_button2_clicked()
{
    qDebug("Вы нажали на 2.");
    _elevator.call(2);
}

void MainWindow::on_button3_clicked()
{
    qDebug("Вы нажали на 3.");
    _elevator.call(3);
}

void MainWindow::on_button4_clicked()
{
    qDebug("Вы нажали на 4.");
    _elevator.call(4);
}

void MainWindow::on_button5_clicked()
{
    qDebug("Вы нажали на 5.");
    _elevator.call(5);
}

void MainWindow::on_button6_clicked()
{
    qDebug("Вы нажали на 6.");
    _elevator.call(6);
}

void MainWindow::on_button7_clicked()
{
    qDebug("Вы нажали на 7.");
    _elevator.call(7);
}

void MainWindow::on_button8_clicked()
{
    qDebug("Вы нажали на 8.");
    _elevator.call(8);
}

void MainWindow::on_button9_clicked()
{
    qDebug("Вы нажали на 9.");
    _elevator.call(9);
}
