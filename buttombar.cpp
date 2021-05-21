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

void ButtomBar::initWord()
{
    pageList.append("--...-....-...-/---.--.-....-../--..-.-----.--./\n"
                   "-..-.-.-----.-../-..---.....--.-/-.--..-...--.-./-..---.-....--.");
    pageList.append("---..---.--..../-.-.---..-.-.../-...--.---.-...-/-...\n"
                   "------.--.../--..---.--..-.-/-.------..-.---/-.-..----..-.-.");
    pageList.append("-.-.-..---.-.-./--........-.-.-/-.-..-----.-.-./--..---....-..-/\n"
                   "-..----.--...../-..---........./-..---...-.-.-./-..---.-.---.-.");
    pageList.append("-.------...-.../--...-.-.--...-/--.-.--.-..-..-/-..---.....--.-/\n"
               "-.......------.-/-..-.--..--.-.-./-..----.--...../-...--.-.---..../\n"
                    "-..---.....-.--/-.-..---.---.--/-..---.-....--.");
    pageList.append("-...-.------.---/-..---.....--.-/-...-..--......-\n"
               "/-.-.---..-.-.../--....-....----/--...-....-...-");
    pageList.append("--..---......../-.-.-.--..---../--.-.--..-...-./\n"
               "-..----.--...../-..---.-....--.");
    pageList.append("你：我是谁 我在哪");
    pageList.append("M：恭迎多时了，吾主");
    pageList.append(" 你：你是谁？");
    pageList.append("M：吾为汝内心期望而产生的引导者，将全心全意指引汝走向期望的道路");
    pageList.append("你：这种情况下向导不应该都是美少女吗");
    pageList.append("M:如若这是汝所期望的，吾也不是未尝不可尝试......");
    pageList.append("你：保持这样就可以了，反正没有具体形象，不然怪恶心的");
    pageList.append("M:那么，接下来吾将为汝说明一些注意事项，\n"
               "之后的一段时间吾之力量将不足以支撑长期引导，故此还请务必牢记于心。");
    pageList.append("M：汝之肉体正处于长期植物人状态已达两年之余，汝名白颜，是一名极度普通的高中二年级学生。");
    pageList.append("M：因为事故和特殊的药物导致汝的记忆中枢和认知状态受损，\n"
               "但可以得到的情报是现在这个领域之外，有几位对汝十分珍重的个体在等候。");
    pageList.append("你：大致情况了解了，看来大部分还是需要自己开拓");
    pageList.append("M：那么，暂且别过。");
    pageList.append("M:接下来汝之肉身即将苏醒，祝愿汝可以充分享受这片惬意的生活空间。");
    pageList.append("M:啊，差点忘了，排除所有错误答案后剩下的那个无论多反常都是正确的，\n"
               "所以要记得及时存档");
    pageList.append("M:啊，差点忘了，排除所有错误答案后剩下的那个无论多反常都是正确的，\n"
               "所以要记得及时存档");
    pageList.append("-.--..--.....-./--..----..---../-.-..-----.----/-.......------.-/\n"
                    "---.--.-....-../-...-.----.---.-");
    pageList.append("-...-.------.---/-.-..-.-.-....-/-.-------...-.-");
    pageList.append("-...-.---.-.-..-/-...------.--..-/-..---...-.-.-./\n"
                    "-.--.--.--.-..-/-.--.--.-.-..../-...-..----...--/-......-..--...-");
    pageList.append("又是一阵奇怪的杂音，不过多亏了这杂音，至少现在明显感觉得到身体中红液开始正常工作。");
    pageList.append("游荡的灵魂回归了肉体，踏实的厚重感莫名让自己觉得安心了几分"); //change page
    pageList.append("脸颊两侧盐分干涸后弥留的印记如同依附在甲板上的藤壶，虽然粗糙但余温犹存。或许是自己的，也或许是别人的。");
    pageList.append("网格状碎花的天花板，材质看起来像不规则大理石，与其称之为天花板，倒不如说那是地砖侵占了天花板原有的位置。\n"
                    "边角不规则的异色切块让这块马赛克似的天花板上像是多了几只眼睛，社恐或是强迫症患者看到大概会很不舒服吧，\n"
                    "是设计师的恶趣味么，或是工人的偷工减料也说不定。不...也许根本就是这里主人的爱好罢了。");
    pageList.append("？？？：哦呀，凭自己的意志醒来了呢 ");//change page
    pageList.append("没有什么不适，身体条件反射坐了起来，反倒是身上这些奇怪的管子立刻限制了更大幅度的运动。");
    pageList.append("眼前是一名护士装少女，虽说是护士装，但看起来倒更像是cosplay，总之看起来非常不着调。");
    pageList.append("你：你是谁，这里是...医院么，我睡了多久？");
    pageList.append("？？？：我只是个路过的假面骑士，给我记好了！");
    pageList.append("你：...");
    pageList.append("？？？：不好意思这句话我想说很久了，实在没忍住");
    pageList.append("感觉..眼前这位少女相当脱线，不过也算是萌点所在？");
    pageList.append("？？？：不逗你了，我只是个普通的打工人罢了，\n"
                    "接下来的时间就交给你的家属和亲友啦，我还有其他的工要打，有缘再见~");
    pageList.append("话音未落，少女已经不见了踪影，速度之快堪比中午等待下课铃声瞬间冲向食堂的学生。");
    pageList.append("乔丹：兄——弟——！！！");
    pageList.append("我天，怎么又是男人。等等我为什么要说又");
    pageList.append("虽然具体记不太清，但眼前这个金发男子无疑是从小的好兄弟乔丹，\n"
                    "没错不是代号这就是他的本名，大概是因为父母期望他成为迈克尔乔丹那样的国际球星吧，\n"
                    "并且事实是他的体育项目的确非常好。对了，他的金发是染的。");
    pageList.append("你：好了好了兄弟，你这是想让我再倒下么，如果真要在倒下我更想被f罩闷死。");
    pageList.append("白芊：哥..？（抽噎）");
    pageList.append("忽的，被软绵绵的一双小手轻轻拉住了指尖");
    pageList.append("和自己有许多相似之处的娇小少女，这无疑是年幼三岁的亲生妹妹白芊，\n"
                    "印象当中非常懂事，在这个父母双忙的年代承担了几乎全部家务，\n"
                    "听说在她所在的班级也是充当了榜样级班长的角色，总之，因为这么个能干的妹妹存在总会酸到很多肥宅就是了");
    pageList.append("你：好了芊芊乖~你大哥我可是无敌的jo级生物，怎么可能丢下你不管呢~");
    pageList.append("白芊：5555.....哥....哥....抱");
    pageList.append("看着泣不成声可怜的孩子，罪恶感油然而生，在自己昏睡的过程中，一个人大概吃了不少苦头吧");
    pageList.append("你：真是个爱撒娇的孩子呢，放心，既然大哥在，为了守护你与世界为敌又有何妨");
    pageList.append("唔，总觉得有些中二，羞耻感瞬间爆棚，不过这种基本的觉悟可是一开始就应该做好了不是吗。");
    pageList.append("江珂：呦，终于清醒了么。在你昏睡的这段时间给大家造成了多少困扰清楚么。");
    pageList.append("讲话还是一如既往的毫不客气呢，窗边年长自己三岁的高挑女性江珂，\n"
                    "年纪轻轻就做到了城市治安部总长，此外还是我的邻居兼姐姐，虽然我们没有任何遗传学上的亲缘关系就是了。\n"
                    "不过，这个严厉仅仅是公众场合维持形象的表现罢了。");
    pageList.append("你：抱歉啊姐姐大人~长久以来辛苦你啦。不过在这里守着放着工作不管真的没问题吗~");
    pageList.append("江珂：现在让你安全到家就是我的工作（啪）");
    pageList.append("你：对待伤员都这么不留情！我要向妇联举报！咦，好像没有男权协会..");
    pageList.append("无论在哪个时代男性都不收保护呢");
    pageList.append("0：喵~");
    pageList.append("唉嘿，这个小糯米团子可是亲女儿，怎么看都是一只可爱的喵星人，\n"
                    "虽然不太记得为什么要叫零这个名字，但潜意识告诉自己以前很多事情只会跟她讲。毕竟人畜无害的可爱猫猫谁不爱呢~");
    pageList.append("你：咦，你的毛，变长了呢");
    pageList.append("我怎么记得应该是一直纯种的杂种短毛猫呢");
    pageList.append("0：喵嗷？——米嗷嗷————！");
    pageList.append("突然小糯米团子变成了小刺团子浑身毛发齐刷刷的竖立，如临大敌。\n"
                    "大概是她觉得自己很凶吧，白玉海参一样抖动的身体但显得尤为滑稽");
    pageList.append("不过很快我就发现了造成恐慌的源头------牛顿看了大概会气的从棺材板里跳出来，\n"
                    "虽然牛顿是火化的。不过这么长的头发还能飘飘然，想必打理起来也一定非常困难吧。\n"
                    "这股暗红色缓缓从昏暗灯光的走廊中流入室内，也难怪可怜的猫猫吓个不轻。");
    pageList.append("林瑾：人家等你好辛苦呢，亲爱的小白同学~~");
    pageList.append("但凡男人听到这中酥酥麻麻的话应该都会兴奋吧，但不知怎的，却突然有些阵阵寒意。");
    pageList.append("这位少女是林瑾，既是邻居，也算是青梅竹马，无论外表还是能力都是金字塔顶尖存在，完全不是自己这种中下层人士可比的。");
    pageList.append("你：让..让您久等了");
    pageList.append("-...------.--..-/-..---...-.-.-./-.--..-.---..--/\n"
                    "-..---.-.---.-./-.------...-.../-.-..--.---...-/-..-.--..--.-..-");
    pageList.append("咦，幻听了么，又是奇怪的杂音。虽说听起来像是某种电磁波震动，但却夹杂着类似女性的音色。");
    pageList.append("乔丹：好了好了你就别吓唬他了，这才刚醒好好让他恢复一下吧。");
    pageList.append("林瑾：啊，乔丹你在这啊。那现在可以请你去外面把门关上吗");
    pageList.append("乔丹：明明是我先来的！");
    pageList.append("你：噗嗤——");
    pageList.append("二人：？");
    pageList.append("你：总觉得你们从以前开始就是这样了呢，关系真好呢");
    pageList.append("二人：---才没有！");
    pageList.append("白芊：其实是我一直都在...（小声）");
    pageList.append("江珂：好了好了都安静一下，既然当事人可以出院了，那就先搭我的车给你们送回各家吧。");
    pageList.append("白芊：哥，我来帮你换衣服");
    pageList.append("你：额，我自己能行");
    pageList.append("虽然多少已经猜到昏睡期间的换洗是谁在做了，但当着这么多人的面拜托自己的妹妹帮忙换衣服自然是做不出来。");//change page
    pageList.append("久违的，脚踏实地的感觉，全身的重心突然堆积在脚底，高强度的用力让膝盖直接提出抗议，要不是有人搀扶着现在大概已经对着地面一扣三拜了。");
    pageList.append("昏暗而拥挤的走廊，明明没有堆放任何杂物但依旧显得十分拥堵，灯光苟延残喘着尝试证明自己的剩余价值，\n"
                    "大概但有一些聒噪就会吓得立刻熄火。没有看到窗户，却能明显感觉到气流忙碌的进行着置换，\n"
                    "这种感觉就像是女人的头发横扫似的不断摩擦擦着皮肤表面的每一个毛囊。自己这件病房大概是最里面的一间吧，\n"
                    "总觉得能在最里面房间完好无损走出来真是奇迹。");
    pageList.append("这条走廊里除了最远处的微弱光亮，似乎没看到其他病房，谈不上阴森，但总觉得那光亮更像是灯芯或是烛火。");
    pageList.append("这条走廊真的有尽头么。如果只有自己一个人的话，不知道要走多久才能到达尽头呢，不不，仅凭自己一个人，多半是不会走下去的吧。");
    pageList.append("这家医院的设计师真的是鬼才，这种阴间的病房设计仿佛就是在贴心的位患者提供停尸房前期体验活动。");//change page
    pageList.append("终于到达了地表...瞬间收缩瞳孔的阳光...人类生存证明的嘈杂声，真是糟透了，这个毫无价值快要烂掉的城市。");
    pageList.append("末了，空气的清新程度属实意料之外，虽然大脑可能已经忘记了，但肺部却如获新生，\n"
                    "毕竟每一个肺泡都把不知前多久那个雾以吸为贵的年代刻在了DNA里。这些人类的发展居然没有带来环境的破坏，可喜可贺，可喜可贺。");
    pageList.append("女队员：总长，车已经准备好了。");
    //first choose



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
        saveList.insert(inputValue, textNumber);
    }
}

void ButtomBar::slotLoadPressed()
{
    bool ok = false;
    int inputValue = QInputDialog::getInt(NULL, "请选择读档序号", "vlaue:",
                                          1, -1, 40, 1, &ok);
    if (ok)
    {
        textNumber = saveList.at(inputValue);
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


void ButtomBar::changeWord(const QString &word)
{
    buttomWord->setText(word);
}
