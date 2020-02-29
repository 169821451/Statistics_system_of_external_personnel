#ifndef LOGIN_H
#define LOGIN_H




#include "logon.h"


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

    // 声明INI文件指针
    QSettings* settings;
    // ini文件路径
    QString UserPath;
    //
    QString Username;

    QString Password;

    QByteArray m_passWord;

    // 注册界面类指针
    logon* on;

private slots:
    void on_denglu_clicked();

    void on_zhuce_clicked();

private:
    Ui::login *ui;



};

#endif // LOGIN_H
