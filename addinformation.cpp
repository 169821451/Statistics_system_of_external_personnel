#include "addinformation.h"
#include "ui_addinformation.h"

addInformation::addInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addInformation)
{
    ui->setupUi(this);
}

addInformation::~addInformation()
{
    delete ui;
}

void addInformation::on_pushButton_2_clicked()
{
    close();
}

void addInformation::on_pushButton_clicked()
{
    QString name = ui->name->text();

    QString age = ui->age->text();

    QString IDcard = ui->IDcard->text();

    QString address = ui->address->text();

    QString where = ui->where->text();

    QString when = ui->when->text();

    if(name == "")
        QMessageBox::warning(this,"错误","姓名不能为空",QMessageBox::Ok);
    else if(age == "")
        QMessageBox::warning(this,"错误","年龄不能为空",QMessageBox::Ok);
    else if (IDcard == "") {
        QMessageBox::warning(this,"错误","身份证号不能为空",QMessageBox::Ok);
    }
    else if (address == "") {
        QMessageBox::warning(this,"错误","住址不能为空",QMessageBox::Ok);
    }
    else if (where == "") {
        QMessageBox::warning(this,"错误","返程地址不能为空",QMessageBox::Ok);
    }
    else if (when == "") {
        QMessageBox::warning(this,"错误","返程时间不能为空",QMessageBox::Ok);
    }
    else
    {
        // sql语句在数据库中写入新的人员信息
        QString inSert = QString("insert into user.statisticaltable values ('%1','%2','%3','%4','%5','%6'); ").arg(name).arg(age).arg(IDcard).arg(address).arg(where).arg(when);
        // 查询验证新录入信息是否重复是否重复
        QString S = QString("select * from user.statisticaltable where 身份证号='%1' ").arg(IDcard);
        QSqlQuery query;

        if(query.exec(S) && query.first())
        {
            QMessageBox::warning(nullptr,"错误","身份证号已存在!",QMessageBox::Ok);
            return;
        }
        else
        {
            if(query.exec(inSert))
            {
                QMessageBox::information(nullptr,"成功","信息录入成功!",QMessageBox::Yes);
                this->close();
            }
            else
            {
                QMessageBox::warning(nullptr,"错误","信息录入失败!",QMessageBox::Ok);
                return;
            }
        }

    }
}
