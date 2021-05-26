#include "mianwidget.h"
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <QDebug>
#include <QMap>

struct GameImage
{
    QString people;
    QString background;
};

QMap<int, GameImage> pages =
{
    { 26, { "", "背景/天花板.jpg" } },
    { 27, { "人/配/NPC/护士？.png", "背景/医院病房(昼)_540.png" } },
    { 38, { "人/主/乔丹/乔丹 开心.png", "背景/医院病房(昼)_540.png" } },
    { 46, { "人/主/白芊/白芊 抽泣.png", "背景/医院病房(昼)_540.png" } },
    { 50, { "人/主/江珂/江珂 微怒.png", "背景/医院病房(昼)_540.png" } },
    { 56, { "人/主/猫/猫 开心.png" , "背景/医院病房(昼)_540.png" } },
    { 63, { "人/主/林瑾/林瑾 卖萌.png", "背景/医院病房(昼)_540.png" } },
    { 69, { "人/主/乔丹/乔丹 嫌弃.png", "背景/医院病房(昼)_540.png" } },
    { 70, { "人/主/林瑾/林瑾 卖萌.png", "背景/医院病房(昼)_540.png" } },
    { 71, { "人/主/乔丹/乔丹 生气.png", "背景/医院病房(昼)_540.png" } },
    { 77, { "人/主/白芊/白芊 无语.png", "背景/医院病房(昼)_540.png" } },
    { 78, { "人/主/江珂/江珂 无语.png", "背景/医院病房(昼)_540.png" } },
    { 79, { "人/主/白芊/白芊 假笑.png", "背景/医院病房(昼)_540.png" } },
    { 82, { "", "背景/医院走廊_540.jpg"} },
    { 87, { "", "背景/医院_540.png"} },
    { 88, { "人/配/队长 瑞雪.png", "" } },
    { 89, { "人/主/江珂/江珂 微怒.png", "背景/坦克.jpg" } },
    { 92, { "", "背景/街边_540.jpg" } },
    { 94, { "", "背景/马路上_540.jpg" } },
    { 95, { "人/配/NPC普通教徒.png", "背景/教堂（室外）昼_540.png"} },
    { 98, { "人/主/乔丹/乔丹 坏笑.png", "背景/车内.jpg" } },
    { 102, { "人/主/江珂/江珂 无语.png", "背景/车内.jpg" } },
    { 104, { "人/主/乔丹/乔丹 生气.png", "背景/车内.jpg" } },
    { 105, { "人/主/林瑾/林瑾 困扰.png", "背景/车内.jpg" } },
    { 106, { "人/主/乔丹/乔丹 生气.png", "背景/车内.jpg" } },
    { 107, { "人/主/林瑾/林瑾 暴怒.png", "背景/车内.jpg"} },
    { 108, { "人/主/江珂/江珂 无语.png", "背景/车内.jpg" } },
    { 109, { "人/主/白芊/白芊 无语.png", "背景/车内.jpg" } },
    { 110, { "人/主/猫/猫 撒娇.png", "背景/车内.jpg" } },
    { 112, { "人/主/乔丹/乔丹 淫笑.png", "背景/车内.jpg" } },
    { 115, { "人/主/乔丹/乔丹 淫笑.png", "背景/车内.jpg" } },
    { 118, { "", "背景/校园空地-白天_540.jpg" } },
    { 119, { "人/主/白芊/白芊 抽泣.png", "背景/校园空地-白天_540.jpg"} },
    { 121, { "人/主/江珂/江珂 无语.png", "背景/校园空地-白天_540.jpg"} }
};

MainWidget::MainWidget(QWidget *parent): QWidget(parent), backgroundLabel(NULL), peopleLable(NULL), pageTimer(NULL), curPage(0)
{
    layoutUI();
    control();
}

void MainWidget::setcurPage(int page)
{
    curPage = page;
    if (pages.contains(curPage))
    {
        auto img = pages[curPage];
        if (img.people.length() > 0)
        {
            auto peopleQSS = QString("QLabel{image:url(") + img.people + QString(");}");
            peopleLable->setStyleSheet(peopleQSS);
            peopleLable->show();
        }
        else
        {
            peopleLable->hide();
        }

        auto bgQSS = QString("QLabel{image:url(") + img.background + QString(");}");
        backgroundLabel->setStyleSheet(bgQSS);
        backgroundLabel->show();
    }

    qDebug() << "show background label";
    update();
}

void MainWidget::layoutUI()
{
    backgroundLabel = new QLabel(this);
    peopleLable = new QLabel(this);

    peopleLable->setGeometry(0, 0, 300, 540);
    backgroundLabel->setGeometry(0, 0, 960, 540);
}

void MainWidget::control()
{
    peopleLable->hide();
    backgroundLabel->hide();
}
