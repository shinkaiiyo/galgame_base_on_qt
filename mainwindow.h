#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QList>
#include <QMediaPlayer>
class QLabel;
class QTimer;
class QMouseEvent;
class MainWidget;
class ButtomBar;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void layoutUI();
    void control();
    void startGame();
    void loadGame();
    void extra();
    void config();
    void exitGame();

private:
    QLabel *firstPic;
    QLabel *secendPic;
    QLabel *thridPic;
    QList<int> saveList;
    QList<int> pageList;

    MainWidget *mainWidget;
    ButtomBar *buttomBar;
    QMediaPlayer * player;
    QTimer *changeViewTimer;

public slots:
    void slotChangeView();
    void slotMainPage();
    void slotRestartMusic(QMediaPlayer::State newState);
};

#endif // MainWindow_H
