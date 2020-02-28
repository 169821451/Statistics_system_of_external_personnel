#include "login.h"
#include "ui_login.h"




login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    // 隐藏最大化 最小化  关闭按钮
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    m_passWord = ui->lineEdit_2->text().toLatin1();

    // 按钮加阴影效果
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(5, 5);
    shadow_effect->setColor(QColor(43, 43, 43));
    shadow_effect->setBlurRadius(8);
    ui->denglu->setGraphicsEffect(shadow_effect);

    // 初始化INI文件路径
    UserPath = QCoreApplication::applicationDirPath();
    UserPath += "/User.ini";

    // 判断INI文件是否存在，如果不存在则创建INI文件并写入默认数据
    QFileInfo File(UserPath);
    settings = new QSettings(UserPath,QSettings::IniFormat);
    if(File.exists() == false)
    {
        // 创建INI文件
        //QSettings *Settings = new QSettings(UserPath,QSettings::IniFormat);

        // 设置默认用户名及密码
        QString UserName = "admin";

        QString PassWord = "admin1";

        // 写入默认数据

        settings->setValue("Users/UsreName",UserName);

        settings->setValue("Users/PassWord",PassWord);

    }

}

login::~login()
{
    delete ui;
}

void login::on_denglu_clicked()
{
    // 读取ini文件中的用户名及密码


    Username = ui->lineEdit->text();

    Password = ui->lineEdit_2->text();

    if(Username == "")
        QMessageBox::warning(this,"","Username is empty");
    else if(Password == "")
        QMessageBox::warning(this,"","Password is empty");
    else
    {
        // sql语句在数据库中进行查询验证
        QString S = QString("select * from public.user where username='%1'and password='%2' ").arg(Username).arg(Password);
        QSqlQuery query;
        query.exec(S);
        if(query.first())
        {
            QMessageBox::information(NULL,"sucess","Login Sucess",QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(NULL,"Error","Login Error,please try again!",QMessageBox::Ok);
            return;
        }

        qDebug()<<"123";
        accept();
    }



}
