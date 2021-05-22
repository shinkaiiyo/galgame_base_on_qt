#ifndef MianWidget_H
#define MianWidget_H

#include <QObject>
#include <QWidget>

#include <QList>

class QLabel;
class QTimer;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent);

public:
    void setcurPage(int page);

private:
    void layoutUI();
    void control();

private:
    QLabel *peopleLable;
    QLabel *backgroundLabel;
    QTimer *pageTimer;
    int curPage;
    QList<int> saveList;

};

#endif //MianWidgett_H
