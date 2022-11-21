#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <QSystemTrayIcon>
#include<QString>
class Notifications
{
    QString titre,description;
public:
    Notifications();
    void notify(QString,QString);
};
#endif // NOTIFICATIONS_H
