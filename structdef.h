//ȫ�ֱ�����

//perchase-------------------------------------------
    typedef struct purchase//ԭ�ϲɹ�����
    {
        char p_date[20];//ʱ��
        int kind;       //ԭ������
        double p_money;//ԭ�Ͻ���
        int weight;     //ԭ������
        char p_number[20];//�������
        struct purchase *p_next;//������һ�ڵ�
    }PUR;

    PUR Cp_head={"0",0,0,0,"0",NULL};//ȫ��������ͷ����ʼ��
    PUR *p_head=&Cp_head;//ȫ������ԭ���ڱ���ͷָ�룬�ڱ���ͷ
    int jin_count=0;//ȫ������������ż�����

//SELL-----------------------------------------------------------
    typedef struct sell //��������
    {
        int drink;      //��Ʒ����
        int taste;      //��ζ
        int temper;     //�¶�
        int sugar;      //���
        int standard;   //���
        int much;        //����
        char s_date[20]; //ʱ��
        char s_number[20];//�µ����
        double money;      //�������
        struct sell *s_next;//������һ�ڵ�
    }SELL;
    /* ��������������������������Ϊint���ţ���ζǰ{}Ϊ��Ʒ��ţ�����Ϊԭ�����ģ�<>Ϊ�۸�--------
        ��񣺡�1���󣻡�2���У���3��С��
        ��Ʒ����1�������̲裻����Ҷ15//10//5g��<15//13//8>��2������裻������30//20//10g+ţ��300//200//100g��<10//8//5>
                ��3�����ȣ������ȶ�20//15//10g��<16//14//10>��4�����̣�������350//250//150g��<12//10//8>
        ��ζ��{1}��1��ţ��ζ��ţ��300g����2����ݮζ����ݮ20g����3������ζ������20g��
                {2}��1����ݮζ����ݮ20g����2������ζ������20g����3������ζ������50g��
                {3}��1���ڿ��ȣ�����ӣ���2��Ĩ��ζ����Ҷ5g����3��������ŵ��ţ��50g��
                {4}��1��ԭζ��������ӣ���2����ݮζ����ݮ20g����3������ζ������20g��
        ��ȣ���1��ȫ�ǣ�30g�ǣ���2������ǣ�15g�ǣ���3�����ǣ�0g��
        �¶ȣ���1���ȣ���2�����£���3���ӱ�


    */
    typedef struct shopping{//���ﳵ�ڵ�;
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

    int sum=0;//��������
    SELL*head=NULL;
    SELL*tail=NULL;//�����ڵ�ͷָ����Ҫ��Ϊȫ�ֱ���;

//ԭ�Ͽ��---------------------------------------------

    int milk=30000; //ţ�̡�1��
    int tea=20000;    //��Ҷ��2��
    int cream=10000;  //���͡�3��
    int coffee=10000; //���ȶ���4��
    int yoghurt=10000;//���̡�5��
    int straw=10000;  //��ݮ��6��
    int grape=10000;  //���ѡ�7��
    int sugar=10000;  //���ǡ�8��


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
    }STOCKNOTE;//������¼������Ʒʱԭ�ϵ�ʹ����� ;

    STOCKNOTE*NOTEhead;
    STOCKNOTE*NOTEtail;


//login---------------------------------------------------
    int count=0;
    int n=5;
    int login_time=0; //�ú������ô���


//money----------------------------------------------------
      double zijin=1000000;//���ʽ�

typedef struct all{
	double all_trans_money;
	char all_name[20];
	char all_formnumber[20];
	char all_time[20];
	struct all *all_next;
}Allform;

    //������ת
    typedef struct order {
        double order_trans_money;        //ת�ƽ��
        char order_formnumber[20];      //������ת���
        char order_time[20];          //ʱ��
        struct order *order_next;     //��һ�ڵ�
    } Orderform;

    //Ͷ����ת
    typedef struct other {
        double other_trans_money;     //����ת�ƽ��
        char other_formnumber[20];    //������ת���
        char other_time[20];        //������תʱ��
        struct other *other_next;  //��һ�ڵ�
    } Otherform;

    //ԭ����ת
    typedef struct material {
        double material_trans_money;     //ԭ��ת�ƽ��
        char material_formnumber[20];       //ԭ����ת���
        char material_time[20];     //ԭ����תʱ��
        struct material *material_next;  //��һ�ڵ�
    } Materialform;

    //��ת��ͷ
    Allform*allhead=NULL,*allwei=NULL,*allp,*allq;
    Orderform*orderhead=NULL,*orderwei=NULL,*orderp,*orderq;//������ת
    Otherform*otherhead=NULL,*otherwei=NULL,*otherp,*otherq;//Ͷ����ת
    Materialform*materialhead=NULL,*materialwei=NULL,*materialp,*materialq; //ԭ����ת
    char all_number[10]="NO0000";
    char other_number[10]="NO0000";
    char order_number[10]="NO0000";
    char material_number[10]="NO0000";


//VIp-------------------------------------------------
    typedef struct Vip
    {
        char phone[100];            //�绰����
        char name[20];
        char mibao[20];
        char vip_pass[100];         //����
        int  score;             //���
        struct Vip* next;       //��һ�ڵ�
    }VIP;

    VIP*head_v,*rear_v;      //д����������ͷ�ڱ��ڵ��β���

//yuceduqu-----------------------------------------------

int d[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int search_result[8][7];

char trtime[7][20];
