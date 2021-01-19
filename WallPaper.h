#pragma once
#include <QtWidgets/QWidget>
#include "ui_WallPaper.h"
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QRect>
#include "SettingWidget.h"
#include <QtMultimedia/QMediaPlayer>
#include <QtMultiMediaWidgets/QVideoWidget>
#include <QtMultiMedia/QMediaPlaylist>
#include <QUrl>
#include <QEvent>
#include <Windows.h>


class WallPaper : public QWidget {
    Q_OBJECT

public:
    WallPaper(QWidget *parent = Q_NULLPTR);
    ~WallPaper();
private:
    Ui::WallPaperClass ui;

    QPoint startCoor;
    QSystemTrayIcon *systemTray;

    bool isDraging;
    SettingWidget *settingWidget;
    QString myStyleSheet;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *playlist;

    void iniUi();
    void iniStyleSheet();
    void iniConnect();
    void iniSystemTray();


private slots:
    void onBtnMinimiseClicked();
    void onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason);
    void onBtnSettingClicked();
    void onSelectImage(QString *fileName);
    void onSelectWallPaper(QString *fileName);

protected:
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;

    void enterEvent(QEvent *event)override;
    void leaveEvent(QEvent *event)override;

};
