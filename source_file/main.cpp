#include "..\\header_file\\mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<QSqlResult>
#include<QSqlDatabase>
#include<QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
