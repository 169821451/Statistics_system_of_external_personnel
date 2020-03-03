#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QTextCodec>

#include "login.h"
#include "addinformation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QTextCodec* code;

    addInformation* add;

private slots:
    void on_pushButton_clicked();

    void on_nameselect_2_clicked();

    void on_Dateselect_clicked();

    void on_addressselect_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
