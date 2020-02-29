#include "logon.h"
#include "ui_logon.h"

logon::logon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logon)
{
    ui->setupUi(this);

    // 隐藏最大化 最小化  关闭按钮
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);



}

logon::~logon()
{
    delete ui;
}

void logon::on_pushButton_clicked()
{
    userName = ui->user->text();
    passWord = ui->pass->text();

    if(userName == "")
        QMessageBox::warning(this,"","Username is empty");
    else if(passWord == "")
        QMessageBox::warning(this,"","Password is empty");
    else
    {
        // sql语句在数据库中写入新的用户名密码
        inSert = QString("insert into user.username values ('%1','%2'); ").arg(userName).arg(passWord);
        // 查询验证用户名是否重复
        QString S = QString("select * from user.username where username='%1' ").arg(userName);
        QSqlQuery query;

        if(query.exec(S) && query.first())
        {
            QMessageBox::warning(nullptr,"Error","Duplicate user name, please re-enter!",QMessageBox::Ok);
            return;
        }
        else
        {
            if(query.exec(inSert))
            {
                QMessageBox::information(nullptr,"sucess","Logon Sucess",QMessageBox::Yes);
                this->close();
            }
            else
            {
                QMessageBox::warning(nullptr,"Error","Registration failed, please try again!",QMessageBox::Ok);
                return;
            }
        }

    }

}
