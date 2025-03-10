#include "manualmodepage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>

ManualModePage::ManualModePage(QWidget *parent)
    : QWidget(parent)
{
    // 主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 创建水平布局的按钮栏
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // 创建按钮
    QPushButton *buttons[] = {
        new QPushButton("A", this),
        new QPushButton("B", this),
        new QPushButton("A-B", this),
        new QPushButton("A1>A2", this),
        new QPushButton("A->A", this),
        new QPushButton("B1>B2", this),
        new QPushButton("A+B-B", this),
        new QPushButton("A-A+B-B", this),
        new QPushButton("A-B-hold-A-B", this)
    };

    for (QPushButton *btn : buttons) {
        btn->setMinimumSize(75, 20); // 设置最小尺寸
        QFont font = btn->font();
        font.setPointSize(7); // 设置字体大小
        btn->setFont(font);
    }

    // 设置水平布局的间距
    buttonLayout->setSpacing(5);
    // 将按钮添加到水平布局
    for (QPushButton *btn : buttons) {
        buttonLayout->addWidget(btn);
    }

    // 创建堆栈窗口并添加子页面
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(createPage("A"));
    stackedWidget->addWidget(createPage("B"));
    stackedWidget->addWidget(createPage("A-B"));
    stackedWidget->addWidget(createPage("A1>A2"));
    stackedWidget->addWidget(createPage("A->A"));
    stackedWidget->addWidget(createPage("B1>B2"));
    stackedWidget->addWidget(createPage("A+B-B"));
    stackedWidget->addWidget(createPage("A-A+B-B"));
    stackedWidget->addWidget(createPage("A-B-hold-A-B"));

    // 将按钮布局和堆栈窗口添加到主布局
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(stackedWidget);

    // 连接按钮信号
    connect(buttons[0], &QPushButton::clicked, this, &ManualModePage::switchToPageA);
    connect(buttons[1], &QPushButton::clicked, this, &ManualModePage::switchToPageB);
    connect(buttons[2], &QPushButton::clicked, this, &ManualModePage::switchToPageAB);
    connect(buttons[3], &QPushButton::clicked, this, &ManualModePage::switchToPageA1A2);
    connect(buttons[4], &QPushButton::clicked, this, &ManualModePage::switchToPageAA);
    connect(buttons[5], &QPushButton::clicked, this, &ManualModePage::switchToPageB1B2);
    connect(buttons[6], &QPushButton::clicked, this, &ManualModePage::switchToPageABB);
    connect(buttons[7], &QPushButton::clicked, this, &ManualModePage::switchToPageAABBB);
    connect(buttons[8], &QPushButton::clicked, this, &ManualModePage::switchToPageABHoldAB);
}

QWidget* ManualModePage::createPage(const QString &text) {
    QWidget *page = new QWidget();

    if (text == "A") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);

        // 第一个水平布局：按钮和标签
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        QLabel *labelInjectionMode = new QLabel("注射模式A", page);
        QPushButton *btnTestNeedle = new QPushButton("试针", page);
        QPushButton *btnGroupInjection = new QPushButton("团注式", page);


        // 设置按钮和标签的大小
        btnTestNeedle->setMinimumSize(100, 30); // 试针按钮大小
        btnGroupInjection->setMinimumSize(100, 30); // 团注式按钮大小
        labelInjectionMode->setMinimumSize(150, 30); // 注射模式A标签大小

        buttonLayout->addWidget(btnTestNeedle);
        buttonLayout->addWidget(btnGroupInjection);
        buttonLayout->addWidget(labelInjectionMode);

        // 第二个水平布局：标签
        QHBoxLayout *labelLayout = new QHBoxLayout();
        QLabel *labelRate = new QLabel("注射速率", page);
        QLabel *labelVolume = new QLabel("注射量", page);

        // 设置标签的大小
        labelRate->setMinimumSize(100, 30); // 注射速率标签大小
        labelVolume->setMinimumSize(100, 30); // 注射量标签大小

        labelLayout->addWidget(labelRate);
        labelLayout->addWidget(labelVolume);

        // 第三个水平布局：输入控件
        QHBoxLayout *inputLayout = new QHBoxLayout();
        QLineEdit *editRate = new QLineEdit(page);
        QLineEdit *editVolume = new QLineEdit(page);

        // 设置输入控件的大小
        editRate->setMinimumSize(50, 30); // 注射速率输入框大小
        editVolume->setMinimumSize(50, 30); // 注射量输入框大小

        inputLayout->addWidget(editRate);
        inputLayout->addWidget(editVolume);

        // 设置布局间距
        buttonLayout->setSpacing(10); // 按钮布局的间距
        labelLayout->setSpacing(10);  // 标签布局的间距
        inputLayout->setSpacing(10);  // 输入控件布局的间距
        mainLayout->setSpacing(5);   // 主垂直布局的间距

        // 设置对齐方式
        buttonLayout->setAlignment(Qt::AlignLeft);   // 按钮布局左对齐
        labelLayout->setAlignment(Qt::AlignLeft);    // 标签布局左对齐
        inputLayout->setAlignment(Qt::AlignLeft);    // 输入控件布局左对齐

        // 设置字体大小
        QFont font;
        font.setPointSize(12); // 设置字体大小为 12

        btnTestNeedle->setFont(font);
        btnGroupInjection->setFont(font);
        labelInjectionMode->setFont(font);
        labelRate->setFont(font);
        labelVolume->setFont(font);
        editRate->setFont(font);
        editVolume->setFont(font);

        // 将三个水平布局添加到主垂直布局
        mainLayout->addLayout(buttonLayout);
        mainLayout->addLayout(labelLayout);
        mainLayout->addLayout(inputLayout);

        // 设置布局
        page->setLayout(mainLayout);
    }

    else if (text == "A-B") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);

        // 顶部按钮布局
        QHBoxLayout *topButtonLayout = new QHBoxLayout();
        QPushButton *btnTestNeedle = new QPushButton("试针", page);
        QPushButton *btnGroupInjection = new QPushButton("团注", page);
        QPushButton *btnSuction = new QPushButton("吸药", page);
        QLabel *labelInjectionMode = new QLabel("注射模式：A-B", page);
        QLabel *labelStatus = new QLabel("准备中", page);
        QPushButton *btnStart = new QPushButton("启动", page);

        // 设置按钮和标签大小
        btnTestNeedle->setMinimumSize(80, 30);
        btnGroupInjection->setMinimumSize(80, 30);
        btnSuction->setMinimumSize(80, 30);
        labelInjectionMode->setMinimumSize(120, 30);
        labelStatus->setMinimumSize(80, 30);
        btnStart->setMinimumSize(80, 30);

        // 添加按钮和标签到布局
        topButtonLayout->addWidget(btnTestNeedle);
        topButtonLayout->addWidget(btnGroupInjection);
        topButtonLayout->addWidget(btnSuction);
        topButtonLayout->addWidget(labelInjectionMode);
        topButtonLayout->addSpacing(20); // 添加间距
        topButtonLayout->addWidget(labelStatus);
        topButtonLayout->addWidget(btnStart);

        // 注射速率和注射量输入框
        QGridLayout *inputLayout = new QGridLayout();
        QLabel *labelRateA = new QLabel("A 注射速率", page);
        QLabel *labelVolumeA = new QLabel("A 注射量", page);
        QLineEdit *editRateA = new QLineEdit(page);
        QLineEdit *editVolumeA = new QLineEdit(page);

        QLabel *labelRateB = new QLabel("B 注射速率", page);
        QLabel *labelVolumeB = new QLabel("B 注射量", page);
        QLineEdit *editRateB = new QLineEdit(page);
        QLineEdit *editVolumeB = new QLineEdit(page);

        // 设置输入框大小（缩小为原来的三分之一）
        editRateA->setMinimumSize(60, 30);
        editVolumeA->setMinimumSize(60, 30);
        editRateB->setMinimumSize(60, 30);
        editVolumeB->setMinimumSize(60, 30);

        inputLayout->addWidget(labelRateA, 0, 0);
        inputLayout->addWidget(editRateA, 0, 1);
        inputLayout->addWidget(labelVolumeA, 1, 0);
        inputLayout->addWidget(editVolumeA, 1, 1);

        inputLayout->addWidget(labelRateB, 2, 0);
        inputLayout->addWidget(editRateB, 2, 1);
        inputLayout->addWidget(labelVolumeB, 3, 0);
        inputLayout->addWidget(editVolumeB, 3, 1);

        // 显示区域
        QVBoxLayout *displayLayout = new QVBoxLayout();
        QLabel *labelDisplay = new QLabel("显示区域：显示针管当前剩余溶液", page);
        labelDisplay->setAlignment(Qt::AlignCenter);
        labelDisplay->setMinimumSize(300, 50);

        // 添加进度控件
        QProgressBar *progressBarA = new QProgressBar(page);
        progressBarA->setMinimum(0);
        progressBarA->setMaximum(100);
        progressBarA->setValue(50); // 设置初始值
        progressBarA->setFormat("A: %p%");

        QProgressBar *progressBarB = new QProgressBar(page);
        progressBarB->setMinimum(0);
        progressBarB->setMaximum(100);
        progressBarB->setValue(30); // 设置初始值
        progressBarB->setFormat("B: %p%");

        displayLayout->addWidget(labelDisplay);
        displayLayout->addWidget(progressBarA);
        displayLayout->addWidget(progressBarB);

        // 将输入框和显示区域添加到水平布局
        QHBoxLayout *inputDisplayLayout = new QHBoxLayout();
        inputDisplayLayout->addLayout(inputLayout);
        inputDisplayLayout->addLayout(displayLayout);

        // 其他参数布局（压力限制、注射延迟、扫描时间、注射时间）
        QHBoxLayout *paramLayout = new QHBoxLayout();
        QLabel *labelPressureLimit = new QLabel("压力限制", page);
        QLabel *labelInjectionDelay = new QLabel("注射延迟", page);
        QLabel *labelScanTime = new QLabel("扫描时间", page);
        QLabel *labelInjectionTime = new QLabel("注射时间", page);

        QLineEdit *editPressureLimit = new QLineEdit(page);
        QLineEdit *editInjectionDelay = new QLineEdit(page);
        QLineEdit *editScanTime = new QLineEdit(page);
        QLineEdit *editInjectionTime = new QLineEdit(page);

        // 设置输入框大小
        editPressureLimit->setMinimumSize(100, 30);
        editInjectionDelay->setMinimumSize(100, 30);
        editScanTime->setMinimumSize(100, 30);
        editInjectionTime->setMinimumSize(100, 30);

        paramLayout->addWidget(labelPressureLimit);
        paramLayout->addWidget(editPressureLimit);
        paramLayout->addWidget(labelInjectionDelay);
        paramLayout->addWidget(editInjectionDelay);
        paramLayout->addWidget(labelScanTime);
        paramLayout->addWidget(editScanTime);
        paramLayout->addWidget(labelInjectionTime);
        paramLayout->addWidget(editInjectionTime);

        // 将布局添加到主垂直布局
        mainLayout->addLayout(topButtonLayout);
        mainLayout->addLayout(inputDisplayLayout);
        mainLayout->addLayout(paramLayout);

        // 设置布局
        page->setLayout(mainLayout);
    }


    else {
        // 其他页面的默认布局
        QVBoxLayout *layout = new QVBoxLayout(page);
        QLabel *label = new QLabel("这是页面 " + text, page);
        label->setAlignment(Qt::AlignCenter);
        layout->addWidget(label);
    }

    return page;
}

// 槽函数实现
void ManualModePage::switchToPageA()       { stackedWidget->setCurrentIndex(0); }
void ManualModePage::switchToPageB()       { stackedWidget->setCurrentIndex(1); }
void ManualModePage::switchToPageAB()      { stackedWidget->setCurrentIndex(2); }
void ManualModePage::switchToPageA1A2()    { stackedWidget->setCurrentIndex(3); }
void ManualModePage::switchToPageAA()      { stackedWidget->setCurrentIndex(4); }
void ManualModePage::switchToPageB1B2()    { stackedWidget->setCurrentIndex(5); }
void ManualModePage::switchToPageABB()     { stackedWidget->setCurrentIndex(6); }
void ManualModePage::switchToPageAABBB()   { stackedWidget->setCurrentIndex(7); }
void ManualModePage::switchToPageABHoldAB(){ stackedWidget->setCurrentIndex(8); }
