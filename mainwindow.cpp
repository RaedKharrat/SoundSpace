#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "connection.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QSystemTrayIcon>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(inv.afficherTout());
    //ui->tableView->setEditTriggers(QTableView::AllEditTriggers);
   // ui->tableView->setSelectionBehavior(QTableView::SelectRows);
    //ui->tableView->horizontalHeader()->setStretchLastSection(true);
   // ui->tableView->setItemDelegateForColumn(4,new TailButtonsDelegate(ui->tableView));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView->setModel(inv.afficherTout());
}





void MainWindow::on_ajoutaff_clicked()
{


    ui->nom->setText("");
    ui->prenom->setText("");
    ui->mail->setText("");
    ui->id->setText("");
    ui->adresse->setText("");
    ui->programme->setText("");
    ui->dateAjout->setDate((QDate::currentDate()).addDays(1));
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_confirmerajout_clicked()
{
    invite * inv = new invite(ui->nom->text(), ui->prenom->text(), ui->mail->text(),ui->id->text().toInt(), ui->adresse->text(),ui->programme->text(),ui->dateAjout->date());
    //inv->ajouter();
     bool test=inv->ajouter();
    if (test)
    {
    notifier.notify("Invite Ajout","Invite d'ajout effecter avec succes");
    ui->stackedWidget->setCurrentIndex(1);
}
}

void MainWindow::on_annulerajout_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_sup_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_confirmersup_clicked()
{
    inv.setIDinv(ui->idsupp->text().toInt());
    bool test=inv.supprimer(inv.getIdinv());
    if(test)

        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_modif_clicked()
{

ui->stackedWidget->setCurrentIndex(2);
ui->dateEdit->setDate((QDate::currentDate()).addDays(1));

}


void MainWindow::on_modifier_clicked()
{
QString NOM= ui->nom->text();
QString PRENOM= ui->prenom->text();
QString MAIL= ui->mail->text();
int IDINV = ui->id->text().toInt();
QString ADRESSE= ui->adresse->text();
QString PROGRAMME= ui->programme->text();
invite * inv = new invite(NOM,PRENOM,MAIL,IDINV,ADRESSE,PROGRAMME,ui->dateEdit->date());
inv->modify(IDINV);
ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_annulermodif_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_capture_clicked()
{
    QPixmap screen_shot = ui->tableView->grab();
    QImage img = screen_shot.toImage();
    img.save("Capture.png");
    QDesktopServices::openUrl(QUrl("Capture.png"));

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->tableView->setModel(inv.TRI(index));

}






void MainWindow::on_rech_textChanged(const QString &arg1)
{
    ui->tableView->setModel(inv.afficher(arg1));

}

void MainWindow::on_dateAjout_userDateChanged(const QDate &date)
{
    if(date < (QDate::currentDate()).addDays(1)){
        notifier.notify("Ajout Invite Date ","Date soit supperieure d'Aujourd'hui");
        ui->dateAjout->setDate((QDate::currentDate()).addDays(1));
    }
}

void MainWindow::on_calendrier_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    Calendrier *cal = new Calendrier();

    cal->resize(600,600);
    cal->show();
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    if(date < (QDate::currentDate()).addDays(1)){
        notifier.notify("Modification Invite Date ","Date soit supperieure d'Aujourd'hui");
        ui->dateEdit->setDate((QDate::currentDate()).addDays(1));
    }
}
