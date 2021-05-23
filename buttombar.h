#ifndef ButtomBar_H
#define ButtomBar_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QList>
#include <QString>
class QMouseEvent;
class QTimer;
class QMediaPlayer;
class QMediaPlaylist;
class ButtomBar : public QWidget
{
    Q_OBJECT
public:
    ButtomBar(QWidget *parent);

public:
    void setTextNumber(int number);

private:
    void layoutUI();
    void control();
    void initWord();
    void changeWord(const QString &word);

private:
    QLabel *buttomPic;
    QLabel *buttomWord;
    QTimer *textTimer;
    int textNumber;
    QMediaPlayer * player;
    QList<int> saveList;
    QList<QString> pageList;
    QMediaPlaylist *playList;

protected:
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void slotChangeText();
    void slotSavePressed();
    void slotLoadPressed();
    void slotQsavePressed();
    void slotQloadPressed();
    void slotAutoPressed();
    void slotSkipPressed();
    void slotSecedePressed();

signals:
    void signalMainPage();

};

#endif // ButtomBar_H
