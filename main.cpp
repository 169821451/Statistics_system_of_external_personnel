#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec*pCodec=QTextCodec::codecForName("System");//获取系统字体编码

    QTextCodec::setCodecForLocale(pCodec);


    login login;

    MainWindow *w;
    w = new MainWindow;

    if(login.exec() == QDialog::Accepted)
    {
        w->show();

    }
    else {
        QMessageBox::information(nullptr,"a","aaa",QMessageBox::Ok);
        return -1;
    }

    return a.exec();

}
