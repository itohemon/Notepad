#include "license.h"
#include "ui_license.h"

#include <QTextStream>
#include <QDebug>

licenseDialog::licenseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::licenseDialog)
{
    ui->setupUi(this);

    QFile file("/home/itohemon/license.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->plainTextEdit->appendPlainText(line);
    }
}

licenseDialog::~licenseDialog()
{
    delete ui;
}

void licenseDialog::on_pushButton_clicked()
{
    this->close();
}
