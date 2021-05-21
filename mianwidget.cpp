#include "mianwidget.h"
#include <QLabel>

MainWidget::MainWidget(QWidget *parent): QWidget(parent), backgroundLabel(NULL), peopleLable(NULL), pageTimer(NULL), curPage(0)
{
    layoutUI();
    control();
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
