#ifndef MianWidget_H
#define MianWidget_H

#include <QObject>
#include <QWidget>

class QLabel;
class QTimer;
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent);

protected:

private:
    void layoutUI();
    void control();

private:
    QLabel *peopleLable;
    QLabel *backgroundLabel;
    QTimer *pageTimer;
    int curPage;

};

#endif //MianWidgett_H
