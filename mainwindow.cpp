#include "mainwindow.h"
#include "mianwidget.h"
#include "ButtomBar.h"
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QInputDialog>
#include <QPushButton>
#include <iostream>

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
//    buttomBar->setGeometry(0, 540, 960, 238);

    firstChoose = new QPushButton(this);
    secondChoose = new QPushButton(this);
    firstChoose->setGeometry(300, 100, 330, 100);
    secondChoose->setGeometry(300, 250, 330, 100);
    firstChoose->setStyleSheet("QPushButton{font-size: 10px;text-align: center center}");
    secondChoose->setStyleSheet("QPushButton{font-size: 10px;text-align: center center}");
    firstChoose->hide();
    secondChoose->hide();
    buttomBar->setGeometry(0, 540, 960, 238);
    buttomBar->setMainWidget(mainWidget);

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
    changeViewTimer->start(1);
    player = new QMediaPlayer;
    connect(changeViewTimer, SIGNAL(timeout()), this, SLOT(slotChangeView()));
    connect(buttomBar, SIGNAL(signalMainPage()), this, SLOT(slotMainPage()));
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(slotRestartMusic(QMediaPlayer::State)));
    connect(buttomBar, SIGNAL(siganlChoose()), this, SLOT(slotChoose()));
    connect(firstChoose, SIGNAL(pressed()), this, SLOT(slotFinishChoose()));
    connect(secondChoose, SIGNAL(pressed()), this, SLOT(slotFinishChoose()));
}

void MainWindow::startGame()
{
    thridPic->hide();
    mainWidget->show();
    buttomBar->show();
}

void MainWindow::loadGame()
{
    bool ok = false;
    int inputValue = QInputDialog::getInt(NULL, "请选择读档序号", "vlaue:",
                                          1, -1, 40, 1, &ok);

    if (ok)
    {
        buttomBar->setTextNumber(inputValue);
        mainWidget->setcurPage(inputValue);
    }
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
        player->setMedia(QUrl::fromLocalFile("7.mp3"));
        player->setVolume(50);
        player->play();
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

void MainWindow::slotMainPage()
{
    secendPic->hide();
    firstPic->hide();
    buttomBar->hide();
    mainWidget->hide();
    thridPic->show();
}

void MainWindow::slotRestartMusic(QMediaPlayer::State newState)
{
    if(QMediaPlayer::State::StoppedState == newState)
    {
        player->setMedia(QUrl::fromLocalFile("7.mp3"));
        player->setVolume(50);
        player->play();
    }
}

void MainWindow::slotChoose()
{
    firstChoose->setText("车原来是指虎式坦克啊。");
    secondChoose->setText("军备设施民用真的好吗。");
    firstChoose->show();
    secondChoose->show();
}

void MainWindow::slotFinishChoose()
{
    firstChoose->hide();
    secondChoose->hide();
    buttomBar->setTextNumber(89);
}
