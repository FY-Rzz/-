//全局变量区

//perchase-------------------------------------------
    typedef struct purchase//原料采购订单
    {
        char p_date[20];//时间
        int kind;       //原料种类
        double p_money;//原料进价
        int weight;     //原料重量
        char p_number[20];//订单编号
        struct purchase *p_next;//链表下一节点
    }PUR;

    PUR Cp_head={"0",0,0,0,"0",NULL};//全局量（表头并初始化
    PUR *p_head=&Cp_head;//全局量（原料哨兵表头指针，哨兵表头
    int jin_count=0;//全局量（订单编号计数菌

//SELL-----------------------------------------------------------
    typedef struct sell //售卖订单
    {
        int drink;      //饮品种类
        int taste;      //口味
        int temper;     //温度
        int sugar;      //甜度
        int standard;   //规格
        int much;        //数量
        char s_date[20]; //时间
        char s_number[20];//下单编号
        double money;      //订单金额
        struct sell *s_next;//链表下一节点
    }SELL;
    /* ————————【】内数字为int代号，口味前{}为饮品编号，（）为原料消耗，<>为价格--------
        规格：【1】大；【2】中；【3】小；
        饮品：【1】果茶奶茶；（茶叶15//10//5g）<15//13//8>【2】冰淇凌；（奶油30//20//10g+牛奶300//200//100g）<10//8//5>
                【3】咖啡；（咖啡豆20//15//10g）<16//14//10>【4】酸奶；（酸奶350//250//150g）<12//10//8>
        口味：{1}【1】牛乳味（牛奶300g）【2】草莓味（草莓20g）【3】葡萄味（葡萄20g）
                {2}【1】草莓味（草莓20g）【2】葡萄味（葡萄20g）【3】酸奶味（酸奶50g）
                {3}【1】黑咖啡（无添加）【2】抹茶味（茶叶5g）【3】卡布奇诺（牛奶50g）
                {4}【1】原味；（无添加）【2】草莓味（草莓20g）【3】葡萄味（葡萄20g）
        甜度：【1】全糖（30g糖）【2】五分糖（15g糖）【3】无糖（0g）
        温度：【1】热；【2】常温；【3】加冰


    */
    typedef struct shopping{//购物车节点;
       char s_date[20];
       int drink;
       int taste;
       int temper;
       int sugar;
       int standard;
       int much;
       double shop_money;
       struct shopping*s_next;
    }SHOP;

    int sum=0;//订单总数
    SELL*head=NULL;
    SELL*tail=NULL;//订单节点头指针需要设为全局变量;

//原料库存---------------------------------------------

    int milk=30000; //牛奶【1】
    int tea=20000;    //茶叶【2】
    int cream=10000;  //奶油【3】
    int coffee=10000; //咖啡豆【4】
    int yoghurt=10000;//酸奶【5】
    int straw=10000;  //草莓【6】
    int grape=10000;  //葡萄【7】
    int sugar=10000;  //白糖【8】


    typedef struct yuanliaojilu{
    int tea;
    int milk;
    int cream;
    int coffee;
    int yoghurt;
    int straw;
    int grape;
    int sugar;
    char s_date[20];
    struct yuanliaojilu*s_next;
    }STOCKNOTE;//用来记录制作饮品时原料的使用情况 ;

    STOCKNOTE*NOTEhead;
    STOCKNOTE*NOTEtail;


//login---------------------------------------------------
    int count=0;
    int n=5;
    int login_time=0; //该函数调用次数


//money----------------------------------------------------
      double zijin=1000000;//总资金

typedef struct all{
	double all_trans_money;
	char all_name[20];
	char all_formnumber[20];
	char all_time[20];
	struct all *all_next;
}Allform;

    //订单流转
    typedef struct order {
        double order_trans_money;        //转移金额
        char order_formnumber[20];      //订单流转编号
        char order_time[20];          //时间
        struct order *order_next;     //下一节点
    } Orderform;

    //投资流转
    typedef struct other {
        double other_trans_money;     //其他转移金额
        char other_formnumber[20];    //其他流转编号
        char other_time[20];        //其他流转时间
        struct other *other_next;  //下一节点
    } Otherform;

    //原料流转
    typedef struct material {
        double material_trans_money;     //原料转移金额
        char material_formnumber[20];       //原料流转编号
        char material_time[20];     //原料流转时间
        struct material *material_next;  //下一节点
    } Materialform;

    //流转表头
    Allform*allhead=NULL,*allwei=NULL,*allp,*allq;
    Orderform*orderhead=NULL,*orderwei=NULL,*orderp,*orderq;//订单流转
    Otherform*otherhead=NULL,*otherwei=NULL,*otherp,*otherq;//投资流转
    Materialform*materialhead=NULL,*materialwei=NULL,*materialp,*materialq; //原料流转
    char all_number[10]="NO0000";
    char other_number[10]="NO0000";
    char order_number[10]="NO0000";
    char material_number[10]="NO0000";


//VIp-------------------------------------------------
    typedef struct Vip
    {
        char phone[100];            //电话号码
        char name[20];
        char mibao[20];
        char vip_pass[100];         //密码
        int  score;             //余额
        struct Vip* next;       //下一节点
    }VIP;

    VIP*head_v,*rear_v;      //写入主函数的头哨兵节点和尾结点

//yuceduqu-----------------------------------------------

int d[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int search_result[8][7];

char trtime[7][20];
