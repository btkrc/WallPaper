#include "SettingWidget.h"
SettingWidget::SettingWidget(QWidget *parent)
    :QWidget(parent) {
    ui.setupUi(this);
    iniUi();
    iniConnect();
}

void SettingWidget::iniUi() {
    /*设置此属性，此指针指向的内存在关闭时会自动释放*/
    setAttribute(Qt::WA_DeleteOnClose);
    setStyleSheet("#widget{background-color:rgba(0,0,0,0.5);border-radius:10px;}\
QPushButton{color:orange;background-color:black;border-radius:10px;}");
}

void SettingWidget::iniConnect() {
    QObject::connect(ui.btnSelectImage, SIGNAL(clicked()), this, SLOT(onBtnSelectImage()));
    QObject::connect(ui.btnSelectWallPaper,SIGNAL(clicked()), this, SLOT(onBtnSelectWallPaper()));
}

void SettingWidget::onBtnSelectWallPaper(){
    QString fileName("");//直接构造，不使用拷贝构造
    fileName = QFileDialog::getOpenFileName(this, QString(QStringLiteral("选择一个视频")), 
        "../" + QApplication::applicationDirPath(),
        "image (*.mp4;*.avi;*.wmv)");
    if (fileName != "")
        emit selectWallPaper(&fileName);
    else
        emit selectWallPaper(nullptr);

}

void SettingWidget::onBtnSelectImage() {
    /*如果用户取消，则发送一个空指针*/
    QString fileName("");
    fileName = QFileDialog::getOpenFileName(this, QString(QStringLiteral("只支持png格式")), "", "image (*.png)");
    if (fileName != "")
        emit selectImage(&fileName);
    else
        emit selectImage(nullptr);
}
