#ifndef LOGON_H
#define LOGON_H

#include <QDialog>
#include <QString>
#include <QSettings>
#include <QFileInfo>
#include <QByteArray>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class logon;
}

class logon : public QDialog
{
    Q_OBJECT

public:
    explicit logon(QWidget *parent = nullptr);
    ~logon();


    QString userName;

    QString passWord;

    QString inSert;


private slots:
    void on_pushButton_clicked();

private:
    Ui::logon *ui;
};

#endif // LOGON_H
