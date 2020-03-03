#ifndef LOGON_H
#define LOGON_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

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
#include <QTextCodec>
#include <QSqlQueryModel>
#include <QTabWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QFile>

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
