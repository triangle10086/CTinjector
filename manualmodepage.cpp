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

    if (text == "A-B") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);
        mainLayout->setSpacing(20); // 设置整体行距

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

        // 注射速率和注射量布局（同一行）
        QHBoxLayout *rateVolumeLayout = new QHBoxLayout();
        QLabel *labelRate = new QLabel("注射速率", page);
        QLabel *labelVolume = new QLabel("注射量", page);

        // 设置标签字体大小
        QFont font = labelRate->font();
        font.setPointSize(24); // 设置字体大小为 24
        labelRate->setFont(font);
        labelVolume->setFont(font);

        // 设置标签大小
        labelRate->setMinimumSize(100, 30); // 设置注射速率标签大小
        labelVolume->setMinimumSize(100, 30); // 设置注射量标签大小

        // 添加间距，将标签往右边移动
        rateVolumeLayout->addSpacing(120); // 添加左边间距
        rateVolumeLayout->addWidget(labelRate);
        rateVolumeLayout->addSpacing(120); // 添加间距
        rateVolumeLayout->addWidget(labelVolume);
        // 输入框布局（两行）
        QVBoxLayout *inputLayout = new QVBoxLayout();

        // 第一行输入框
        QHBoxLayout *inputRow1Layout = new QHBoxLayout();
        QLabel *labelA = new QLabel("A", page);
        QLineEdit *editRateA = new QLineEdit(page);
        QLineEdit *editVolumeA = new QLineEdit(page);

        editRateA->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeA->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow1Layout->addWidget(labelA);
        inputRow1Layout->addWidget(editRateA);
        inputRow1Layout->addWidget(editVolumeA);

        // 第二行输入框
        QHBoxLayout *inputRow2Layout = new QHBoxLayout();
        QLabel *labelB = new QLabel("B", page);
        QLineEdit *editRateB = new QLineEdit(page);
        QLineEdit *editVolumeB = new QLineEdit(page);

        editRateB->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeB->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow2Layout->addWidget(labelB);
        inputRow2Layout->addWidget(editRateB);
        inputRow2Layout->addWidget(editVolumeB);

        // 将两行输入框添加到布局
        inputLayout->addLayout(inputRow1Layout);
        inputLayout->addLayout(inputRow2Layout);

        // 显示区域（进度条）
        QVBoxLayout *displayLayout = new QVBoxLayout();
        displayLayout->setSpacing(20); // 设置行距

        // A 进度条
        QHBoxLayout *progressLayoutA = new QHBoxLayout();
        QProgressBar *progressBarA = new QProgressBar(page);
        progressBarA->setMinimum(0);
        progressBarA->setMaximum(100);
        progressBarA->setValue(50); // 设置初始值
        progressBarA->setTextVisible(false); // 隐藏默认百分比显示
        progressBarA->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #4CAF50; }"); // 设置进度条样式

        QLabel *labelProgressA = new QLabel("A: 50/100", page); // 显示剩余容量/总容量
        progressLayoutA->addWidget(labelProgressA); // 标签放在左边
        progressLayoutA->addWidget(progressBarA);
        displayLayout->addLayout(progressLayoutA);

        // B 进度条
        QHBoxLayout *progressLayoutB = new QHBoxLayout();
        QProgressBar *progressBarB = new QProgressBar(page);
        progressBarB->setMinimum(0);
        progressBarB->setMaximum(100);
        progressBarB->setValue(30); // 设置初始值
        progressBarB->setTextVisible(false); // 隐藏默认百分比显示
        progressBarB->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #2196F3; }"); // 设置进度条样式

        QLabel *labelProgressB = new QLabel("B: 30/100", page); // 显示剩余容量/总容量
        progressLayoutB->addWidget(labelProgressB); // 标签放在左边
        progressLayoutB->addWidget(progressBarB);
        displayLayout->addLayout(progressLayoutB);

        // 其他参数布局（压力限制、注射延迟、扫描时间、注射时间）
        QHBoxLayout *paramLayout = new QHBoxLayout();
        paramLayout->setSpacing(10); // 设置行距

        QLabel *labelPressureLimit = new QLabel("压力限制", page);
        QLabel *labelInjectionDelay = new QLabel("注射延迟", page);
        QLabel *labelScanTime = new QLabel("扫描时间", page);
        QLabel *labelInjectionTime = new QLabel("注射时间", page);

        QLineEdit *editPressureLimit = new QLineEdit(page);
        QLineEdit *editInjectionDelay = new QLineEdit(page);
        QLineEdit *editScanTime = new QLineEdit(page);
        QLineEdit *editInjectionTime = new QLineEdit(page);

        // 设置输入框大小（缩小长度）
        editPressureLimit->setMinimumSize(80, 30);
        editInjectionDelay->setMinimumSize(80, 30);
        editScanTime->setMinimumSize(80, 30);
        editInjectionTime->setMinimumSize(80, 30);

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
        mainLayout->addLayout(rateVolumeLayout);
        mainLayout->addLayout(inputLayout);
        mainLayout->addLayout(displayLayout);
        mainLayout->addLayout(paramLayout);

        // 设置布局
        page->setLayout(mainLayout);
    }

    else if (text == "A") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);
        mainLayout->setSpacing(20); // 设置整体行距

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

        // 注射速率和注射量布局
        QHBoxLayout *rateVolumeLayout = new QHBoxLayout();
        QLabel *labelRate = new QLabel("注射速率", page);
        QLabel *labelVolume = new QLabel("注射量", page);

        // 设置标签字体大小
        QFont font = labelRate->font();
        font.setPointSize(24); // 设置字体大小为 24
        labelRate->setFont(font);
        labelVolume->setFont(font);

        // 设置标签大小
        labelRate->setMinimumSize(100, 30); // 设置注射速率标签大小
        labelVolume->setMinimumSize(100, 30); // 设置注射量标签大小

        // 添加间距，将标签往右边移动
        rateVolumeLayout->addSpacing(120); // 添加左边间距
        rateVolumeLayout->addWidget(labelRate);
        rateVolumeLayout->addSpacing(120); // 添加间距
        rateVolumeLayout->addWidget(labelVolume);
        // 输入框布局（两行）
        QVBoxLayout *inputLayout = new QVBoxLayout();

        // 第一行输入框
        QHBoxLayout *inputRow1Layout = new QHBoxLayout();
        QLabel *labelA = new QLabel("A", page);
        QLineEdit *editRateA = new QLineEdit(page);
        QLineEdit *editVolumeA = new QLineEdit(page);

        editRateA->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeA->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow1Layout->addWidget(labelA);
        inputRow1Layout->addWidget(editRateA);
        inputRow1Layout->addWidget(editVolumeA);

        // 将两行输入框添加到布局
        inputLayout->addLayout(inputRow1Layout);

        // 显示区域（进度条）
        QVBoxLayout *displayLayout = new QVBoxLayout();
        displayLayout->setSpacing(20); // 设置行距

        // A 进度条
        QHBoxLayout *progressLayoutA = new QHBoxLayout();
        QProgressBar *progressBarA = new QProgressBar(page);
        progressBarA->setMinimum(0);
        progressBarA->setMaximum(100);
        progressBarA->setValue(50); // 设置初始值
        progressBarA->setTextVisible(false); // 隐藏默认百分比显示
        progressBarA->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #4CAF50; }"); // 设置进度条样式

        QLabel *labelProgressA = new QLabel("A: 50/100", page); // 显示剩余容量/总容量
        progressLayoutA->addWidget(labelProgressA); // 标签放在左边
        progressLayoutA->addWidget(progressBarA);
        displayLayout->addLayout(progressLayoutA);


        // 其他参数布局（压力限制、注射延迟、扫描时间、注射时间）
        QHBoxLayout *paramLayout = new QHBoxLayout();
        paramLayout->setSpacing(10); // 设置行距

        QLabel *labelPressureLimit = new QLabel("压力限制", page);
        QLabel *labelInjectionDelay = new QLabel("注射延迟", page);
        QLabel *labelScanTime = new QLabel("扫描时间", page);
        QLabel *labelInjectionTime = new QLabel("注射时间", page);

        QLineEdit *editPressureLimit = new QLineEdit(page);
        QLineEdit *editInjectionDelay = new QLineEdit(page);
        QLineEdit *editScanTime = new QLineEdit(page);
        QLineEdit *editInjectionTime = new QLineEdit(page);

        // 设置输入框大小（缩小长度）
        editPressureLimit->setMinimumSize(80, 30);
        editInjectionDelay->setMinimumSize(80, 30);
        editScanTime->setMinimumSize(80, 30);
        editInjectionTime->setMinimumSize(80, 30);

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
        mainLayout->addSpacing(10); // 添加行距
        mainLayout->addLayout(rateVolumeLayout);
        mainLayout->addSpacing(10); // 添加行距
        mainLayout->addLayout(inputLayout);
        mainLayout->addSpacing(20); // 添加行距
        mainLayout->addLayout(displayLayout);
        mainLayout->addSpacing(20); // 添加行距
        mainLayout->addLayout(paramLayout);

        // 设置布局
        page->setLayout(mainLayout);
    }

    else     if (text == "B") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);
        mainLayout->setSpacing(20); // 设置整体行距

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

        // 注射速率和注射量布局（同一行）
        QHBoxLayout *rateVolumeLayout = new QHBoxLayout();
        QLabel *labelRate = new QLabel("注射速率", page);
        QLabel *labelVolume = new QLabel("注射量", page);

        // 设置标签字体大小
        QFont font = labelRate->font();
        font.setPointSize(24); // 设置字体大小为 24
        labelRate->setFont(font);
        labelVolume->setFont(font);

        // 设置标签大小
        labelRate->setMinimumSize(100, 30); // 设置注射速率标签大小
        labelVolume->setMinimumSize(100, 30); // 设置注射量标签大小

        // 添加间距，将标签往右边移动
        rateVolumeLayout->addSpacing(120); // 添加左边间距
        rateVolumeLayout->addWidget(labelRate);
        rateVolumeLayout->addSpacing(120); // 添加间距
        rateVolumeLayout->addWidget(labelVolume);
        // 输入框布局（两行）
        QVBoxLayout *inputLayout = new QVBoxLayout();

        // 第二行输入框
        QHBoxLayout *inputRow2Layout = new QHBoxLayout();
        QLabel *labelB = new QLabel("B", page);
        QLineEdit *editRateB = new QLineEdit(page);
        QLineEdit *editVolumeB = new QLineEdit(page);

        editRateB->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeB->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow2Layout->addWidget(labelB);
        inputRow2Layout->addWidget(editRateB);
        inputRow2Layout->addWidget(editVolumeB);

        // 将两行输入框添加到布局
        inputLayout->addLayout(inputRow2Layout);

        // 显示区域（进度条）
        QVBoxLayout *displayLayout = new QVBoxLayout();
        displayLayout->setSpacing(20); // 设置行距

        // B 进度条
        QHBoxLayout *progressLayoutB = new QHBoxLayout();
        QProgressBar *progressBarB = new QProgressBar(page);
        progressBarB->setMinimum(0);
        progressBarB->setMaximum(100);
        progressBarB->setValue(30); // 设置初始值
        progressBarB->setTextVisible(false); // 隐藏默认百分比显示
        progressBarB->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #2196F3; }"); // 设置进度条样式

        QLabel *labelProgressB = new QLabel("B: 30/100", page); // 显示剩余容量/总容量
        progressLayoutB->addWidget(labelProgressB); // 标签放在左边
        progressLayoutB->addWidget(progressBarB);
        displayLayout->addLayout(progressLayoutB);

        // 其他参数布局（压力限制、注射延迟、扫描时间、注射时间）
        QHBoxLayout *paramLayout = new QHBoxLayout();
        paramLayout->setSpacing(10); // 设置行距

        QLabel *labelPressureLimit = new QLabel("压力限制", page);
        QLabel *labelInjectionDelay = new QLabel("注射延迟", page);
        QLabel *labelScanTime = new QLabel("扫描时间", page);
        QLabel *labelInjectionTime = new QLabel("注射时间", page);

        QLineEdit *editPressureLimit = new QLineEdit(page);
        QLineEdit *editInjectionDelay = new QLineEdit(page);
        QLineEdit *editScanTime = new QLineEdit(page);
        QLineEdit *editInjectionTime = new QLineEdit(page);

        // 设置输入框大小（缩小长度）
        editPressureLimit->setMinimumSize(80, 30);
        editInjectionDelay->setMinimumSize(80, 30);
        editScanTime->setMinimumSize(80, 30);
        editInjectionTime->setMinimumSize(80, 30);

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
        mainLayout->addSpacing(10); // 添加行距
        mainLayout->addLayout(rateVolumeLayout);
        mainLayout->addSpacing(10); // 添加行距
        mainLayout->addLayout(inputLayout);
        mainLayout->addSpacing(20); // 添加行距
        mainLayout->addLayout(displayLayout);
        mainLayout->addSpacing(20); // 添加行距
        mainLayout->addLayout(paramLayout);

        // 设置布局
        page->setLayout(mainLayout);
    }

    else    if (text == "A1>A2") {
        // 主垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(page);
        mainLayout->setSpacing(20); // 设置整体行距

        // 顶部按钮布局
        QHBoxLayout *topButtonLayout = new QHBoxLayout();
        QPushButton *btnTestNeedle = new QPushButton("试针", page);
        QPushButton *btnGroupInjection = new QPushButton("团注", page);
        QPushButton *btnSuction = new QPushButton("吸药", page);
        QLabel *labelInjectionMode = new QLabel("注射模式：A1>A2", page);
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

        // 注射速率和注射量布局（同一行）
        QHBoxLayout *rateVolumeLayout = new QHBoxLayout();
        QPushButton *holdButton = new QPushButton("Hold");
        holdButton->setCheckable(true);  // 设为可切换
        holdButton->setChecked(false);  // 初始状态
        QLabel *labelRate = new QLabel("注射速率", page);
        QLabel *labelVolume = new QLabel("注射量", page);

        // 设置标签字体大小
        QFont font = labelRate->font();
        font.setPointSize(24); // 设置字体大小为 24
        labelRate->setFont(font);
        labelVolume->setFont(font);

        // 设置标签大小
        labelRate->setMinimumSize(100, 30); // 设置注射速率标签大小
        labelVolume->setMinimumSize(100, 30); // 设置注射量标签大小

        // 添加间距，将标签往右边移动
        rateVolumeLayout->addWidget(holdButton);
        rateVolumeLayout->addSpacing(120); // 添加左边间距
        rateVolumeLayout->addWidget(labelRate);
        rateVolumeLayout->addSpacing(120); // 添加间距
        rateVolumeLayout->addWidget(labelVolume);
        // 输入框布局（两行）
        QVBoxLayout *inputLayout = new QVBoxLayout();

        // 第一行输入框
        QHBoxLayout *inputRow1Layout = new QHBoxLayout();
        QLabel *labelA = new QLabel("A1", page);
        QLineEdit *editRateA = new QLineEdit(page);
        QLineEdit *editVolumeA = new QLineEdit(page);

        editRateA->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeA->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow1Layout->addWidget(labelA);
        inputRow1Layout->addWidget(editRateA);
        inputRow1Layout->addWidget(editVolumeA);

        // 第二行输入框
        QHBoxLayout *inputRow2Layout = new QHBoxLayout();
        QLabel *labelB = new QLabel("A2", page);
        QLineEdit *editRateB = new QLineEdit(page);
        QLineEdit *editVolumeB = new QLineEdit(page);

        editRateB->setMinimumSize(10, 30); // 缩小输入框长度
        editVolumeB->setMinimumSize(10, 30); // 缩小输入框长度

        inputRow2Layout->addWidget(labelB);
        inputRow2Layout->addWidget(editRateB);
        inputRow2Layout->addWidget(editVolumeB);

        // 将两行输入框添加到布局
        inputLayout->addLayout(inputRow1Layout);
        inputLayout->addLayout(inputRow2Layout);

        // 显示区域（进度条）
        QVBoxLayout *displayLayout = new QVBoxLayout();
        displayLayout->setSpacing(20); // 设置行距

        // A1 进度条
        QHBoxLayout *progressLayoutA = new QHBoxLayout();
        QProgressBar *progressBarA = new QProgressBar(page);
        progressBarA->setMinimum(0);
        progressBarA->setMaximum(100);
        progressBarA->setValue(50); // 设置初始值
        progressBarA->setTextVisible(false); // 隐藏默认百分比显示
        progressBarA->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #4CAF50; }"); // 设置进度条样式

        QLabel *labelProgressA = new QLabel("A1: 50/100", page); // 显示剩余容量/总容量
        progressLayoutA->addWidget(labelProgressA); // 标签放在左边
        progressLayoutA->addWidget(progressBarA);
        displayLayout->addLayout(progressLayoutA);

        // A2 进度条
        QHBoxLayout *progressLayoutB = new QHBoxLayout();
        QProgressBar *progressBarB = new QProgressBar(page);
        progressBarB->setMinimum(0);
        progressBarB->setMaximum(100);
        progressBarB->setValue(30); // 设置初始值
        progressBarB->setTextVisible(false); // 隐藏默认百分比显示
        progressBarB->setStyleSheet("QProgressBar { border: 1px solid grey; border-radius: 5px; background: white; }"
                                    "QProgressBar::chunk { background-color: #2196F3; }"); // 设置进度条样式

        QLabel *labelProgressB = new QLabel("A2: 30/100", page); // 显示剩余容量/总容量
        progressLayoutB->addWidget(labelProgressB); // 标签放在左边
        progressLayoutB->addWidget(progressBarB);
        displayLayout->addLayout(progressLayoutB);

        // 其他参数布局（压力限制、注射延迟、扫描时间、注射时间）
        QHBoxLayout *paramLayout = new QHBoxLayout();
        paramLayout->setSpacing(10); // 设置行距

        QLabel *labelPressureLimit = new QLabel("压力限制", page);
        QLabel *labelInjectionDelay = new QLabel("注射延迟", page);
        QLabel *labelScanTime = new QLabel("扫描时间", page);
        QLabel *labelInjectionTime = new QLabel("注射时间", page);

        QLineEdit *editPressureLimit = new QLineEdit(page);
        QLineEdit *editInjectionDelay = new QLineEdit(page);
        QLineEdit *editScanTime = new QLineEdit(page);
        QLineEdit *editInjectionTime = new QLineEdit(page);

        // 设置输入框大小（缩小长度）
        editPressureLimit->setMinimumSize(80, 30);
        editInjectionDelay->setMinimumSize(80, 30);
        editScanTime->setMinimumSize(80, 30);
        editInjectionTime->setMinimumSize(80, 30);

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
        mainLayout->addLayout(rateVolumeLayout);
        mainLayout->addLayout(inputLayout);
        mainLayout->addLayout(displayLayout);
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
