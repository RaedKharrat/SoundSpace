#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>

class invite
{
 QDate date;
 QString nom,prenom,mail,adresse,programme;
 int idinv;

public:

 invite(){}
 invite(QString,QString,QString,int,QString,QString,QDate);
 QString getNom(){return nom;}
 QString getPrenom(){return prenom;}
 QString getMail(){return mail;}
 int getIdinv(){return idinv;}
 QString getAdresse(){return adresse;}
 QString getProgramme(){return programme;}
 QDate getDate(){return date;}

 void setNom(QString nm){this->nom=nm;}
 void setPrenom(QString pn){prenom=pn;}
 void setMail(QString ml){mail=ml;}
 void setIDinv(int id){this->idinv=id;}
 void setAdresse(QString ad){adresse=ad;}
 void setProgramme(QString pg){programme=pg;}
 void setDate(QDate da){date = da;}
 bool ajouter();


 QSqlQueryModel * afficher(QString);
 QSqlQueryModel * afficherTout();
 bool supprimer(int);
 bool modify(int);
  QSqlQueryModel * chercher(QString);

 QSqlQueryModel * TRI(int index);

};

#endif // INVITE_H
