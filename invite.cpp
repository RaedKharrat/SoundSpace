#include "invite.h"
#include <QDebug>

invite::invite (QString nom,QString prenom ,QString mail ,int idinv,QString adresse,QString programme,QDate date)
{
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->idinv=idinv;
    this->adresse=adresse;
    this->programme=programme;
    this->date = date;

}
// constructeur

bool invite::ajouter()
{
    QSqlQuery query;

    QString id = QString::number(idinv);//declaration


    query.prepare("insert into invite (nom,prenom,mail,idinv,adresse,programme,date_invite) ""values(:NOM,:PRENOM,:MAIL,:IDINV,:ADRESSE,:PROGRAMME,:DATE_INVITE)");// requette sql


   query.bindValue(":NOM",nom);
   query.bindValue(":PRENOM",prenom);
   query.bindValue(":MAIL",mail);
   query.bindValue(":IDINV",id);
   query.bindValue(":ADRESSE",adresse);
   query.bindValue(":PROGRAMME",programme);
   query.bindValue(":DATE_INVITE",date);


   return query.exec();
}

QSqlQueryModel * invite::afficherTout(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from invite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));

    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));

    model->setHeaderData(2,Qt::Horizontal,QObject::tr("MAIL"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDINV"));

    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));

    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PROGRAMME"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATE"));

    return model;

}
QSqlQueryModel * invite::afficher(QString rech)
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from invite where lower(nom) LIKE lower('%" + rech + "%') OR lower(prenom) LIKE lower('%" + rech + "%')");


model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("MAIL"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDINV"));

model->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));

model->setHeaderData(5,Qt::Horizontal,QObject::tr("PROGRAMME"));



return model;
}

bool invite::supprimer(int idinv)
{
QSqlQuery query;
QString res = QString::number(idinv);
query.prepare("Delete from invite where idinv= :idinv");
query.bindValue(0,res);
return query.exec();
}




bool invite::modify(int idinv){
    QSqlQuery query;
    query.prepare("UPDATE invite SET NOM=:NOM, PRENOM=:PRENOM ,MAIL=:MAIL ,IDINV=:IDINV ,ADRESSE=:ADRESSE ,PROGRAMME=:PROGRAMME WHERE IDinv=:IDinv");
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":MAIL",mail);
    query.bindValue(":IDINV",idinv);
    query.bindValue(":ADRESSE",adresse);
    query.bindValue(":PROGRAMME",programme);
    return query.exec();
}

QSqlQueryModel * invite::TRI(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    switch (index) {
    case 1 :
        model->setQuery("select * from invite ORDER BY IDinv DESC ");

        break;
        case 2:
        model->setQuery("select * from invite ORDER BY IDinv  ");

            break;
            case 3 :
        model->setQuery("select * from invite ORDER BY NOM DESC ");

                break;

                case 4 :
        model->setQuery("select * from invite ORDER BY NOM  ");

                    break;
                    case 5 :
        model->setQuery("select * from invite ORDER BY PRENOM DESC ");

                        break;
                        case 6 :
        model->setQuery("select * from invite ORDER BY PRENOM  ");

                            break;
    default:
        model->setQuery("select * from invite ORDER BY IDinv ");


        }

     return model;
}




QSqlQueryModel* invite::chercher(QString field){
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT * FROM invite WHERE (NOM LIKE '%"+field+"%' OR ID LIKE '%"+field+"%' )");


model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("MAIL"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDINV"));

model->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));

model->setHeaderData(5,Qt::Horizontal,QObject::tr("PROGRAMME"));

}

