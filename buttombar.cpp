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

void ButtomBar::setTextNumber(int number)
{
    textNumber = saveList.at(number);
    if(textTimer->isActive())
    {
        textTimer->stop();
        textTimer->start(10000);
    }
    slotChangeText();
}

void ButtomBar::layoutUI()
{
    buttomPic = new QLabel(this);
    buttomWord = new QLabel(this);
    buttomPic->setGeometry(0, 0, 960, 238);
    buttomWord->setGeometry(238, 25, 800, 200);
    buttomWord->setStyleSheet("QLabel{font-size: 10px;text-align: center center}");
    buttomPic->setStyleSheet("QLabel{image:url(logginpage/框.png);}");
}

void ButtomBar::control()
{
    textTimer = new QTimer(this);
    player = new QMediaPlayer(this);
    connect(textTimer, SIGNAL(timeout()), this, SLOT(slotChangeText()));
}

void ButtomBar::initWord()
{
    int i = 0;
    pageList.insert(i, "--...-....-...-/---.--.-....-../--..-.-----.--./\n"
                   "-..-.-.-----.-../-..---.....--.-/-.--..-...--.-./-..---.-....--.");
    i++;
    pageList.insert(i, "---..---.--..../-.-.---..-.-.../-...--.---.-...-/-...\n"
                   "------.--.../--..---.--..-.-/-.------..-.---/-.-..----..-.-.");
    i++;
    pageList.insert(i, "-.-.-..---.-.-./--........-.-.-/-.-..-----.-.-./--..---....-..-/\n"
                   "-..----.--...../-..---........./-..---...-.-.-./-..---.-.---.-.");
    i++;
    pageList.insert(i, "-.------...-.../--...-.-.--...-/--.-.--.-..-..-/-..---.....--.-/\n"
               "-.......------.-/-..-.--..--.-.-./-..----.--...../-...--.-.---..../\n"
                    "-..---.....-.--/-.-..---.---.--/-..---.-....--.");
    i++;
    pageList.insert(i, "-...-.------.---/-..---.....--.-/-...-..--......-\n"
               "/-.-.---..-.-.../--....-....----/--...-....-...-");
    i++;
    pageList.insert(i, "--..---......../-.-.-.--..---../--.-.--..-...-./\n"
               "-..----.--...../-..---.-....--.");
    i++;
    pageList.insert(i, "你：我是谁 我在哪");
    i++;
    pageList.insert(i, "M：恭迎多时了，吾主");
    i++;
    pageList.insert(i, " 你：你是谁？");
    i++;
    pageList.insert(i, "M：吾为汝内心期望而产生的引导者，将全心全意指引汝走向期望的道路");
    i++;
    pageList.insert(i, "你：这种情况下向导不应该都是美少女吗");
    i++;
    pageList.insert(i, "M:如若这是汝所期望的，吾也不是未尝不可尝试......");
    i++;
    pageList.insert(i, "你：保持这样就可以了，反正没有具体形象，不然怪恶心的");
    i++;
    pageList.insert(i, "M:那么，接下来吾将为汝说明一些注意事项，\n"
               "之后的一段时间吾之力量将不足以支撑长期引导，故此还请务必牢记于心。");
    i++;
    pageList.insert(i, "M：汝之肉体正处于长期植物人状态已达两年之余，汝名白颜，是一名极度普通的高中二年级学生。");
    i++;
    pageList.insert(i, "M：因为事故和特殊的药物导致汝的记忆中枢和认知状态受损，\n"
               "但可以得到的情报是现在这个领域之外，有几位对汝十分珍重的个体在等候。");
    i++;
    pageList.insert(i, "你：大致情况了解了，看来大部分还是需要自己开拓");
    i++;
    pageList.insert(i, "M：那么，暂且别过。");
    i++;
    pageList.insert(i, "M:接下来汝之肉身即将苏醒，祝愿汝可以充分享受这片惬意的生活空间。");
    i++;
    pageList.insert(i, "M:啊，差点忘了，排除所有错误答案后剩下的那个无论多反常都是正确的，\n"
               "所以要记得及时存档");
    i++;
    pageList.insert(i, "-.--..--.....-./--..----..---../-.-..-----.----/-.......------.-/\n"
                    "---.--.-....-../-...-.----.---.-");
    i++;
    pageList.insert(i, "-...-.------.---/-.-..-.-.-....-/-.-------...-.-");
    i++;
    pageList.insert(i, "-...-.---.-.-..-/-...------.--..-/-..---...-.-.-./\n"
                    "-.--.--.--.-..-/-.--.--.-.-..../-...-..----...--/-......-..--...-");
    i++;
    pageList.insert(i, "又是一阵奇怪的杂音，不过多亏了这杂音，至少现在明显感觉得到身体中红液开始正常工作。");
    i++;
    pageList.insert(i, "游荡的灵魂回归了肉体，踏实的厚重感莫名让自己觉得安心了几分");
    i++; //change page
    pageList.insert(i, "脸颊两侧盐分干涸后弥留的印记如同依附在甲板上的藤壶，虽然粗糙但余温犹存。或许是自己的，也或许是别人的。");
    i++;
    pageList.insert(i, "网格状碎花的天花板，材质看起来像不规则大理石，与其称之为天花板，倒不如说那是地砖侵占了天花板原有的位置。\n"
                    "边角不规则的异色切块让这块马赛克似的天花板上像是多了几只眼睛，社恐或是强迫症患者看到大概会很不舒服吧，\n"
                    "是设计师的恶趣味么，或是工人的偷工减料也说不定。不...也许根本就是这里主人的爱好罢了。");
    i++;
    pageList.insert(i, "？？？：哦呀，凭自己的意志醒来了呢 ");
    i++;//change page
    pageList.insert(i, "没有什么不适，身体条件反射坐了起来，反倒是身上这些奇怪的管子立刻限制了更大幅度的运动。");
    i++;
    pageList.insert(i, "眼前是一名护士装少女，虽说是护士装，但看起来倒更像是cosplay，总之看起来非常不着调。");
    i++;
    pageList.insert(i, "你：你是谁，这里是...医院么，我睡了多久？");
    i++;
    pageList.insert(i, "？？？：我只是个路过的假面骑士，给我记好了！");
    i++;
    pageList.insert(i, "你：...");
    i++;
    pageList.insert(i, "？？？：不好意思这句话我想说很久了，实在没忍住");
    i++;
    pageList.insert(i, "感觉..眼前这位少女相当脱线，不过也算是萌点所在？");
    i++;
    pageList.insert(i, "？？？：不逗你了，我只是个普通的打工人罢了，\n"
                    "接下来的时间就交给你的家属和亲友啦，我还有其他的工要打，有缘再见~");
    i++;
    pageList.insert(i, "话音未落，少女已经不见了踪影，速度之快堪比中午等待下课铃声瞬间冲向食堂的学生。");
    i++;
    pageList.insert(i, "请进");
    i++;
    pageList.insert(i, "乔丹：兄——弟——！！！");
    i++;
    pageList.insert(i, "我天，怎么又是男人。等等我为什么要说又");
    i++;
    pageList.insert(i, "虽然具体记不太清，但眼前这个金发男子无疑是从小的好兄弟乔丹，\n"
                    "没错不是代号这就是他的本名，大概是因为父母期望他成为迈克尔乔丹那样的国际球星吧，\n"
                    "并且事实是他的体育项目的确非常好。对了，他的金发是染的。");
    i++;
    pageList.insert(i, "你：好了好了兄弟，你这是想让我再倒下么，如果真要在倒下我更想被f罩闷死。");
    i++;
    pageList.insert(i, "白芊：哥..？（抽噎）");
    i++;
    pageList.insert(i, "忽的，被软绵绵的一双小手轻轻拉住了指尖");
    i++;
    pageList.insert(i, "和自己有许多相似之处的娇小少女，这无疑是年幼三岁的亲生妹妹白芊，\n"
                    "印象当中非常懂事，在这个父母双忙的年代承担了几乎全部家务，\n"
                    "听说在她所在的班级也是充当了榜样级班长的角色，总之，因为这么个能干的妹妹存在总会酸到很多肥宅就是了");
    i++;
    pageList.insert(i, "你：好了芊芊乖~你大哥我可是无敌的jo级生物，怎么可能丢下你不管呢~");
    i++;
    pageList.insert(i, "白芊：5555.....哥....哥....抱");
    i++;
    pageList.insert(i, "看着泣不成声可怜的孩子，罪恶感油然而生，在自己昏睡的过程中，一个人大概吃了不少苦头吧");
    i++;
    pageList.insert(i, "你：真是个爱撒娇的孩子呢，放心，既然大哥在，为了守护你与世界为敌又有何妨");
    i++;
    pageList.insert(i, "唔，总觉得有些中二，羞耻感瞬间爆棚，不过这种基本的觉悟可是一开始就应该做好了不是吗。");
    i++;
    pageList.insert(i, "江珂：呦，终于清醒了么。在你昏睡的这段时间给大家造成了多少困扰清楚么。");
    i++;
    pageList.insert(i, "讲话还是一如既往的毫不客气呢，窗边年长自己三岁的高挑女性江珂，\n"
                    "年纪轻轻就做到了城市治安部总长，此外还是我的邻居兼姐姐，虽然我们没有任何遗传学上的亲缘关系就是了。\n"
                    "不过，这个严厉仅仅是公众场合维持形象的表现罢了。");
    i++;
    pageList.insert(i, "你：抱歉啊姐姐大人~长久以来辛苦你啦。不过在这里守着放着工作不管真的没问题吗~");
    i++;
    pageList.insert(i, "江珂：现在让你安全到家就是我的工作（啪）");
    i++;
    pageList.insert(i, "你：对待伤员都这么不留情！我要向妇联举报！咦，好像没有男权协会..");
    i++;
    pageList.insert(i, "无论在哪个时代男性都不收保护呢");
    i++;
    pageList.insert(i, "0：喵~");
    i++;
    pageList.insert(i, "唉嘿，这个小糯米团子可是亲女儿，怎么看都是一只可爱的喵星人，\n"
                    "虽然不太记得为什么要叫零这个名字，但潜意识告诉自己以前很多事情只会跟她讲。毕竟人畜无害的可爱猫猫谁不爱呢~");
    i++;
    pageList.insert(i, "你：咦，你的毛，变长了呢");
    i++;
    pageList.insert(i, "我怎么记得应该是一直纯种的杂种短毛猫呢");
    i++;
    pageList.insert(i, "0：喵嗷？——米嗷嗷————！");
    i++;
    pageList.insert(i, "突然小糯米团子变成了小刺团子浑身毛发齐刷刷的竖立，如临大敌。\n"
                    "大概是她觉得自己很凶吧，白玉海参一样抖动的身体但显得尤为滑稽");
    i++;
    pageList.insert(i, "不过很快我就发现了造成恐慌的源头------牛顿看了大概会气的从棺材板里跳出来，\n"
                    "虽然牛顿是火化的。不过这么长的头发还能飘飘然，想必打理起来也一定非常困难吧。\n"
                    "这股暗红色缓缓从昏暗灯光的走廊中流入室内，也难怪可怜的猫猫吓个不轻。");
    i++;
    pageList.insert(i, "林瑾：人家等你好辛苦呢，亲爱的小白同学~~");
    i++;
    pageList.insert(i, "但凡男人听到这中酥酥麻麻的话应该都会兴奋吧，但不知怎的，却突然有些阵阵寒意。");
    i++;
    pageList.insert(i, "这位少女是林瑾，既是邻居，也算是青梅竹马，无论外表还是能力都是金字塔顶尖存在，完全不是自己这种中下层人士可比的。");
    i++;
    pageList.insert(i, "你：让..让您久等了");
    i++;
    pageList.insert(i, "-...------.--..-/-..---...-.-.-./-.--..-.---..--/\n"
                    "-..---.-.---.-./-.------...-.../-.-..--.---...-/-..-.--..--.-..-");
    i++;
    pageList.insert(i, "咦，幻听了么，又是奇怪的杂音。虽说听起来像是某种电磁波震动，但却夹杂着类似女性的音色。");
    i++;
    pageList.insert(i, "乔丹：好了好了你就别吓唬他了，这才刚醒好好让他恢复一下吧。");
    i++;
    pageList.insert(i, "林瑾：啊，乔丹你在这啊。那现在可以请你去外面把门关上吗");
    i++;
    pageList.insert(i, "乔丹：明明是我先来的！");
    i++;
    pageList.insert(i, "你：噗嗤——");
    i++;
    pageList.insert(i, "二人：？");
    i++;
    pageList.insert(i, "你：总觉得你们从以前开始就是这样了呢，关系真好呢");
    i++;
    pageList.insert(i, "二人：---才没有！");
    i++;
    pageList.insert(i, "白芊：其实是我一直都在...（小声）");
    i++;
    pageList.insert(i, "江珂：好了好了都安静一下，既然当事人可以出院了，那就先搭我的车给你们送回各家吧。");
    i++;
    pageList.insert(i, "白芊：哥，我来帮你换衣服");
    i++;
    pageList.insert(i, "你：额，我自己能行");
    i++;
    pageList.insert(i, "虽然多少已经猜到昏睡期间的换洗是谁在做了，但当着这么多人的面拜托自己的妹妹帮忙换衣服自然是做不出来。");
    i++;//change page
    pageList.insert(i, "久违的，脚踏实地的感觉，全身的重心突然堆积在脚底，高强度的用力让膝盖直接提出抗议，要不是有人搀扶着现在大概已经对着地面一扣三拜了。");
    i++;
    pageList.insert(i, "昏暗而拥挤的走廊，明明没有堆放任何杂物但依旧显得十分拥堵，灯光苟延残喘着尝试证明自己的剩余价值，\n"
                    "大概但有一些聒噪就会吓得立刻熄火。没有看到窗户，却能明显感觉到气流忙碌的进行着置换，\n"
                    "这种感觉就像是女人的头发横扫似的不断摩擦擦着皮肤表面的每一个毛囊。自己这件病房大概是最里面的一间吧，\n"
                    "总觉得能在最里面房间完好无损走出来真是奇迹。");
    i++;
    pageList.insert(i, "这条走廊里除了最远处的微弱光亮，似乎没看到其他病房，谈不上阴森，但总觉得那光亮更像是灯芯或是烛火。");
    i++;
    pageList.insert(i, "这条走廊真的有尽头么。如果只有自己一个人的话，不知道要走多久才能到达尽头呢，不不，仅凭自己一个人，多半是不会走下去的吧。");
    i++;
    pageList.insert(i, "这家医院的设计师真的是鬼才，这种阴间的病房设计仿佛就是在贴心的位患者提供停尸房前期体验活动。");
    i++;//change page
    pageList.insert(i, "终于到达了地表...瞬间收缩瞳孔的阳光...人类生存证明的嘈杂声，真是糟透了，这个毫无价值快要烂掉的城市。");
    i++;
    pageList.insert(i, "末了，空气的清新程度属实意料之外，虽然大脑可能已经忘记了，但肺部却如获新生，\n"
                    "毕竟每一个肺泡都把不知前多久那个雾以吸为贵的年代刻在了DNA里。这些人类的发展居然没有带来环境的破坏，可喜可贺，可喜可贺。");
    i++;
    pageList.insert(i, "女队员：总长，车已经准备好了。");
    i++;
    //first choose
    pageList.insert(i, "江珂：没时间解释了，快上车。");
    i++;
    pageList.insert(i, "半推半就的上了车，不过车里面还蛮大的。与外观不符的是这台车子内部丝毫不亚于一些高档房车，功能完善程度叹为观止。");
    i++;
    pageList.insert(i, "身居其中完全可以自由的预览到车外的情况。如此奢侈的内部装修，大概是某个领导私吞国家拨款军费的直接表象了");
    i++;
    pageList.insert(i, "广播：上津门交通安全部门提醒您 道路千万条 安全第一条 出行不规范 亲人两行泪");
    i++;
    pageList.insert(i, "完全没有感情的棒读，自然也不会真的有人会去听从劝告。毕竟人类对于自己不感兴趣的东西既无法看到也无法认知。");
    i++;//change page
    pageList.insert(i, "果然，世界会随着自己改变这种事，根本不可能。说到底，我们又是何时认识到自己不是世界的主角呢。");
    i++;//change page
    pageList.insert(i, "一群整齐划一的考斯普雷的人，虽然不知道他们在考斯什么，嘛，多半他们自己也不知道考斯什么仅仅是为了当前蹭热度吧");
    i++;
    pageList.insert(i, "众教徒：啊~啊~~~");
    i++;
    pageList.insert(i, "单纯的富有感情的拖长中音，人员看起来全都是女性，年纪可能最大不会超过40岁，最小的，唔，大概也就刚刚小学毕业的亚子。");
    i++;
    pageList.insert(i, "乔丹：哎？那堆教徒里是有美女吗你怎么这么在意。");
    i++;
    pageList.insert(i, "你：教徒？");
    i++;
    pageList.insert(i, "乔丹：对啊，那群人好像信奉什么外神，主张减少人类干涉让生态恢复平衡，\n"
                    "现在好像是每天例行的圣歌吧，自从这群人在这里，倒是跳广场舞的大妈不见了。");
    i++;
    pageList.insert(i, "你：这种聚众活动政府不管嘛");
    i++;
    pageList.insert(i, "江珂：倒不是不管，但毕竟他们没有做出任何危害城市的举动，反而更像是提倡环保的友好组织，\n"
                    "虽然会做一些理念宣传，但更多的时候是在进行实际的环境维护工作，所以上级也自然默许存在了。");
    i++;
    pageList.insert(i, "的确，如果提倡环保的话某种意义上这还算是个不错的宗教");
    i++;
    pageList.insert(i, "乔丹：但是我有一点就很气啊");
    i++;
    pageList.insert(i, "林瑾：是因为那个教会唯一的男人是作为教主的糟老头子吗");
    i++;
    pageList.insert(i, "乔丹：对啊我也想坐拥如此庞大的后宫啊....哎？");
    i++;
    pageList.insert(i, "林瑾：果然是渣男啊");
    i++;
    pageList.insert(i, "江珂：一开口就是老渣男了");
    i++;
    pageList.insert(i, "白芊：...熟练的渣男");
    i++;
    pageList.insert(i, "0：喵呜！");
    i++;
    pageList.insert(i, "喂，你看着我也没用，这时候如果帮助你大概会变成女性公敌吧");
    i++;
    pageList.insert(i, "乔丹：兄弟~这是个正常男人都会想要的吧~~");
    i++;
    pageList.insert(i, "心理和感情常常是不相等的，有时候会做出砍死完全不合理的结论也是这个原因。\n"
                    "不过单纯满足虚荣心的话后宫确实很棒，但只是想想自然不能这么讲就是了。");
    i++;
    pageList.insert(i, "你：汝与曹贼何异...");
    i++;
    pageList.insert(i, "乔丹：男人变态有什么错！");
    i++;
    pageList.insert(i, "上次这样的喧闹，是什么时候呢");
    i++;//change page
    pageList.insert(i, "你：痛...");
    i++;
    pageList.insert(i, "刚才那是什么，回忆吗，看来记忆恢复伴随头疼的说法是真的了。");
    i++;
    pageList.insert(i, "白芊：哥！怎么了哪里不舒服");
    i++;
    pageList.insert(i, "你：没什么，可能这车密封性太好了有点缺氧。");
    i++;
    pageList.insert(i, "江珂：要下车吗，虽然没多远了。");
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
    else if(event->x() <= 950 && event->y() <= 232 && event->x() >= 863 && event->y() >= 214)
    {
        slotSecedePressed();
    }
    else
    {
       slotChangeText();
    }
}

void ButtomBar::slotChangeText()
{
    switch(textNumber)
    {
    case 0:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/电码1.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 5:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("音效/玻璃破碎.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 7:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/1恭迎多时了.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 9:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/2吾乃汝内心期望而产生.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 11:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/3如若这是汝所期望的.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 13:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/4那么接下来.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 14:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/5擆擵擏懱.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 15:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/6因为事故.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 17:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/7那么.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 18:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/8愙壓棃.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 19:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/M/9啊差点忘了.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 20:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("音效/推门.WAV"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 21:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/电码2.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 27:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/？？？/凭自己的.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 31:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/？？？/路过的74.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 33:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/？？？/不好意思.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 35:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/？？？/不逗你了.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 37:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("音效/咚咚咚咚的敲门音效.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 38:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/兄弟！.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 46:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白芊/555哥哥抱抱——.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 50:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK1.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 53:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK2.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 56:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/喵！.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 60:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/喵~嗷！.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 63:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/林瑾/人家等你好辛苦.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 67:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/电码3.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 69:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/好啦好啦别吓唬.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 70:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/林瑾/乔丹你也在这啊.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 71:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/明明我先.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 76:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白芊/其实我一直都在.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 77:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK3.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 78:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白芊/帮你换衣服.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 88:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/npc/队长（女）/车准备好了.mp3"));
        player->setVolume(100);
        player->play();
        break;
        if(textTimer->isActive())
        {
            textTimer->stop();
            emit signalChoose();
        }
    }
    case 89:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK4.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 92:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/配/npc/广播/安全交通部门.mP3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 98:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/那堆教徒.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 100:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/对啊那群人信奉.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 102:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK5.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 104:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/但是有一点.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 105:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/林瑾/教会唯一的男人.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 106:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/庞大的后宫.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 107:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/林瑾/果然是渣男.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 108:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK6.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 109:
    {
        player->stop();
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白芊/熟练的渣男.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 110:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白零/喵呜~.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 112:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/正常男人都会想要的.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 115:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/乔丹/男人变态.m4a"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 119:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/白芊/哪里不舒服.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    case 121:
    {
        player->stop();
        player->setMedia(QUrl::fromLocalFile("cv/主/江珂/JK7.mp3"));
        player->setVolume(100);
        player->play();
        break;
    }
    default:
        break;
    }
    changeWord(pageList.at(textNumber));
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
        textTimer->stop();
        textTimer->start(10000);
        slotChangeText();
    }
}

void ButtomBar::slotQsavePressed()
{
    saveList.insert(0, textNumber);
}

void ButtomBar::slotQloadPressed()
{
    textNumber = saveList.at(0);
    textTimer->stop();
    textTimer->start(10000);
    slotChangeText();
}

void ButtomBar::slotAutoPressed()
{
    if(textTimer->isActive())
    {
        textTimer->stop();
    }
    else
    {
        textTimer->start(10000);
    }
}

void ButtomBar::slotSkipPressed()
{
    textNumber += 1;
    textTimer->stop();
    textTimer->start(10000);
    slotChangeText();
}

void ButtomBar::slotSecedePressed()
{
    emit signalMainPage();
}


void ButtomBar::changeWord(const QString &word)
{
    buttomWord->setText(word);
}
