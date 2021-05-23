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
class QPushButton;
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
    QPushButton *firstChoose;
    QPushButton *secondChoose;

public slots:
    void slotChangeView();
    void slotMainPage();
    void slotRestartMusic(QMediaPlayer::State newState);
    void slotChoose();
    void slotFinishChoose();
};

#endif // MainWindow_H
