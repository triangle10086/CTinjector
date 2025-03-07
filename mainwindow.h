#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 前向声明
class WeightModePage;
class ManualModePage;
class InjectionPlanPage;
class InjectionRecordPage;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    WeightModePage *weightModePage;
    ManualModePage *manualModePage;
    InjectionPlanPage *injectionPlanPage;
    InjectionRecordPage *injectionRecordPage;

private slots:
    void on_weightModeButton_clicked();
    void on_manualModeButton_clicked();
    void on_injectionPlanButton_clicked();
    void on_injectionRecordButton_clicked();


};
#endif // MAINWINDOW_H
