#include "connection.h"
#include <QDebug>
#include <QSqlDatabase>

connection::connection()

{

}

bool connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
qDebug()<< "connection : " << test;
 return  test;
}
void connection::closeConnection(){db.close();}
