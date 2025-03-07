#include "mainwindow.h"

#include "weightmodepage.h"
#include "injectionplanpage.h"
#include "manualmodepage.h"
#include "injectionrecordpage.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete weightModePage;
    delete manualModePage;
    delete injectionPlanPage;
    delete injectionRecordPage;

    delete ui;
}
