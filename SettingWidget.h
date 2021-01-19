#pragma once

#include <QtWidgets/QWidget>
#include "ui_SettingWidget.h"
#include <QFileDialog>
#include <QString>


class SettingWidget : public QWidget {
    Q_OBJECT
public:
    SettingWidget(QWidget*parent=Q_NULLPTR);

private:
    Ui::SettingWidgetClass ui;

    void iniUi();
    void iniConnect();

signals:
    void selectImage(QString *fileName);
    void selectWallPaper(QString *fileName);

private slots:
    void onBtnSelectImage();
    void onBtnSelectWallPaper();
};