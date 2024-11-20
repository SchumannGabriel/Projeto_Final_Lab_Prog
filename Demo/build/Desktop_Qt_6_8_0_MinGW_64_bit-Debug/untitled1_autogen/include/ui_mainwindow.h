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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *paginaInicial;
    QWidget *paginaControle;
    QPushButton *botao_controle;
    QPushButton *botao_cadastro;
    QPushButton *botao_config;
    QLabel *label;
    QWidget *paginaCadastro;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(452, 404);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        paginaInicial = new QStackedWidget(centralwidget);
        paginaInicial->setObjectName("paginaInicial");
        paginaInicial->setGeometry(QRect(70, 40, 281, 331));
        paginaControle = new QWidget();
        paginaControle->setObjectName("paginaControle");
        botao_controle = new QPushButton(paginaControle);
        botao_controle->setObjectName("botao_controle");
        botao_controle->setGeometry(QRect(100, 90, 75, 24));
        botao_cadastro = new QPushButton(paginaControle);
        botao_cadastro->setObjectName("botao_cadastro");
        botao_cadastro->setGeometry(QRect(100, 150, 75, 24));
        botao_config = new QPushButton(paginaControle);
        botao_config->setObjectName("botao_config");
        botao_config->setGeometry(QRect(100, 220, 81, 24));
        label = new QLabel(paginaControle);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 111, 20));
        paginaInicial->addWidget(paginaControle);
        paginaCadastro = new QWidget();
        paginaCadastro->setObjectName("paginaCadastro");
        paginaInicial->addWidget(paginaCadastro);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        paginaInicial->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        botao_controle->setText(QCoreApplication::translate("MainWindow", "Controle", nullptr));
        botao_cadastro->setText(QCoreApplication::translate("MainWindow", "Cadastro", nullptr));
        botao_config->setText(QCoreApplication::translate("MainWindow", "Configura\303\247\303\243o", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pagina de Controle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
