#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,768);
    // 设置日期查询默认日期为当前日期
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());

    // 设置中文
    code = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(code);

    // -------------------------------------设置表格初始化------------------------//
    // 设置表格大小
    ui->tableView->resize(830,610);
    // 背景网格线设置
    // 显示
    ui->tableView->setShowGrid(true);
    // 设置网格线画笔 此处为实线
    ui->tableView->setGridStyle(Qt::SolidLine);
    // 设置表头
    QStandardItemModel* stdModel = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("姓名,年龄,身份证号,住址,返程地址,返程时间").simplified().split(",");
    stdModel->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(stdModel);
    ui->tableView->show();
    // 设置表格无法编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置选中方式为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置列宽
    ui->tableView->setColumnWidth(0,80); // 姓名
    ui->tableView->setColumnWidth(1,50); // 年龄
    ui->tableView->setColumnWidth(2,200); // 身份证号
    ui->tableView->setColumnWidth(3,300); // 住址
    ui->tableView->setColumnWidth(4,120); // 返程地址
    ui->tableView->setColumnWidth(5,80); // 返程时间

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // sql语句在数据库中进行查询验证

    QString age;
    QString IDcard;
    QString address;
    QString where;
    QString when;

//    ui->tableWidget->setItem(1,0,new QTableWidgetItem(name));
//    ui->tableWidget->setItem(1,1,new QTableWidgetItem(age));
//    ui->tableWidget->setItem(1,2,new QTableWidgetItem(IDcard));
//    ui->tableWidget->setItem(1,3,new QTableWidgetItem(address));
//    ui->tableWidget->setItem(1,4,new QTableWidgetItem(where));
//    ui->tableWidget->setItem(1,5,new QTableWidgetItem(when));

    // 设置表格无法编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置选中方式为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置列宽
    ui->tableView->setColumnWidth(0,60); // 姓名
    ui->tableView->setColumnWidth(1,50); // 年龄
    ui->tableView->setColumnWidth(2,200); // 身份证号
    ui->tableView->setColumnWidth(3,300); // 住址
    ui->tableView->setColumnWidth(4,120); // 返程地址
    ui->tableView->setColumnWidth(5,80); // 返程时间
    // 设置显示数据库内容
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);

    QString select = QString("select * from user.statisticaltable");//.arg(name).arg(age).arg(IDcard).arg(address).arg(where).arg(when);

    model->setQuery(select);
    model->setHeaderData(0,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(1,Qt::Horizontal,tr("年龄"));
    model->setHeaderData(2,Qt::Horizontal,tr("身份照"));
    model->setHeaderData(3,Qt::Horizontal,tr("住址"));
    model->setHeaderData(4,Qt::Horizontal,tr("返程地址"));
    model->setHeaderData(5,Qt::Horizontal,tr("返程时间"));
    ui->tableView->setModel(model);

}

void MainWindow::on_nameselect_2_clicked()
{
    QString Name;
    Name = ui->nameselect->text().toUtf8();
//    QString select = QString("select * from statisticaltable where name='%1' ").arg(Name);//.arg(name).arg(age).arg(IDcard).arg(address).arg(where).arg

    // sql语句在数据库中进行查询验证
    QString select = QString("select * from user.statisticaltable where 姓名='%1' ").arg(Name);;
    QSqlQuery query;
    query.exec(select);
    if(query.first())
    {
        // 设置表格无法编辑
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // 设置选中方式为整行选中
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        // 设置列宽
        ui->tableView->setColumnWidth(0,60); // 姓名
        ui->tableView->setColumnWidth(1,50); // 年龄
        ui->tableView->setColumnWidth(2,200); // 身份证号
        ui->tableView->setColumnWidth(3,300); // 住址
        ui->tableView->setColumnWidth(4,120); // 返程地址
        ui->tableView->setColumnWidth(5,80); // 返程时间
        // 设置显示数据库内容
        QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
        model->setQuery(select);
        model->setHeaderData(0,Qt::Horizontal,tr("姓名"));
        model->setHeaderData(1,Qt::Horizontal,tr("年龄"));
        model->setHeaderData(2,Qt::Horizontal,tr("身份照"));
        model->setHeaderData(3,Qt::Horizontal,tr("住址"));
        model->setHeaderData(4,Qt::Horizontal,tr("返程地址"));
        model->setHeaderData(5,Qt::Horizontal,tr("返程时间"));
        ui->tableView->setModel(model);

    }
    else
    {
        QMessageBox::warning(NULL,"Error","无此数据!",QMessageBox::Ok);
        ui->nameselect->clear();
        return;
    }

}

void MainWindow::on_Dateselect_clicked()
{
    QString date = ui->dateEdit->text();
    qDebug()<< date;
    // sql语句在数据库中进行查询验证
    QString select = QString("select * from user.statisticaltable where 返程时间='%1' ").arg(date);;
    QSqlQuery query;
    query.exec(select);
    if(query.first())
    {
        // 设置表格无法编辑
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // 设置选中方式为整行选中
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        // 设置列宽
        ui->tableView->setColumnWidth(0,60); // 姓名
        ui->tableView->setColumnWidth(1,50); // 年龄
        ui->tableView->setColumnWidth(2,200); // 身份证号
        ui->tableView->setColumnWidth(3,300); // 住址
        ui->tableView->setColumnWidth(4,120); // 返程地址
        ui->tableView->setColumnWidth(5,80); // 返程时间
        // 设置显示数据库内容
        QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
        model->setQuery(select);
        model->setHeaderData(0,Qt::Horizontal,tr("姓名"));
        model->setHeaderData(1,Qt::Horizontal,tr("年龄"));
        model->setHeaderData(2,Qt::Horizontal,tr("身份照"));
        model->setHeaderData(3,Qt::Horizontal,tr("住址"));
        model->setHeaderData(4,Qt::Horizontal,tr("返程地址"));
        model->setHeaderData(5,Qt::Horizontal,tr("返程时间"));
        ui->tableView->setModel(model);

    }
    else
    {
        QMessageBox::warning(NULL,"Error","无此数据!",QMessageBox::Ok);
        return;
    }
}

void MainWindow::on_addressselect_clicked()
{
    QString IDcard = ui->address->text();
    qDebug()<< IDcard;
    // sql语句在数据库中进行查询验证
    QString select = QString("select * from user.statisticaltable where 身份证号='%1' ").arg(IDcard);;
    QSqlQuery query;
    query.exec(select);
    if(query.first())
    {
        // 设置表格无法编辑
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // 设置选中方式为整行选中
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        // 设置列宽
        ui->tableView->setColumnWidth(0,60); // 姓名
        ui->tableView->setColumnWidth(1,50); // 年龄
        ui->tableView->setColumnWidth(2,200); // 身份证号
        ui->tableView->setColumnWidth(3,300); // 住址
        ui->tableView->setColumnWidth(4,120); // 返程地址
        ui->tableView->setColumnWidth(5,80); // 返程时间
        // 设置显示数据库内容
        QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
        model->setQuery(select);
        model->setHeaderData(0,Qt::Horizontal,tr("姓名"));
        model->setHeaderData(1,Qt::Horizontal,tr("年龄"));
        model->setHeaderData(2,Qt::Horizontal,tr("身份照"));
        model->setHeaderData(3,Qt::Horizontal,tr("住址"));
        model->setHeaderData(4,Qt::Horizontal,tr("返程地址"));
        model->setHeaderData(5,Qt::Horizontal,tr("返程时间"));
        ui->tableView->setModel(model);

    }
    else
    {
        QMessageBox::warning(NULL,"Error","无此数据!",QMessageBox::Ok);
        ui->address->clear();
        return;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    add = new addInformation;
    add->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开文件","","Allfile(*.*);;Csvfile(*.csv)");
qDebug()<<"1";
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"111";
    }
qDebug()<<"2";
    QStringList list;
qDebug()<<"3";
    list.clear();
qDebug()<<"4";
    QTextStream in(&file);
    qDebug()<<"5";
    QSqlQuery query;
qDebug()<<"6";

    while (!in.atEnd())
    {

        QString fileLine = in.readLine();

        list = fileLine.split(",", QString::SkipEmptyParts);
        QString name = list.at(0);

        QString age = list.at(1);

        QString IDcard = list.at(2);

        QString address = list.at(3);

        QString where = list.at(4);

        QString when = list.at(5);

        query.prepare("INSERT INTO user.statisticaltable values ('姓名','年龄','身份证号','住址','返程地址','返程时间');");
        query.bindValue("姓名",list.at(0));
        query.bindValue("年龄",list.at(1));
        query.bindValue("身份证号",list.at(2));
        query.bindValue("住址",list.at(3));
        query.bindValue("返程地址",list.at(4));
        query.bindValue("返程时间",list.at(5));

        query.exec();
        qDebug()<<"12";
        qDebug()<<query.lastError().text();
    }

}
