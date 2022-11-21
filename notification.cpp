#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
#include <QIcon>
Notifications::Notifications()
{

}

void Notifications::notify(QString titre,QString desc)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage(titre,desc,QSystemTrayIcon::Information,15000);
}
