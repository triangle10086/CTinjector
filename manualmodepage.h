#ifndef MANUALMODEPAGE_H
#define MANUALMODEPAGE_H

#include <QWidget>
#include <QStackedWidget>

class ManualModePage : public QWidget
{
    Q_OBJECT

public:
    explicit ManualModePage(QWidget *parent = nullptr);

private slots:
    void switchToPageA();
    void switchToPageB();
    void switchToPageAB();
    void switchToPageA1A2();
    void switchToPageAA();
    void switchToPageB1B2();
    void switchToPageABB();
    void switchToPageAABBB();
    void switchToPageABHoldAB();

private:
    QStackedWidget *stackedWidget;
    QWidget *createPage(const QString &text); // 创建通用页面
};

#endif // MANUALMODEPAGE_H
