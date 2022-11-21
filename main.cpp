#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    connection c;

    bool test=c.createconnection();

    if(test)
    {
       // QMessageBox::information(nullptr, QObject::tr("database is open"),
         //           QObject::tr("connection seccessful"), QMessageBox::Cancel);
        w.show();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed "), QMessageBox::Cancel);
w.show();


    return a.exec();
}
