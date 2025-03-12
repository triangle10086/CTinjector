#include "weightmodepage.h"
#include <QDebug>

WeightModePage::WeightModePage(QWidget *parent)
    : QWidget{parent}
{
    // 主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 第一行：试针、团注、吸药、智能注射模式标签、启动中/完成、启动按钮
    QHBoxLayout *topButtonLayout = new QHBoxLayout();
    topButtonLayout->addWidget(new QPushButton("试针"));
    topButtonLayout->addWidget(new QPushButton("团注"));
    topButtonLayout->addWidget(new QPushButton("吸药"));
    topButtonLayout->addWidget(new QLabel("智能注射模式"));
    topButtonLayout->addWidget(new QLabel("启动中/完成"));
    topButtonLayout->addWidget(new QPushButton("启动"));
    mainLayout->addLayout(topButtonLayout);

    // 第二行：分为两个垂直布局
    QHBoxLayout *secondRowLayout = new QHBoxLayout();

    // 第一个垂直布局：头部、颈部、胸部、腹部、下肢按钮
    QVBoxLayout *leftButtonLayout = new QVBoxLayout();
    leftButtonLayout->setSpacing(0); // 设置按钮间距为0

    QPushButton *headButton = new QPushButton("头部");
    QPushButton *neckButton = new QPushButton("颈部");
    QPushButton *chestButton = new QPushButton("胸部");
    QPushButton *abdomenButton = new QPushButton("腹部");
    QPushButton *lowerExtremityButton = new QPushButton("下肢");

    leftButtonLayout->addWidget(headButton);
    leftButtonLayout->addWidget(neckButton);
    leftButtonLayout->addWidget(chestButton);
    leftButtonLayout->addWidget(abdomenButton);
    leftButtonLayout->addWidget(lowerExtremityButton);

    // 第二个垂直布局：肿瘤和血管界面
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(createTumorPage());  // 添加肿瘤界面
    stackedWidget->addWidget(createVesselPage()); // 添加血管界面

    // 将两个垂直布局添加到第二行
    secondRowLayout->addLayout(leftButtonLayout);
    secondRowLayout->addWidget(stackedWidget);

    // 将第二行添加到主布局
    mainLayout->addLayout(secondRowLayout);

    // 连接信号槽
    connect(headButton, &QPushButton::clicked, this, &WeightModePage::onHeadClicked);
}

// 创建肿瘤界面
QWidget* WeightModePage::createTumorPage() {
    QWidget *page = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(page);

    // 模式标签和体重、造影剂浓度按钮
    QHBoxLayout *modeLayout = new QHBoxLayout();
    modeLayout->addWidget(new QLabel("模式：头部-肿瘤"));

    // 体重输入框
    QHBoxLayout *weightLayout = new QHBoxLayout();
    weightLayout->addWidget(new QLabel("体重"));
    weightLayout->addWidget(new QLineEdit());
    modeLayout->addLayout(weightLayout);

    // 造影剂浓度输入框
    QHBoxLayout *contrastLayout = new QHBoxLayout();
    contrastLayout->addWidget(new QLabel("造影剂浓度"));
    contrastLayout->addWidget(new QLineEdit());
    modeLayout->addLayout(contrastLayout);

    layout->addLayout(modeLayout);

    // 注射速率和注射浓度标签
    QHBoxLayout *rateConcentrationLayout = new QHBoxLayout();
    rateConcentrationLayout->addWidget(new QLabel("注射速率"));
    rateConcentrationLayout->addWidget(new QLabel("注射浓度"));
    layout->addLayout(rateConcentrationLayout);

    // 输入框
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(new QLabel("A"));
    inputLayout->addWidget(new QLineEdit());
    inputLayout->addWidget(new QLineEdit());
    layout->addLayout(inputLayout);

    // 进度条
    QHBoxLayout *progressLayout = new QHBoxLayout();
    progressLayout->addWidget(new QLabel("A"));
    QProgressBar *progressBar = new QProgressBar();
    progressBar->setValue(50); // 设置初始值
    progressLayout->addWidget(progressBar);
    layout->addLayout(progressLayout);

    // 压力限制、注射延迟、扫描时间、注射时间按钮
    QHBoxLayout *paramLayout = new QHBoxLayout();
    paramLayout->addWidget(new QLabel("压力限制"));
    paramLayout->addWidget(new QLineEdit());
    paramLayout->addWidget(new QLabel("注射延迟"));
    paramLayout->addWidget(new QLineEdit());
    paramLayout->addWidget(new QLabel("扫描时间"));
    paramLayout->addWidget(new QLineEdit());
    paramLayout->addWidget(new QLabel("注射时间"));
    paramLayout->addWidget(new QLineEdit());
    layout->addLayout(paramLayout);

    return page;
}

// 创建血管界面
QWidget* WeightModePage::createVesselPage() {
    QWidget *page = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(page);

    // 添加标签
    layout->addWidget(new QLabel("这是血管的注射界面"));

    return page;
}

// 头部按钮点击事件
void WeightModePage::onHeadClicked() {
    if (!optionsWidget) {
        // 创建血管和肿瘤选项
        optionsWidget = new QWidget();
        QHBoxLayout *optionsLayout = new QHBoxLayout(optionsWidget);
        QPushButton *tumorButton = new QPushButton("肿瘤");
        QPushButton *vesselButton = new QPushButton("血管");
        optionsLayout->addWidget(tumorButton);
        optionsLayout->addWidget(vesselButton);

        // 将选项添加到头部按钮的右侧
        QHBoxLayout *headLayout = qobject_cast<QHBoxLayout*>(this->layout()->itemAt(1)->layout()->itemAt(0)->layout());
        headLayout->addWidget(optionsWidget);

        // 连接信号槽
        connect(tumorButton, &QPushButton::clicked, this, &WeightModePage::onTumorClicked);
        connect(vesselButton, &QPushButton::clicked, this, &WeightModePage::onVesselClicked);
    }
}

// 肿瘤选项点击事件
void WeightModePage::onTumorClicked() {
    stackedWidget->setCurrentIndex(0); // 切换到肿瘤界面
}

// 血管选项点击事件
void WeightModePage::onVesselClicked() {
    stackedWidget->setCurrentIndex(1); // 切换到血管界面


}
