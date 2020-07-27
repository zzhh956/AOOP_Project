#include "ui_mainwindow.h"
#include "..\\header_file\\mainwindow.h"
#include "..\\header_file\\building.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&building,SIGNAL(updateGUI()),this, SLOT(slot_update_data()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    building.setCheckfloor(ui->comboBox->currentIndex()+1);
    building.run();
    windata=building.getData();
    ui->lineEdit->setText(QString::fromStdString(windata.testdata));
    ui->lineEdit_2->setText(QString::fromStdString(windata.myanswer));
    ui->lineEdit_3->setText(QString::fromStdString(to_string(windata.spendtime)));
    ui->lineEdit_4->setText(QString::fromStdString(to_string(windata.correct)));
    ui->lcdNumber->display(windata.nowfloor);
    ui->lcdNumber_2->display(windata.elevatorpeople);
    ui->lcdNumber_3->display(windata.distance);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_7->setHidden(true);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->comboBox->setEnabled(false);
    building.startSimulation();
}

void MainWindow::slot_update_data()
{
    windata = building.getData();

    if(windata.nowfloor){
        ui->lineEdit->setText(QString::fromStdString(windata.testdata));
        ui->lineEdit_2->setText(QString::fromStdString(windata.myanswer));
        ui->lineEdit_3->setText(QString::fromStdString(to_string(windata.spendtime)));
        ui->lineEdit_4->setText(QString::fromStdString(to_string(windata.correct)));
        ui->lcdNumber->display(windata.nowfloor);
        ui->lcdNumber_2->display(windata.elevatorpeople);
        ui->lcdNumber_3->display(windata.distance);
        ui->comboBox->setCurrentIndex(windata.nowfloor-1);
    }
    else{
        ui->label_7->setHidden(false);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->comboBox->setEnabled(true);
    }
}
