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

    connect(ui->ActionWeight, &QAction::triggered, this, &MainWindow::switchToWeightModePage);
    connect(ui->ActionManual, &QAction::triggered, this, &MainWindow::switchToManualModePage);
    connect(ui->ActionPlan, &QAction::triggered, this, &MainWindow::switchToInjectionPlanPage);
    connect(ui->ActionRecord, &QAction::triggered, this, &MainWindow::switchToInjectionRecordPage);

  // 设置默认显示的页面
    ui->stackedWidget->setCurrentWidget(weightModePage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 切换到 WeightModePage
void MainWindow::switchToWeightModePage()
{
    ui->stackedWidget->setCurrentWidget(weightModePage);
}

// 切换到 ManualModePage
void MainWindow::switchToManualModePage()
{
    ui->stackedWidget->setCurrentWidget(manualModePage);
}

// 切换到 InjectionPlanPage
void MainWindow::switchToInjectionPlanPage()
{
    ui->stackedWidget->setCurrentWidget(injectionPlanPage);
}

// 切换到 InjectionRecordPage
void MainWindow::switchToInjectionRecordPage()
{
    ui->stackedWidget->setCurrentWidget(injectionRecordPage);
}
