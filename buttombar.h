#ifndef ButtomBar_H
#define ButtomBar_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QString>
class QLabel;
class QMouseEvent;
class QTimer;
class QMediaPlayer;
class ButtomBar : public QWidget
{
    Q_OBJECT
public:
    ButtomBar(QWidget *parent);

public:  
    void startTimer(int interval);

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

};

#endif // ButtomBar_H
