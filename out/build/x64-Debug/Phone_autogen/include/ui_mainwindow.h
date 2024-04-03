/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addButton;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_number;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_delete;
    QPushButton *deleteButton;
    QListView *listView;
    QComboBox *comboBox;
    QPushButton *DeleteNull_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(500, 110, 91, 24));
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(350, 70, 133, 22));
        lineEdit_number = new QLineEdit(centralwidget);
        lineEdit_number->setObjectName("lineEdit_number");
        lineEdit_number->setGeometry(QRect(500, 70, 133, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 10, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 40, 381, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 160, 391, 20));
        lineEdit_delete = new QLineEdit(centralwidget);
        lineEdit_delete->setObjectName("lineEdit_delete");
        lineEdit_delete->setGeometry(QRect(442, 190, 221, 22));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(500, 220, 91, 24));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(30, 40, 301, 471));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(640, 70, 141, 22));
        DeleteNull_button = new QPushButton(centralwidget);
        DeleteNull_button->setObjectName("DeleteNull_button");
        DeleteNull_button->setGeometry(QRect(480, 280, 141, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "AddUser", nullptr));
        lineEdit_name->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        lineEdit_number->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Caller list", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter here info to add user, service must be number from 1 to 3", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter here info to delete user by number, all numbers are unique value", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "DeleteUser", nullptr));
        DeleteNull_button->setText(QCoreApplication::translate("MainWindow", "DeleteAll Null", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
