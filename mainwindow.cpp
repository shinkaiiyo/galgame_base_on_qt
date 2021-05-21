#include "mainwindow.h"
#include "mianwidget.h"
#include "ButtomBar.h"
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    layoutUI();
    control();
}

MainWindow::~MainWindow()
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        return;
    }
    if(thridPic->isVisible())
    {
        if(event->x() <= 422 && event->y() <= 298 && event->x() >= 53 && event->y() >= 230)
        {
            startGame();
        }
        else if(event->x() <= 422 && event->y() <= 384 && event->x() >= 53 && event->y() >= 315)
        {
            loadGame();
        }
        else if(event->x() <= 422 && event->y() <= 469 && event->x() >= 53 && event->y() >= 401)
        {
            extra();
        }
        else if(event->x() <= 422 && event->y() <= 553 && event->x() >= 53 && event->y() >= 487)
        {
            config();
        }
        else if(event->x() <= 422 && event->y() <= 640 && event->x() >= 53 && event->y() >= 570)
        {
            exitGame();
        }
    }
}

void MainWindow::layoutUI()
{
    setGeometry(0, 0, 960, 778);

    firstPic = new QLabel(this);
    secendPic = new QLabel(this);
    thridPic = new QLabel(this);

    firstPic->setGeometry(0, 0, 960, 677);
    secendPic->setGeometry(0, 0, 960, 677);
    thridPic->setGeometry(0, 0, 960, 677);

    mainWidget = new MainWidget(this);
    buttomBar = new ButtomBar(this);

    mainWidget->setGeometry(0, 0, 960, 540);
    buttomBar->setGeometry(0, 540, 960, 238);

    firstPic->setStyleSheet("QLabel{image:url(logginpage/1.jpg);}");
    secendPic->setStyleSheet("QLabel{image:url(logginpage/2.jpg);}");
    thridPic->setStyleSheet("QLabel{image:url(logginpage/3.png);}");
    mainWidget->hide();
    buttomBar->hide();
    firstPic->show();
    secendPic->hide();
    thridPic->hide();
}

void MainWindow::control()
{
    changeViewTimer = new QTimer(this);
    changeViewTimer->start(10000);
    connect(changeViewTimer, SIGNAL(timeout()), this, SLOT(slotChangeView()));
}

void MainWindow::startGame()
{
    thridPic->hide();
    mainWidget->show();
    buttomBar->show();
    buttomBar->startTimer(10000);
}

void MainWindow::loadGame()
{
    //TODO
}

void MainWindow::extra()
{
    //TODO
}

void MainWindow::config()
{
    //TODO
}

void MainWindow::exitGame()
{
    exit(0);
}

void MainWindow::slotChangeView()
{
    if(firstPic->isVisible())
    {
        firstPic->hide();
        secendPic->show();
    }
    else
    {
        if(secendPic->isVisible())
        {
            secendPic->hide();
            thridPic->show();
            changeViewTimer->stop();
        }
    }
}
