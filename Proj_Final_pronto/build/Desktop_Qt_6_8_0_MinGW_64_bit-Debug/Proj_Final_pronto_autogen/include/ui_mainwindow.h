/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *PaginaInicial;
    QWidget *paginaInicial;
    QLabel *label;
    QPushButton *botao_controle;
    QPushButton *botao_cadastro;
    QPushButton *botao_config;
    QWidget *pagina;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        PaginaInicial = new QStackedWidget(centralwidget);
        PaginaInicial->setObjectName("PaginaInicial");
        PaginaInicial->setGeometry(QRect(140, 40, 311, 331));
        paginaInicial = new QWidget();
        paginaInicial->setObjectName("paginaInicial");
        label = new QLabel(paginaInicial);
        label->setObjectName("label");
        label->setGeometry(QRect(108, 30, 71, 20));
        botao_controle = new QPushButton(paginaInicial);
        botao_controle->setObjectName("botao_controle");
        botao_controle->setGeometry(QRect(110, 80, 75, 24));
        botao_cadastro = new QPushButton(paginaInicial);
        botao_cadastro->setObjectName("botao_cadastro");
        botao_cadastro->setGeometry(QRect(110, 130, 75, 24));
        botao_config = new QPushButton(paginaInicial);
        botao_config->setObjectName("botao_config");
        botao_config->setGeometry(QRect(104, 180, 81, 24));
        PaginaInicial->addWidget(paginaInicial);
        pagina = new QWidget();
        pagina->setObjectName("pagina");
        pushButton = new QPushButton(pagina);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 270, 75, 24));
        PaginaInicial->addWidget(pagina);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        PaginaInicial->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pagina Inicial", nullptr));
        botao_controle->setText(QCoreApplication::translate("MainWindow", "Controle", nullptr));
        botao_cadastro->setText(QCoreApplication::translate("MainWindow", "Cadastro", nullptr));
        botao_config->setText(QCoreApplication::translate("MainWindow", "Configura\303\247\303\243o", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Voltar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
