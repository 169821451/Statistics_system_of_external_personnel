#ifndef ADDINFORMATION_H
#define ADDINFORMATION_H

#include <QDialog>
#include "logon.h"

namespace Ui {
class addInformation;
}

class addInformation : public QDialog
{
    Q_OBJECT

public:
    explicit addInformation(QWidget *parent = nullptr);
    ~addInformation();




private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addInformation *ui;
};

#endif // ADDINFORMATION_H
