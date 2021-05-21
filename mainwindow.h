#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QList>
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

    QTimer *changeViewTimer;

public slots:
    void slotChangeView();
};

#endif // MainWindow_H
