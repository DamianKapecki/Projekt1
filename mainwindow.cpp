#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Reset_clicked()
{
    ui->P1->setText("0");
    ui->P2->setText("0");
    ui->P3->setText("0");
    ui->P4->setText("0");
    ui->P5->setText("0");
    ui->P6->setText("0");
    ui->N1->setText("0");
    ui->N2->setText("0");
    ui->N3->setText("0");
    ui->N4->setText("0");
    ui->N5->setText("0");
    ui->N6->setText("0");

}

