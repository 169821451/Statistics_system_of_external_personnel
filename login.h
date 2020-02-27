#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include <QSettings>
#include <QFileInfo>
#include <QByteArray>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QTextCodec>
#include <QDebug>



//#include "mainwindow.h"

class mainwindow;

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    mainwindow* w;

    QSettings* settings;

    QString UserPath;

    QString Username;

    QString Password;

    QByteArray m_passWord;


private slots:
    void on_denglu_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
