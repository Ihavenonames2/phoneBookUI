#include "mainwindow.h"
#include "qlistwidget.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    model_ = new AbonentsModel;
    ui->listView->setModel(model_);
    QSqlQuery query;
    query.exec("SELECT * FROM services");
    while (query.next())
    {
        ui->comboBox->addItem(query.value(1).toString());
    } 
   
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model_;
}

void MainWindow::on_addButton_clicked() 
{
    QString name = ui->lineEdit_name->text();
    QString phoneNumber = ui->lineEdit_number->text();
    QString service = ui->comboBox->currentText();
    QSqlQuery query;
    query.exec(QString("SELECT* FROM services WHERE service = %1").arg(service));
    
    Abonent abonent;
    abonent.setName(name);
    abonent.setNumber(phoneNumber);
    abonent.setService(query.value(0).toString());
    model_->addAbonent(abonent);
}

void MainWindow::on_deleteButton_clicked()
{
    QString phoneNumber = ui->lineEdit_delete->text();
    model_->deleteAbonent(phoneNumber);
}


