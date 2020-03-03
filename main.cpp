#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 设置全局字体
    QTextCodec*pCodec=QTextCodec::codecForName("GBK");//获取系统字体编码

    QTextCodec::setCodecForLocale(pCodec);


    login login;

    MainWindow *w;
    w = new MainWindow;

    // 建立数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("user");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("toor");

    if(db.open())
    {
        if(login.exec() == QDialog::Accepted)
        {
            w->show();
        }
        else {
            QMessageBox::information(nullptr,"提示","数据库连接成功",QMessageBox::Ok);
            return 0;
        }
    }
    else
    {
        qDebug()<<db.lastError().text();
        QMessageBox::warning(nullptr,"error","打开数据库失败",QMessageBox::Ok);
        return 0;
    }



    return a.exec();

}
