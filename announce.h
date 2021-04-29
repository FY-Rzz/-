
//（进货订单条数，订单哨兵链表头）进货订单创建函数
PUR* jinhuo(int n,PUR* jp_head);

//（全局链表头）进货记录查询函数
void jinhuo_cha_all(PUR* head);

//（目标日期字符串，全局链表头）按时间查询
void jinhuo_cha_time(char date[],PUR *head);

//（目标编号字符串，全局链表头）按编号查询
void jinhuo_cha_number(char number[],PUR *head);

//（目标种类，全局链表头）按种类查询
void jinhuo_cha_kind(int kind,PUR* head);

//（原料链表头指针）进货记录文件导出函数
void jinhuo_txt(PUR* head);

//(全局链表头）从文件中读取进货订单信息
void jinhuo_read(PUR *head);

//链表按时间排序
void jinhuo_sort(PUR* sorthead);

//(原料种类，增减<1,0>，重量）库存修改函数
int kucun_gai(int s_kind,int turn,int s_weight);

//当前库存查询函数
void kucun_cha();

//原料记录
void yuanliaojilu(SHOP*head);

//记录查询
void yuanliaojilucha(STOCKNOTE*NOTEhead);

/*--------------------LOGIN-------------------------------------------*/

//移动函数
 void gotoxy(int x,int y);

//输入函数
int input(char*p,int y);

//打印图形函数
void print_picture(int login_time);

//菜单选择函数
void loopout(HANDLE hwnd,COORD coord,int count);

//查验函数
int searchchar(char*p,int n);

//密保查验函数
int searchchar_mibao(char*p,int n);

//密保函数
int mibao_hanshu(char*mibao);

//初次设置密保的函数
void mibaoinitial(char*key,FILE*fpointer);

//初次设置密码的函数
void Passwordinitial(char*key,FILE *fpointer);

//管理系统综合函数
int  manage_system();

/*--------------------------------------------------*/
//金钱输入函数
double  search_putin();

//编号增加函数
int bianhao_plus(char*bianhao);

//编号比较函数
int bianhao_cmp(char*A,char*B);

//日期比较函数
int riqi_cmp(char*A,char*B);

//1.总资金流转链表生成函数
void all_zijin_gai();

//2.总流转遍历
int all_bianli();

//3.总资金链表删除
void delete_all();

//1.订单流转链表生成函数
void order_zijin_gai();

// 2.订单资金流转记录
double order_sum_money(SHOP*trans);

//3.订单链表按时间遍历
void order_time_search();

//4.订单链表按编号遍历
void order_bianhao_search();

//5.每一笔订单导出
void order_zijin_txt();

//6.订单链表删除
void delete_order();

//------//

//1.原料流转链表生成函数
void material_zijin_gai();

//2.原料资金流转记录
float sum_money(PUR*trans);

//3.原料按时间遍历
void material_time_search();

//4.原料按编号遍历
void material_bianhao_search();

//5.每一笔原料导出
void material_zijin_txt();

//6.原料链表删除
void delete_material();

//------//

//1.投资流转链表生成函数
void other_zijin_gai();

//2.投资函数
void touzi(double money);

//3.投资按时间遍历
void other_time_search();

//4.投资按编号遍历
void other_bianhao_search();

//5.每一笔投资导出
void other_zijin_txt();

//6.投资链表删除
void delete_other();

//------//

// 资金查询
void zijin_cha();

//总资金数据文件导出
void zijin_txt();

//资金管理选择菜单
int money_manage_choose();

//时间输入——投资
int time_input_money(char* timeplus);


/*-------------------------------------------------*/

//1.原料流转链表生成函数
void material_zijin_gai();

//2.原料资金流转记录
float sum_money(PUR*trans);//传给我一个原料结构体类型链表表头

//3.原料按时间遍历
void material_time_search();

//4.原料按编号遍历
void material_bianhao_search();

//5.每一笔原料导出
void material_zijin_txt();

//6.原料链表删除
void delete_material();

void other_sort();


/*-------------------------------------------------*/

int isnum(char a[],int n);      //判断输入的是不是数字（用于检测手机号）

int phone_repeat(char *phone);


VIP* tobe_vip();            //注册vip
//会员结构体需要在主函数设置头尾两个指针，head_v,rear_v;

void isvip(int money);                   //输入账号密码判断是否为vip

VIP* vip_login();

void choujiang(VIP*p);

void pass_change(VIP*p);

void F_inputVip(VIP*head);

void _inputVip(VIP*head);

/*------------------------------------------------------*/

int time_hefa(char* extra);             //判断输入的日期是否合法

int bianhao_hefa(char* bb);           //判断输入的编号是否合法

int bianhao_hefa1(char* bb);

void xs_timesearch();  //按时间查找销售记录

void xs_goodssearch();

void xs_dingdansearch();


void Print(SELL*head);

void PRINTf(SELL*p);


void dingdan_wenjiandu();


/*--------------------------------------------------------*/

void PRINTxinxi();

void PRINTF(SHOP*p);

void buy(SHOP*q);//传入此次购买购物车链表的头节点并复制

int xiaoshou_jiancha(SHOP*p,int key);//传入购物车链表头节点，检查原料是否充足

SHOP *Recommend(SHOP*p);

int shop_car();

void wenjian_ding(SELL*head);//需要传入订单节点指针

void dingdan_wenjiandu();

/*-----------------------------------------------------------*/

int kucun_menu();

int jinhuo_menu();

int shoumai_menu();

int time_input(char* timeplus);
void PRINTxinxi();
 void xiaoliangtongji(SELL*head);

// /-------------------------------------------------------------
//（储值数组）拟合并预测
double yuce(int y[35]);

int leap(int year);

void timetrans(char tr_date[11]);

int** search_material(STOCKNOTE*p);

void kucun_jiance();
