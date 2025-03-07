/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "injectionplanpage.h"
#include "injectionrecordpage.h"
#include "manualmodepage.h"
#include "weightmodepage.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionManual;
    QAction *ActionRecord;
    QAction *ActionPlan;
    QAction *ActionWeight;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    WeightModePage *WeightModePage;
    InjectionPlanPage *InjectionPlanPage;
    InjectionRecordPage *InjectionRecordPage;
    ManualModePage *ManualModePage;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(687, 486);
        ActionManual = new QAction(MainWindow);
        ActionManual->setObjectName("ActionManual");
        ActionManual->setMenuRole(QAction::MenuRole::NoRole);
        ActionRecord = new QAction(MainWindow);
        ActionRecord->setObjectName("ActionRecord");
        ActionRecord->setMenuRole(QAction::MenuRole::NoRole);
        ActionPlan = new QAction(MainWindow);
        ActionPlan->setObjectName("ActionPlan");
        ActionPlan->setMenuRole(QAction::MenuRole::NoRole);
        ActionWeight = new QAction(MainWindow);
        ActionWeight->setObjectName("ActionWeight");
        ActionWeight->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 671, 401));
        WeightModePage = new WeightModePage();
        WeightModePage->setObjectName("WeightModePage");
        stackedWidget->addWidget(WeightModePage);
        InjectionPlanPage = new InjectionPlanPage();
        InjectionPlanPage->setObjectName("InjectionPlanPage");
        stackedWidget->addWidget(InjectionPlanPage);
        InjectionRecordPage = new InjectionRecordPage();
        InjectionRecordPage->setObjectName("InjectionRecordPage");
        stackedWidget->addWidget(InjectionRecordPage);
        ManualModePage = new ManualModePage();
        ManualModePage->setObjectName("ManualModePage");
        stackedWidget->addWidget(ManualModePage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 687, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(ActionWeight);
        toolBar->addAction(ActionManual);
        toolBar->addAction(ActionPlan);
        toolBar->addAction(ActionRecord);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ActionManual->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", nullptr));
        ActionRecord->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\260\204\350\256\260\345\275\225", nullptr));
        ActionPlan->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\260\204\346\226\271\346\241\210", nullptr));
        ActionWeight->setText(QCoreApplication::translate("MainWindow", "\344\275\223\351\207\215\346\250\241\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
