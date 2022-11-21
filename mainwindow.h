#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "invite.h"
#include "TailButtonsDelegate.h"
#include "notification.h"
#include "calendrier.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:


    void on_pushButton_13_clicked();


    void on_ajoutaff_clicked();

    void on_confirmerajout_clicked();

    void on_annulerajout_clicked();

    void on_sup_clicked();

    void on_confirmersup_clicked();


    void on_modif_clicked();

    void on_modifier_clicked();


    void on_annulermodif_clicked();

    void on_capture_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_21_clicked();




    void on_rech_textChanged(const QString &arg1);

    void on_dateAjout_userDateChanged(const QDate &date);

    void on_calendrier_clicked();

    void on_pushButton_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    invite  inv;
    Notifications notifier;
    int mref;
    QByteArray data;
};
#endif // MAINWINDOW_H
