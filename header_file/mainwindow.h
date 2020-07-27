#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlResult>
#include <QSqlDatabase>
#include "building.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


    private slots:
        void on_pushButton_clicked();
        void on_pushButton_3_clicked();
        void slot_update_data();

    private:
        Ui::MainWindow *ui;
        Building building;
        Data windata;
};

#endif // MAINWINDOW_H
