
//���������������������ڱ�����ͷ������������������
PUR* jinhuo(int n,PUR* jp_head);

//��ȫ������ͷ��������¼��ѯ����
void jinhuo_cha_all(PUR* head);

//��Ŀ�������ַ�����ȫ������ͷ����ʱ���ѯ
void jinhuo_cha_time(char date[],PUR *head);

//��Ŀ�����ַ�����ȫ������ͷ������Ų�ѯ
void jinhuo_cha_number(char number[],PUR *head);

//��Ŀ�����࣬ȫ������ͷ���������ѯ
void jinhuo_cha_kind(int kind,PUR* head);

//��ԭ������ͷָ�룩������¼�ļ���������
void jinhuo_txt(PUR* head);

//(ȫ������ͷ�����ļ��ж�ȡ����������Ϣ
void jinhuo_read(PUR *head);

//����ʱ������
void jinhuo_sort(PUR* sorthead);

//(ԭ�����࣬����<1,0>������������޸ĺ���
int kucun_gai(int s_kind,int turn,int s_weight);

//��ǰ����ѯ����
void kucun_cha();

//ԭ�ϼ�¼
void yuanliaojilu(SHOP*head);

//��¼��ѯ
void yuanliaojilucha(STOCKNOTE*NOTEhead);

/*--------------------LOGIN-------------------------------------------*/

//�ƶ�����
 void gotoxy(int x,int y);

//���뺯��
int input(char*p,int y);

//��ӡͼ�κ���
void print_picture(int login_time);

//�˵�ѡ����
void loopout(HANDLE hwnd,COORD coord,int count);

//���麯��
int searchchar(char*p,int n);

//�ܱ����麯��
int searchchar_mibao(char*p,int n);

//�ܱ�����
int mibao_hanshu(char*mibao);

//���������ܱ��ĺ���
void mibaoinitial(char*key,FILE*fpointer);

//������������ĺ���
void Passwordinitial(char*key,FILE *fpointer);

//����ϵͳ�ۺϺ���
int  manage_system();

/*--------------------------------------------------*/
//��Ǯ���뺯��
double  search_putin();

//������Ӻ���
int bianhao_plus(char*bianhao);

//��űȽϺ���
int bianhao_cmp(char*A,char*B);

//���ڱȽϺ���
int riqi_cmp(char*A,char*B);

//1.���ʽ���ת�������ɺ���
void all_zijin_gai();

//2.����ת����
int all_bianli();

//3.���ʽ�����ɾ��
void delete_all();

//1.������ת�������ɺ���
void order_zijin_gai();

// 2.�����ʽ���ת��¼
double order_sum_money(SHOP*trans);

//3.��������ʱ�����
void order_time_search();

//4.����������ű���
void order_bianhao_search();

//5.ÿһ�ʶ�������
void order_zijin_txt();

//6.��������ɾ��
void delete_order();

//------//

//1.ԭ����ת�������ɺ���
void material_zijin_gai();

//2.ԭ���ʽ���ת��¼
float sum_money(PUR*trans);

//3.ԭ�ϰ�ʱ�����
void material_time_search();

//4.ԭ�ϰ���ű���
void material_bianhao_search();

//5.ÿһ��ԭ�ϵ���
void material_zijin_txt();

//6.ԭ������ɾ��
void delete_material();

//------//

//1.Ͷ����ת�������ɺ���
void other_zijin_gai();

//2.Ͷ�ʺ���
void touzi(double money);

//3.Ͷ�ʰ�ʱ�����
void other_time_search();

//4.Ͷ�ʰ���ű���
void other_bianhao_search();

//5.ÿһ��Ͷ�ʵ���
void other_zijin_txt();

//6.Ͷ������ɾ��
void delete_other();

//------//

// �ʽ��ѯ
void zijin_cha();

//���ʽ������ļ�����
void zijin_txt();

//�ʽ����ѡ��˵�
int money_manage_choose();

//ʱ�����롪��Ͷ��
int time_input_money(char* timeplus);


/*-------------------------------------------------*/

//1.ԭ����ת�������ɺ���
void material_zijin_gai();

//2.ԭ���ʽ���ת��¼
float sum_money(PUR*trans);//������һ��ԭ�Ͻṹ�����������ͷ

//3.ԭ�ϰ�ʱ�����
void material_time_search();

//4.ԭ�ϰ���ű���
void material_bianhao_search();

//5.ÿһ��ԭ�ϵ���
void material_zijin_txt();

//6.ԭ������ɾ��
void delete_material();

void other_sort();


/*-------------------------------------------------*/

int isnum(char a[],int n);      //�ж�������ǲ������֣����ڼ���ֻ��ţ�

int phone_repeat(char *phone);


VIP* tobe_vip();            //ע��vip
//��Ա�ṹ����Ҫ������������ͷβ����ָ�룬head_v,rear_v;

void isvip(int money);                   //�����˺������ж��Ƿ�Ϊvip

VIP* vip_login();

void choujiang(VIP*p);

void pass_change(VIP*p);

void F_inputVip(VIP*head);

void _inputVip(VIP*head);

/*------------------------------------------------------*/

int time_hefa(char* extra);             //�ж�����������Ƿ�Ϸ�

int bianhao_hefa(char* bb);           //�ж�����ı���Ƿ�Ϸ�

int bianhao_hefa1(char* bb);

void xs_timesearch();  //��ʱ��������ۼ�¼

void xs_goodssearch();

void xs_dingdansearch();


void Print(SELL*head);

void PRINTf(SELL*p);


void dingdan_wenjiandu();


/*--------------------------------------------------------*/

void PRINTxinxi();

void PRINTF(SHOP*p);

void buy(SHOP*q);//����˴ι����ﳵ�����ͷ�ڵ㲢����

int xiaoshou_jiancha(SHOP*p,int key);//���빺�ﳵ����ͷ�ڵ㣬���ԭ���Ƿ����

SHOP *Recommend(SHOP*p);

int shop_car();

void wenjian_ding(SELL*head);//��Ҫ���붩���ڵ�ָ��

void dingdan_wenjiandu();

/*-----------------------------------------------------------*/

int kucun_menu();

int jinhuo_menu();

int shoumai_menu();

int time_input(char* timeplus);
void PRINTxinxi();
 void xiaoliangtongji(SELL*head);

// /-------------------------------------------------------------
//����ֵ���飩��ϲ�Ԥ��
double yuce(int y[35]);

int leap(int year);

void timetrans(char tr_date[11]);

int** search_material(STOCKNOTE*p);

void kucun_jiance();
