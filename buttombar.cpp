#include "ButtomBar.h"
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>
#include <QList>
#include <QMediaPlayer>
#include <QUrl>
#include <QInputDialog>

ButtomBar::ButtomBar(QWidget *parent): QWidget(parent), buttomPic(NULL), buttomWord(NULL),
    textTimer(NULL), textNumber(0), player(NULL)
{
    layoutUI();
    control();
}

void ButtomBar::startTimer(int interval)
{
    textTimer->start(interval);
}

void ButtomBar::layoutUI()
{
    buttomPic = new QLabel(this);
    buttomWord = new QLabel(this);
    buttomPic->setGeometry(0, 0, 960, 238);
    buttomWord->setGeometry(238, 25, 800, 100);
}

void ButtomBar::control()
{
    textTimer = new QTimer(this);
    player = new QMediaPlayer(this);
    connect(textTimer, SIGNAL(timeout()), this, SLOT(slotChangeText()));
}

void ButtomBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        return;
    }
    if(event->x() <= 332 && event->y() <= 232 && event->x() >= 244 && event->y() >= 214)
    {
        slotSavePressed();
    }
    else if(event->x() <= 434 && event->y() <= 232 && event->x() >= 347 && event->y() >= 214)
    {
        slotLoadPressed();
    }
    else if(event->x() <= 539 && event->y() <= 232 && event->x() >= 450 && event->y() >= 214)
    {
        slotQsavePressed();
    }
    else if(event->x() <= 641 && event->y() <= 232 && event->x() >= 553 && event->y() >= 214)
    {
        slotQloadPressed();
    }
    else if(event->x() <= 744 && event->y() <= 232 && event->x() >= 656 && event->y() >= 214)
    {
        slotAutoPressed();
    }
    else if(event->x() <= 880 && event->y() <= 232 && event->x() >= 759 && event->y() >= 214)
    {
        slotSkipPressed();
    }
    else if(event->x() <= 824 && event->y() <= 232 && event->x() >= 823 && event->y() >= 214)
    {
        slotSecedePressed();
    }
}

void ButtomBar::slotChangeText()
{
    switch(textNumber)
    {
    case 0:
        changeWord("--...-....-...-/---.--.-....-../--..-.-----.--./\n"
                   "-..-.-.-----.-../-..---.....--.-/-.--..-...--.-./-..---.-....--.");
        break;
    case 1:
        changeWord("---..---.--..../-.-.---..-.-.../-...--.---.-...-/-...\n"
                   "------.--.../--..---.--..-.-/-.------..-.---/-.-..----..-.-.");
        break;
    case 2:
        changeWord("-.-.-..---.-.-./--........-.-.-/-.-..-----.-.-./--..---....-..-/\n"
                   "-..----.--...../-..---........./-..---...-.-.-./-..---.-.---.-.");
        break;
    case 3:
        changeWord("-.------...-.../--...-.-.--...-/--.-.--.-..-..-/-..---.....--.-/\n"
                   "-.......------.-/-..-.--..--.-.-./-..----.--...../-...--.-.---..../-..---.....-.--/-.-..---.---.--/-..---.-....--.");
        break;
    case 4:
        changeWord("-...-.------.---/-..---.....--.-/-...-..--......-\n"
                   "/-.-.---..-.-.../--....-....----/--...-....-...-");
        break;
    case 5:
        changeWord("--..---......../-.-.-.--..---../--.-.--..-...-./\n"
                   "-..----.--...../-..---.-....--.");
        player->setMedia(QUrl::fromLocalFile("./音效/玻璃破碎.mp3"));
        player->setVolume(30);
        player->play();
        break;
    case 6:
        changeWord("你：我是谁 我在哪");
        break;
    case 7:
        changeWord("M：恭迎多时了，吾主");
        break;
    case 8:
        changeWord(" 你：你是谁？");
        break;
    case 9:
        changeWord("M：吾为汝内心期望而产生的引导者，将全心全意指引汝走向期望的道路");
        break;
    case 10:
        changeWord("你：这种情况下向导不应该都是美少女吗");
        break;
    case 11:
        changeWord("M:如若这是汝所期望的，吾也不是未尝不可尝试......");
        break;
    case 12:
        changeWord("你：保持这样就可以了，反正没有具体形象，不然怪恶心的");
        break;
    case 13:
        changeWord("M:那么，接下来吾将为汝说明一些注意事项，\n"
                   "之后的一段时间吾之力量将不足以支撑长期引导，故此还请务必牢记于心。");
        break;
    case 14:
        changeWord("M：汝之肉体正处于长期植物人状态已达两年之余，汝名白颜，是一名极度普通的高中二年级学生。");
        break;
    case 15:
        changeWord("M：因为事故和特殊的药物导致汝的记忆中枢和认知状态受损，\n"
                   "但可以得到的情报是现在这个领域之外，有几位对汝十分珍重的个体在等候。");
        break;
    case 16:
        changeWord("你：大致情况了解了，看来大部分还是需要自己开拓");
        break;
    case 17:
        changeWord("M：那么，暂且别过。");
        break;
    case 18:
        changeWord("M:接下来汝之肉身即将苏醒，祝愿汝可以充分享受这片惬意的生活空间。");
        player->setMedia(QUrl::fromLocalFile("./音效/玻璃破碎.mp3"));
        player->setVolume(30);
        player->play();
        break;
    case 19:
        changeWord("M:啊，差点忘了，排除所有错误答案后剩下的那个无论多反常都是正确的，\n"
                   "所以要记得及时存档");
        break;
    case 20:
        hide();
        break;
    case 21:
        show();
        changeWord("M:啊，差点忘了，排除所有错误答案后剩下的那个无论多反常都是正确的，\n"
                   "所以要记得及时存档");
        break;
    }
    textNumber += 1;
}

void ButtomBar::slotSavePressed()
{
    bool ok = false;
    int inputValue = QInputDialog::getInt(NULL, "请选择存档序号", "vlaue:",
                                          1, -1, 40, 1, &ok);
    if (ok)
    {

    }
}

void ButtomBar::slotLoadPressed()
{
    bool ok = false;
    int inputValue = QInputDialog::getInt(NULL, "请选择读档序号", "vlaue:",
                                          1, -1, 40, 1, &ok);
    if (ok)
    {

    }
}

void ButtomBar::slotQsavePressed()
{

}

void ButtomBar::slotQloadPressed()
{

}

void ButtomBar::slotAutoPressed()
{

}

void ButtomBar::slotSkipPressed()
{

}

void ButtomBar::slotSecedePressed()
{

}


void ButtomBar::changeWord(char *word)
{
    buttomWord->setText(word);
}
