#ifndef WEIGHTMODEPAGE_H
#define WEIGHTMODEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QLineEdit>
#include <QProgressBar>

class WeightModePage : public QWidget
{
    Q_OBJECT
public:
    explicit WeightModePage(QWidget *parent = nullptr);

signals:

private slots:
    void onHeadClicked();       // 头部按钮点击事件
    void onTumorClicked();      // 肿瘤选项点击事件
    void onVesselClicked();     // 血管选项点击事件

private:
    QStackedWidget *stackedWidget;  // 用于切换肿瘤和血管界面
    QWidget *optionsWidget;         // 血管和肿瘤选项的容器
    QWidget *createTumorPage();     // 创建肿瘤界面
    QWidget *createVesselPage();    // 创建血管界面

};

#endif // WEIGHTMODEPAGE_H
