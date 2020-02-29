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

    // 设置中文字体
    code = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(code);

    // -------------------------------------设置表格初始化------------------------//
    // 初始化表格
    ui->tableWidget->setColumnCount(6); // 设置列数
    ui->tableWidget->setRowCount(5);    // 设置行数
    // 隐藏行号
    QHeaderView *rowHerder = ui->tableWidget->verticalHeader();
    rowHerder->setHidden(true);
    // 设置标题行
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // 行高列宽自适应大小
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置表格是否可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置表格选中方式 ：选中整行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置边框
    ui->tableWidget->setFrameShape(QFrame::WinPanel);
    //ui->tableWidget->setShowGrid(false);
    // 设置表格选中颜色： 粉色
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(85,255,255);"
                                   "border:0px solid gray");

    // 写入登记信息名称
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(code->toUnicode("姓名")));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(code->toUnicode("年龄")));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(code->toUnicode("身份证号")));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(code->toUnicode("住址")));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(code->toUnicode("返程地址")));
    ui->tableWidget->setItem(0,5,new QTableWidgetItem(code->toUnicode("返程日期")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // sql语句在数据库中进行查询验证
    QString name;
    QString age;
    QString IDcard;
    QString address;
    QString where;
    QString when;
    QString select = QString("select * from user.statisticaltable where name='%1'and age='%2' and IDcard='%3'and address='%4'and where='%5'and when='%6' ").arg(name).arg(age).arg(IDcard).arg(address).arg(where).arg(when);
    QSqlQuery query;
    query.exec(select);
    qDebug()<<IDcard;
    ui->tableWidget->setItem(1,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(age));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem(IDcard));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem(address));
    ui->tableWidget->setItem(1,4,new QTableWidgetItem(where));
    ui->tableWidget->setItem(1,5,new QTableWidgetItem(when));

}
