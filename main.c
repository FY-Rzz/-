#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include "structdef.h"
#include "announce.h"


int main()
{
    SetConsoleTitleA("��Ʒ�����ϵͳ");  //���ô��ڵı���
    system("mode con cols=300 lines=50 ");//���ô��ڴ�С
    system("color 9E");//���ô�����ɫ
    head_v=(VIP*)malloc(sizeof(VIP));
    head_v->next=NULL;
    FILE* fpvip=fopen("VIPyuan.txt","r");
	while(!feof(fpvip))
    {
    	VIP*pvpv=(VIP*)malloc(sizeof(VIP));
		fscanf(fpvip,"%s %s %s %s %d",pvpv->phone,pvpv->vip_pass,pvpv->name,pvpv->mibao,&pvpv->score);
		pvpv->next=head_v->next;
		head_v->next=pvpv;
	}


    for(;;)
    {
        switch(manage_system())
        {
            case 1://ԭ�Ͻ�������ϵͳ
                for(;;)
                {
                   int p_tag=1;//������һ����־
                   switch(jinhuo_menu())
                   {
                       char cha_time[20];
                       case 1://ԭ�Ͻ���
                           {system("cls");
                           int n;//������������
                           printf("�������������������\t");
                           scanf("%d",&n);
                           jinhuo(n,p_head);
                           printf("ԭ�Ͻ�����ɣ�");
                           system("pause");
                           break ;}
                       case 2://������Ϣ��ѯ
                           {system("cls");
                            printf("\t\t��� 1.   ��ѯȫ��                        ���\n\n");
                            printf("\t\t��� 2.   ��ʱ���ѯ                      ���\n\n");
                            printf("\t\t��� 3.   ��������Ų�ѯ                  ���\n\n");
                            printf("\t\t��� 4.   ��ԭ�������ѯ                  ���\n\n");
                            printf("\t\t��� 0.   ������һ���˵�                  ���\n\n");
                            int ans2=0;
                            scanf("%d",&ans2);
                            switch(ans2)
                            {
                                case 1:
                                    system("cls");
                                    jinhuo_cha_all(p_head);
                                    break ;
                                case 2:
                                    system("cls");

                                    printf("�����������ѯ��ʱ֮��Ľ���������\n");
                                    time_input(cha_time);
                                    jinhuo_cha_time(cha_time,p_head);
                                    break ;
                                case 3:
                                    {system("cls");
                                    printf("�����������ѯ�Ľ�����ţ�\n");
                                    char cha_number[20];
                                    scanf("%s",cha_number);
                                    jinhuo_cha_number(cha_number,p_head);

                                    break ;
                                    }

                                case 4:
                                    {while(1)
                                    {
                                        system("cls");
                                        printf("�����������ѯ��ԭ�����ࣺ\n");
                                        printf("\t\t��� 1.   ţ��                  ���\n\n");
                                        printf("\t\t��� 2.   ��Ҷ                  ���\n\n");
                                        printf("\t\t��� 3.   ����                  ���\n\n");
                                        printf("\t\t��� 4.   ���ȶ�                ���\n\n");
                                        printf("\t\t��� 5.   ����                  ���\n\n");
                                        printf("\t\t��� 6.   ��ݮ                  ���\n\n");
                                        printf("\t\t��� 7.   ����                  ���\n\n");
                                        printf("\t\t��� 8.   ����                  ���\n\n");
                                        printf("\t\t��� 0.   ������һ���˵�        ���\n\n");

                                        int cha_kind=0;
                                        scanf("%d",&cha_kind);
                                        if(cha_kind)
                                        {
                                            jinhuo_cha_kind(cha_kind,p_head);
                                            break ;
                                        }
                                        if(!cha_kind)
                                            break ;
                                        printf("���������������������룡");
                                        Sleep(2000);
                                    }
                                    break ;}
                                case 0:
                                    break ;
                            }
                            system("pause");
                            break ;}
                        case 3://������Ϣ�ļ�����
                            system("cls");
                            jinhuo_txt(p_head);
                            system("pause");
                            break ;
                        case 4://���ļ��ж�ȡ������Ϣ
                            system("cls");
                            jinhuo_read(p_head);
                            system("pause");
                            break ;
                        case 0:
                            p_tag=0;
                            break ;

                   }
                   if(!p_tag)
                        break ;
                }
                break ;
            case 2://��Ʒ��������ϵͳ
                for(;;){
                    int s_tag=0;
                    //SELL*head1;

                    switch(shoumai_menu())
                    {

                  	case 1:shop_car();
                        system("pause");
                        break;
                  	case 2:
						for (;;)
                        {
                            int fanhui1 = 1, jhuo;
                            do {
                                system("CLS");
                                printf("\n\n\t\t===============================��Ʒ��Ϣ��ѯϵͳ======================\n\n");
                                printf("\t\t��� 1.   ��ʱ���ѯ                      ���\n\n");
                                printf("\t\t��� 2.   ����Ʒ��ѯ                      ���\n\n");
                                printf("\t\t��� 3.   ��������ѯ                      ���\n\n");
                                printf("\t\t��� 4.   ��ѯȫ������                        ���\n\n");
								printf("\t\t��� 0.   ������һ��                          ���\n\n");
								printf("\t\t��ѡ����Ҫ���е�ѡ�0-4)");

								scanf("%d", &jhuo);
                                if (jhuo < 0 || jhuo>4)
                                {
                                    printf("\n\n���벻����Ҫ����������ȷ����Ϣ��\n\n");
                                    Sleep(1000);
                                }
                            } while (jhuo < 0 || jhuo>4);
                            switch (jhuo)
                            {
                                case 1:
                                    system("CLS");
								    xs_timesearch();
								    system("PAUSE");
                                    break;
                                case 2:
									system("CLS");
									xs_goodssearch();
									system("PAUSE");
                                    break;
                                case 3:
									system("CLS");
									xs_dingdansearch();
									system("PAUSE");
                                    break;
                                case 4:
                                	system("CLS");
								    Print(head);
								    printf("\t��ѯ���\n");
									system("pause");
                                    break;

                                case 0:
                                	system("CLS");
                                	fanhui1 = 0;
                                    break;
                            }
                            if (!fanhui1)
                                break;
                        }
                        break;

                  	case 3:{SELL*o=head;
                  	    wenjian_ding(o);system("pause");}
                        break;
                    case 4:
                        {SELL*o=head;xiaoliangtongji(o);system("pause");}
                        break;
                  	case 0:
                  	    s_tag=1;
                        break;
				  }
				  if(s_tag)
                    break ;
             }
             break ;

            case 3://ԭ�Ͽ��
                for(;;)
                {
                    int ku_tag=0;
                    switch(kucun_menu())
                    {
                        case 1:
                            system("cls");
                            kucun_cha();
                            system("pause");
                            system("cls");
                            break ;
                        case 2:{
                            system("cls");
                            STOCKNOTE*o=NOTEhead;
                            yuanliaojilucha(o);
                            system("pause");}break;
                        case 3:
                        {
                            system("cls");
                            kucun_jiance();
                            system("pause");
                            break ;
                        }
                        case 0:
                            ku_tag=1;
                    }
                    if(ku_tag)
                        break ;
                }
                break ;

            case 4://ip����ϵͳ
                for(;;)
				{
					int fhui=1;
					VIP*pvip,*pvip2;
					char vipc[29];
					system("CLS");
					do{
                        system("cls");
					    printf("\n\n\t\t===============================��Ա����ϵͳ======================\n\n");
                        printf("\t\t��� 1.   ע���Ա                      ���\n\n");
                        printf("\t\t��� 2.   �˻�����                      ���\n\n");
                        printf("\t\t��� 3.   ��ӡȫ����Ա��Ϣ              ���\n\n");
                        printf("\t\t��� 4.   �ļ�������Ա��Ϣ              ���\n\n");
                        printf("\t\t��� 0.   ������һ���˵�                ���\n\n");
                        printf("\t\t��ѡ����Ҫ���е�ѡ�0-4��");
                        scanf("%s",vipc);
                        if(strlen(vipc)!=1||vipc[0]<'0'||vipc[0]>'4')
                        {
                        	printf("\n���벻����Ҫ����������ȷ����Ϣ��\n");
                            Sleep(1000);
						}
				   }while(strlen(vipc)!=1||vipc[0]<'0'||vipc[0]>'4');
					switch(vipc[0]-'0')
					{
						case 1:
							system("cls");
						    pvip2=tobe_vip();
						    if(pvip2)
						    printf("\t��Աע��ɹ�!\n");
						    system("pause");
						    break;
						case 2:
							system("cls");
							lala:
							pvip=vip_login();
							if(!pvip){break;}
							la:
							system("cls");
							printf("\n\t��������Ҫִ�е�ѡ��:");
							printf("\n\t1.�޸�����");
							printf("\n\t2.�齱������200���֣�");
							printf("\n\t3.�˳���¼\n");
							scanf("%s",vipc);
							switch(vipc[0]-'0')
							{
								case 1:pass_change(pvip);break;
								case 2:choujiang(pvip);break;
								case 3:goto lala;
							}
							goto la;
							system("pause");
							break;
						case 0:
							system("cls");
							fhui=0;
							break;
						case 3:
							system("cls");
							_inputVip(head_v);
							system("pause");
							break;
						case 4:
						    system("cls");
							F_inputVip(head_v);
							system("pause");
							break;
					}
					if(!fhui) break;
				}break;





			case 5://�ʽ����ϵͳ

				while(1) {
					int m_tag=1;
					//char money_get=money_manage_choose();
					double touzi_money;

					switch(money_manage_choose()) {
						case '1'://���ʽ�
							zijin_txt();//��ʾ��txt�ı�
							system("cls");
							zijin_cha();//������ʾ
							system("pause");
							break;

						case '2'://����txt
							system("cls");
							order_zijin_txt();
							break;

						case '3'://ԭ��txt
							system("cls");
							material_zijin_txt();
							break;

						case '4'://Ͷ��txt
							system("cls");
							other_zijin_txt();
							break;

						case '5'://Ͷ��
							system("cls");
							printf("����0�˳�:\n");
							printf("������Ͷ�ʽ��:");
							touzi_money=search_putin();
							//scanf("%lf",&touzi_money);
							if(touzi_money<=0)break;
							else touzi(touzi_money);
							break;

						case '6'://Ͷ��
							system("cls");
							all_bianli();
							break;

						case 0:
							m_tag=0;
							break;
					}
					if(!m_tag)break;
				}//while
				break ;

        }

    }
    return 0;
}

int kucun_menu()
{
    int ans;
    do{
        system("cls");
        printf("\n\n\t\t==============================������ϵͳ============================\n\n");
        printf("\t\t��� 1.   ԭ�����п���ѯ              ���\n\n");
        printf("\t\t��� 2.   ԭ��ʹ�ü�¼��ѯ              ���\n\n");
        printf("\t\t��� 3.   ������������              ���\n\n");
        printf("\t\t��� 0.   ������һ���˵�                ���\n\n");
        printf("\t\t--------------------------------------------\n\n");
        printf("\t\t��ѡ����Ҫ���е�ѡ�0-3��");
        scanf("%d",&ans);
        if(ans<0||ans>3)
        {
            printf("\n\n���벻����Ҫ����������ȷ����Ϣ��\n\n");
            Sleep(1000);
        }
    }while(ans<0||ans>3);
    return ans;
}

int jinhuo_menu()
{
    int ans;
    do{
        system("cls");
        printf("\n\n\t\t===============================ԭ�Ͻ�������ϵͳ======================\n\n");
        printf("\t\t��� 1.   ԭ�Ͻ���                      ���\n\n");
        printf("\t\t��� 2.   ������Ϣ��ѯ                  ���\n\n");
        printf("\t\t��� 3.   ������Ϣ�ļ�����              ���\n\n");
        printf("\t\t��� 4.   ���ļ��ж�ȡ������Ϣ          ���\n\n");
        printf("\t\t��� 0.   ������һ���˵�                ���\n\n");
        printf("\t\t-------------------------------------------------------------------------\n\n");
        printf("\t\t��ѡ����Ҫ���е�ѡ�0-4��");
        scanf("%d",&ans);
        if(ans<0||ans>4)
        {
            printf("\n\n���벻����Ҫ����������ȷ����Ϣ��\n\n");
            Sleep(1000);
        }
    }while(ans<0||ans>4);
    return ans;
}

int shoumai_menu()
{
    int ans;
    do{
        system("cls");
        printf("\n\n\t\t===============================��Ʒ��������ϵͳ======================\n\n");
        printf("\t\t��� 1.   ��Ʒ����                         ���\n\n");
        printf("\t\t��� 2.   ��Ʒ������Ϣ��ѯ                 ���\n\n");
        printf("\t\t��� 3.   ��Ʒ������Ϣ��Ϣ�ļ�����         ���\n\n");
        printf("\t\t��� 4.   ��Ʒ����ͳ��                     ���\n\n");
        printf("\t\t��� 0.   ������һ���˵�                   ���\n\n");
        printf("\t\t--------------------------------------------\n\n");
        printf("\t\t��ѡ����Ҫ���е�ѡ�0-4��");
        scanf("%d",&ans);
        if(ans<0||ans>4)
        {
            printf("\n\n���벻����Ҫ����������ȷ����Ϣ��\n\n");
            Sleep(1000);
        }
    }while(ans<0||ans>4);
    return ans;
}



int time_input(char* timeplus) { //(ʱ��洢����)ʱ���ʽ����
	int judge,year,month,day;
	int i,k;
	char extra[20];
	while(1) {
		scanf("%s",extra);
		if(strlen(extra)!=10||extra[4]!='.'||extra[7]!='.'||extra[0]=='.'||extra[1]=='.'||extra[2]=='.'||extra[3]=='.'||extra[5]=='.'||extra[6]=='.'||extra[8]=='.'||extra[9]=='.') {
			judge=0;
		}else {
			for(i=0;i<10;i++) {
				if(i!=4&&i!=7) {
					if((extra[i]<'0'||extra[i]>'9')) {
						judge=0;
						break;
					} else {
						judge=1;
					}
				}
			}
			year=(extra[0]-'0')*1000+(extra[1]-'0')*100+(extra[2]-'0')*10+(extra[3]-'0');
			month=(extra[5]-'0')*10+(extra[6]-'0');
			day=(extra[8]-'0')*10+(extra[9]-'0');
			if(year<2021) judge=0;
			if(month<1||month>12)judge=0;
			if((year%4==0&&year%100!=0)||(year%400==0))
            {
                if((month==2)&&(day<1||day>29))judge=0;
            }
            else
            {
                if((month==2)&&(day<1||day>28))judge=0;
            }
			switch(month){
			case 1:if(day<1||day>31)judge=0;break;
			case 3:if(day<1||day>31)judge=0;break;
            case 5:if(day<1||day>31)judge=0;break;
            case 7:if(day<1||day>31)judge=0;break;
            case 8:if(day<1||day>31)judge=0;break;
            case 10:if(day<1||day>31)judge=0;break;
            case 12:if(day<1||day>31)judge=0;break;
			case 4:if(day<1||day>30)judge=0;break;
            case 6:if(day<1||day>30)judge=0;break;
            case 9:if(day<1||day>30)judge=0;break;
            case 11:if(day<1||day>30)judge=0;break;
			}
		}
			if(judge){
			break ;}else{
			printf("�������벻����ʵ�ʣ�����������\n");}
	}
     for( i=0,k=0; i<10; i++) {
		 timeplus[k++]=extra[i];
	}
	timeplus[10]='\0';
	return 1;
}

//--------------------------------VIP-------------------------------------------
int isnum(char a[],int n)      //�ж�������ǲ������֣����ڼ���ֻ��ţ�
{   int i=0;
    for(;i<n;i++) if(a[i]>'9'||a[i]<'0') return 0;
    return 1;
}

int phone_repeat(char *phone)
{
    VIP*p=head_v->next;
    while(p)
    {
        if(strcmp(phone,p->phone)==0) return 0;  //0Ϊ�ظ�
        p=p->next;
    }
    return 1;
}

VIP* tobe_vip()            //ע��vip
//��Ա�ṹ����Ҫ������������ͷβ����ָ�룬head_v,rear_v;
{
    system("CLS");
    VIP* pp=(VIP*)malloc(sizeof(VIP));
    pp->next=NULL;
    char Phone[30],password1[30],mi1[30],vv[30],xingming[30];
    int flag=1,len1;
    do
    {
        if(flag==0) printf("�����ʽ������ظ�������������\n");
        else printf("����������ֻ��ţ�\n");
        scanf("%s",Phone);
        len1=strlen(Phone);
        flag=0;
    }while(len1!=11||!isnum(Phone,len1)||!phone_repeat(Phone));


    flag=1;
    do
    {
        if(flag==0)  printf("������������������\n");
        printf("�������������(������15λ)��\n");
        scanf("%s",password1);
        flag=0;
    }while(strlen(password1)>15);        //���벻����16λ


    printf("\n��������������:");
    scanf("%s",xingming);

    printf("\n�����롰��ĸ�����˭�����Ĵ���Ϊ�ܱ���");
    scanf("%s",mi1);
    printf("\nȷ��ע���Ա��(����1ȷ��ע��)");
    scanf("%s",vv);
    if(strlen(vv)!=1||vv[0]!='1')
    {
        printf("\n����ע��ȡ��");
        return NULL;
    }
    else
    {
        strcpy(pp->mibao,mi1);
        strcpy(pp->phone,Phone);
        strcpy(pp->name,xingming);
        strcpy(pp->vip_pass,password1);
        pp->score=0;
        pp->next=head_v->next;
        head_v->next=pp;
        return pp;
    }
}

void isvip(int money)                  //�����˺������ж��Ƿ�Ϊvip
{
    char s[20],dianhua[20];
    //int flag=1;
    printf("\n���Ƿ�ΪVIP�ͻ�?(����1ȷ��)");
    scanf("%s",s);
    if(strlen(s)==1&&s[0]=='1')
    {
	    queren1:
        printf("\n\t���������ĵ绰����ȷ�����:");
        scanf("%s",dianhua);
        if(strlen(dianhua)!=11||!isnum(dianhua,11)){printf("�ֻ��Ÿ�ʽ����\n");goto queren1;}
        VIP*p=head_v->next;
        while(p)
        {
            if(strcmp(p->phone,dianhua)==0) break;
            p=p->next;
        }
        if(p==0)
        {
            printf("�˻�������,�Ƿ��ٴ����룿������1ȷ�ϣ�");
            scanf("%s",s);
            if(strlen(s)==1&&s[0]=='1') goto queren1;
            else return;
        }
        else
        {
            printf("�˻��ɹ���%d��",money);
            p->score+=money;

        }
    }
    else
    {
        printf("\n���Ƿ����ΪVIP�ͻ���(����1ȷ��)");
        scanf("%s",s);
        if(strlen(s)!=1||s[0]!='1') return;
        else
        {
            VIP*pv=tobe_vip();
            if(pv==NULL)
            {
                printf("\n����ע�ᣬ�����޻���");
            }
            else
            {
                printf("\nע��ɹ����ɹ���%d��",money);
                pv->score+=money;
            }
            return;
        }
    }
}



VIP* vip_login()           //��Ա����
{
    char ca[30],ph[30],pa[30],bao[30];
    VIP*p=head_v->next;
    shuru:             //�����Ƿ�Ϸ����ص�ַ
    system("CLS");
    printf("\t��ѡ��:\n");
    printf("\t1;�����¼\n\t2;��������\n\t3.������һ��\n");
    scanf("%s",ca);
    if(strlen(ca)==1&&ca[0]=='3') return NULL;  //������һ��
	if(strlen(ca)!=1||(ca[0]!='1'&&ca[0]!='2'))
	{
		printf("\n�����ʽ������Ҫ������������");
        goto shuru;
	}
    ph1:                               //�ֻ������뷵�صص�
    printf("\n�����������ֻ����룺");
    scanf("%s",ph);
    if(strlen(ph)!=11||!isnum(ph,11))
        {printf("�ֻ��Ÿ�ʽ����\n");goto ph1;}
    while(p)
    {
        if(strcmp(p->phone,ph)==0) break;
        p=p->next;
    }

    if(strlen(ca)==1&&ca[0]=='1')       //ѡ�������¼
    {
        printf("\n����������:");
        scanf("%s",pa);
        if(p==NULL||strcmp(p->vip_pass,pa)!=0)
        {
            printf("\n�ֻ��Ż�����������������룡");
            goto ph1;
        }
        else
        {
            printf("��½�ɹ���");
            Sleep(1000);
            return p;

        }
    }
    else        //ѡ���������룬�ܱ���¼
    {
        printf("\n���������⡰��ĸ�����˭���Ĵ�:");
        baohu:         //���������ܱ�
        scanf("%s",bao);
        if(strcmp(p->mibao,bao)==0)
        {
            printf("\n������ȷ,�����ѱ���ʼ��Ϊ123456");
            Sleep(1000);
            strcpy(p->vip_pass,"123456");
            return p;
        }
        else
        {
            printf("\n�����������������:");
            goto baohu;
        }
    }

}



void choujiang(VIP*p)
{
    system("CLS");
    if(p->score<200) {printf("���Ļ��ֲ���\n");system("pause");return;}
    printf("\t��Ʒ������\n");
    printf("\t�صȽ�����2%��\n");
    printf("\tһ�Ƚ�����5%��\n");
    printf("\t���Ƚ�����10%��\n");
    printf("\t���Ƚ�����23%��\n");
    printf("\t���뽱����60%��\n");
    srand((unsigned)time(NULL));
    int n=rand()%100;
    p->score-=200;
    if(n==0||n==1){printf("��ϲ������صȽ�\n");system("pause");}
    if(n>=2&&n<=6){printf("��ϲ�����һ�Ƚ�\n");system("pause");}
    if(n>=7&&n<=16){printf("��ϲ����ж��Ƚ�\n");system("pause");}
    if(n>=17&&n<=39){printf("��ϲ��������Ƚ�\n");system("pause");}
    if(n>=40&&n<=99){printf("������˲��뽱\n");system("pause");}
}

void pass_change(VIP*p)
{
    char pass[39];
    printf("���������ԭ���룺");
    scanf("%s",pass);
    while(strcmp(p->vip_pass,pass)!=0){printf("\t�������\n");scanf("%s",pass);}
    printf("��������������룺");
    scanf("%s",pass);
    while(strlen(pass)>15){printf("\t���볤�ȹ���");scanf("%s",pass);}
    strcpy(p->vip_pass,pass);
    printf("�����޸ĳɹ�");
    Sleep(1000);
}


void F_inputVip(VIP*head)
{
    VIP*pp=head->next;
    if(!pp)
	{
		printf("\t��ʱ��û�л�Ա��Ϣ.\n");
		return;
	}
    FILE*fp;
    fp=fopen("VIPsystem.txt","w");
    fprintf(fp,"\t��Ա����\t\t\t����\n");
    while(pp)
    {
        fprintf(fp,"\t%s\t\t%d\n",pp->phone,pp->score);
        pp=pp->next;
    }
    fclose(fp);
}
void _inputVip(VIP*head)
{
	system("CLS");
	printf("\t��Ա����\t\t\t����\t\t\t����\n");
	VIP*pp=head->next;
	if(!pp)
	{
		printf("\t��ʱ��û�л�Ա��Ϣ.\n");
		return;
	}
    while(pp)
    {
        printf("\t%s\t\t\t%s\t\t\t%d\n",pp->phone,pp->vip_pass,pp->score);
        pp=pp->next;
    }
}



//---------------------------------jinhuo----------------------------------------------

PUR* jinhuo(int n,PUR* jp_head)//���������������������ڱ�����ͷ������������������
{
    int i;
    PUR* j_head,*tmp,*q;
    char tmp_time[20];
    while(n<=0)
    {
        printf("������Ϸ����֣�\n");
        scanf("%d",&n);
    };
    q=j_head=jp_head;
    while(j_head->p_next!=NULL)//��λ��ǰβ����
    {
        j_head=j_head->p_next;
    }
    q=j_head;
    printf("�����뱾�βɹ�ʱ�䣨2021.xx.xx):\t");
    time_input(tmp_time);//ʱ�����뺯��
    for(i=0;i<n;i++,jin_count++)
    {
        double mmm;//�ݴ��ʽ�
        printf("\n������� %d �ʶ�����Ϣ��\n",i+1);
        printf("\n��ԭ��������Ϣ�����ִ��棺1.ţ�� 2.��Ҷ 3.���� 4.���ȶ� 5.���� 6.��ݮ 7.���� 8.����||������λĬ��Ϊ�ˡ�\n\n");
        char str[20]={'0','0','0','0'};
        sprintf(str,"%03d",jin_count);
        tmp=(PUR*)malloc(sizeof(PUR));

        printf("ԭ �� �� �� ��\t");
        do{
            scanf("%d",&tmp->kind);
            if(tmp->kind<0||tmp->kind>8)
                printf("��������ȷ�����࣡\n");
        }while(tmp->kind<0||tmp->kind>8);

        strcpy(tmp->p_date,tmp_time);//ʱ��

        printf("ԭ �� �� �� ��\t");
        //scanf("%lf",&tmp->p_money);
        mmm=search_putin();
        tmp->p_money=mmm;

        printf("ԭ �� �� �� ��\t");
        do{
            scanf("%d",&tmp->weight);
            if(tmp->weight<0)
                printf("��������ȷ��������\n");
        }while(tmp->weight<0);

        //�����������
         for(int i=0,k=0;i<10;i++)
        {
            if(i!=4&&i!=7)
            {
                tmp->p_number[k]=tmp->p_date[i];
                k++;
            }
        }
        tmp->p_number[8]='\0';
        strcat(tmp->p_number,str  );

        q->p_next=tmp;//��ǰβ��������������
        tmp->p_next=NULL;
        q=q->p_next;
        /*����޸ĺ���*/
        kucun_gai(tmp->kind,1,tmp->weight);

    }
    sum_money(j_head->p_next);
    jinhuo_sort(p_head);
    return jp_head;
}

void jinhuo_cha_all(PUR* head)//��ȫ������ͷ��������¼��ѯ����
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("Ŀǰ���޽�����¼��\n");
        system("pause");
        return ;
    }
    printf("ԭ�Ͻ�����¼���£�\n");
    printf("\t\t---�������---\t\t---����---\t\t---����---\t\t---����---\t\t---ʱ��---\n");

    while(tmpP!=NULL)
    {
        printf("\t\t%s",tmpP->p_number);
        switch(tmpP->kind)
        {
            case 1:printf("\t\tţ��\t\t");break;
            case 2:printf("\t\t��Ҷ\t\t");break;
            case 3:printf("\t\t����\t\t");break;
            case 4:printf("\t\t���ȶ�\t\t");break;
            case 5:printf("\t\t����\t\t");break;
            case 6:printf("\t\t��ݮ\t\t");break;
            case 7:printf("\t\t����\t\t");break;
            case 8:printf("\t\t����\t\t");break;
        }
        printf("\t%.2lf\t",tmpP->p_money);
        printf("\t\t%d\t",tmpP->weight);
        printf("\t\t%s\n",tmpP->p_date);
        tmpP=tmpP->p_next;
    }

    printf("\n------------------------------------------------------------------------------------");
    printf("\n��ѯ������\n\n");


}

void jinhuo_cha_time(char date[],PUR *head)//��Ŀ�������ַ�����ȫ������ͷ����ʱ���ѯ
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("Ŀǰ���޽�����¼��\n");
        system("pause");
        return ;
    }
    printf("��Ӧ���ں�ԭ�Ͻ�����¼���£�\n");
    printf("\t\t---�������---\t\t---����---\t\t---����---\t\t---����---\t\t---ʱ��---\n");

    while(tmpP!=NULL)
    {
        if(strcmp(date,tmpP->p_date)<0||strcmp(date,tmpP->p_date)==0)//��ʱ�䲻����Ҫ�������
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\tţ��\t\t");break;
                case 2:printf("\t\t��Ҷ\t\t");break;
                case 3:printf("\t\t����\t\t");break;
                case 4:printf("\t\t���ȶ�\t\t");break;
                case 5:printf("\t\t����\t\t");break;
                case 6:printf("\t\t��ݮ\t\t");break;
                case 7:printf("\t\t����\t\t");break;
                case 8:printf("\t\t����\t\t");break;
            }
            printf("\t%.2lf\t",tmpP->p_money);
            printf("\t\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
        }
        tmpP=tmpP->p_next;
    }

    printf("\n-------------------------------------------------------------------------------------");
    printf("\n��ѯ������\n\n");
}

void jinhuo_cha_number(char number[],PUR *head)//��Ŀ�����ַ�����ȫ������ͷ������Ų�ѯ
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("Ŀǰ���޽�����¼��\n");
        system("pause");
        return ;
    }
    printf("��Ӧ���ԭ�Ͻ�����¼���£�\n");
    printf("\t\t---�������---\t\t---����---\t\t---����---\t\t---����---\t\t---ʱ��---\n");

    while(tmpP!=NULL)
    {
        if(strcmp(number,tmpP->p_number)==0)
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\tţ��\t\t");break;
                case 2:printf("\t\t��Ҷ\t\t");break;
                case 3:printf("\t\t����\t\t");break;
                case 4:printf("\t\t���ȶ�\t\t");break;
                case 5:printf("\t\t����\t\t");break;
                case 6:printf("\t\t��ݮ\t\t");break;
                case 7:printf("\t\t����\t\t");break;
                case 8:printf("\t\t����\t\t");break;
            }
            printf("\t%.2lf\t",tmpP->p_money);
            printf("\t\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
            printf("\n---------------------------------------------------------------------------------");
            printf("\n ��ѯ������\n\n");
            return ;
        }
        tmpP=tmpP->p_next;
    }

    printf("\n-----------------------------------------------------------------------");
    printf("\n ��ѯʧ�ܣ�δ�ҵ���Ӧ��ţ�\n\n");
}

void jinhuo_cha_kind(int kind,PUR* head)//��Ŀ�����࣬ȫ������ͷ���������ѯ
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("Ŀǰ���޽�����¼��\n");
        system("pause");
        return ;
    }
    printf("��Ӧԭ�����������¼���£�\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t---�������---\t\t---����---\t\t---����---\t\t---����---\t\t---ʱ��---\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    while(tmpP!=NULL)
    {
        if(kind==tmpP->kind)
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\tţ��\t\t");break;
                case 2:printf("\t\t��Ҷ\t\t");break;
                case 3:printf("\t\t����\t\t");break;
                case 4:printf("\t\t���ȶ�\t\t");break;
                case 5:printf("\t\t����\t\t");break;
                case 6:printf("\t\t��ݮ\t\t");break;
                case 7:printf("\t\t����\t\t");break;
                case 8:printf("\t\t����\t\t");break;
            }
            printf("\t%.2lf",tmpP->p_money);
            printf("\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
        }
        tmpP=tmpP->p_next;
    }

    printf("\n---------------------------------------------------------------------------");
    printf("\n��ѯ������\n\n");
}

void jinhuo_txt(PUR* head)//��ԭ������ͷָ�룩������¼�ļ���������
{
    PUR* p_head=head->p_next;
    FILE *fjp=NULL;

    if((fjp=fopen("����������Ϣ����.txt","w"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        return ;
    }



    while(p_head!=NULL)
    {
        fprintf(fjp,"%s",p_head->p_number);
        fprintf(fjp,"\t\t%s",p_head->p_date);
        switch(p_head->kind)
        {
            case 1:fprintf(fjp,"\t\tţ��\t\t");break;
            case 2:fprintf(fjp,"\t\t��Ҷ\t\t");break;
            case 3:fprintf(fjp,"\t\t����\t\t");break;
            case 4:fprintf(fjp,"\t\t���ȶ�\t\t");break;
            case 5:fprintf(fjp,"\t\t����\t\t");break;
            case 6:fprintf(fjp,"\t\t��ݮ\t\t");break;
            case 7:fprintf(fjp,"\t\t����\t\t");break;
            case 8:fprintf(fjp,"\t\t����\t\t");break;
        }
        fprintf(fjp,"\t\t%lf",p_head->p_money);
        fprintf(fjp,"\t\t%d\n",p_head->weight);

        p_head=p_head->p_next;
    }

    fclose(fjp);
    printf("�ļ�������ɣ�\n\n");

}

void jinhuo_read(PUR *head)//(ȫ������ͷ�����ļ��ж�ȡ����������Ϣ
{
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t---�������---\t\t---ʱ��---\t\t---����---\t\t---����---\t\t---����---\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    char jr_date[20];//ʱ��
    char jr_kind[20];       //ԭ������
    double jr_money;    //ԭ�ϵ���
    int jr_weight;     //ԭ������
    char jr_number[20];//�������
    PUR *q,*r_head,*tmp;
    q=r_head=head;
    while(r_head->p_next!=NULL)
    {
        r_head=r_head->p_next;
    }
    q=r_head;//qΪ��ǰβ����

    FILE *jh;
    jh=fopen("����������Ϣ����.txt","rt");
    while(fscanf(jh,"%s\t\t%s\t\t%s\t\t\t\t%lf\t\t%d\n",jr_number,jr_date,jr_kind,&jr_money,&jr_weight)!=EOF)
    {

        printf("\t\t%s\t\t%s\t\t%s\t\t\t\t%.2lf\t\t%d\n",jr_number,jr_date,jr_kind,jr_money,jr_weight);//���ļ���Ϣ���

        //���ļ���Ϣ��������
        tmp=(PUR*)malloc(sizeof(PUR));

        //tmp->kind=jr_kind;
        if(strcmp("ţ��",jr_kind)==0)
            tmp->kind=1;
        if(strcmp("��Ҷ",jr_kind)==0)
            tmp->kind=2;
        if(strcmp("����",jr_kind)==0)
            tmp->kind=3;
        if(strcmp("���ȶ�",jr_kind)==0)
            tmp->kind=4;
        if(strcmp("����",jr_kind)==0)
            tmp->kind=5;
        if(strcmp("��ݮ",jr_kind)==0)
            tmp->kind=6;
        if(strcmp("����",jr_kind)==0)
            tmp->kind=7;
        if(strcmp("����",jr_kind)==0)
            tmp->kind=8;

        kucun_gai(tmp->kind,1,jr_weight);//�޸Ŀ��
        strcpy(tmp->p_date,jr_date);
        strcpy(tmp->p_number,jr_number);
        tmp->weight=jr_weight;
        tmp->p_money=jr_money;
        tmp->p_next=NULL;
        sum_money(tmp);//�޸��ʽ�
        q->p_next=tmp;//��������
        q=q->p_next;

    }
    fclose(jh);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("�ļ���ȡ��ϣ�\n\n");
    jinhuo_sort(p_head);
}

int kucun_gai(int s_kind,int turn,int s_weight)//(ԭ�����࣬����<1,0>������������޸ĺ���
{
    int k_flag=1;
    switch(s_kind)
    {
        case 1:
            {
                if(turn)
                    milk+=s_weight;
                else
                {
                    if(milk>s_weight)
                        milk-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ţ�� ");
                         k_flag=0;
                    }

                }
                break;
            }
        case 2:
            {
                if(turn)
                    tea+=s_weight;
                else
                {
                    if(tea>s_weight)
                        tea-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ��Ҷ ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 3:
            {
                if(turn)
                    cream+=s_weight;
                else
                {
                    if(cream>s_weight)
                        cream-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ���� ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 4:
            {
                if(turn)
                    coffee+=s_weight;
                else
                {
                    if(coffee>s_weight)
                        coffee-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ���� ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 5:
            {
                if(turn)
                    yoghurt+=s_weight;
                else
                {
                    if(yoghurt>s_weight)
                        yoghurt-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ���� ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 6:
            {
                if(turn)
                    straw+=s_weight;
                else
                {
                    if(straw>s_weight)
                        straw-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ��ݮ ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 7:
            {
                if(turn)
                    grape+=s_weight;
                else
                {
                    if(grape>s_weight)
                        grape-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ���� ");
                         k_flag=0;
                    }
                }
                break;
            }
        case 8:
            {
                if(turn)
                    sugar+=s_weight;
                else
                {
                    if(sugar>s_weight)
                        sugar-=s_weight;
                    else
                    {
                         printf("����ʧ�ܣ�����\n");
                         printf(" ���� ");
                         k_flag=0;
                    }
                }
                break;
            }
        default:
            {
                printf("��ѡ����ȷ�����࣡\n");
                return 0;
            }
        if(k_flag==0)
        {
            printf(" ��治�㣬�뼰ʱ���䣡\n");
            return 0;
        }
        return 1;

    }
    return 1;

}

void kucun_cha()//��ǰ����ѯ����
{
    printf("\n--------------------------------------------\n");
    printf(" ţ��   ��ǰ���Ϊ��%d g\n",milk);
    printf(" ��Ҷ   ��ǰ���Ϊ��%d g\n",tea);
    printf(" ����   ��ǰ���Ϊ��%d g\n",cream);
    printf(" ���ȶ� ��ǰ���Ϊ��%d g\n",coffee);
    printf(" ����   ��ǰ���Ϊ��%d g\n",yoghurt);
    printf(" ��ݮ   ��ǰ���Ϊ��%d g\n",straw);
    printf(" ����   ��ǰ���Ϊ��%d g\n",grape);
    printf(" ����   ��ǰ���Ϊ��%d g\n",sugar);
    printf("        ��ѯ������     \n\n");
    printf("--------------------------------------------\n");
}





//--===================================SEARCH==============================================

int time_hefa(char* extra) { //(ʱ��洢����)ʱ���ʽ����
	int judge,year,month,day;
	int i,k;
	if(strlen(extra)!=10||extra[4]!='.'||extra[7]!='.'||extra[0]=='.'||extra[1]=='.'||extra[2]=='.'||extra[3]=='.'||extra[5]=='.'||extra[6]=='.'||extra[8]=='.'||extra[9]=='.') {
		return 0;
	}
	for(i=0;i<10;i++) {
		if(i!=4&&i!=7) {
			if((extra[i]<'0'||extra[i]>'9')) {
				return 0;
			}
		}
	}
	year=(extra[0]-'0')*1000+(extra[1]-'0')*100+(extra[2]-'0')*10+(extra[3]-'0');
	month=(extra[5]-'0')*10+(extra[6]-'0');
	day=(extra[8]-'0')*10+(extra[9]-'0');
	if(year<2021) return 0;
	if(month<1||month>12) return 0;
	if((year%4==0&&year%100!=0)||(year%400==0))
    {
        if((month==2)&&(day<1||day>29))return 0;
    }
    else
    {
        if((month==2)&&(day<1||day>28))return 0;
    }
	switch(month){
	case 1:if(day<1||day>31)return 0;break;
	case 3:if(day<1||day>31)return 0;break;
    case 5:if(day<1||day>31)return 0;break;
    case 7:if(day<1||day>31)return 0;break;
    case 8:if(day<1||day>31)return 0;break;
    case 10:if(day<1||day>31)return 0;break;
    case 12:if(day<1||day>31)return 0;break;
	case 4:if(day<1||day>30)return 0;break;
    case 6:if(day<1||day>30)return 0;break;
    case 9:if(day<1||day>30)return 0;break;
    case 11:if(day<1||day>30)return 0;break;
	}
	return 1;
}

int bianhao_hefa1(char* bb)           //�ж�����ı���Ƿ�Ϸ�
{
    int len=strlen(bb),i=3;
    if(len<4) return 0;
    if(bb[0]!='D'||bb[1]!='N'||bb[2]!='O') return 0;

    for(;i<len;i++)
    {
        if(bb[i]>'9'||bb[i]<'0') return 0;
    }
    return 1;
}

int bianhao_hefa(char* bb)           //�ж�����ı���Ƿ�Ϸ�
{
    if(bb[0]!='N'||bb[1]!='O') return 0;
    int len=strlen(bb),i=2;
    for(;i<len;i++)
    {
        if(bb[i]>'9'||bb[i]<'0') return 0;
    }
    return 1;
}


void xs_timesearch() {   //��ʱ��������ۼ�¼
    //������������ֹ��Χ
    char start_time[100],end_time[100];
    printf("\t\t�������ѯʱ�����(��ʽ��2000.01.01)\n");
    scanf("%s",start_time);
    while(!time_hefa(start_time))
    {
        printf("\t\t������Ϸ�����\n");
        scanf("%s",start_time);
    }
    //
    printf("\t\t�������ѯʱ���յ�(��ʽͬ��)\n");
    scanf("%s",end_time);
     while(!time_hefa(end_time)||strcmp(start_time,end_time)>0)
    {
        printf("\t\t������Ϸ�����\n");
        scanf("%s",end_time);
    }


    SELL*p=head;
    printf("��Ʒ����\t��ζ\t         �¶�\t\t���\t");
    printf("���\t����\tʱ��\t\t�µ����\n\n");
    printf("---------------------------------------------------------------------------------------------\n");
    while(p)
    {
        if(strcmp(p->s_date,start_time)>=0&&strcmp(p->s_date,end_time)<=0)
		PRINTf(p);
        p=p->s_next;
    }
}
void xs_goodssearch()
{
    char goods_name[100];
    printf("\t\t��������Ʒ����:\n");
    scanf("%s",goods_name);
    while(strlen(goods_name)>1||goods_name[0]>'4'||goods_name[0]<'0')
    {
        printf("\n\t\t��������ȷ����Ʒ����\n");
        scanf("%s",goods_name);
    }
    //
    int key1=goods_name[0]-'0';

    SELL*p=head;
    printf("��Ʒ����        ��ζ          �¶�          ���           ���         ����          ʱ��             �µ����\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
    while(p)
    {
        if(key1==p->drink)
		PRINTf(p);
        p=p->s_next;
    }

}
void xs_dingdansearch()
{
    char buy_name[100];
    printf("\t\t��������Ʒ�������");
    scanf("%s",buy_name);
    while(!bianhao_hefa1(buy_name))
    {
        printf("\t\t��������ȷ�Ķ������\n");
        scanf("%s",buy_name);
    }
    SELL*p=head;
    printf("��Ʒ����        ��ζ          �¶�          ���           ���         ����          ʱ��             �µ����\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
    while(p)
    {
        if(strcmp(p->s_number,buy_name)==0)
		PRINTf(p);
        p=p->s_next;
    }
}

void Print(SELL*head)
{
    SELL*p0=head;
    if(p0!=NULL)
    {
        printf("\t\t��ѯ�����¼�¼\n");
    }
    else
    {
        printf("������������δ��ѯ�����ۼ�¼");
        Sleep(1000);
        return ;
    }
    printf("��Ʒ����        ��ζ          �¶�          ���           ���         ����          ʱ��             �µ����\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
    while(p0!=NULL)
    {
        PRINTf(p0);
        p0=p0->s_next;
    }
}
void FilePrint(SELL*head)      //�ļ�����
{
    FILE*fp;
    fp=fopen("ShouMaiJiLu.txt","w");
    SELL*p0=head;
    while(p0)
    {
    fprintf(fp," ��Ʒ����          ��ζ              �¶�                ���                    ���                ����                 ʱ��                  �µ����\n");
    fprintf(fp,"%3d%20d%20d%30d%20d%20d%20s%20s\n",p0->drink,p0->taste,p0->temper,p0->sugar,p0->standard,p0->much,p0->s_date,p0->s_number);
    p0=p0->s_next;
    }
}

void PRINTf(SELL*p)
{
	int k;
	k=10*p->drink+p->taste;
switch(k){
	case 11:printf("�����̲�        ţ��ζ   ");break;
	case 12:printf("�����̲�        ��ݮζ   "); break;
	case 13:printf("�����̲�        ����ζ   "); break;
    case 21:printf("������          ��ݮζ   ");break;
	case 22:printf("������          ����ζ   ");break;
	case 23:printf("������          ����ζ   ");break;
	case 31:printf("����            �ڿ���   ");break;
	case 32:printf("����            Ĩ��ζ   ");break;
	case 33:printf("����            ������ŵ ");break;
	case 41:printf("����            ԭζ     ");break;
	case 42:printf("����            ��ݮζ   ");break;
	case 43:printf("����            ����ζ   ");break;
}
	switch(p->temper) {
case 1:printf("     ��   "); break;
case 2:printf("     ���� ");break;
case 3:printf("     �ӱ� "); break;
}
	switch(p->sugar) {
case 1:printf("         ȫ��   ");break;
case 2:printf("         ����� ");break;
case 3:printf("         ����   ");break;
}
	switch(p->standard) {
case 1:printf("        ��  ");break;
case 2:printf("        ��  ");break;
case 3:printf("        С  "); break;
}
printf("          %d",p->much);
printf("           %s",p->s_date);
printf("         %s\n",p->s_number);
p=p->s_next;
}

//===========================================LOGIN===========================================================
//�ƶ�����
void gotoxy(int x,int y) {
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//���뺯��
int input(char*p,int y) {
	char cinchar;
	int i;//��������λ��
	cinchar=getch();
	for(i=0; cinchar!=13&&i<12; i++)
    {
		if(cinchar==27) {//����esc ���򷵻���һ��
			system("cls");
			return -1;//������һ��
		}//esc
		if(cinchar!=8) {//����ɾ����
			p[i]=cinchar;
			if(y==1)printf("%c",cinchar);
			if(y==2)printf("*");
		}
		else if(i>0) { //ɾ��һλ
			i-=2;
			printf("\b \b");
		}
		else i-=1; //ɾ������û�����κ��ַ�

		cinchar=getch();
	}             //for
return (i<=10)?i:-2;
}

//��ӡͼ�κ���
void print_picture(int login_time){
	int i;
	gotoxy(40,20);
		printf("�˺ţ�");
		gotoxy(40,25);
		printf("���룺");
		for(i=0; i<35; i++) {
			gotoxy(40+i,18);
			printf("_");
		}
		for(i=0; i<35; i++) {
			gotoxy(40+i,21);
			printf("_");
		}
		for(i=0; i<35; i++) {
			gotoxy(40+i,23);
			printf("_");
		}
		for(i=0; i<35; i++) {
			gotoxy(40+i,26);
			printf("_");
		}
		if(login_time){
			gotoxy(40,10);
		printf("����ESC�˳�����");
		exit(0);
		}
}

//�˵�ѡ����
void loopout(HANDLE hwnd,COORD coord,int count) {
	system("cls");//����
	while(count<=0)count+=n;//һֱ�ӵ�count���Ϊ����
	switch(count%n) {
		case 0:
			gotoxy(85,5);
			printf("--> *ԭ�Ͻ�������*");
			gotoxy(85,13);
			printf("*��Ʒ��������*");
			gotoxy(85,21);
			printf("*ԭ�Ͽ�����*");
			gotoxy(85,29) ;
			printf("*��Ա�˻�����*");
			gotoxy(85,37) ;
			printf("*�ʽ����*");
			gotoxy(85,45);
			printf("����ESC�˳���¼");
			break;
		case 1:
			gotoxy(85,5);
			printf("*ԭ�Ͻ�������*");
			gotoxy(85,13);
			printf("-->*��Ʒ��������*");
			gotoxy(85,21);
			printf("*ԭ�Ͽ�����*");
			gotoxy(85,29) ;
			printf("*��Ա�˻�����*");
			gotoxy(85,37) ;
			printf("*�ʽ����*");
			gotoxy(85,45);
			printf("����ESC�˳���¼");
			break;
		case 2:
			gotoxy(85,5);
			printf("*ԭ�Ͻ�������*");
			gotoxy(85,13);
			printf("*��Ʒ��������*");
			gotoxy(85,21);
			printf("-->*ԭ�Ͽ�����*");
			gotoxy(85,29) ;
			printf("*��Ա�˻�����*");
			gotoxy(85,37) ;
			printf("*�ʽ����*");
			gotoxy(85,45);
			printf("����ESC�˳���¼");
			break;
		case 3:
			gotoxy(85,5);
			printf("*ԭ�Ͻ�������*");
			gotoxy(85,13);
			printf("*��Ʒ��������*");
			gotoxy(85,21);
			printf("*ԭ�Ͽ�����*");
			gotoxy(85,29) ;
			printf("-->*��Ա�˻�����*");
			gotoxy(85,37) ;
			printf("*�ʽ����*");
			gotoxy(85,45);
			printf("����ESC�˳���¼");
			break;
		case 4:
			gotoxy(85,5);
			printf("*ԭ�Ͻ�������*");
			gotoxy(85,13);
			printf("*��Ʒ��������*");
			gotoxy(85,21);
			printf("*ԭ�Ͽ�����*");
			gotoxy(85,29) ;
			printf("*��Ա�˻�����*");
			gotoxy(85,37) ;
			printf("-->*�ʽ����*");
			gotoxy(85,45);
			printf("����ESC�˳���¼");
			break;

	}
}

//���麯��
int searchchar(char*p,int n) {
	int i;
	int count_int=0,count_char=0;

	for(i=0; i<5; i++)if(!p[i])return 1;//������5λ
	if(p[5]!='\0')return 1;//����5λ
	for(i=0; i<n; i++){
		if(p[i]<='9'&&p[i]>='0')count_int++;
		else if(p[i]>='a'&&p[i]<='z')count_char++;
		else if(p[i]>='A'&&p[i]<='Z')count_char++;
		else return 1;//���������ַ�
	}
	if(count_int&&count_char)	return 0;//���ֺ��ַ������ֹ�
	else return 1;//���ֺ��ַ�δ�����ֹ�
}

//�ܱ����麯��
int searchchar_mibao(char*p,int n) {
	int i;
	int count_int=0;
	for(i=0; i<6; i++)if(!p[i])return 1;//������6λ
	if(p[6]!='\0')return 1;//����6λ
	for(i=0; i<n; i++) {
		if(p[i]<='9'&&p[i]>='0')count_int++;
		else return 1;//���������ַ�
	}
	if(count_int)	return 0;//���ֺ��ַ������ֹ�
	else return 1;//���ֺ��ַ�δ�����ֹ�
}

//�ܱ�����
int mibao_hanshu(char*mibao) {
	system("cls");
	gotoxy(10,9);
	printf("����������ֻ��ţ�");
	char A[1000];
	input(A,1);
	if(strcmp(mibao,A)==0)return 1;
	return 0;
}

//���������ܱ��ĺ���
void mibaoinitial(char*key,FILE*fpointer) {
	//��δ�����ܱ�
	gotoxy(10,11);
	printf("���ε�½�����������ܱ�,Ҫ��Ϊ6λ����:");
	gets(key);
	FILE*fpointer2=fopen("mibao.txt","w");
	fputs(key,fpointer2);//д�����������
	fclose(fpointer2);
	while(searchchar_mibao(key,6)) {
		system("cls");
		gotoxy(10,9);
		if(fpointer)printf("���³�ʼ�����룬Ҫ��Ϊ6λ����:");
		else printf("�ܱ���������Ҫ��Ϊ6λ����,����������:");
		gets(key);
		fpointer2=fopen("mibao.txt","w");
		fputs(key,fpointer2);
		fclose(fpointer2);
}
}

//������������ĺ���
void Passwordinitial(char*key,FILE*fpointer) {
	//��δ��������
	gotoxy(10,9);
	printf("���ε�½��������������,Ҫ��Ϊ5Ϊ������ĸ����ַ���:");
	gets(key);
	FILE*fpointer2=fopen("mima.txt","w");
	fputs(key,fpointer2);//д�����������
	fclose(fpointer2);
//������������
	while(searchchar(key,5)) {
		system("cls");
		gotoxy(10,9);
		if(fpointer)printf("���³�ʼ�����룬Ҫ��Ϊ5λ������ĸ����ַ���:");
		else printf("������������Ҫ��Ϊ5λ������ĸ����ַ���,����������:");
		gets(key);
		fpointer2=fopen("mima.txt","w");
		fputs(key,fpointer2);
		fclose(fpointer2);
	}
}

//����ϵͳ�ۺϺ���
int  manage_system() {

	COORD coord;//λ�ñ���
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);//������
//	int i,j=0;
	int t=0;//�ж�������
	FILE*fpointer=fopen("mima.txt","r");
	char zhanghaoinitial[10]="12345";     //�趨�õ��˺�
	char key[1000];                      //�����趨�����벢�������ļ���
	char key_mibao[1000];                      //�����趨���ܱ����������ļ���
	char zhanghao[1000];               //����������˺�
	char mima[1000];                  //�������������
	char key2[100];
	char mibao[10];

	//��ʼ��������
aa:

	printf("                                     ************************\n");
	printf("                                     ��ӭʹ�þưɾ�Ӫ����ϵͳ\n");
	printf("                                     ************************");

	if(login_time!=0)goto cc;//����ڶ���ִ�иú���
	fclose(fpointer);//�ر��ļ�
	if(fpointer==0){
          Passwordinitial(key,fpointer);//��ʧ�ܱ�ʾû�г�ʼ�����룬��ʼ����
        mibaoinitial(key_mibao,fpointer);//��ʧ�ܱ�ʾû�г�ʼ���ܱ�����ʼ����
	}

	system("cls");

	//�������
	for(t=0; t<3;) {
bb: //�����˺ţ�����
		print_picture(login_time);

		//�����˺�
		//��λ�˺Ź��
		coord.X = 45;
		coord.Y = 20;
		SetConsoleCursorPosition(hwnd,coord);
		//���ú��������˺�
		int zhanghao_return=input(zhanghao,1);//��ȡ���뺯������ֵ�����󷵻�-1����ȷ���������ַ�����
		switch(zhanghao_return)
		{
		case -1:
			if(fpointer==0)	goto aa;// ���ǵ�һ�γ�ʼ�����룬����esc���goto aa���³�ʼ������
			else system("cls");//���ǵ�һ�γ�ʼ�����룬
			gotoxy(10,10);
			printf("          ���ѳ�ʼ�������룬�޷����д˲���");
			system("pause");
		case -2:
			system("cls");
        	gotoxy(10,10);
			printf("          �����˺ų�����������������");
			goto bb;
		default:
		zhanghao[zhanghao_return]='\0';//���ַ����룬��β��һ��\0
		}


		//��������
		coord.X = 45;
		coord.Y = 25;
		SetConsoleCursorPosition(hwnd,coord);

		int mima_return=input(mima,2);
		switch(mima_return)
		{
		case -1:
			if(fpointer==0)	goto aa;
			else system("cls");
			gotoxy(10,10);
			printf("          ���ѳ�ʼ�������룬�޷����д˲���");
			system("pause");
        case -2:
        	system("cls");
        	gotoxy(10,10);
			printf("          �������볤����������������");
			goto bb;
		default:
		mima[mima_return]='\0';
		}
		//��txt�ļ���ȡ֮ǰ��������
		FILE*fpointer=fopen("mima.txt","r");
		fscanf(fpointer,"%s",key);//��ȡ�ı��ļ�������key��
		fclose(fpointer);

		//����
		t++;//��������һ
		if(strcmp(zhanghao,zhanghaoinitial)==0&&strcmp(mima,key)==0) {
			system("cls");
			gotoxy(10,10);
			printf("          ������ȷ");
			system("pause");
			break;
		} else {//��������
			if(t<3) {//��������3��
				system("cls");
				gotoxy(30,8);
				printf("         �˺Ż�������������������������\n");
				gotoxy(40,10);
				system ("pause");
				system("cls");
				goto bb;
			} else {//���󳬹�3��
				system("cls");
				gotoxy(30,8);
				printf("         �˺Ż������������󳬹�3���Զ��˳�\n\n");
				printf("         ����ͨ���ܱ��һ����룬�밴�ո��");
				if(getche()==32) {
					FILE*fpointer_mibao=fopen("mibao.txt","r");
					fscanf(fpointer_mibao,"%s",mibao);
					fclose(fpointer_mibao);
					if(mibao_hanshu(mibao)) {
						system("cls");
						Passwordinitial(key2,fpointer);
						goto cc;
					}  else {
						system("cls");
						printf("�����ܱ�����2����Զ��˳�");
						Sleep(2000);
						exit(0);
					}//else4�ܱ���������
				} else {
					system("cls");
					printf("�����ܱ�����2����Զ��˳�");
					Sleep(2000);
					exit(0);
				} //else3�������ܱ��Զ��˳�
			}//else2�������
		}//else1��������
	}//   for
	//�˵�ѡ��



cc://��ʼ�˵�ѡ��
	system("cls");
	gotoxy(85,5);
	printf("*ԭ�Ͻ�������*");
	gotoxy(85,13);
	printf("*��Ʒ��������*");
	gotoxy(85,21);
	printf("*ԭ�Ͽ�����*");
	gotoxy(85,29) ;
	printf("*��Ա�˻�����*");
	gotoxy(85,37) ;
	printf("*�ʽ����*");
	gotoxy(85,45);
	printf("����ESC�˳���¼");
//��λ��ǰ��굽
	coord.X = 85;
	coord.Y = 6;
	SetConsoleCursorPosition(hwnd,coord);

//�ƶ�
	while (1) {
		int p;
		p=getch();
		switch(p) {
			case 27:
				system("cls");
				goto bb;
			case 13: //���»س������벻ͬ�˵�
				while(count<=0)count+=n;
				if(count%n==0)goto dd;//ԭ�Ͻ�������
				if(count%n==1)goto ee;//��Ʒ����
				if(count%n==2)goto ff;//ԭ�Ͽ��
				if(count%n==3)goto gg;//��Ա�˻�����
				if(count%n==4)goto hh;//�ʽ����
			case 49:  //1��
				count--;
				coord.Y-=8;//�������
				if(coord.Y<5)coord.Y=38;//��������ϱ߼������ƻص����±�
				loopout(hwnd, coord,count);
				//SetConsoleCursorPosition(hwnd,coord);//���±�ǹ��λ��
				break;

			case 50:  //2��
				count++;
				coord.Y+=8;
				if(coord.Y>38)coord.Y=6;
				loopout(hwnd, coord,count);
				//SetConsoleCursorPosition(hwnd,coord);
				break;
		}//switch
	}

dd:login_time++;
	system("cls");
	printf("ԭ�Ͻ�������");
	return 1;
ee:login_time++;
	system("cls");
	printf("��Ʒ��������");
	return 2;
ff:login_time++;
	system("cls");
	printf("ԭ�Ͽ�����");
	return 3;
gg:login_time++;
	system("cls");
	printf("��Ա�˻�����");
	return 4;
hh:login_time++;
	system("cls");
	printf("�ʽ����");
	return 5;
}



//========================================MONEY==============================================

//************************************************************************************************************* *************************************************************************************************************
//************************************************************************************************************* *************************************************************************************************************
//��Ǯ���뺯��
double  search_putin() {
	char A[15];
	int i;
	int dotcount=0;//'.'���ִ���
	int before_dot=0;//������֮ǰλ��
	double change_A=0,change_B=0;
for(i=0;i<14;i++){
		scanf("%c",&A[i]);

		if(A[i]==10){
			if(i==0){
				i--;
			continue;
			}
			else break;
		}//if
	}
	A[i]='\0';


	int len=strlen(A);

	if(len>15)return 0;//������15λ

	for(i=0; i<len; i++) {
		if(A[i]==32)continue;

		if(A[i]>'9'||A[i]<'0')
		{
			if(A[i]=='.')
			{
				dotcount++;
				before_dot=i;
			}
			else return 0; //���������ַ�
		}
	}
	//����2�����ϡ�����
	if(dotcount>1) return 0;

	if(dotcount==1) {
		for(i=0; i<before_dot; i++) {
			if(A[i]==32)continue; //�ո�
			change_A*=10;
			change_A=change_A+(double)(A[i]-'0');
		}

		for(i=len-1; i>before_dot; i--) {
			if(A[i]==32)continue; //�ո�

			change_B=change_B+(double)(A[i]-'0');
			change_B*=0.1;
		}
		return change_A+change_B;
	}//if

	else {
		for(i=0; i<len; i++) {
			if(A[i]==32)continue; //�ո�
			change_A*=10;
			change_A=change_A+(double)(A[i]-'0');
		}

		return change_A;
	}//else
}//����

//������Ӻ���
int bianhao_plus(char*bianhao) {
	bianhao[5]++;
	if(bianhao[5]==('9'+1)) {
		bianhao[5]='0';
		bianhao[4]++;
	}
	if(bianhao[4]==('9'+1)) {
		bianhao[4]='0';
		bianhao[3]++;
	}
	if(bianhao[3]==('9'+1)) {
		bianhao[3]='0';
		bianhao[2]++;
	}
	if(bianhao[2]==('9'+1)) {
		return 0;
	}
	return 1;
}

//��űȽϺ���
int bianhao_cmp(char*A,char*B) {
	int suma=0,sumb=0;
	suma=A[5]-'0'+(A[4]-'0')*10+(A[3]-'0')*100+(A[2]-'0')*1000;
	int n=strlen(B);
	int i;
	for(i=2; i<n; i++) {
		sumb*=10;
		sumb+=B[i]-'0';
	}
	if(suma<sumb)return -1;
	else if(suma>sumb)return 1;
	else return 0;
}


//���ڱȽϺ���
int riqi_cmp(char*A,char*B) {
	char C[5],D[5];
	int i;
	C[0]=A[5],C[1]=A[6],C[2]=A[8],C[3]=A[9];
	D[0]=B[5],D[1]=B[6],D[2]=B[8],D[3]=B[9];
	i=strcmp(C,D);
	return i;
}

//************************************************************************************************************* *************************************************************************************************************
//************************************************************************************************************* *************************************************************************************************************

//**************************************************************************************************************************************************************************************************************************
//                                                                                                         ALL
//************************************************************************************************************* *************************************************************************************************************
//1.���ʽ���ת�������ɺ���
void all_zijin_gai() {
	Allform*p;
	if(allhead==0) {
		p=(Allform*)malloc(sizeof(Allform));//if������
		allhead=p;
		allwei=p;
		p->all_next=NULL;
	} else {		                                  //����ǿ�
		p=(Allform*)malloc(sizeof(Allform));
		allwei->all_next=p;
		allwei=p;
		p->all_next=NULL;
	}
}

//2.����ת����
int all_bianli() {
	FILE*fpointer=fopen("all_zijin.txt","w");
	//Materialform*p;
	int i;
	Allform * trans=allhead;
	if(trans==NULL) {
		return 0;
	}

	for(i=1; trans!=0; i++) {

		fprintf(fpointer,"%d .\n",i);
		fprintf(fpointer,"\n�ʽ���ת��Ŀ��%s\n",trans->all_name);
		printf("�ʽ���ת��ţ�%s\n",trans->all_name);
		fprintf(fpointer,"\n�ʽ���ת��ţ�%s\n",trans->all_formnumber);
		printf("�ʽ���ת��ţ�%s\n",trans->all_formnumber);
		fprintf(fpointer,"�ʽ���תʱ�䣺%s\n",trans->all_time);
		printf("�ʽ���תʱ�䣺%s\n",trans->all_time);
		fprintf(fpointer,"�ʽ���ת��%lf\n\n",trans->all_trans_money);
		printf("�ʽ���ת��%lf\n",trans->all_trans_money);
		trans=trans->all_next;
	}
	fclose(fpointer);
	system("pause");
	return 1;
}

//3.���ʽ�����ɾ��
void delete_all() {
	Allform*p=allhead,*q;
	while(p) {
		q=p;
		p=p->all_next;
		free(q);
	}
}
//**************************************************************************************************************************************************************************************************************************
//                                                                                                         all
//************************************************************************************************************* *************************************************************************************************************
//1.������ת�������ɺ���
void order_zijin_gai() {
	Orderform*p;
	if(orderhead==0) {
		p=(Orderform*)malloc(sizeof(Orderform));//if������
		orderhead=p;
		orderwei=p;
		p->order_next=NULL;
	} else {		                                  //����ǿ�
		p=(Orderform*)malloc(sizeof(Orderform));
		orderwei->order_next=p;
		orderwei=p;
		p->order_next=NULL;
	}
}

// 2.�����ʽ���ת��¼
double order_sum_money (SHOP*trans) {//������һ��SHOP�͵������ͷ
	int choice;//��Ȩ
	double money=0,moneysum=0;//��תÿ�ʽ������ܽ��

	order_zijin_gai();//ÿ�ε��øú�������һ���ڵ�

	if(trans==NULL) { //������
		return 0;
	}

	//�������
	while(trans->s_next) {
		choice=trans->drink*10+trans->standard*1;//���࣬���
		switch(choice) {
//�����̲�
			case 11:
				money=15;
				break;
			case 12:
				money=13;
				break;
			case 13:
				money=8;
				break;
//�����
			case 21:
				money=10;
				break;
			case 22:
				money=8;
				break;
			case 23:
				money=5;
				break;
//����
			case 31:
				money=16;
				break;
			case 32:
				money=14;
				break;
			case 33:
				money=10;
				break;
//����
			case 41:
				money=12;
				break;
			case 42:
				money=10;
				break;
			case 43:
				money=8;
				break;
		}

		//����Ϊ��һ����Ʒ��Ͳ���
		money*=trans->much;//����
		trans->shop_money=money;//������shop�ṹ����
		trans=trans->s_next;//��һ�ڵ�
		moneysum+=money; //��͸ù˿��ܻ���
	}//while

	choice=trans->drink*10+trans->standard*1;//���࣬���
	switch(choice) {
//�����̲�
		case 11:
			money=15;
			break;
		case 12:
			money=13;
			break;
		case 13:
			money=8;
			break;
//�����
		case 21:
			money=10;
			break;
		case 22:
			money=8;
			break;
		case 23:
			money=5;
			break;
//����
		case 31:
			money=16;
			break;
		case 32:
			money=14;
			break;
		case 33:
			money=10;
			break;
//����
		case 41:
			money=12;
			break;
		case 42:
			money=10;
			break;
		case 43:
			money=8;
			break;
	}

	//����Ϊ��һ����Ʒ��Ͳ���
	money*=trans->much;//����
	trans->shop_money=money;//������shop�ṹ����
	moneysum+=money; //��͸ù˿��ܻ���

	//����Ϊ�Ըù˿������������Ʒ���
	zijin+=moneysum;   //���ʽ���ת

	orderwei->order_trans_money=moneysum;//���涩����¼
	strcpy(orderwei->order_time,trans->s_date);//����ʱ��

	//���±��浽all��
	all_zijin_gai();
	allwei->all_trans_money=moneysum;
	strcpy(allwei->all_name,"order");
	strcpy(allwei->all_time,trans->s_date);
	int confirm=bianhao_plus(all_number);
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("��Ź���");
	}

	//bianhao
	confirm=bianhao_plus(order_number);
	if(confirm)strcpy(allwei->all_formnumber,order_number);
	else {
		system("cls");
		printf("��Ź���");
	}
 	return moneysum;
}

//3.��������ʱ�����
void order_time_search() {
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯʱ������:\n\n");
	printf("�������ѯʱ����㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",A);
	}
	printf("�������ѯʱ���յ㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",B);
	}
	if(riqi_cmp(A,B)>0) {
		system("cls");
		printf("����ȷ����ʱ�����䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	orderp=orderhead;
	while(orderp!=NULL) {
		if(riqi_cmp(orderp->order_time,A)<0&&orderp->order_next!=0)
			orderp=orderp->order_next;
		else break;
	}
	orderq=orderp;
	while(orderq!=NULL) {
		if(riqi_cmp(orderq->order_time,B)<0&&orderq->order_next!=0)
			orderq=orderq->order_next;
		else	break;
	}
}

//4.����������ű���
void order_bianhao_search() {
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯ�������:\n\n");
	printf("�������ѯ�����㣨��ʽΪNO123456...��:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",A);
	}
	printf("�������ѯ����յ㣨��ʽΪNO123456...��:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("����ȷ���������䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	orderp=orderhead;
	while(orderp) {
		if(bianhao_cmp((orderp->order_formnumber),A)<0&&orderp->order_next!=0)
			orderp=orderp->order_next;
		else break;
	}
	orderq=orderp;
	while(orderq) {
		if(bianhao_cmp(orderq->order_formnumber,B)<0&&orderq->order_next!=0)
			orderq=orderq->order_next;
		else break;
	}
}

//5.ÿһ�ʶ�������
void order_zijin_txt() {
	FILE*fpointer=fopen("order_zijin.txt","w");
	//Orderform*p;
	int i;
	char a;
aa:
	printf("��ѡ����ҷ�ʽ\n");
	printf("����0������һ��\n");
	printf("���� 1 ����ʱ�����\n");
	printf("���� 2 �����ż���\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			order_time_search();
			system("cls");
			printf("�������������ʽ������1���������������");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			order_bianhao_search();
			system("cls");
			printf("�������������ʽ������1���������������");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
	}

	for(i=1; orderp<=orderq&&orderp!=0; i++) {
            printf("\n%d .\n",i);
		fprintf(fpointer,"\n%d .\n",i);
		fprintf(fpointer,"������ת��ţ�%s\n",orderp->order_formnumber);
		printf("������ת��ţ�%s\n",orderp->order_formnumber);
		fprintf(fpointer,"������תʱ�䣺%s\n",orderp->order_time);
		printf("������תʱ�䣺%s\n",orderp->order_time);
		fprintf(fpointer,"������ת��%lf\n\n",orderp->order_trans_money);
		printf("������ת��%lf\n",orderp->order_trans_money);
		orderp=orderp->order_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.��������ɾ��
void delete_order() {
	Orderform*p=orderhead,*q;
	while(p) {
		q=p;
		p=p->order_next;
		free(q);
	}
}

//**************************************************************************************************************************************************************************************************************************
//                                                                                                         MATERIAL
//************************************************************************************************************* *************************************************************************************************************
//1.ԭ����ת�������ɺ���
void material_zijin_gai() {
	Materialform*p;
	if(materialhead==0) {
		p=(Materialform*)malloc(sizeof(Materialform));//if������
		materialhead=p;
		materialwei=p;
		p->material_next=NULL;
	} else {		                                  //����ǿ�
		p=(Materialform*)malloc(sizeof(Materialform));
		materialwei->material_next=p;
		materialwei=p;
		p->material_next=NULL;
	}
}

//2.ԭ���ʽ���ת��¼
float sum_money(PUR*trans) {//������һ��ԭ�Ͻṹ�����������ͷ
	float money=0,moneysum=0;
	//int choice;
	material_zijin_gai();
	if(trans==NULL) {
		return 0;
	}
	while(trans->p_next!=NULL) {
		money=trans->p_money;
		money*=trans->weight;
		trans=trans->p_next;
		moneysum+=money;

	}	//while
	money=trans->p_money;
	money*=trans->weight;

	moneysum+=money;
	zijin-=moneysum;

	if(zijin<0)return 0;//���˷���0

	materialwei->material_trans_money=moneysum;//���涩����¼

	//���±��浽all��
	all_zijin_gai();
	allwei->all_trans_money=-moneysum;//Ǯ
	strcpy(allwei->all_name,"material");//name
	strcpy(allwei->all_time,trans->p_date);//ʱ��
	int confirm=bianhao_plus(all_number);//���
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("��Ź���");
	}

	//bianhao
	confirm=bianhao_plus(material_number);
	if(confirm)strcpy(materialwei->material_formnumber,material_number);
	else {
		system("cls");
		printf("��Ź���");
	}

	strcpy(materialwei->material_time,trans->p_date);//ʱ��
	return moneysum;
}

//3.ԭ�ϰ�ʱ�����
void material_time_search() {
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯʱ������:\n\n");

	printf("�������ѯʱ����㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",A);
	}
	printf("�������ѯʱ���յ㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",B);
	}
	if(strcmp(A,B)>0) {
		system("cls");
		printf("����ȷ����ʱ�����䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	materialp=materialhead;
	while(materialp!=NULL) {
		if(riqi_cmp(materialp->material_time,A)<0&&materialp->material_next!=0)
			materialp=materialp->material_next;
		else break;
	}
	materialq=materialp;
	while(materialq!=NULL) {
		if(riqi_cmp(materialq->material_time,B)<0&&materialq->material_next!=0)
			materialq=materialq->material_next;
		else	break;
	}
}

//4.ԭ�ϰ���ű���
void material_bianhao_search() {
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯ�������:\n\n");

	printf("�������ѯ�����㣨��ʽΪNO123456...��:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",A);
	}
	printf("�������ѯ����յ㣨��ʽΪNO123456...��:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("����ȷ���������䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	materialp=materialhead;
	while(materialp) {
		if(bianhao_cmp((materialp->material_formnumber),A)<0&&materialp->material_next!=0)
			materialp=materialp->material_next;
		else break;
	}
	materialq=materialp;
	while(materialq) {
		if(bianhao_cmp(materialq->material_formnumber,B)<0&&materialq->material_next!=0)
			materialq=materialq->material_next;
		else break;
	}
}

//5.ÿһ��ԭ�ϵ���
void material_zijin_txt() {
	FILE*fpointer=fopen("material_zijin.txt","w");
	//Materialform*p;
	int i;
	char a;
aa:
	printf("��ѡ����ҷ�ʽ\n");
	printf("����0������һ��\n");
	printf("���� 1 ����ʱ�����\n");
	printf("���� 2 �����ż���\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			material_time_search();
			system("cls");
			printf("�������������ʽ������1������������˳�");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			material_bianhao_search();
			system("cls");
			printf("�������������ʽ������1������������˳�");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
	}

	for(i=1; materialp<=materialq&&materialp!=0; i++) {
             printf("\n%d .\n",i);
		fprintf(fpointer,"%d .\n",i);
		fprintf(fpointer,"\nԭ����ת��ţ�%s\n",materialp->material_formnumber);
		printf("ԭ����ת��ţ�%s\n",materialp->material_formnumber);
		fprintf(fpointer,"ԭ����תʱ�䣺%s\n",materialp->material_time);
		printf("ԭ����תʱ�䣺%s\n",materialp->material_time);
		fprintf(fpointer,"ԭ����ת��%lf\n\n",materialp->material_trans_money);
		printf("ԭ����ת��%lf\n",materialp->material_trans_money);
		materialp=materialp->material_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.ԭ������ɾ��
void delete_material() {
	Materialform*p=materialhead,*q;
	while(p) {
		q=p;
		p=p->material_next;
		free(q);
	}
}

//************************************************************************************************************* *************************************************************************************************************
//                                                                                                          order
//************************************************************************************************************* *************************************************************************************************************

//1.Ͷ����ת�������ɺ���
void other_zijin_gai() {
	Otherform*p;
	if(otherhead==0) {
		p=(Otherform*)malloc(sizeof(Otherform));//if������
		otherhead=p;
		otherwei=p;
		p->other_next=NULL;
	} else {		                                  //����ǿ�
		p=(Otherform*)malloc(sizeof(Otherform));
		otherwei->other_next=p;
		otherwei=p;
		p->other_next=NULL;
	}
}

//2.Ͷ�ʺ���
void touzi(double money) {
	char A[20];
	//int check;
	other_zijin_gai();
	zijin+=money;

	//���
	otherwei->other_trans_money=money;

	//time
	printf("������ʱ�䣨��ʽΪ2021.xx.xx��:");
	time_input(A);
	strcpy(otherwei->other_time,A);

	//���±��浽all��
	all_zijin_gai();
	allwei->all_trans_money=money;//Ǯ
	strcpy(allwei->all_name,"touzi");//name
	strcpy(allwei->all_time,otherwei->other_time);//ʱ��
	int confirm=bianhao_plus(all_number);//���
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("��Ź���");
	}


	//bianhao
	confirm=bianhao_plus(other_number);
	if(confirm)strcpy(otherwei->other_formnumber,other_number);
	else {
		system("cls");
		printf("��Ź���");
	}
	printf("���Ϊ��%s\n",otherwei->other_formnumber);
	system("pause");
}

//3.Ͷ�ʰ�ʱ�����
void other_time_search() {
   // other_sort();
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯʱ������:\n\n");
	printf("�������ѯʱ����㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",A);
	}
	printf("�������ѯʱ���յ㣨��ʽΪ2021.01.05��:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("�����������������루��ʽΪ2021.01.05��:\n");
		scanf("%s",B);
	}
	if(riqi_cmp(A,B)>0) {
		system("cls");
		printf("����ȷ����ʱ�����䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	otherp=otherhead;
	while(otherp!=NULL) {
		if(riqi_cmp(otherp->other_time,A)<0&&otherp->other_next!=0)
			otherp=otherp->other_next;
		else break;
	}
	otherq=otherp;
	while(otherq!=NULL) {
		if(riqi_cmp((otherq->other_time),B)<0&&otherq->other_next!=0)
			otherq=otherq->other_next;
		else	break;
	}
}

//4.Ͷ�ʰ���ű���
void other_bianhao_search() {
	char A[30],B[30];
aa:
	printf("��������Ҫ��ѯ�������:\n\n");
	printf("�������ѯ�����㣨��ʽΪNO123456...��:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",A);
	}
	printf("�������ѯ����յ㣨��ʽΪNO123456...��:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("�����������������루��ʽΪNO123456...��:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("����ȷ���������䣬ע�����С���յ�");
		system("pause");
		goto aa;
	}

	otherp=otherhead;
	while(otherp) {
		if(bianhao_cmp((otherp->other_formnumber),A)<0&&otherp->other_next!=0)
			otherp=otherp->other_next;
		else break;
	}
	otherq=otherp;
	while(otherq) {
		if(bianhao_cmp((otherq->other_formnumber),B)<0&&otherq->other_next!=0)
			otherq=otherq->other_next;
		else break;
	}
}



//5.ÿһ��Ͷ�ʵ���
void other_zijin_txt() {
	FILE*fpointer=fopen("other_zijin.txt","w");
	//Otherform*p;
	int i;
	char a;
aa:
	printf("��ѡ����ҷ�ʽ\n");
	printf("����0������һ��\n");
	printf("���� 1 ����ʱ�����\n");
	printf("���� 2 �����ż���\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			other_time_search();
			system("cls");
			printf("�������������ʽ������1������������˳�");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			other_bianhao_search();
			system("cls");
			printf("�������������ʽ������1������������˳�\n");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
	}

	for(i=1; otherp->other_formnumber<=otherq->other_formnumber&&otherp!=0; i++) {
           printf("\n%d .\n",i);
		fprintf(fpointer,"%d .\n",i);
		fprintf(fpointer,"\nͶ����ת��ţ�%s\n",otherp->other_formnumber);
		printf("Ͷ����ת��ţ�%s\n",otherp->other_formnumber);
		fprintf(fpointer,"Ͷ����תʱ�䣺%s\n",otherp->other_time);
		printf("Ͷ����תʱ�䣺%s\n",otherp->other_time);
		fprintf(fpointer,"Ͷ����ת��%lf\n\n",otherp->other_trans_money);
		printf("Ͷ����ת��%lf\n",otherp->other_trans_money);
		otherp=otherp->other_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.Ͷ������ɾ��
void delete_other() {
	Otherform*p=otherhead,*q;
	while(p) {
		q=p;
		p=p->other_next;
		free(q);
	}
}

//************************************************************************************************************* *************************************************************************************************************
//                                                                                                          ���ʽ�
//************************************************************************************************************* *************************************************************************************************************
// �ʽ��ѯ
void zijin_cha() {
	printf("��ǰ���ʽ�Ϊ��") ;
	printf("%lf",zijin);
}

//���ʽ������ļ�����
void zijin_txt() {
	FILE*fpointer=fopen("zijin.txt","w");

	fprintf(fpointer,"��ǰ���ʽ�Ϊ��%lf",zijin);
	fclose(fpointer);
}

//�ʽ����ѡ��˵�
int money_manage_choose() {
	char money_get;
	system("cls");
	gotoxy(85,5);
	printf("1.��ǰ���ʽ��ѯ");
	gotoxy(85,10);
	printf("2.�����ʽ���ת��ѯ");
	gotoxy(85,15) ;
	printf("3.ԭ�Ͻ����ʽ���ת��ѯ");
	gotoxy(85,20) ;
	printf("4.Ͷ���ʽ���ת��ѯ");
	gotoxy(85,25) ;
	printf("5.Ͷ�ʹ���");
	gotoxy(85,30) ;
	printf("6.���ʽ���ת");
	gotoxy(85,40);
	printf("����0���ز˵�ѡ��");
	gotoxy(85,35);
	printf("�����Ӧ���ֽ���ѡ��");

	money_get=getche();

	while(1) {

		switch(money_get) {

			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
				return money_get;
			case '0':
				return 0;
			default:
				system("cls");
				gotoxy(85,5);
				printf("1.��ǰ���ʽ��ѯ");
				gotoxy(85,10);
				printf("2.�����ʽ���ת��ѯ");
				gotoxy(85,15) ;
				printf("3.ԭ�Ͻ����ʽ���ת��ѯ");
				gotoxy(85,20) ;
				printf("4.Ͷ���ʽ���ת��ѯ");
				gotoxy(85,25) ;
				printf("5.Ͷ�ʹ���");
				gotoxy(85,30) ;
				printf("6.���ʽ���ת");
				gotoxy(85,40);
				printf("����0���ز˵�ѡ��");
				gotoxy(85,35);
				printf("������������������:");
		}//switch
		money_get=getche();

	} //while
}



int time_input_money(char* timeplus) { //(ʱ��洢����)ʱ���ʽ����
	int judge;
	int i,k;
	char extra[20];
	while(1) {
		scanf("%s",extra);
		if(strlen(extra)!=10||extra[4]!='.'||extra[7]!='.'||extra[0]=='.'||extra[1]=='.'||extra[2]=='.'||extra[3]=='.'||extra[5]=='.'||extra[6]=='.'||extra[8]=='.'||extra[9]=='.') {
			printf("�������벻���ϸ�ʽҪ�����������루xxxx.xx.xx��\n");
			judge=0;
		} else {
			for(i=0; i<10; i++) {
				if(i!=4&&i!=7) {
					if((extra[i]<'0'||extra[i]>'9')) {
						printf("�������벻����ʵ�����������������\n");
						judge=0;
						break;
					} else {
						judge=1;
					}
				}
			}
			if(((extra[0]-'0')*1000+(extra[1]-'0')*100+(extra[2]-'0')*10+(extra[3]-'0')!=2021)||((extra[5]-'0')*10
			        +(extra[6]-'0')>12)||((extra[5]-'0')*10+(extra[6]-'0')<1)||((extra[8]-'0')*10+(extra[9]-'0')<1)||((extra[8]-'0')*10+(extra[9]-'0')>31)||((extra[8]-'0')*10+(extra[9]-'0')<1)) {
				judge=0;
				printf("�������벻����ʵ�����������������\n");
			} else {
				judge=1;
			}
		}
		if(judge)
			break ;
	}

	for( i=0,k=0; i<10; i++) {
		 {
			timeplus[k]=extra[i];
			k++;
		}
	}
	return 1;
}


//====================================================================================
void PRINTF(SHOP*p){
    system("cls");
    SHOP*o=p;
    printf("\n                   ���ι��򶩵�����\n");
	while(p!=NULL){
		int k;
		k=10*p->drink+p->taste;
	switch(k){
		case 11:printf("        �����̲�ţ��ζ ");break;
		case 12:printf("        �����̲��ݮζ "); break;
		case 13:printf("        �����̲�����ζ "); break;
        case 21:printf("        �����ܲ�ݮζ ");break;
		case 22:printf("        ����������ζ ");break;
		case 23:printf("        ����������ζ ");break;
		case 31:printf("        ���Ⱥڿ��� ");break;
		case 32:printf("        ����Ĩ��ζ ");break;
		case 33:printf("        ���ȿ�����ŵ ");break;
		case 41:printf("        ����ԭζ ");break;
		case 42:printf("        ���̲�ݮζ ");break;
		case 43:printf("        ��������ζ ");break;
	}
		switch(p->temper) {
	case 1:printf("�� "); break;
	case 2:printf("���� ");break;
	case 3:printf("�ӱ� "); break;
	}
		switch(p->sugar) {
	case 1:printf("ȫ�� ");break;
	case 2:printf("����� ");break;
	case 3:printf("���� ");break;
	}
		switch(p->standard) {
	case 1:printf("��  ");break;
	case 2:printf("��  ");break;
	case 3:printf("С  "); break;
	}printf("%s    ",p->s_date);
    printf("������%d\n",p->much);
	p=p->s_next;

	}
	double l=order_sum_money(o);
    printf("       �ܽ�%lf\n",l);
    isvip(l);
}

void buy(SHOP*q){//����˴ι����ﳵ�����ͷ�ڵ㲢����;
  while(q!=NULL)
	{

        SELL*p=(SELL*)malloc(sizeof(SELL));
        p->s_next=NULL;
        int zlength=0;
		sum++;
		p->drink=q->drink;
		p->sugar=q->sugar;
		p->taste=q->taste;
		p->temper=q->temper;
		p->standard=q->standard;
		p->much=q->much;
		strcpy(p->s_date,q->s_date);//������Ϣ;
	    int k=sum,buy_count=0;//���ݶ����������ɶ�����ţ�
	    while(k>0){
	    	k=k/10;
	    	buy_count++;
		}
		p->s_number[0]='D';
		p->s_number[1]='N';
		p->s_number[2]='O';
		p->s_number[buy_count+3]='\0';
		k=sum;
		zlength=buy_count+2;
		while(k>0){
			p->s_number[zlength--]=k%10+'0';
			k=k/10;
		}

		if(head==NULL){
            head=tail=p;
        }
        else{
            tail->s_next=p;
            tail=p;
            p->s_next=NULL;
        }
        q=q->s_next;
	}
}
int xiaoshou_jiancha(SHOP*p,int key){//���빺�ﳵ����ͷ�ڵ㣬���ԭ���Ƿ���� ;
	switch(p->drink){
		case 1://�����̲�
			switch(p->standard){
				case 1://��
					switch(p->taste){
					case 1://ţ��ζ
					if(key==1){
	                tea+=15;milk+=300;}
				   else{
					if(tea<15){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(milk<300){
					printf(" ����ʧ��,ţ�̲���\n");
					return 0;
				   }else{
						if(!key)
						milk-=300;
					}
				}
					break;
					case 2://��ݮζ
					if(key==1){
						tea+=15;straw+=20;
					}else{
					if(tea<15){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(straw<20){
					printf("����ʧ��,��ݮ����\n");
					return 0;
				    }else{
						if(!key)
						straw-=20;
					}
				}
					break;
				    case 3://����ζ
				    if(key==1){
				    	tea+=15;grape+=20;
					}else{
					if(tea<15){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(grape<20){
					printf("����ʧ��,���Ѳ���\n");
					return 0;
					}else{
						if(!key)
						grape-=20;
					}
				}
					break;
				}
				break;
				case 2://�б�
				 switch(p->taste){
					case 1://ţ��ζ
					if(key==1){
						tea+=10;milk+=300;
					}else{
					if(tea<10){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(milk<300){
					printf("����ʧ��,ţ�̲���\n");
					return 0;
					}else{
						if(!key)
						milk-=300;
					}
				}
					break;
					case 2://��ݮζ
					if(key==1){
						tea+=10;straw+=20;
					}else{
					if(tea<10){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(straw<20){
					printf("����ʧ��,��ݮ����\n");
					return 0;
				  }else{
						if(!key)
						straw-=20;
					}
			}
					break;
				    case 3://����ζ
				    if(key==1){
				    	tea+=10;grape+=20;
					}else{
					if(tea<10){
					printf("����ʧ��,��Ҷ����\n");
				return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(grape<20){
					printf("����ʧ��,���Ѳ���\n");
					return 0;
				}else{
						if(!key)
						grape-=20;
					}break;
			}
			}break;
				case 3://С��
				 switch(p->taste){
					case 1://ţ��ζ
					if(key==1){
				    tea+=5;milk+=300;}else{
					if(tea<5){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
						if(!key)
						tea-=5;
					}
					if(milk<300){
					printf("����ʧ��,ţ�̲���\n");
				  return 0;
				}else{
						if(!key)
					milk-=300;
					}
				}
					break;
					case 2://��ݮζ
					if(key==1){
						tea+=5;straw+=20;
					}else{
					if(tea<5){
					printf("����ʧ��,��Ҷ����\n");
					return 0;
					}else{
					if(!key)
					tea-=5;
					}
					if(straw<20){
					printf("����ʧ��,��ݮ����\n");
					return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
				    case 3://����ζ
				    if(key==1){
				    	tea+=5;grape+=20;
					}else{
					if(tea<5){
					printf("����ʧ��,��Ҷ����\n");
				    return 0;
					}else{
					if(!key)
					tea-=5;
					}
					if(grape<20){
					printf("����ʧ�ܣ����Ѳ���\n");
					return 0;
					}else{
					if(!key)
					grape-=20;
					}
				    break;
				}
			}
				break;
			}break;
		case 2://������
				switch(p->standard){
				case 1://��
					switch(p->taste){
					case 1://��ݮζ
					if(key==1){
						cream+=30;milk+=300;straw+=20;
					}else{
					if(cream<30){
					printf("����ʧ�ܣ����Ͳ���\n");
			        return 0;
				     }else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("����ʧ�ܣ�ţ�̲���\n");
					return 0;
						}else{
					if(!key)
				      milk-=300;
					}

					if(straw<20){
					printf("����ʧ�ܣ����̲���\n");
					return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://����ζ
					if(key==1){
						cream+=30;milk+=300;grape+=20;
					}else{

					if(cream<30){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
					}else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("����ʧ�ܣ�ţ�̲���\n");
					return 0;
					}else{
					if(!key)
					milk-=300;
					}
					if(grape<20){
					printf("����ʧ�ܣ���ݮ����\n");
							return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://����ζ
				    if(key==1){
						cream+=30;milk+=300;yoghurt+=50;
					}else{
						if(cream<30){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
			   }else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("����ʧ�ܣ�ţ�̲���\n");
						return 0;
					}else{
					if(!key)
					milk-=300;
					}
					if(yoghurt<50){
					printf("����ʧ�ܣ����Ѳ���\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
			}
					break;
				}break;
				case 2://�б�
				 switch(p->taste){
					case 1://��ݮζ
					    if(key){
						cream+=20;milk+=200;straw+=20;
					}else{
					if(cream<20){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
					}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("����ʧ�ܣ�ţ�̲���\n");
					return 0;
					}else{
					if(!key)
					milk-=200;
					}
					if(straw<20){
					printf("����ʧ�ܣ����̲���\n");
						return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://����ζ
					if(key==1){
						cream+=20;milk+=200;grape+=20;
					}else{
					if(cream<20){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
					}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("����ʧ�ܣ�ţ�̲���\n");
						return 0;
					}else{
					if(!key)
					milk-=200;
					}
					if(grape<20){
					printf("����ʧ�ܣ���ݮ����\n");
						return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://����ζ
				    if(key==1){
						cream+=20;milk+=200;yoghurt+=50;
					}else{
						if(cream<20){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
				}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("����ʧ�ܣ�ţ�̲���\n");
					return 0;
						}else{
					if(!key)
					milk-=200;
					}
					if(yoghurt<50){
					printf("����ʧ�ܣ����Ѳ���\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
				}
					break;
				}break;
				case 3://С��
				switch(p->taste){
					case 1://��ݮζ
					 if(key==1){
						cream+=10;milk+=100;straw+=20;
					}else{
					if(cream<10){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
				}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("����ʧ�ܣ�ţ�̲���\n");
						return 0;
					}else{
					if(!key)
					milk-=100;
					}
					if(straw<20){
					printf("����ʧ�ܣ����̲���\n");
						return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://����ζ
					if(key==1){
						cream+=10;milk+=100;grape+=20;
					}else{
					if(cream<10){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
					}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("����ʧ�ܣ�ţ�̲���\n");
					   return 0;
					 }else{
					if(!key)
					milk-=100;
					}
					if(grape<20){
					printf("����ʧ�ܣ���ݮ����\n");
					return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://����ζ
				    if(key==1){
						cream+=10;milk+=100;yoghurt+=50;
					}else{
					if(cream<10){
					printf("����ʧ�ܣ����Ͳ���\n");
					return 0;
					}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("����ʧ�ܣ�ţ�̲���\n");
						return 0;
						}else{
					if(!key)
				milk-=100;
					}
					if(yoghurt<50){
					printf("����ʧ�ܣ����Ѳ���\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
				}
					break;
            	}break;
			}break;
		case 3://����
			 switch(p->standard){
			 	case 1://��
				 switch(p->taste){
				 	case 1://�ڿ���
				 	if(key==1){
						coffee+=20;
					}else{
					 if(coffee<20){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;
				}else{
					if(!key)
					coffee-=20;
					}
				}
					 break;
					 case 2://Ĩ��ζ
					 if(key==1){
						coffee+=20;tea+=5;
					}else{
					 if(coffee<20){
					 printf("����ʧ�ܣ����ȶ�����\n");
					return 0; }else{
					if(!key)
					coffee-=20;
					}
					 if(tea<5){
					 	printf("����ʧ��,��Ҷ����\n");
					 	return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://������ŵ
					 if(key==1){
						coffee+=20;milk+=50;
					}else{
					 if(coffee<20){
					 printf("����ʧ�ܣ����ȶ�����\n");
					return 0; }else{
					if(!key)
					coffee-=20;
					}
					 if(milk<50){
					 	printf("����ʧ�ܣ�ţ�̲���\n");
					 return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					 break;
				 }break;
				 case 2://�б�
				  switch(p->taste){
				 	case 1://�ڿ���
				 	if(key==1){
						coffee+=15;
					}else{
					 if(coffee<15){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=15;
					}
				}
					 break;
					 case 2://Ĩ��ζ
					 if(key==1){
						coffee+=15;tea+=5;
					}else{
					 if(coffee<15){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=15;
					}
					 if(tea<5){
					 	printf("����ʧ��,��Ҷ����\n");
					 return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://������ŵ
					 if(key==1){
						coffee+=15;milk+=50;
					}else{
					  if(coffee<15){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;
					}else{
					if(!key)
					coffee-=15;
					}
					 if(milk<50){
					 	printf("����ʧ�ܣ�ţ�̲���\n");
					 	return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					 break;
				 }break;
				case 3://С��
				 switch(p->taste){
				 	case 1://�ڿ���
				 	if(key==1){
						coffee+=10;
					}else{
					 if(coffee<10){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=10;
					}
				}
					 break;
					 case 2://Ĩ��ζ
					 if(key==1){
						coffee+=10;tea+=5;
					}else{
					 if(coffee<10){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;}else{
					if(!key)
					coffee-=10;
					}
					 if(tea<5){
					 	printf("����ʧ��,��Ҷ����\n");
					 	return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://������ŵ
					 if(key==1){
						coffee+=10;milk+=50;
					}else{
					 if(coffee<10){
					 printf("����ʧ�ܣ����ȶ�����\n");
					 return 0;}else{
					if(!key)
					coffee-=10;
					}
					 if(milk<50){
					 	printf("����ʧ�ܣ�ţ�̲���\n");
					 	return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					  break;
				 }break;
			 }break;
		case 4://����
			 switch(p->standard){
			 	case 1://��
				 switch(p->taste) {
				 	case 1://ԭζ
				 	if(key==1){
						yoghurt+=350;
					}else{
				if(yoghurt<350){
					 printf("����ʧ��,���̲���\n");
					 return 0;}else{
					if(!key)
					yoghurt-=350;
					}
					}
					 break;
					 case 2://��ݮζ
					 	if(key==1){
						yoghurt+=350;straw+=20;
					}else{
					 if(yoghurt<350){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=350;
					}
					 if(straw<20){
					 		printf("����ʧ��,��ݮ����\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://����ζ
					 	if(key==1){
						yoghurt+=350;grape+=20;
					}else{
					 if(yoghurt<350){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=350;
					}
				 if(grape<20){
					 		printf("����ʧ��,���Ѳ���\n");
					 		return 0;
					 }else{
					if(!key)
					grape-=20;
					}
				}
					 break;
				}break;
				  case 2://�б�
				  switch(p->taste) {
				 	case 1://ԭζ
				 		if(key==1){
						yoghurt+=250;
					}else{
					 if(yoghurt<250){
					 printf("����ʧ��,���̲���\n");
					 return 0;
			}else{
					if(!key)
					yoghurt-=250;
					}
				}
					 break;
					 case 2://��ݮζ
					 	if(key==1){
						yoghurt+=250;straw+=20;
					}else{
					 if(yoghurt<250){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=250;
					}
					 if(straw<20){
					 		printf("����ʧ��,��ݮ����\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://����ζ
					 	if(key==1){
						yoghurt+=250;grape+=20;
					}else{
					 if(yoghurt<250){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=250;
					}
				 if(grape<20){
					 		printf("����ʧ��,���Ѳ���\n");
					 		return 0;
					 }else{
					if(!key)
					grape-=20;
					}
				}
					  break;
				 }break;
				case 3://С��
				 switch(p->taste) {
				 	case 1://ԭζ
				 		if(key==1){
						yoghurt+=150;
					}else{
					 if(yoghurt<150){
					 printf("����ʧ��,���̲���\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=150;
					}
				}
					 break;
					 case 2://��ݮζ
					 	if(key==1){
						yoghurt+=150;straw+=20;
					}else{
					  if(yoghurt<150){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=150;
					}
					 if(straw<20){
					 		printf("����ʧ��,��ݮ����\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://����ζ
					 	if(key==1){
						yoghurt+=150;grape+=20;
					}else{
					  if(yoghurt<150){
					 	printf("����ʧ��,���̲���\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=150;
					}
				 if(grape<20){
					 		printf("����ʧ��,���Ѳ���\n");
					 		return 0;
					 }else{
					if(!key)
					grape-=20;
					}
				}
					 break;
				 }break;
			 }break;
		}
		switch(p->sugar){
    case 1://����
        if(key){
            sugar+=30;
        }else{
        if(sugar<30){
    printf("����ʧ�ܣ����ǲ���");
    return 0;
        }else{
        if(!key){
            sugar-=30;
        }
        }
		}break;
        case 2://5����
            if(key){
            sugar+=15;
        }else{
        if(sugar<15){
    printf("����ʧ�ܣ����ǲ���");
    return 0;
        }else{
        if(!key){
            sugar-=15;
        }
        }
		}break;
        case 3://����
        break;
		}
		return 1;
}
SHOP *Recommend(SHOP*p){
	int judge;
  	p->standard=2;
  	printf("�й��");
  	if(xiaoshou_jiancha(p,-1)==1){
  		printf("����Ʒ��������1���й�����Ƿ��� ���ǣ�1����0\n");
  		scanf("%d",&judge);
  		if(judge){
  		p->standard=2;
  		p->much=1;
  		xiaoshou_jiancha(p,0);
  		return p;
  		}else{
  		printf("���ѷ�������\n");
  		return NULL;
		  }
	  }else{
  p->standard=3;
  printf("С���:");
  if(xiaoshou_jiancha(p,-1)==1){
  		printf("����Ʒ��������1��С������Ƿ��� ���ǣ�1����0\n");
  		scanf("%d",&judge);
  		if(judge){
  		p->standard=3;
  		p->much=1;
  		xiaoshou_jiancha(p,0);
  		return p;
	  }else{
	  		printf("���ѷ�������\n");
	  		return NULL;
	  }
  }else{
  	printf("�ò�Ʒ���޷�����\n");
  	return NULL;
  }
}
}

int shop_car(){
system("cls");
int choose;
printf("ѡ����ʽ1:�ֶ�����0���ļ�����");
scanf("%d",&choose);
if(choose){
PRINTxinxi();
SHOP*head=NULL,*tail=NULL;
int n;//�û���Ҫ�������Ʒ�����������
char temp[100]={'@'};
char extra[100];//����û������Ƿ���ȷ�õ���ʱ����;
printf("\n\n\n        ��������Ҫ�����������Ʒ,0<n<4||\n");
while(1)
		{
		scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'4'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
        }
    n=extra[0]-'0';
for(int x=1;x<=n;x++){
int judge,i;
SHOP*p=(SHOP*)malloc(sizeof(SHOP));
p->s_next=NULL;
printf("\t��������Ʒ����:\n");
		while(1)
		{
		scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'4'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
        }
		p->drink=extra[0]-'0';
printf("\t��������Ʒ���\n");
	    while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
	}
		p->standard=extra[0]-'0';
printf("\t��������Ʒ��ζ\n");
		 while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
	}
	   p->taste=extra[0]-'0';
printf("\t��������Ʒ�¶�\n");
		while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
	}
		p->temper=extra[0]-'0';
printf("\t��������Ʒ���\n");
		while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("�������벻����ʵ�����������������\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("�������벻����ʵ�����������������\n");
			 }else{
			     printf("����ɹ�\n");
			 	break;
			 }
		}
	}
	p->sugar=extra[0]-'0';
printf("\t��������Ʒ����\n");
		 p->much=0;
		 while(1){
        scanf("%s",extra);
        for(i=0;i<strlen(extra);i++){
        	if((extra[i]<'0')||(extra[i]>'9')||(extra[0]=='0')){
        		printf("�������벻����ʵ�����������������\n");
        		judge=0;
        		break;
			}else{
			   	judge=1;
			}
		}
		if(judge){
            printf("����ɹ�\n");
			break;
		}
	}
	for(i=0;i<strlen(extra);i++){
		p->much+=(extra[i]-'0')*(int)pow(10,strlen(extra)-i-1);
	}
	printf("��������ʱ��\n");
	time_input(p->s_date);
     i=1;judge=1;
		while(i<=p->much){//������Ʒ�������ԭ���Ƿ��㹻;
        temp[i]=xiaoshou_jiancha(p,-1)+'0';
        if(temp[1]=='0'&&p->standard==3){
        	printf("\t����Ʒ�Ѿ��޷�����,��Ǹ\n");
        	free(p);
            judge=0;
        	break;
		}
		if(temp[1]=='0'&&p->standard!=3){
			printf("��Ϊ���Ƽ�����������Ʒ\n");
			SHOP*y=Recommend(p);
			if(y==NULL){
				free(p);
                judge=0;
				break;
			}else{
				if(head==NULL){
				head=tail=p;
				}else{
				tail->s_next=p;
				tail=p;
			} judge=0;
			break;
		}
	}
	if(temp[i]=='1') xiaoshou_jiancha(p,0);
		if(i>1&&temp[i]=='0'){
			printf("����Ʒֻ������%d��,���Ƿ���,�ǣ�1����0\n",i-1);
		    scanf("%d",&judge);
		    if(judge){
			p->much=i-1;
			if(head==NULL){
					head=tail=p;
				}else{
				tail->s_next=p;
				tail=p;} judge=0;break;
	}else{
		int j=1;
		while(j<=i-1){
		xiaoshou_jiancha(p,1);
		j++;
		}judge=0;
		free(p);
		break;
	}
	}
i++;
}
if(judge){
if(head==NULL){
					head=tail=p;
				}else{
				tail->s_next=p;
				tail=p;
			}
}
}
if(head==NULL){
	printf("��Ǹδ���ṩ����Ҫ����Ʒ\n");
}else{
    SHOP*o=head;
    PRINTF(o);
    o=head;
    yuanliaojilu(o);
    o=head;
    buy(o);
    printf("����ɹ�");
}
}else{
dingdan_wenjiandu();
}
return 0;
}

void wenjian_ding(SELL*head){//��Ҫ���붩���ڵ�ָ�� ;
	FILE*fp;
	SELL*p=head;
	int i=1,k;
	fp=fopen("dingdan.txt","w");
	while(p!=NULL){
	fprintf(fp,"\n��%d��������Ϣ\n",i);
	i++;
	k=10*p->drink+p->taste;
	switch(k){
		case 11:fprintf(fp,"��Ʒ���ࣺ�����̲� \n��ζ��ţ��ζ\n");break;
		case 12:fprintf(fp,"��Ʒ���ࣺ�����̲� \n��ζ����ݮζ\n"); break;
		case 13:fprintf(fp,"��Ʒ���ࣺ�����̲� \n��ζ������ζ\n"); break;
		case 21:fprintf(fp,"��Ʒ���ࣺ������   \n��ζ����ݮζ\n");break;
		case 22:fprintf(fp,"��Ʒ���ࣺ������   \n��ζ������ζ\n");break;
		case 23:fprintf(fp,"��Ʒ���ࣺ������   \n��ζ������ζ\n");break;
		case 31:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ���ڿ���\n");break;
		case 32:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ��Ĩ��ζ\n");break;
		case 33:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ��������ŵ\n");break;
		case 41:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ��ԭζ\n");break;
		case 42:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ����ݮζ\n");break;
		case 43:fprintf(fp,"��Ʒ���ࣺ����     \n��ζ������ζ\n");break;
	}
		switch(p->temper) {
	case 1:fprintf(fp,"�¶�:��\n"); break;
	case 2:fprintf(fp,"�¶�:����\n");break;
	case 3:fprintf(fp,"�¶�:�ӱ�\n"); break;
	}
		switch(p->sugar) {
	case 1:fprintf(fp,"��ȣ�ȫ��\n");break;
	case 2:fprintf(fp,"��ȣ������\n");break;
	case 3:fprintf(fp,"��ȣ�����\n");break;
	}
		switch(p->standard) {
	case 1:fprintf(fp,"��񣺴�\n");break;
	case 2:fprintf(fp,"�����\n");break;
	case 3:fprintf(fp,"���С\n"); break;
	}
	fprintf(fp,"����:%d��\n����:%s\n�������:%s",p->much,p->s_date,p->s_number);
	p=p->s_next;
}
fclose(fp);
printf("�ļ������ɹ�����ǰ��dingdan.txt�鿴");
}



//---------------------------------------------------------------------------------
void yuanliaojilu(SHOP*head){
	while(head!=NULL)
    {
		STOCKNOTE*p=(STOCKNOTE*)malloc(sizeof(STOCKNOTE));
		p->tea=p->cream=p->grape=p->milk=p->sugar=p->straw=p->coffee=p->yoghurt=0;
		p->s_next=NULL;
		int k=head->drink*1000+head->taste*100+head->standard*10+head->sugar;
		switch(k){
			case 1111:p->tea=15*head->much;p->milk=300*head->much;p->sugar=30*head->much;break;
			case 1112:p->tea=15*head->much;p->milk=300*head->much;p->sugar=15*head->much;break;
			case 1113:p->tea=15*head->much;p->milk=300*head->much;break;
			case 1121:p->tea=10*head->much;p->milk=300*head->much;p->sugar=30*head->much;break;
			case 1122:p->tea=10*head->much;p->milk=300*head->much;p->sugar=15*head->much;break;
			case 1123:p->tea=10*head->much;p->milk=300*head->much;break;
			case 1131:p->tea=5*head->much;p->milk=300*head->much;p->sugar=30*head->much;break;
			case 1132:p->tea=5*head->much;p->milk=300*head->much;p->sugar=15*head->much;break;
			case 1133:p->tea=5*head->much;p->milk=300*head->much;break;


			case 1211:p->tea=15*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 1212:p->tea=15*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 1213:p->tea=15*head->much;p->straw=20*head->much;break;
			case 1221:p->tea=10*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 1222:p->tea=10*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 1223:p->tea=10*head->much;p->straw=20*head->much;break;
			case 1231:p->tea=5*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 1232:p->tea=5*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 1233:p->tea=5*head->much;p->straw=20*head->much;break;


			case 1311:p->tea=15*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 1312:p->tea=15*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 1313:p->tea=15*head->much;p->grape=20*head->much;break;
			case 1321:p->tea=10*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 1322:p->tea=10*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 1323:p->tea=10*head->much;p->grape=20*head->much;break;
			case 1331:p->tea=5*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 1332:p->tea=5*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 1333:p->tea=5*head->much;p->grape=20*head->much;break;

			case 2111:p->cream=30*head->much;p->milk=300*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 2112:p->cream=30*head->much;p->milk=300*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 2113:p->cream=30*head->much;p->milk=300*head->much;p->straw=20*head->much;break;
			case 2121:p->cream=20*head->much;p->milk=200*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 2122:p->cream=20*head->much;p->milk=200*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 2123:p->cream=20*head->much;p->milk=200*head->much;p->straw=20*head->much;break;
			case 2131:p->cream=10*head->much;p->milk=100*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 2132:p->cream=10*head->much;p->milk=100*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 2133:p->cream=10*head->much;p->milk=100*head->much;p->straw=20*head->much;break;


			case 2211:p->cream=30*head->much;p->milk=300*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 2212:p->cream=30*head->much;p->milk=300*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 2213:p->cream=30*head->much;p->milk=300*head->much;p->grape=20*head->much;break;
			case 2221:p->cream=20*head->much;p->milk=200*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 2222:p->cream=20*head->much;p->milk=200*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 2223:p->cream=20*head->much;p->milk=200*head->much;p->grape=20*head->much;break;
			case 2231:p->cream=10*head->much;p->milk=100*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 2232:p->cream=10*head->much;p->milk=100*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 2233:p->cream=10*head->much;p->milk=100*head->much;p->grape=20*head->much;break;


			case 2311:p->cream=30*head->much;p->milk=300*head->much;p->yoghurt=50*head->much;p->sugar=30*head->much;break;
			case 2312:p->cream=30*head->much;p->milk=300*head->much;p->yoghurt=50*head->much;p->sugar=15*head->much;break;
			case 2313:p->cream=30*head->much;p->milk=300*head->much;p->yoghurt=50*head->much;break;
			case 2321:p->cream=20*head->much;p->milk=200*head->much;p->yoghurt=50*head->much;p->sugar=30*head->much;break;
			case 2322:p->cream=20*head->much;p->milk=200*head->much;p->yoghurt=50*head->much;p->sugar=15*head->much;break;
			case 2323:p->cream=20*head->much;p->milk=200*head->much;p->yoghurt=50*head->much;break;
			case 2331:p->cream=10*head->much;p->milk=100*head->much;p->yoghurt=50*head->much;p->sugar=30*head->much;break;
			case 2332:p->cream=10*head->much;p->milk=100*head->much;p->yoghurt=50*head->much;p->sugar=15*head->much;break;
			case 2333:p->cream=10*head->much;p->milk=100*head->much;p->yoghurt=50*head->much;break;

			case 3111:p->coffee=20*head->much;p->sugar=30*head->much;break;
			case 3112:p->coffee=20*head->much;p->sugar=15*head->much;break;
			case 3113:p->coffee=20*head->much;break;
			case 3121:p->coffee=15*head->much;p->sugar=30*head->much;break;
			case 3122:p->coffee=15*head->much;p->sugar=15*head->much;break;
			case 3123:p->coffee=15*head->much;break;
			case 3131:p->coffee=10*head->much;p->sugar=30*head->much;break;
			case 3132:p->coffee=10*head->much;p->sugar=15*head->much;break;
			case 3133:p->coffee=10*head->much;break;


			case 3211:p->coffee=20*head->much;p->tea=5*head->much;p->sugar=30*head->much;break;
			case 3212:p->coffee=20*head->much;p->tea=5*head->much;p->sugar=15*head->much;break;
			case 3213:p->coffee=20*head->much;p->tea=5*head->much;break;
			case 3221:p->coffee=15*head->much;p->tea=5*head->much;p->sugar=30*head->much;break;
			case 3222:p->coffee=15*head->much;p->tea=5*head->much;p->sugar=15*head->much;break;
			case 3223:p->coffee=15*head->much;p->tea=5*head->much;break;
			case 3231:p->coffee=10*head->much;p->tea=5*head->much;p->sugar=30*head->much;break;
			case 3232:p->coffee=10*head->much;p->tea=5*head->much;p->sugar=15*head->much;break;
			case 3233:p->coffee=10*head->much;p->tea=5*head->much;break;


			case 3311:p->coffee=20*head->much;p->milk=50*head->much;p->sugar=30*head->much;break;
			case 3312:p->coffee=20*head->much;p->milk=50*head->much;p->sugar=15*head->much;break;
			case 3313:p->coffee=20*head->much;p->milk=50*head->much;break;
			case 3321:p->coffee=15*head->much;p->milk=50*head->much;p->sugar=30*head->much;break;
			case 3322:p->coffee=15*head->much;p->milk=50*head->much;p->sugar=15*head->much;break;
			case 3323:p->coffee=15*head->much;p->milk=50*head->much;break;
			case 3331:p->coffee=10*head->much;p->milk=50*head->much;p->sugar=30*head->much;break;
			case 3332:p->coffee=10*head->much;p->milk=50*head->much;p->sugar=15*head->much;break;
			case 3333:p->coffee=10*head->much;p->milk=50*head->much;break;

			case 4111:p->yoghurt=350*head->much;p->sugar=30*head->much;break;
			case 4112:p->yoghurt=350*head->much;p->sugar=15*head->much;break;
			case 4113:p->yoghurt=350*head->much;break;
			case 4121:p->yoghurt=250*head->much;p->sugar=30*head->much;break;
			case 4122:p->yoghurt=250*head->much;p->sugar=15*head->much;break;
			case 4123:p->yoghurt=250*head->much;break;
			case 4131:p->yoghurt=150*head->much;p->sugar=30*head->much;break;
			case 4132:p->yoghurt=150*head->much;p->sugar=15*head->much;break;
			case 4133:p->yoghurt=150*head->much;break;


			case 4211:p->yoghurt=350*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 4212:p->yoghurt=350*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 4213:p->yoghurt=350*head->much;p->straw=20*head->much;break;
			case 4221:p->yoghurt=250*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 4222:p->yoghurt=250*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 4223:p->yoghurt=250*head->much;p->straw=20*head->much;break;
			case 4231:p->yoghurt=150*head->much;p->straw=20*head->much;p->sugar=30*head->much;break;
			case 4232:p->yoghurt=150*head->much;p->straw=20*head->much;p->sugar=15*head->much;break;
			case 4233:p->yoghurt=150*head->much;p->straw=20*head->much;break;


			case 4311:p->yoghurt=350*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 4312:p->yoghurt=350*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 4313:p->yoghurt=350*head->much;p->grape=20*head->much;break;
			case 4321:p->yoghurt=250*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 4322:p->yoghurt=250*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 4323:p->yoghurt=250*head->much;p->grape=20*head->much;break;
			case 4331:p->yoghurt=150*head->much;p->grape=20*head->much;p->sugar=30*head->much;break;
			case 4332:p->yoghurt=150*head->much;p->grape=20*head->much;p->sugar=15*head->much;break;
			case 4333:p->yoghurt=150*head->much;p->grape=20*head->much;break;
		}
		strcpy(p->s_date,head->s_date);
		if(NOTEhead==NULL){
			NOTEhead=NOTEtail=p;
		}else{
			NOTEtail->s_next=p;
			NOTEtail=p;
		}
		head=head->s_next;
	}
}
void yuanliaojilucha(STOCKNOTE*x){
    int Smilk=0;
    int Stea=0;
    int Scream=0;
    int Scoffee=0;
    int Syoghurt=0;
    int Sstraw=0;
    int Sgrape=0;
    int Ssugar=0;
    char date1[20];
    char date2[20];
    int choose;
    STOCKNOTE*p=x;
    printf("�����Բ�ѯԭ��ʹ�ü�¼:\n1:һ��ʱ��;    2:����\n");
	scanf("%d",&choose);
	switch(choose){
		case 1:
		while(1){
        printf("�����뿪ʼʱ��\n");
		scanf("%s",date1);
		printf("���������ʱ��\n");
		scanf("%s",date2);
		if(strcmp(date1,date2)<=0){
			break;
		}else{
			printf("����ʱ�����벻����ʵ�����,����������\n");
		}
	}
	if(p==NULL)
    {printf("��ǰԭ����ʹ�ü�¼");
    return ;}
	while(strcmp(p->s_date,date1)<0) p=p->s_next;
	while(p!=NULL&&(strcmp(p->s_date,date1)>=0)&&(strcmp(p->s_date,date2)<=0)){
		   Smilk+=p->milk;
		   Stea+=p->tea;
		   Scream+=p->cream;
		   Scoffee+=p->coffee;
		   Syoghurt+=p->yoghurt;
		   Sstraw+=p->straw;
		   Sgrape+=p->grape;
		   Ssugar+=p->sugar;
		   p=p->s_next;
}
	if(Smilk!=0)printf("\nţ��ʹ������%d\n",Smilk);
	if(Stea!=0)printf("��ʹ������%d\n",Stea);
	if(Scream!=0)printf("����ʹ������%d\n",Scream);
	if(Scoffee!=0)printf("���ȶ�ʹ������%d\n",Scoffee);
	if(Syoghurt!=0)printf("����ʹ������%d\n",Syoghurt);
	if(Sstraw!=0)printf("��ݮʹ������%d\n",Sstraw);
	if(Sgrape!=0)printf("����ʹ������%d\n",Sgrape);
	if(Ssugar!=0)printf("��ʹ������%d\n\n\n",Ssugar);
	break;
	case 2:
		while(x!=NULL){
		   Smilk+=x->milk;
		   Stea+=x->tea;
		   Scream+=x->cream;
		   Scoffee+=x->coffee;
		   Syoghurt+=x->yoghurt;
		   Sstraw+=x->straw;
		   Sgrape+=x->grape;
		   Ssugar+=x->sugar;
		   x=x->s_next;
		   }if(Smilk!=0)printf("\nţ��ʹ������%d\n",Smilk);
	if(Stea!=0)printf("��ʹ������%d\n",Stea);
	if(Scream!=0)printf("����ʹ������%d\n",Scream);
	if(Scoffee!=0)printf("���ȶ�ʹ������%d\n",Scoffee);
	if(Syoghurt!=0)printf("����ʹ������%d\n",Syoghurt);
	if(Sstraw!=0)printf("��ݮʹ������%d\n",Sstraw);
	if(Sgrape!=0)printf("����ʹ������%d\n",Sgrape);
	if(Ssugar!=0)printf("��ʹ������%d\n",Ssugar);
		   break;

	}
}


void PRINTxinxi(){
printf("\n                  \t��Ʒ��Ϣ������\n");
printf("\t���:       [1]��       [2]��       [3]С\n");
printf("\t���:       [1]ȫ��     [2]�����   [3] ����\n");
printf("\t�¶�:       [1]��       [2]����     [3] ��\n");
printf("\t��Ʒ:       [1]�����̲�   ��:15Ԫ  �б�: 13Ԫ   С��:8Ԫ\n");
printf("\t��Ʒ:       [2]������     ��:10Ԫ  �б�: 8Ԫ    С��:5Ԫ\n");
printf("\t��Ʒ:       [3]����       ��:16Ԫ  �б�: 14Ԫ   С��:10Ԫ\n");
printf("\t��Ʒ:       [4]����       ��:12Ԫ  �б�: 10Ԫ   С��:8Ԫ\n");
printf("\t�����̲�:   [1]ţ��ζ  [2]��ݮζ    [3] ����ζ\n");
printf("\t������:     [1]��ݮζ  [2]����ζ    [3] ����ζ\n");
printf("\t����:       [1]�ڿ���  [2]Ĩ��ζ    [3] ������ŵ\n");
printf("\t����:       [1]ԭζ    [2]��ݮζ    [3] ����ζ\n");
}

void jinhuo_sort(PUR* sorthead)
{
    PUR* p0,*q0,*q,*q1;
    p0=q0=sorthead;
    if(p0==NULL)
        return ;
    int i=2,k;
    while(q0!=NULL)
        {q0=q0->p_next;
        i++;
        }
    for(k=0;k<=i;k++)
    {
        q0=p0;
        while(q0->p_next->p_next!=NULL)
        {
            q=q0->p_next;
            if(strcmp(q->p_date,q->p_next->p_date)>0)
            {
                q1=q->p_next;
                q0->p_next=q1;
                q->p_next=q1->p_next;
                q1->p_next=q;
            }
            else
            {
                q0=q0->p_next;
            }
        }
    }
}
void dingdan_wenjiandu(){
    int dw_n=0;
	SHOP*head=NULL,*tail=NULL;
	system("cls");
	printf("��Ҫ���������������Ϣ");
	scanf("%d",&dw_n);
	FILE*fp;
	fp=fopen("dingdandu.txt","r");
 for(int i=1;i<=dw_n;i++){
		SHOP*p=(SHOP*)malloc(sizeof(SHOP));
		p->s_next=NULL;
		fscanf(fp,"%d%d%d%d%d%d",&p->drink,&p->standard,&p->taste,&p->sugar,&p->temper,&p->much);
		while(1){
		char ch=fgetc(fp);
		if(ch=='#')break;
	}
	    fscanf(fp,"%s",p->s_date);
	    if(head==NULL){
	    	head=tail=p;
		}else{
			tail->s_next=p;
			tail=p;
		}
		for(int k=1;k<=p->much;k++){
		xiaoshou_jiancha(p,0);
	}
}
fclose(fp);
SHOP*o=head;
PRINTF(o);
o=head;
buy(o);
o=head;
yuanliaojilu(o);
}

void xiaoliangtongji(SELL*head){
	 system("cls");
	 printf("��ѯ��ʽ��1:һ����Ʒ2��ȫ����Ʒ\n");
	 int choose;
	 int kind;
	 int taste;
	 int k;
	 int sales=0;
	 scanf("%d",&choose);
	 switch(choose){
	 	case 1:
	 	printf("��������Ʒ������\n");
	 	scanf("%d",&kind);
	 	printf("��������Ʒ�Ŀ�ζ\n");
	 	scanf("%d",&taste);
	 	SELL*o=head;
	 	while(o!=NULL){
	 		if(o->drink==kind&&o->taste==taste)
	 		sales+=o->much;
	 		o=o->s_next;
		 }
	 	printf("����Ʒ����Ϊ%d\n",sales);
	 	break;
	 	case 2:{
	 		int sales11=0,sales12=0,sales13=0,sales21=0,sales22=0,sales23=0,sales31=0,sales32=0,sales33=0,sales41=0,sales42=0,sales43=0;
	 		SELL*o=head;
	 		while(o!=NULL){
	 		k=o->drink*10+o->taste;
	 		switch(k){
	 			 case 11:sales11+=o->much;break;
				 case 12:sales12+=o->much;break;
				 case 13:sales13+=o->much;break;
				 case 21:sales21+=o->much;break;
				 case 22:sales22+=o->much;break;
				 case 23:sales23+=o->much;break;
				 case 31:sales31+=o->much;break;
				 case 32:sales32+=o->much;break;
				 case 33:sales33+=o->much;break;
				 case 41:sales41+=o->much;break;
				 case 42:sales42+=o->much;break;
				 case 43:sales43+=o->much;break;
	 		}
	 			o=o->s_next;
	 		}
	 		printf("�����̲�ţ��ζ   ������%d\n",sales11);
	 		printf("�����̲��ݮζ   ������%d\n",sales12);
	 		printf("�����̲�����ζ   ������%d\n",sales13);
	 		printf("�����ܲ�ݮζ     ������%d\n",sales21);
	 		printf("����������ζ     ������%d\n",sales22);
	 		printf("����������ζ     ������%d\n",sales23);
	 		printf("����ԭζ�ڿ���   ������%d\n",sales31);
	 		printf("����Ĩ��ζ       ������%d\n",sales32);
	 		printf("���ȿ�����ŵ     ������%d\n",sales33);
	 		printf("����ԭζ         ������%d\n",sales41);
	 		printf("���̲�ݮζ       ������%d\n",sales42);
	 		printf("��������ζ       ������%d\n",sales43);
	 		break;}
	 		}
			 }

//------------------------------------------------------
double yuce(int y[35])//����ֵ���飩��ϲ�Ԥ��
{
    int k_day=7;
    double a,b;//�ع�ϵ��
    double dx[35],dy[35];

    //��������ת��
    for(int i=0;i<k_day;i++)
    {
        dx[i]=i+1;
        dy[i]=(double)y[i];
    }

    //�м��������
    double hexy=0,hex=0,hey=0,hex2=0;
    for(int i=0;i<k_day;i++)
    {
        hexy+=dx[i]*dy[i];
        hex+=dx[i];
        hey+=dy[i];
        hex2+=dx[i]*dx[i];
    }

    //�ع�ϵ������
    b=(k_day*hexy-hex*hey)/(k_day*hex2-hex*hex);
    a=hey/k_day-b*hex/k_day;

    //Ԥ��
    double y_result=0;//Ԥ����
    y_result=b*8+a;

    return y_result;//����Ԥ����
}

int leap(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
	return 1;
	else
	return 0;
}

void timetrans(char tr_date[11])
{
    int year,month,day;
    year=(tr_date[0]-'0')*1000+(tr_date[1]-'0')*100+(tr_date[2]-'0')*10+(tr_date[3]-'0');
    month=(tr_date[5]-'0')*10+(tr_date[6]-'0');
	day=(tr_date[8]-'0')*10+(tr_date[9]-'0');
	for(int tn=6;tn>=0;tn--)
    {
        while(day-1<=0)
        {
            if(month>1)
            {
                month--;
                day=day+d[leap(year)][month];
            }
            else
            {
                year--;
                month=12;
                day=day+d[leap(year)][month];
            }
        }
        day=day-1;
        char tr_year[5],tr_month[3],tr_day[3];
        sprintf(tr_year,"%04d",year);
        sprintf(tr_month,"%02d",month);
        sprintf(tr_day,"%02d",day);
        sprintf(trtime[tn],"%s.%s.%s",tr_year,tr_month,tr_day);
    }

	return 0;
}

int** search_material(STOCKNOTE*q) //pΪͷ
{
    STOCKNOTE*p=q;
   int ii,jj;
   for(ii=0;ii<8;ii++)  //ԭ������
   {
       switch(ii)
       {
        case 0://milk
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->milk;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 1://tea
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->tea;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 2://cream
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->cream;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 3://coffee
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->coffee;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 4://yoghurt
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->yoghurt;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 5://straw
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->straw;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 6://grape
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->grape;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        case 7://sugar
            for(jj=0;jj<7;jj++) //����
            {
               int sum=0;
               p=q;
               while(p)
               {
                   if(strcmp(p->s_date,trtime[jj])==0)
                   sum+=p->sugar;
                   p=p->s_next;
               }
               search_result[ii][jj]=sum;
            }
            break;
        }
    }
    //------------
    for(int i=0;i<8;i++)
    {
        switch(i+1)
        {
            case 1:printf("\tţ�̽�����������ֱ�Ϊ��  ");break;
            case 2:printf("\t��Ҷ������������ֱ�Ϊ��  ");break;
            case 3:printf("\t���ͽ�����������ֱ�Ϊ��  ");break;
            case 4:printf("\t���ȶ�������������ֱ�Ϊ��");break;
            case 5:printf("\t���̽�����������ֱ�Ϊ��  ");break;
            case 6:printf("\t��ݮ������������ֱ�Ϊ��  ");break;
            case 7:printf("\t���ѽ�����������ֱ�Ϊ��  ");break;
            case 8:printf("\t���ǽ�����������ֱ�Ϊ��  ");break;
        }
        for(int k=0;k<7;k++)
        {

            printf("%4d ",search_result[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");
    return search_result;
}

void kucun_jiance()
{
    char yutime[11];
    printf("�������������ڣ�");
    time_input(yutime);
    timetrans(yutime);
    search_material(NOTEhead);
    for(int i=0;i<8;i++)
    {
        double yuresult;
        yuresult=yuce(search_result[i]);
        if(yuresult<0)
            yuresult=0;
        switch(i+1)
        {
            case 1:
                printf("ţ��Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",milk);
                if(yuresult>milk)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 2:
                printf("��ҶԤ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",tea);
                if(yuresult>tea)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 3:
                printf("����Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",cream);
                if(yuresult>cream)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 4:
                printf("���ȶ�Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",coffee);
                if(yuresult>coffee)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 5:
                printf("����Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",yoghurt);
                if(yuresult>yoghurt)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 6:
                printf("��ݮԤ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",straw);
                if(yuresult>straw)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 7:
                printf("����Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",grape);
                if(yuresult>grape)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
            case 8:
                printf("����Ԥ��ʹ����Ϊ��%llf g,\t",yuresult);
                printf("��ǰ���Ϊ%dg,",sugar);
                if(yuresult>sugar)
                    printf("��治�㣬�뼰ʱ���䣡\n");
                else
                    printf("��ǰ�����㡣\n");
                break;
        }
    }
}

