#include "mainwindow.h"
#include "weightmodepage.h"
#include "manualmodepage.h"
#include "injectionplanpage.h"
#include "injectionrecordpage.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , weightModePage(new WeightModePage(this))
    , manualModePage(new ManualModePage(this))
    , injectionPlanPage(new InjectionPlanPage(this))
    , injectionRecordPage(new InjectionRecordPage(this))
{
    ui->setupUi(this);

    // 将页面添加到 stackedWidget
    ui->stackedWidget->addWidget(weightModePage);
    ui->stackedWidget->addWidget(manualModePage);
    ui->stackedWidget->addWidget(injectionPlanPage);
    ui->stackedWidget->addWidget(injectionRecordPage);

    // 设置默认显示的页面
    ui->stackedWidget->setCurrentWidget(weightModePage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
