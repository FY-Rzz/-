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
    SetConsoleTitleA("饮品店管理系统");  //设置窗口的标题
    system("mode con cols=300 lines=50 ");//设置窗口大小
    system("color 9E");//设置窗口颜色
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
            case 1://原料进货管理系统
                for(;;)
                {
                   int p_tag=1;//返回上一级标志
                   switch(jinhuo_menu())
                   {
                       char cha_time[20];
                       case 1://原料进货
                           {system("cls");
                           int n;//进货订单条数
                           printf("请输入进货订单条数：\t");
                           scanf("%d",&n);
                           jinhuo(n,p_head);
                           printf("原料进货完成！");
                           system("pause");
                           break ;}
                       case 2://进货信息查询
                           {system("cls");
                            printf("\t\t☆☆ 1.   查询全部                        ☆☆\n\n");
                            printf("\t\t☆☆ 2.   按时间查询                      ☆☆\n\n");
                            printf("\t\t☆☆ 3.   按订单编号查询                  ☆☆\n\n");
                            printf("\t\t☆☆ 4.   按原料种类查询                  ☆☆\n\n");
                            printf("\t\t☆☆ 0.   返回上一级菜单                  ☆☆\n\n");
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

                                    printf("请输入您想查询何时之后的进货订单：\n");
                                    time_input(cha_time);
                                    jinhuo_cha_time(cha_time,p_head);
                                    break ;
                                case 3:
                                    {system("cls");
                                    printf("请输入您想查询的进货编号：\n");
                                    char cha_number[20];
                                    scanf("%s",cha_number);
                                    jinhuo_cha_number(cha_number,p_head);

                                    break ;
                                    }

                                case 4:
                                    {while(1)
                                    {
                                        system("cls");
                                        printf("请输入您想查询的原料种类：\n");
                                        printf("\t\t☆☆ 1.   牛奶                  ☆☆\n\n");
                                        printf("\t\t☆☆ 2.   茶叶                  ☆☆\n\n");
                                        printf("\t\t☆☆ 3.   奶油                  ☆☆\n\n");
                                        printf("\t\t☆☆ 4.   咖啡豆                ☆☆\n\n");
                                        printf("\t\t☆☆ 5.   酸奶                  ☆☆\n\n");
                                        printf("\t\t☆☆ 6.   草莓                  ☆☆\n\n");
                                        printf("\t\t☆☆ 7.   葡萄                  ☆☆\n\n");
                                        printf("\t\t☆☆ 8.   白糖                  ☆☆\n\n");
                                        printf("\t\t☆☆ 0.   返回上一级菜单        ☆☆\n\n");

                                        int cha_kind=0;
                                        scanf("%d",&cha_kind);
                                        if(cha_kind)
                                        {
                                            jinhuo_cha_kind(cha_kind,p_head);
                                            break ;
                                        }
                                        if(!cha_kind)
                                            break ;
                                        printf("数据输入有误！请重新输入！");
                                        Sleep(2000);
                                    }
                                    break ;}
                                case 0:
                                    break ;
                            }
                            system("pause");
                            break ;}
                        case 3://进货信息文件导出
                            system("cls");
                            jinhuo_txt(p_head);
                            system("pause");
                            break ;
                        case 4://从文件中读取进货信息
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
            case 2://商品售卖管理系统
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
                                printf("\n\n\t\t===============================商品信息查询系统======================\n\n");
                                printf("\t\t☆☆ 1.   按时间查询                      ☆☆\n\n");
                                printf("\t\t☆☆ 2.   按商品查询                      ☆☆\n\n");
                                printf("\t\t☆☆ 3.   按订单查询                      ☆☆\n\n");
                                printf("\t\t☆☆ 4.   查询全部订单                        ☆☆\n\n");
								printf("\t\t☆☆ 0.   返回上一级                          ☆☆\n\n");
								printf("\t\t请选择您要运行的选项（0-4)");

								scanf("%d", &jhuo);
                                if (jhuo < 0 || jhuo>4)
                                {
                                    printf("\n\n输入不符合要求，请输入正确的信息！\n\n");
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
								    printf("\t查询完毕\n");
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

            case 3://原料库存
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

            case 4://ip管理系统
                for(;;)
				{
					int fhui=1;
					VIP*pvip,*pvip2;
					char vipc[29];
					system("CLS");
					do{
                        system("cls");
					    printf("\n\n\t\t===============================会员管理系统======================\n\n");
                        printf("\t\t☆☆ 1.   注册会员                      ☆☆\n\n");
                        printf("\t\t☆☆ 2.   账户管理                      ☆☆\n\n");
                        printf("\t\t☆☆ 3.   打印全部会员信息              ☆☆\n\n");
                        printf("\t\t☆☆ 4.   文件导出会员信息              ☆☆\n\n");
                        printf("\t\t☆☆ 0.   返回上一级菜单                ☆☆\n\n");
                        printf("\t\t请选择您要运行的选项（0-4）");
                        scanf("%s",vipc);
                        if(strlen(vipc)!=1||vipc[0]<'0'||vipc[0]>'4')
                        {
                        	printf("\n输入不符合要求，请输入正确的信息！\n");
                            Sleep(1000);
						}
				   }while(strlen(vipc)!=1||vipc[0]<'0'||vipc[0]>'4');
					switch(vipc[0]-'0')
					{
						case 1:
							system("cls");
						    pvip2=tobe_vip();
						    if(pvip2)
						    printf("\t会员注册成功!\n");
						    system("pause");
						    break;
						case 2:
							system("cls");
							lala:
							pvip=vip_login();
							if(!pvip){break;}
							la:
							system("cls");
							printf("\n\t请输入你要执行的选项:");
							printf("\n\t1.修改密码");
							printf("\n\t2.抽奖（花费200积分）");
							printf("\n\t3.退出登录\n");
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





			case 5://资金管理系统

				while(1) {
					int m_tag=1;
					//char money_get=money_manage_choose();
					double touzi_money;

					switch(money_manage_choose()) {
						case '1'://总资金
							zijin_txt();//显示于txt文本
							system("cls");
							zijin_cha();//窗口显示
							system("pause");
							break;

						case '2'://订单txt
							system("cls");
							order_zijin_txt();
							break;

						case '3'://原料txt
							system("cls");
							material_zijin_txt();
							break;

						case '4'://投资txt
							system("cls");
							other_zijin_txt();
							break;

						case '5'://投资
							system("cls");
							printf("输入0退出:\n");
							printf("请输入投资金额:");
							touzi_money=search_putin();
							//scanf("%lf",&touzi_money);
							if(touzi_money<=0)break;
							else touzi(touzi_money);
							break;

						case '6'://投资
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
        printf("\n\n\t\t==============================库存管理系统============================\n\n");
        printf("\t\t☆☆ 1.   原料现有库存查询              ☆☆\n\n");
        printf("\t\t☆☆ 2.   原料使用记录查询              ☆☆\n\n");
        printf("\t\t☆☆ 3.   检测库存进货提醒              ☆☆\n\n");
        printf("\t\t☆☆ 0.   返回上一级菜单                ☆☆\n\n");
        printf("\t\t--------------------------------------------\n\n");
        printf("\t\t请选择您要运行的选项（0-3）");
        scanf("%d",&ans);
        if(ans<0||ans>3)
        {
            printf("\n\n输入不符合要求，请输入正确的信息！\n\n");
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
        printf("\n\n\t\t===============================原料进货管理系统======================\n\n");
        printf("\t\t☆☆ 1.   原料进货                      ☆☆\n\n");
        printf("\t\t☆☆ 2.   进货信息查询                  ☆☆\n\n");
        printf("\t\t☆☆ 3.   进货信息文件导出              ☆☆\n\n");
        printf("\t\t☆☆ 4.   从文件中读取进货信息          ☆☆\n\n");
        printf("\t\t☆☆ 0.   返回上一级菜单                ☆☆\n\n");
        printf("\t\t-------------------------------------------------------------------------\n\n");
        printf("\t\t请选择您要运行的选项（0-4）");
        scanf("%d",&ans);
        if(ans<0||ans>4)
        {
            printf("\n\n输入不符合要求，请输入正确的信息！\n\n");
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
        printf("\n\n\t\t===============================商品售卖管理系统======================\n\n");
        printf("\t\t☆☆ 1.   商品购买                         ☆☆\n\n");
        printf("\t\t☆☆ 2.   商品售卖信息查询                 ☆☆\n\n");
        printf("\t\t☆☆ 3.   商品售卖信息信息文件导出         ☆☆\n\n");
        printf("\t\t☆☆ 4.   商品销量统计                     ☆☆\n\n");
        printf("\t\t☆☆ 0.   返回上一级菜单                   ☆☆\n\n");
        printf("\t\t--------------------------------------------\n\n");
        printf("\t\t请选择您要运行的选项（0-4）");
        scanf("%d",&ans);
        if(ans<0||ans>4)
        {
            printf("\n\n输入不符合要求，请输入正确的信息！\n\n");
            Sleep(1000);
        }
    }while(ans<0||ans>4);
    return ans;
}



int time_input(char* timeplus) { //(时间存储数组)时间格式输入
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
			printf("您的输入不符合实际，请重新输入\n");}
	}
     for( i=0,k=0; i<10; i++) {
		 timeplus[k++]=extra[i];
	}
	timeplus[10]='\0';
	return 1;
}

//--------------------------------VIP-------------------------------------------
int isnum(char a[],int n)      //判断输入的是不是数字（用于检测手机号）
{   int i=0;
    for(;i<n;i++) if(a[i]>'9'||a[i]<'0') return 0;
    return 1;
}

int phone_repeat(char *phone)
{
    VIP*p=head_v->next;
    while(p)
    {
        if(strcmp(phone,p->phone)==0) return 0;  //0为重复
        p=p->next;
    }
    return 1;
}

VIP* tobe_vip()            //注册vip
//会员结构体需要在主函数设置头尾两个指针，head_v,rear_v;
{
    system("CLS");
    VIP* pp=(VIP*)malloc(sizeof(VIP));
    pp->next=NULL;
    char Phone[30],password1[30],mi1[30],vv[30],xingming[30];
    int flag=1,len1;
    do
    {
        if(flag==0) printf("输入格式有误或重复，请重新输入\n");
        else printf("请输入你的手机号：\n");
        scanf("%s",Phone);
        len1=strlen(Phone);
        flag=0;
    }while(len1!=11||!isnum(Phone,len1)||!phone_repeat(Phone));


    flag=1;
    do
    {
        if(flag==0)  printf("输入有误，请重新输入\n");
        printf("请输入你的密码(不超过15位)：\n");
        scanf("%s",password1);
        flag=0;
    }while(strlen(password1)>15);        //密码不超过16位


    printf("\n请输入您的名字:");
    scanf("%s",xingming);

    printf("\n请输入“你的父亲是谁？”的答案作为密保：");
    scanf("%s",mi1);
    printf("\n确认注册会员？(输入1确认注册)");
    scanf("%s",vv);
    if(strlen(vv)!=1||vv[0]!='1')
    {
        printf("\n本次注册取消");
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

void isvip(int money)                  //输入账号密码判断是否为vip
{
    char s[20],dianhua[20];
    //int flag=1;
    printf("\n您是否为VIP客户?(输入1确认)");
    scanf("%s",s);
    if(strlen(s)==1&&s[0]=='1')
    {
	    queren1:
        printf("\n\t请输入您的电话号码确认身份:");
        scanf("%s",dianhua);
        if(strlen(dianhua)!=11||!isnum(dianhua,11)){printf("手机号格式错误\n");goto queren1;}
        VIP*p=head_v->next;
        while(p)
        {
            if(strcmp(p->phone,dianhua)==0) break;
            p=p->next;
        }
        if(p==0)
        {
            printf("账户不存在,是否再次输入？（输入1确认）");
            scanf("%s",s);
            if(strlen(s)==1&&s[0]=='1') goto queren1;
            else return;
        }
        else
        {
            printf("账户成功积%d分",money);
            p->score+=money;

        }
    }
    else
    {
        printf("\n您是否想成为VIP客户？(输入1确认)");
        scanf("%s",s);
        if(strlen(s)!=1||s[0]!='1') return;
        else
        {
            VIP*pv=tobe_vip();
            if(pv==NULL)
            {
                printf("\n放弃注册，本次无积分");
            }
            else
            {
                printf("\n注册成功并成功积%d分",money);
                pv->score+=money;
            }
            return;
        }
    }
}



VIP* vip_login()           //会员管理
{
    char ca[30],ph[30],pa[30],bao[30];
    VIP*p=head_v->next;
    shuru:             //输入是否合法返回地址
    system("CLS");
    printf("\t请选择:\n");
    printf("\t1;密码登录\n\t2;忘记密码\n\t3.返回上一级\n");
    scanf("%s",ca);
    if(strlen(ca)==1&&ca[0]=='3') return NULL;  //返回上一级
	if(strlen(ca)!=1||(ca[0]!='1'&&ca[0]!='2'))
	{
		printf("\n输入格式不符合要求，请重新输入");
        goto shuru;
	}
    ph1:                               //手机号输入返回地点
    printf("\n请输入您的手机号码：");
    scanf("%s",ph);
    if(strlen(ph)!=11||!isnum(ph,11))
        {printf("手机号格式错误\n");goto ph1;}
    while(p)
    {
        if(strcmp(p->phone,ph)==0) break;
        p=p->next;
    }

    if(strlen(ca)==1&&ca[0]=='1')       //选择密码登录
    {
        printf("\n请输入密码:");
        scanf("%s",pa);
        if(p==NULL||strcmp(p->vip_pass,pa)!=0)
        {
            printf("\n手机号或密码错误，请重新输入！");
            goto ph1;
        }
        else
        {
            printf("登陆成功！");
            Sleep(1000);
            return p;

        }
    }
    else        //选择忘记密码，密保登录
    {
        printf("\n请输入问题“你的父亲是谁”的答案:");
        baohu:         //重新输入密保
        scanf("%s",bao);
        if(strcmp(p->mibao,bao)==0)
        {
            printf("\n输入正确,密码已被初始化为123456");
            Sleep(1000);
            strcpy(p->vip_pass,"123456");
            return p;
        }
        else
        {
            printf("\n输入错误，请重新输入:");
            goto baohu;
        }
    }

}



void choujiang(VIP*p)
{
    system("CLS");
    if(p->score<200) {printf("您的积分不足\n");system("pause");return;}
    printf("\t奖品名单：\n");
    printf("\t特等奖：（2%）\n");
    printf("\t一等奖：（5%）\n");
    printf("\t二等奖：（10%）\n");
    printf("\t三等奖：（23%）\n");
    printf("\t参与奖：（60%）\n");
    srand((unsigned)time(NULL));
    int n=rand()%100;
    p->score-=200;
    if(n==0||n==1){printf("恭喜你抽中特等奖\n");system("pause");}
    if(n>=2&&n<=6){printf("恭喜你抽中一等奖\n");system("pause");}
    if(n>=7&&n<=16){printf("恭喜你抽中二等奖\n");system("pause");}
    if(n>=17&&n<=39){printf("恭喜你抽中三等奖\n");system("pause");}
    if(n>=40&&n<=99){printf("你抽中了参与奖\n");system("pause");}
}

void pass_change(VIP*p)
{
    char pass[39];
    printf("请输入你的原密码：");
    scanf("%s",pass);
    while(strcmp(p->vip_pass,pass)!=0){printf("\t密码错误\n");scanf("%s",pass);}
    printf("请输入你的现密码：");
    scanf("%s",pass);
    while(strlen(pass)>15){printf("\t密码长度过长");scanf("%s",pass);}
    strcpy(p->vip_pass,pass);
    printf("密码修改成功");
    Sleep(1000);
}


void F_inputVip(VIP*head)
{
    VIP*pp=head->next;
    if(!pp)
	{
		printf("\t暂时还没有会员信息.\n");
		return;
	}
    FILE*fp;
    fp=fopen("VIPsystem.txt","w");
    fprintf(fp,"\t会员名单\t\t\t积分\n");
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
	printf("\t会员名单\t\t\t密码\t\t\t积分\n");
	VIP*pp=head->next;
	if(!pp)
	{
		printf("\t暂时还没有会员信息.\n");
		return;
	}
    while(pp)
    {
        printf("\t%s\t\t\t%s\t\t\t%d\n",pp->phone,pp->vip_pass,pp->score);
        pp=pp->next;
    }
}



//---------------------------------jinhuo----------------------------------------------

PUR* jinhuo(int n,PUR* jp_head)//（进货订单条数，订单哨兵链表头）进货订单创建函数
{
    int i;
    PUR* j_head,*tmp,*q;
    char tmp_time[20];
    while(n<=0)
    {
        printf("请输入合法数字！\n");
        scanf("%d",&n);
    };
    q=j_head=jp_head;
    while(j_head->p_next!=NULL)//定位当前尾链表
    {
        j_head=j_head->p_next;
    }
    q=j_head;
    printf("请输入本次采购时间（2021.xx.xx):\t");
    time_input(tmp_time);//时间输入函数
    for(i=0;i<n;i++,jin_count++)
    {
        double mmm;//暂存资金
        printf("\n请输入第 %d 笔订单信息：\n",i+1);
        printf("\n【原料种类信息由数字代替：1.牛奶 2.茶叶 3.奶油 4.咖啡豆 5.酸奶 6.草莓 7.葡萄 8.白糖||重量单位默认为克】\n\n");
        char str[20]={'0','0','0','0'};
        sprintf(str,"%03d",jin_count);
        tmp=(PUR*)malloc(sizeof(PUR));

        printf("原 料 种 类 ：\t");
        do{
            scanf("%d",&tmp->kind);
            if(tmp->kind<0||tmp->kind>8)
                printf("请输入正确的种类！\n");
        }while(tmp->kind<0||tmp->kind>8);

        strcpy(tmp->p_date,tmp_time);//时间

        printf("原 料 进 价 ：\t");
        //scanf("%lf",&tmp->p_money);
        mmm=search_putin();
        tmp->p_money=mmm;

        printf("原 料 重 量 ：\t");
        do{
            scanf("%d",&tmp->weight);
            if(tmp->weight<0)
                printf("请输入正确的重量！\n");
        }while(tmp->weight<0);

        //订单编号生成
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

        q->p_next=tmp;//向当前尾链表后插入新链表
        tmp->p_next=NULL;
        q=q->p_next;
        /*库存修改函数*/
        kucun_gai(tmp->kind,1,tmp->weight);

    }
    sum_money(j_head->p_next);
    jinhuo_sort(p_head);
    return jp_head;
}

void jinhuo_cha_all(PUR* head)//（全局链表头）进货记录查询函数
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("目前并无进货记录！\n");
        system("pause");
        return ;
    }
    printf("原料进货记录如下：\n");
    printf("\t\t---订单编号---\t\t---种类---\t\t---单价---\t\t---重量---\t\t---时间---\n");

    while(tmpP!=NULL)
    {
        printf("\t\t%s",tmpP->p_number);
        switch(tmpP->kind)
        {
            case 1:printf("\t\t牛奶\t\t");break;
            case 2:printf("\t\t茶叶\t\t");break;
            case 3:printf("\t\t奶油\t\t");break;
            case 4:printf("\t\t咖啡豆\t\t");break;
            case 5:printf("\t\t酸奶\t\t");break;
            case 6:printf("\t\t草莓\t\t");break;
            case 7:printf("\t\t葡萄\t\t");break;
            case 8:printf("\t\t白糖\t\t");break;
        }
        printf("\t%.2lf\t",tmpP->p_money);
        printf("\t\t%d\t",tmpP->weight);
        printf("\t\t%s\n",tmpP->p_date);
        tmpP=tmpP->p_next;
    }

    printf("\n------------------------------------------------------------------------------------");
    printf("\n查询结束！\n\n");


}

void jinhuo_cha_time(char date[],PUR *head)//（目标日期字符串，全局链表头）按时间查询
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("目前并无进货记录！\n");
        system("pause");
        return ;
    }
    printf("对应日期后原料进货记录如下：\n");
    printf("\t\t---订单编号---\t\t---种类---\t\t---单价---\t\t---重量---\t\t---时间---\n");

    while(tmpP!=NULL)
    {
        if(strcmp(date,tmpP->p_date)<0||strcmp(date,tmpP->p_date)==0)//若时间不符合要求，则不输出
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\t牛奶\t\t");break;
                case 2:printf("\t\t茶叶\t\t");break;
                case 3:printf("\t\t奶油\t\t");break;
                case 4:printf("\t\t咖啡豆\t\t");break;
                case 5:printf("\t\t酸奶\t\t");break;
                case 6:printf("\t\t草莓\t\t");break;
                case 7:printf("\t\t葡萄\t\t");break;
                case 8:printf("\t\t白糖\t\t");break;
            }
            printf("\t%.2lf\t",tmpP->p_money);
            printf("\t\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
        }
        tmpP=tmpP->p_next;
    }

    printf("\n-------------------------------------------------------------------------------------");
    printf("\n查询结束！\n\n");
}

void jinhuo_cha_number(char number[],PUR *head)//（目标编号字符串，全局链表头）按编号查询
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("目前并无进货记录！\n");
        system("pause");
        return ;
    }
    printf("对应编号原料进货记录如下：\n");
    printf("\t\t---订单编号---\t\t---种类---\t\t---单价---\t\t---重量---\t\t---时间---\n");

    while(tmpP!=NULL)
    {
        if(strcmp(number,tmpP->p_number)==0)
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\t牛奶\t\t");break;
                case 2:printf("\t\t茶叶\t\t");break;
                case 3:printf("\t\t奶油\t\t");break;
                case 4:printf("\t\t咖啡豆\t\t");break;
                case 5:printf("\t\t酸奶\t\t");break;
                case 6:printf("\t\t草莓\t\t");break;
                case 7:printf("\t\t葡萄\t\t");break;
                case 8:printf("\t\t白糖\t\t");break;
            }
            printf("\t%.2lf\t",tmpP->p_money);
            printf("\t\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
            printf("\n---------------------------------------------------------------------------------");
            printf("\n 查询结束！\n\n");
            return ;
        }
        tmpP=tmpP->p_next;
    }

    printf("\n-----------------------------------------------------------------------");
    printf("\n 查询失败！未找到对应编号！\n\n");
}

void jinhuo_cha_kind(int kind,PUR* head)//（目标种类，全局链表头）按种类查询
{
    PUR* tmpP=head->p_next;
    if(tmpP==NULL)
    {
        printf("目前并无进货记录！\n");
        system("pause");
        return ;
    }
    printf("对应原料种类进货记录如下：\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t---订单编号---\t\t---种类---\t\t---单价---\t\t---重量---\t\t---时间---\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    while(tmpP!=NULL)
    {
        if(kind==tmpP->kind)
        {
            printf("\t\t%s",tmpP->p_number);
            switch(tmpP->kind)
            {
                case 1:printf("\t\t牛奶\t\t");break;
                case 2:printf("\t\t茶叶\t\t");break;
                case 3:printf("\t\t奶油\t\t");break;
                case 4:printf("\t\t咖啡豆\t\t");break;
                case 5:printf("\t\t酸奶\t\t");break;
                case 6:printf("\t\t草莓\t\t");break;
                case 7:printf("\t\t葡萄\t\t");break;
                case 8:printf("\t\t白糖\t\t");break;
            }
            printf("\t%.2lf",tmpP->p_money);
            printf("\t%d\t",tmpP->weight);
            printf("\t\t%s\n",tmpP->p_date);
        }
        tmpP=tmpP->p_next;
    }

    printf("\n---------------------------------------------------------------------------");
    printf("\n查询结束！\n\n");
}

void jinhuo_txt(PUR* head)//（原料链表头指针）进货记录文件导出函数
{
    PUR* p_head=head->p_next;
    FILE *fjp=NULL;

    if((fjp=fopen("进货订单信息导出.txt","w"))==NULL)
    {
        printf("文件打开失败！\n");
        return ;
    }



    while(p_head!=NULL)
    {
        fprintf(fjp,"%s",p_head->p_number);
        fprintf(fjp,"\t\t%s",p_head->p_date);
        switch(p_head->kind)
        {
            case 1:fprintf(fjp,"\t\t牛奶\t\t");break;
            case 2:fprintf(fjp,"\t\t茶叶\t\t");break;
            case 3:fprintf(fjp,"\t\t奶油\t\t");break;
            case 4:fprintf(fjp,"\t\t咖啡豆\t\t");break;
            case 5:fprintf(fjp,"\t\t酸奶\t\t");break;
            case 6:fprintf(fjp,"\t\t草莓\t\t");break;
            case 7:fprintf(fjp,"\t\t葡萄\t\t");break;
            case 8:fprintf(fjp,"\t\t白糖\t\t");break;
        }
        fprintf(fjp,"\t\t%lf",p_head->p_money);
        fprintf(fjp,"\t\t%d\n",p_head->weight);

        p_head=p_head->p_next;
    }

    fclose(fjp);
    printf("文件导出完成！\n\n");

}

void jinhuo_read(PUR *head)//(全局链表头）从文件中读取进货订单信息
{
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t---订单编号---\t\t---时间---\t\t---种类---\t\t---单价---\t\t---重量---\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    char jr_date[20];//时间
    char jr_kind[20];       //原料种类
    double jr_money;    //原料单价
    int jr_weight;     //原料重量
    char jr_number[20];//订单编号
    PUR *q,*r_head,*tmp;
    q=r_head=head;
    while(r_head->p_next!=NULL)
    {
        r_head=r_head->p_next;
    }
    q=r_head;//q为当前尾链表

    FILE *jh;
    jh=fopen("进货订单信息导入.txt","rt");
    while(fscanf(jh,"%s\t\t%s\t\t%s\t\t\t\t%lf\t\t%d\n",jr_number,jr_date,jr_kind,&jr_money,&jr_weight)!=EOF)
    {

        printf("\t\t%s\t\t%s\t\t%s\t\t\t\t%.2lf\t\t%d\n",jr_number,jr_date,jr_kind,jr_money,jr_weight);//将文件信息输出

        //将文件信息导入链表
        tmp=(PUR*)malloc(sizeof(PUR));

        //tmp->kind=jr_kind;
        if(strcmp("牛奶",jr_kind)==0)
            tmp->kind=1;
        if(strcmp("茶叶",jr_kind)==0)
            tmp->kind=2;
        if(strcmp("奶油",jr_kind)==0)
            tmp->kind=3;
        if(strcmp("咖啡豆",jr_kind)==0)
            tmp->kind=4;
        if(strcmp("酸奶",jr_kind)==0)
            tmp->kind=5;
        if(strcmp("草莓",jr_kind)==0)
            tmp->kind=6;
        if(strcmp("葡萄",jr_kind)==0)
            tmp->kind=7;
        if(strcmp("白糖",jr_kind)==0)
            tmp->kind=8;

        kucun_gai(tmp->kind,1,jr_weight);//修改库存
        strcpy(tmp->p_date,jr_date);
        strcpy(tmp->p_number,jr_number);
        tmp->weight=jr_weight;
        tmp->p_money=jr_money;
        tmp->p_next=NULL;
        sum_money(tmp);//修改资金
        q->p_next=tmp;//链接链表
        q=q->p_next;

    }
    fclose(jh);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("文件读取完毕！\n\n");
    jinhuo_sort(p_head);
}

int kucun_gai(int s_kind,int turn,int s_weight)//(原料种类，增减<1,0>，重量）库存修改函数
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
                         printf("交易失败！！！\n");
                         printf(" 牛奶 ");
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
                         printf("交易失败！！！\n");
                         printf(" 茶叶 ");
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
                         printf("交易失败！！！\n");
                         printf(" 奶油 ");
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
                         printf("交易失败！！！\n");
                         printf(" 咖啡 ");
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
                         printf("交易失败！！！\n");
                         printf(" 酸奶 ");
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
                         printf("交易失败！！！\n");
                         printf(" 草莓 ");
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
                         printf("交易失败！！！\n");
                         printf(" 葡萄 ");
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
                         printf("交易失败！！！\n");
                         printf(" 白糖 ");
                         k_flag=0;
                    }
                }
                break;
            }
        default:
            {
                printf("请选择正确的种类！\n");
                return 0;
            }
        if(k_flag==0)
        {
            printf(" 库存不足，请及时补充！\n");
            return 0;
        }
        return 1;

    }
    return 1;

}

void kucun_cha()//当前库存查询函数
{
    printf("\n--------------------------------------------\n");
    printf(" 牛奶   当前库存为：%d g\n",milk);
    printf(" 茶叶   当前库存为：%d g\n",tea);
    printf(" 奶油   当前库存为：%d g\n",cream);
    printf(" 咖啡豆 当前库存为：%d g\n",coffee);
    printf(" 酸奶   当前库存为：%d g\n",yoghurt);
    printf(" 草莓   当前库存为：%d g\n",straw);
    printf(" 葡萄   当前库存为：%d g\n",grape);
    printf(" 白糖   当前库存为：%d g\n",sugar);
    printf("        查询结束！     \n\n");
    printf("--------------------------------------------\n");
}





//--===================================SEARCH==============================================

int time_hefa(char* extra) { //(时间存储数组)时间格式输入
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

int bianhao_hefa1(char* bb)           //判断输入的编号是否合法
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

int bianhao_hefa(char* bb)           //判断输入的编号是否合法
{
    if(bb[0]!='N'||bb[1]!='O') return 0;
    int len=strlen(bb),i=2;
    for(;i<len;i++)
    {
        if(bb[i]>'9'||bb[i]<'0') return 0;
    }
    return 1;
}


void xs_timesearch() {   //按时间查找销售记录
    //先输入日期起止范围
    char start_time[100],end_time[100];
    printf("\t\t请输入查询时间起点(格式：2000.01.01)\n");
    scanf("%s",start_time);
    while(!time_hefa(start_time))
    {
        printf("\t\t请输入合法日期\n");
        scanf("%s",start_time);
    }
    //
    printf("\t\t请输入查询时间终点(格式同上)\n");
    scanf("%s",end_time);
     while(!time_hefa(end_time)||strcmp(start_time,end_time)>0)
    {
        printf("\t\t请输入合法日期\n");
        scanf("%s",end_time);
    }


    SELL*p=head;
    printf("饮品种类\t口味\t         温度\t\t甜度\t");
    printf("规格\t数量\t时间\t\t下单编号\n\n");
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
    printf("\t\t请输入商品代号:\n");
    scanf("%s",goods_name);
    while(strlen(goods_name)>1||goods_name[0]>'4'||goods_name[0]<'0')
    {
        printf("\n\t\t请输入正确的商品代号\n");
        scanf("%s",goods_name);
    }
    //
    int key1=goods_name[0]-'0';

    SELL*p=head;
    printf("饮品种类        口味          温度          甜度           规格         数量          时间             下单编号\n\n");
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
    printf("\t\t请输入商品订单编号");
    scanf("%s",buy_name);
    while(!bianhao_hefa1(buy_name))
    {
        printf("\t\t请输入正确的订单编号\n");
        scanf("%s",buy_name);
    }
    SELL*p=head;
    printf("饮品种类        口味          温度          甜度           规格         数量          时间             下单编号\n\n");
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
        printf("\t\t查询到以下记录\n");
    }
    else
    {
        printf("此限制条件下未查询到销售记录");
        Sleep(1000);
        return ;
    }
    printf("饮品种类        口味          温度          甜度           规格         数量          时间             下单编号\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
    while(p0!=NULL)
    {
        PRINTf(p0);
        p0=p0->s_next;
    }
}
void FilePrint(SELL*head)      //文件导出
{
    FILE*fp;
    fp=fopen("ShouMaiJiLu.txt","w");
    SELL*p0=head;
    while(p0)
    {
    fprintf(fp," 饮品种类          口味              温度                甜度                    规格                数量                 时间                  下单编号\n");
    fprintf(fp,"%3d%20d%20d%30d%20d%20d%20s%20s\n",p0->drink,p0->taste,p0->temper,p0->sugar,p0->standard,p0->much,p0->s_date,p0->s_number);
    p0=p0->s_next;
    }
}

void PRINTf(SELL*p)
{
	int k;
	k=10*p->drink+p->taste;
switch(k){
	case 11:printf("果茶奶茶        牛乳味   ");break;
	case 12:printf("果茶奶茶        草莓味   "); break;
	case 13:printf("果茶奶茶        葡萄味   "); break;
    case 21:printf("冰激淋          草莓味   ");break;
	case 22:printf("冰激淋          葡萄味   ");break;
	case 23:printf("冰激淋          酸奶味   ");break;
	case 31:printf("咖啡            黑咖啡   ");break;
	case 32:printf("咖啡            抹茶味   ");break;
	case 33:printf("咖啡            卡布奇诺 ");break;
	case 41:printf("酸奶            原味     ");break;
	case 42:printf("酸奶            草莓味   ");break;
	case 43:printf("酸奶            葡萄味   ");break;
}
	switch(p->temper) {
case 1:printf("     热   "); break;
case 2:printf("     常温 ");break;
case 3:printf("     加冰 "); break;
}
	switch(p->sugar) {
case 1:printf("         全糖   ");break;
case 2:printf("         五分糖 ");break;
case 3:printf("         无糖   ");break;
}
	switch(p->standard) {
case 1:printf("        大  ");break;
case 2:printf("        中  ");break;
case 3:printf("        小  "); break;
}
printf("          %d",p->much);
printf("           %s",p->s_date);
printf("         %s\n",p->s_number);
p=p->s_next;
}

//===========================================LOGIN===========================================================
//移动函数
void gotoxy(int x,int y) {
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//输入函数
int input(char*p,int y) {
	char cinchar;
	int i;//保存输入位数
	cinchar=getch();
	for(i=0; cinchar!=13&&i<12; i++)
    {
		if(cinchar==27) {//输入esc ，则返回上一级
			system("cls");
			return -1;//返回上一级
		}//esc
		if(cinchar!=8) {//不是删除键
			p[i]=cinchar;
			if(y==1)printf("%c",cinchar);
			if(y==2)printf("*");
		}
		else if(i>0) { //删除一位
			i-=2;
			printf("\b \b");
		}
		else i-=1; //删除键但没输入任何字符

		cinchar=getch();
	}             //for
return (i<=10)?i:-2;
}

//打印图形函数
void print_picture(int login_time){
	int i;
	gotoxy(40,20);
		printf("账号：");
		gotoxy(40,25);
		printf("密码：");
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
		printf("输入ESC退出程序");
		exit(0);
		}
}

//菜单选择函数
void loopout(HANDLE hwnd,COORD coord,int count) {
	system("cls");//清屏
	while(count<=0)count+=n;//一直加到count结果为正数
	switch(count%n) {
		case 0:
			gotoxy(85,5);
			printf("--> *原料进货管理*");
			gotoxy(85,13);
			printf("*商品售卖管理*");
			gotoxy(85,21);
			printf("*原料库存管理*");
			gotoxy(85,29) ;
			printf("*会员账户管理*");
			gotoxy(85,37) ;
			printf("*资金管理*");
			gotoxy(85,45);
			printf("输入ESC退出登录");
			break;
		case 1:
			gotoxy(85,5);
			printf("*原料进货管理*");
			gotoxy(85,13);
			printf("-->*商品售卖管理*");
			gotoxy(85,21);
			printf("*原料库存管理*");
			gotoxy(85,29) ;
			printf("*会员账户管理*");
			gotoxy(85,37) ;
			printf("*资金管理*");
			gotoxy(85,45);
			printf("输入ESC退出登录");
			break;
		case 2:
			gotoxy(85,5);
			printf("*原料进货管理*");
			gotoxy(85,13);
			printf("*商品售卖管理*");
			gotoxy(85,21);
			printf("-->*原料库存管理*");
			gotoxy(85,29) ;
			printf("*会员账户管理*");
			gotoxy(85,37) ;
			printf("*资金管理*");
			gotoxy(85,45);
			printf("输入ESC退出登录");
			break;
		case 3:
			gotoxy(85,5);
			printf("*原料进货管理*");
			gotoxy(85,13);
			printf("*商品售卖管理*");
			gotoxy(85,21);
			printf("*原料库存管理*");
			gotoxy(85,29) ;
			printf("-->*会员账户管理*");
			gotoxy(85,37) ;
			printf("*资金管理*");
			gotoxy(85,45);
			printf("输入ESC退出登录");
			break;
		case 4:
			gotoxy(85,5);
			printf("*原料进货管理*");
			gotoxy(85,13);
			printf("*商品售卖管理*");
			gotoxy(85,21);
			printf("*原料库存管理*");
			gotoxy(85,29) ;
			printf("*会员账户管理*");
			gotoxy(85,37) ;
			printf("-->*资金管理*");
			gotoxy(85,45);
			printf("输入ESC退出登录");
			break;

	}
}

//查验函数
int searchchar(char*p,int n) {
	int i;
	int count_int=0,count_char=0;

	for(i=0; i<5; i++)if(!p[i])return 1;//不满足5位
	if(p[5]!='\0')return 1;//超过5位
	for(i=0; i<n; i++){
		if(p[i]<='9'&&p[i]>='0')count_int++;
		else if(p[i]>='a'&&p[i]<='z')count_char++;
		else if(p[i]>='A'&&p[i]<='Z')count_char++;
		else return 1;//出现其他字符
	}
	if(count_int&&count_char)	return 0;//数字和字符都出现过
	else return 1;//数字和字符未都出现过
}

//密保查验函数
int searchchar_mibao(char*p,int n) {
	int i;
	int count_int=0;
	for(i=0; i<6; i++)if(!p[i])return 1;//不满足6位
	if(p[6]!='\0')return 1;//超过6位
	for(i=0; i<n; i++) {
		if(p[i]<='9'&&p[i]>='0')count_int++;
		else return 1;//出现其他字符
	}
	if(count_int)	return 0;//数字和字符都出现过
	else return 1;//数字和字符未都出现过
}

//密保函数
int mibao_hanshu(char*mibao) {
	system("cls");
	gotoxy(10,9);
	printf("请输入你的手机号：");
	char A[1000];
	input(A,1);
	if(strcmp(mibao,A)==0)return 1;
	return 0;
}

//初次设置密保的函数
void mibaoinitial(char*key,FILE*fpointer) {
	//还未保存密保
	gotoxy(10,11);
	printf("初次登陆请设置您的密保,要求为6位数字:");
	gets(key);
	FILE*fpointer2=fopen("mibao.txt","w");
	fputs(key,fpointer2);//写入输入的密码
	fclose(fpointer2);
	while(searchchar_mibao(key,6)) {
		system("cls");
		gotoxy(10,9);
		if(fpointer)printf("重新初始化密码，要求为6位数字:");
		else printf("密保输入有误，要求为6位数字,请重新输入:");
		gets(key);
		fpointer2=fopen("mibao.txt","w");
		fputs(key,fpointer2);
		fclose(fpointer2);
}
}

//初次设置密码的函数
void Passwordinitial(char*key,FILE*fpointer) {
	//还未保存密码
	gotoxy(10,9);
	printf("初次登陆请设置您的密码,要求为5为数字字母混合字符串:");
	gets(key);
	FILE*fpointer2=fopen("mima.txt","w");
	fputs(key,fpointer2);//写入输入的密码
	fclose(fpointer2);
//设置密码有误
	while(searchchar(key,5)) {
		system("cls");
		gotoxy(10,9);
		if(fpointer)printf("重新初始化密码，要求为5位数字字母混合字符串:");
		else printf("密码输入有误，要求为5位数字字母混合字符串,请重新输入:");
		gets(key);
		fpointer2=fopen("mima.txt","w");
		fputs(key,fpointer2);
		fclose(fpointer2);
	}
}

//管理系统综合函数
int  manage_system() {

	COORD coord;//位置变量
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);//光标控制
//	int i,j=0;
	int t=0;//判断输错次数
	FILE*fpointer=fopen("mima.txt","r");
	char zhanghaoinitial[10]="12345";     //设定好的账号
	char key[1000];                      //初次设定的密码并保存在文件中
	char key_mibao[1000];                      //初次设定的密宝并保存在文件中
	char zhanghao[1000];               //保存输入的账号
	char mima[1000];                  //保存输入的密码
	char key2[100];
	char mibao[10];

	//初始设置密码
aa:

	printf("                                     ************************\n");
	printf("                                     欢迎使用酒吧经营管理系统\n");
	printf("                                     ************************");

	if(login_time!=0)goto cc;//如果第二次执行该函数
	fclose(fpointer);//关闭文件
	if(fpointer==0){
          Passwordinitial(key,fpointer);//打开失败表示没有初始化密码，开始创建
        mibaoinitial(key_mibao,fpointer);//打开失败表示没有初始化密宝，开始创建
	}

	system("cls");

	//登入界面
	for(t=0; t<3;) {
bb: //输入账号，密码
		print_picture(login_time);

		//输入账号
		//定位账号光标
		coord.X = 45;
		coord.Y = 20;
		SetConsoleCursorPosition(hwnd,coord);
		//调用函数输入账号
		int zhanghao_return=input(zhanghao,1);//获取输入函数返回值，有误返回-1，正确返回输入字符个数
		switch(zhanghao_return)
		{
		case -1:
			if(fpointer==0)	goto aa;// 不是第一次初始化密码，输入esc则会goto aa重新初始化密码
			else system("cls");//若是第一次初始化密码，
			gotoxy(10,10);
			printf("          您已初始化过密码，无法进行此操作");
			system("pause");
		case -2:
			system("cls");
        	gotoxy(10,10);
			printf("          输入账号长度有误，请重新输入");
			goto bb;
		default:
		zhanghao[zhanghao_return]='\0';//以字符读入，结尾加一个\0
		}


		//输入密码
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
			printf("          您已初始化过密码，无法进行此操作");
			system("pause");
        case -2:
        	system("cls");
        	gotoxy(10,10);
			printf("          输入密码长度有误，请重新输入");
			goto bb;
		default:
		mima[mima_return]='\0';
		}
		//从txt文件读取之前保存密码
		FILE*fpointer=fopen("mima.txt","r");
		fscanf(fpointer,"%s",key);//读取文本文件保存在key中
		fclose(fpointer);

		//查验
		t++;//输错次数加一
		if(strcmp(zhanghao,zhanghaoinitial)==0&&strcmp(mima,key)==0) {
			system("cls");
			gotoxy(10,10);
			printf("          输入正确");
			system("pause");
			break;
		} else {//输入有误
			if(t<3) {//错误少于3次
				system("cls");
				gotoxy(30,8);
				printf("         账号或密码输入有误，请您重新输入\n");
				gotoxy(40,10);
				system ("pause");
				system("cls");
				goto bb;
			} else {//错误超过3次
				system("cls");
				gotoxy(30,8);
				printf("         账号或密码输入有误超过3次自动退出\n\n");
				printf("         如需通过密保找回密码，请按空格键");
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
						printf("输入密保有误，2秒后自动退出");
						Sleep(2000);
						exit(0);
					}//else4密保输入有误
				} else {
					system("cls");
					printf("输入密保有误，2秒后自动退出");
					Sleep(2000);
					exit(0);
				} //else3不输入密保自动退出
			}//else2输错三次
		}//else1输入有误
	}//   for
	//菜单选择



cc://开始菜单选择
	system("cls");
	gotoxy(85,5);
	printf("*原料进货管理*");
	gotoxy(85,13);
	printf("*商品售卖管理*");
	gotoxy(85,21);
	printf("*原料库存管理*");
	gotoxy(85,29) ;
	printf("*会员账户管理*");
	gotoxy(85,37) ;
	printf("*资金管理*");
	gotoxy(85,45);
	printf("输入ESC退出登录");
//定位当前光标到
	coord.X = 85;
	coord.Y = 6;
	SetConsoleCursorPosition(hwnd,coord);

//移动
	while (1) {
		int p;
		p=getch();
		switch(p) {
			case 27:
				system("cls");
				goto bb;
			case 13: //按下回车键进入不同菜单
				while(count<=0)count+=n;
				if(count%n==0)goto dd;//原料进货管理
				if(count%n==1)goto ee;//商品售卖
				if(count%n==2)goto ff;//原料库存
				if(count%n==3)goto gg;//会员账户管理
				if(count%n==4)goto hh;//资金管理
			case 49:  //1上
				count--;
				coord.Y-=8;//光标上移
				if(coord.Y<5)coord.Y=38;//如果在最上边继续左移回到最下边
				loopout(hwnd, coord,count);
				//SetConsoleCursorPosition(hwnd,coord);//重新标记光标位置
				break;

			case 50:  //2下
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
	printf("原料进货管理");
	return 1;
ee:login_time++;
	system("cls");
	printf("商品售卖管理");
	return 2;
ff:login_time++;
	system("cls");
	printf("原料库存管理");
	return 3;
gg:login_time++;
	system("cls");
	printf("会员账户管理");
	return 4;
hh:login_time++;
	system("cls");
	printf("资金管理");
	return 5;
}



//========================================MONEY==============================================

//************************************************************************************************************* *************************************************************************************************************
//************************************************************************************************************* *************************************************************************************************************
//金钱输入函数
double  search_putin() {
	char A[15];
	int i;
	int dotcount=0;//'.'出现次数
	int before_dot=0;//‘。’之前位数
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

	if(len>15)return 0;//不许超过15位

	for(i=0; i<len; i++) {
		if(A[i]==32)continue;

		if(A[i]>'9'||A[i]<'0')
		{
			if(A[i]=='.')
			{
				dotcount++;
				before_dot=i;
			}
			else return 0; //出现其他字符
		}
	}
	//出现2个以上‘。’
	if(dotcount>1) return 0;

	if(dotcount==1) {
		for(i=0; i<before_dot; i++) {
			if(A[i]==32)continue; //空格
			change_A*=10;
			change_A=change_A+(double)(A[i]-'0');
		}

		for(i=len-1; i>before_dot; i--) {
			if(A[i]==32)continue; //空格

			change_B=change_B+(double)(A[i]-'0');
			change_B*=0.1;
		}
		return change_A+change_B;
	}//if

	else {
		for(i=0; i<len; i++) {
			if(A[i]==32)continue; //空格
			change_A*=10;
			change_A=change_A+(double)(A[i]-'0');
		}

		return change_A;
	}//else
}//函数

//编号增加函数
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

//编号比较函数
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


//日期比较函数
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
//1.总资金流转链表生成函数
void all_zijin_gai() {
	Allform*p;
	if(allhead==0) {
		p=(Allform*)malloc(sizeof(Allform));//if空链表
		allhead=p;
		allwei=p;
		p->all_next=NULL;
	} else {		                                  //链表非空
		p=(Allform*)malloc(sizeof(Allform));
		allwei->all_next=p;
		allwei=p;
		p->all_next=NULL;
	}
}

//2.总流转遍历
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
		fprintf(fpointer,"\n资金流转项目：%s\n",trans->all_name);
		printf("资金流转编号：%s\n",trans->all_name);
		fprintf(fpointer,"\n资金流转编号：%s\n",trans->all_formnumber);
		printf("资金流转编号：%s\n",trans->all_formnumber);
		fprintf(fpointer,"资金流转时间：%s\n",trans->all_time);
		printf("资金流转时间：%s\n",trans->all_time);
		fprintf(fpointer,"资金流转金额：%lf\n\n",trans->all_trans_money);
		printf("资金流转金额：%lf\n",trans->all_trans_money);
		trans=trans->all_next;
	}
	fclose(fpointer);
	system("pause");
	return 1;
}

//3.总资金链表删除
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
//1.订单流转链表生成函数
void order_zijin_gai() {
	Orderform*p;
	if(orderhead==0) {
		p=(Orderform*)malloc(sizeof(Orderform));//if空链表
		orderhead=p;
		orderwei=p;
		p->order_next=NULL;
	} else {		                                  //链表非空
		p=(Orderform*)malloc(sizeof(Orderform));
		orderwei->order_next=p;
		orderwei=p;
		p->order_next=NULL;
	}
}

// 2.订单资金流转记录
double order_sum_money (SHOP*trans) {//传给我一个SHOP型的链表表头
	int choice;//加权
	double money=0,moneysum=0;//流转每笔金额，订单总金额

	order_zijin_gai();//每次调用该函数生成一个节点

	if(trans==NULL) { //空链表
		return 0;
	}

	//订单求和
	while(trans->s_next) {
		choice=trans->drink*10+trans->standard*1;//种类，规格
		switch(choice) {
//果茶奶茶
			case 11:
				money=15;
				break;
			case 12:
				money=13;
				break;
			case 13:
				money=8;
				break;
//冰淇凌
			case 21:
				money=10;
				break;
			case 22:
				money=8;
				break;
			case 23:
				money=5;
				break;
//咖啡
			case 31:
				money=16;
				break;
			case 32:
				money=14;
				break;
			case 33:
				money=10;
				break;
//酸奶
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

		//以下为对一种饮品求和操作
		money*=trans->much;//杯数
		trans->shop_money=money;//保存在shop结构体中
		trans=trans->s_next;//下一节点
		moneysum+=money; //求和该顾客总花费
	}//while

	choice=trans->drink*10+trans->standard*1;//种类，规格
	switch(choice) {
//果茶奶茶
		case 11:
			money=15;
			break;
		case 12:
			money=13;
			break;
		case 13:
			money=8;
			break;
//冰淇凌
		case 21:
			money=10;
			break;
		case 22:
			money=8;
			break;
		case 23:
			money=5;
			break;
//咖啡
		case 31:
			money=16;
			break;
		case 32:
			money=14;
			break;
		case 33:
			money=10;
			break;
//酸奶
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

	//以下为对一种饮品求和操作
	money*=trans->much;//杯数
	trans->shop_money=money;//保存在shop结构体中
	moneysum+=money; //求和该顾客总花费

	//以下为对该顾客买的所有有饮品求和
	zijin+=moneysum;   //总资金流转

	orderwei->order_trans_money=moneysum;//保存订单记录
	strcpy(orderwei->order_time,trans->s_date);//订单时间

	//以下保存到all中
	all_zijin_gai();
	allwei->all_trans_money=moneysum;
	strcpy(allwei->all_name,"order");
	strcpy(allwei->all_time,trans->s_date);
	int confirm=bianhao_plus(all_number);
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("编号过多");
	}

	//bianhao
	confirm=bianhao_plus(order_number);
	if(confirm)strcpy(allwei->all_formnumber,order_number);
	else {
		system("cls");
		printf("编号过多");
	}
 	return moneysum;
}

//3.订单链表按时间遍历
void order_time_search() {
	char A[30],B[30];
aa:
	printf("请输入想要查询时间区间:\n\n");
	printf("请输入查询时间起点（格式为2021.01.05）:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",A);
	}
	printf("请输入查询时间终点（格式为2021.01.05）:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",B);
	}
	if(riqi_cmp(A,B)>0) {
		system("cls");
		printf("请正确输入时间区间，注意起点小于终点");
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

//4.订单链表按编号遍历
void order_bianhao_search() {
	char A[30],B[30];
aa:
	printf("请输入想要查询编号区间:\n\n");
	printf("请输入查询编号起点（格式为NO123456...）:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",A);
	}
	printf("请输入查询编号终点（格式为NO123456...）:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("请正确输入编号区间，注意起点小于终点");
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

//5.每一笔订单导出
void order_zijin_txt() {
	FILE*fpointer=fopen("order_zijin.txt","w");
	//Orderform*p;
	int i;
	char a;
aa:
	printf("请选择查找方式\n");
	printf("输入0返回上一步\n");
	printf("输入 1 进入时间检索\n");
	printf("输入 2 进入编号检索\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			order_time_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键继续");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			order_bianhao_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键继续");
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
		fprintf(fpointer,"订单流转编号：%s\n",orderp->order_formnumber);
		printf("订单流转编号：%s\n",orderp->order_formnumber);
		fprintf(fpointer,"订单流转时间：%s\n",orderp->order_time);
		printf("订单流转时间：%s\n",orderp->order_time);
		fprintf(fpointer,"订单流转金额：%lf\n\n",orderp->order_trans_money);
		printf("订单流转金额：%lf\n",orderp->order_trans_money);
		orderp=orderp->order_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.订单链表删除
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
//1.原料流转链表生成函数
void material_zijin_gai() {
	Materialform*p;
	if(materialhead==0) {
		p=(Materialform*)malloc(sizeof(Materialform));//if空链表
		materialhead=p;
		materialwei=p;
		p->material_next=NULL;
	} else {		                                  //链表非空
		p=(Materialform*)malloc(sizeof(Materialform));
		materialwei->material_next=p;
		materialwei=p;
		p->material_next=NULL;
	}
}

//2.原料资金流转记录
float sum_money(PUR*trans) {//传给我一个原料结构体类型链表表头
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

	if(zijin<0)return 0;//买不了返回0

	materialwei->material_trans_money=moneysum;//保存订单记录

	//以下保存到all中
	all_zijin_gai();
	allwei->all_trans_money=-moneysum;//钱
	strcpy(allwei->all_name,"material");//name
	strcpy(allwei->all_time,trans->p_date);//时间
	int confirm=bianhao_plus(all_number);//编号
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("编号过多");
	}

	//bianhao
	confirm=bianhao_plus(material_number);
	if(confirm)strcpy(materialwei->material_formnumber,material_number);
	else {
		system("cls");
		printf("编号过多");
	}

	strcpy(materialwei->material_time,trans->p_date);//时间
	return moneysum;
}

//3.原料按时间遍历
void material_time_search() {
	char A[30],B[30];
aa:
	printf("请输入想要查询时间区间:\n\n");

	printf("请输入查询时间起点（格式为2021.01.05）:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",A);
	}
	printf("请输入查询时间终点（格式为2021.01.05）:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",B);
	}
	if(strcmp(A,B)>0) {
		system("cls");
		printf("请正确输入时间区间，注意起点小于终点");
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

//4.原料按编号遍历
void material_bianhao_search() {
	char A[30],B[30];
aa:
	printf("请输入想要查询编号区间:\n\n");

	printf("请输入查询编号起点（格式为NO123456...）:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",A);
	}
	printf("请输入查询编号终点（格式为NO123456...）:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("请正确输入编号区间，注意起点小于终点");
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

//5.每一笔原料导出
void material_zijin_txt() {
	FILE*fpointer=fopen("material_zijin.txt","w");
	//Materialform*p;
	int i;
	char a;
aa:
	printf("请选择查找方式\n");
	printf("输入0返回上一步\n");
	printf("输入 1 进入时间检索\n");
	printf("输入 2 进入编号检索\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			material_time_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键退出");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			material_bianhao_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键退出");
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
		fprintf(fpointer,"\n原料流转编号：%s\n",materialp->material_formnumber);
		printf("原料流转编号：%s\n",materialp->material_formnumber);
		fprintf(fpointer,"原料流转时间：%s\n",materialp->material_time);
		printf("原料流转时间：%s\n",materialp->material_time);
		fprintf(fpointer,"原料流转金额：%lf\n\n",materialp->material_trans_money);
		printf("原料流转金额：%lf\n",materialp->material_trans_money);
		materialp=materialp->material_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.原料链表删除
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

//1.投资流转链表生成函数
void other_zijin_gai() {
	Otherform*p;
	if(otherhead==0) {
		p=(Otherform*)malloc(sizeof(Otherform));//if空链表
		otherhead=p;
		otherwei=p;
		p->other_next=NULL;
	} else {		                                  //链表非空
		p=(Otherform*)malloc(sizeof(Otherform));
		otherwei->other_next=p;
		otherwei=p;
		p->other_next=NULL;
	}
}

//2.投资函数
void touzi(double money) {
	char A[20];
	//int check;
	other_zijin_gai();
	zijin+=money;

	//金额
	otherwei->other_trans_money=money;

	//time
	printf("请输入时间（格式为2021.xx.xx）:");
	time_input(A);
	strcpy(otherwei->other_time,A);

	//以下保存到all中
	all_zijin_gai();
	allwei->all_trans_money=money;//钱
	strcpy(allwei->all_name,"touzi");//name
	strcpy(allwei->all_time,otherwei->other_time);//时间
	int confirm=bianhao_plus(all_number);//编号
	if(confirm)strcpy(allwei->all_formnumber,all_number);
	else {
		system("cls");
		printf("编号过多");
	}


	//bianhao
	confirm=bianhao_plus(other_number);
	if(confirm)strcpy(otherwei->other_formnumber,other_number);
	else {
		system("cls");
		printf("编号过多");
	}
	printf("编号为：%s\n",otherwei->other_formnumber);
	system("pause");
}

//3.投资按时间遍历
void other_time_search() {
   // other_sort();
	char A[30],B[30];
aa:
	printf("请输入想要查询时间区间:\n\n");
	printf("请输入查询时间起点（格式为2021.01.05）:\n");
	scanf("%s",A);
	while(!time_hefa(A)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",A);
	}
	printf("请输入查询时间终点（格式为2021.01.05）:\n");
	scanf("%s",B);
	while(!time_hefa(B)) {
		printf("输入有误请重新输入（格式为2021.01.05）:\n");
		scanf("%s",B);
	}
	if(riqi_cmp(A,B)>0) {
		system("cls");
		printf("请正确输入时间区间，注意起点小于终点");
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

//4.投资按编号遍历
void other_bianhao_search() {
	char A[30],B[30];
aa:
	printf("请输入想要查询编号区间:\n\n");
	printf("请输入查询编号起点（格式为NO123456...）:\n");
	scanf("%s",A);
	while(!bianhao_hefa(A)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",A);
	}
	printf("请输入查询编号终点（格式为NO123456...）:\n");
	scanf("%s",B);
	while(!bianhao_hefa(B)) {
		printf("输入有误请重新输入（格式为NO123456...）:\n");
		scanf("%s",B);
	}
	if(bianhao_cmp(A,B)>0) {
		system("cls");
		printf("请正确输入编号区间，注意起点小于终点");
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



//5.每一笔投资导出
void other_zijin_txt() {
	FILE*fpointer=fopen("other_zijin.txt","w");
	//Otherform*p;
	int i;
	char a;
aa:
	printf("请选择查找方式\n");
	printf("输入0返回上一步\n");
	printf("输入 1 进入时间检索\n");
	printf("输入 2 进入编号检索\n");
	int ch;
	scanf("%d",&ch);
	switch(ch) {
		case 1:
			other_time_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键退出");
			a=getch();
			if(a=='1') {
				system("cls");
				goto aa;
			}
			break;
		case 2:
			other_bianhao_search();
			system("cls");
			printf("如需更换检索方式请输入1，否则按任意键退出\n");
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
		fprintf(fpointer,"\n投资流转编号：%s\n",otherp->other_formnumber);
		printf("投资流转编号：%s\n",otherp->other_formnumber);
		fprintf(fpointer,"投资流转时间：%s\n",otherp->other_time);
		printf("投资流转时间：%s\n",otherp->other_time);
		fprintf(fpointer,"投资流转金额：%lf\n\n",otherp->other_trans_money);
		printf("投资流转金额：%lf\n",otherp->other_trans_money);
		otherp=otherp->other_next;
	}
	fclose(fpointer);
	system("pause");
}

//6.投资链表删除
void delete_other() {
	Otherform*p=otherhead,*q;
	while(p) {
		q=p;
		p=p->other_next;
		free(q);
	}
}

//************************************************************************************************************* *************************************************************************************************************
//                                                                                                          总资金
//************************************************************************************************************* *************************************************************************************************************
// 资金查询
void zijin_cha() {
	printf("当前总资金为：") ;
	printf("%lf",zijin);
}

//总资金数据文件导出
void zijin_txt() {
	FILE*fpointer=fopen("zijin.txt","w");

	fprintf(fpointer,"当前总资金为：%lf",zijin);
	fclose(fpointer);
}

//资金管理选择菜单
int money_manage_choose() {
	char money_get;
	system("cls");
	gotoxy(85,5);
	printf("1.当前总资金查询");
	gotoxy(85,10);
	printf("2.订单资金流转查询");
	gotoxy(85,15) ;
	printf("3.原料进货资金流转查询");
	gotoxy(85,20) ;
	printf("4.投资资金流转查询");
	gotoxy(85,25) ;
	printf("5.投资管理");
	gotoxy(85,30) ;
	printf("6.总资金流转");
	gotoxy(85,40);
	printf("输入0返回菜单选项");
	gotoxy(85,35);
	printf("输入对应数字进入选项");

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
				printf("1.当前总资金查询");
				gotoxy(85,10);
				printf("2.订单资金流转查询");
				gotoxy(85,15) ;
				printf("3.原料进货资金流转查询");
				gotoxy(85,20) ;
				printf("4.投资资金流转查询");
				gotoxy(85,25) ;
				printf("5.投资管理");
				gotoxy(85,30) ;
				printf("6.总资金流转");
				gotoxy(85,40);
				printf("输入0返回菜单选项");
				gotoxy(85,35);
				printf("输入有误，请重新输入:");
		}//switch
		money_get=getche();

	} //while
}



int time_input_money(char* timeplus) { //(时间存储数组)时间格式输入
	int judge;
	int i,k;
	char extra[20];
	while(1) {
		scanf("%s",extra);
		if(strlen(extra)!=10||extra[4]!='.'||extra[7]!='.'||extra[0]=='.'||extra[1]=='.'||extra[2]=='.'||extra[3]=='.'||extra[5]=='.'||extra[6]=='.'||extra[8]=='.'||extra[9]=='.') {
			printf("您的输入不符合格式要求，请重新输入（xxxx.xx.xx）\n");
			judge=0;
		} else {
			for(i=0; i<10; i++) {
				if(i!=4&&i!=7) {
					if((extra[i]<'0'||extra[i]>'9')) {
						printf("您的输入不符合实际情况，请重新输入\n");
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
				printf("您的输入不符合实际情况，请重新输入\n");
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
    printf("\n                   本次购买订单如下\n");
	while(p!=NULL){
		int k;
		k=10*p->drink+p->taste;
	switch(k){
		case 11:printf("        果茶奶茶牛乳味 ");break;
		case 12:printf("        果茶奶茶草莓味 "); break;
		case 13:printf("        果茶奶茶葡萄味 "); break;
        case 21:printf("        冰激淋草莓味 ");break;
		case 22:printf("        冰激淋葡萄味 ");break;
		case 23:printf("        冰激淋酸奶味 ");break;
		case 31:printf("        咖啡黑咖啡 ");break;
		case 32:printf("        咖啡抹茶味 ");break;
		case 33:printf("        咖啡卡布奇诺 ");break;
		case 41:printf("        酸奶原味 ");break;
		case 42:printf("        酸奶草莓味 ");break;
		case 43:printf("        酸奶葡萄味 ");break;
	}
		switch(p->temper) {
	case 1:printf("热 "); break;
	case 2:printf("常温 ");break;
	case 3:printf("加冰 "); break;
	}
		switch(p->sugar) {
	case 1:printf("全糖 ");break;
	case 2:printf("五分糖 ");break;
	case 3:printf("无糖 ");break;
	}
		switch(p->standard) {
	case 1:printf("大  ");break;
	case 2:printf("中  ");break;
	case 3:printf("小  "); break;
	}printf("%s    ",p->s_date);
    printf("数量：%d\n",p->much);
	p=p->s_next;

	}
	double l=order_sum_money(o);
    printf("       总金额：%lf\n",l);
    isvip(l);
}

void buy(SHOP*q){//传入此次购买购物车链表的头节点并复制;
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
		strcpy(p->s_date,q->s_date);//复制信息;
	    int k=sum,buy_count=0;//根据订单总数生成订单编号；
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
int xiaoshou_jiancha(SHOP*p,int key){//传入购物车链表头节点，检查原料是否充足 ;
	switch(p->drink){
		case 1://果茶奶茶
			switch(p->standard){
				case 1://大杯
					switch(p->taste){
					case 1://牛乳味
					if(key==1){
	                tea+=15;milk+=300;}
				   else{
					if(tea<15){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(milk<300){
					printf(" 交易失败,牛奶不足\n");
					return 0;
				   }else{
						if(!key)
						milk-=300;
					}
				}
					break;
					case 2://草莓味
					if(key==1){
						tea+=15;straw+=20;
					}else{
					if(tea<15){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(straw<20){
					printf("交易失败,草莓不足\n");
					return 0;
				    }else{
						if(!key)
						straw-=20;
					}
				}
					break;
				    case 3://葡萄味
				    if(key==1){
				    	tea+=15;grape+=20;
					}else{
					if(tea<15){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=15;
					}
					if(grape<20){
					printf("交易失败,葡萄不足\n");
					return 0;
					}else{
						if(!key)
						grape-=20;
					}
				}
					break;
				}
				break;
				case 2://中杯
				 switch(p->taste){
					case 1://牛乳味
					if(key==1){
						tea+=10;milk+=300;
					}else{
					if(tea<10){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(milk<300){
					printf("交易失败,牛奶不足\n");
					return 0;
					}else{
						if(!key)
						milk-=300;
					}
				}
					break;
					case 2://草莓味
					if(key==1){
						tea+=10;straw+=20;
					}else{
					if(tea<10){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(straw<20){
					printf("交易失败,草莓不足\n");
					return 0;
				  }else{
						if(!key)
						straw-=20;
					}
			}
					break;
				    case 3://葡萄味
				    if(key==1){
				    	tea+=10;grape+=20;
					}else{
					if(tea<10){
					printf("交易失败,茶叶不足\n");
				return 0;
					}else{
						if(!key)
						tea-=10;
					}
					if(grape<20){
					printf("交易失败,葡萄不足\n");
					return 0;
				}else{
						if(!key)
						grape-=20;
					}break;
			}
			}break;
				case 3://小杯
				 switch(p->taste){
					case 1://牛乳味
					if(key==1){
				    tea+=5;milk+=300;}else{
					if(tea<5){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
						if(!key)
						tea-=5;
					}
					if(milk<300){
					printf("交易失败,牛奶不足\n");
				  return 0;
				}else{
						if(!key)
					milk-=300;
					}
				}
					break;
					case 2://草莓味
					if(key==1){
						tea+=5;straw+=20;
					}else{
					if(tea<5){
					printf("交易失败,茶叶不足\n");
					return 0;
					}else{
					if(!key)
					tea-=5;
					}
					if(straw<20){
					printf("交易失败,草莓不足\n");
					return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
				    case 3://葡萄味
				    if(key==1){
				    	tea+=5;grape+=20;
					}else{
					if(tea<5){
					printf("交易失败,茶叶不足\n");
				    return 0;
					}else{
					if(!key)
					tea-=5;
					}
					if(grape<20){
					printf("交易失败，葡萄不足\n");
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
		case 2://冰激凌
				switch(p->standard){
				case 1://大杯
					switch(p->taste){
					case 1://草莓味
					if(key==1){
						cream+=30;milk+=300;straw+=20;
					}else{
					if(cream<30){
					printf("交易失败，奶油不足\n");
			        return 0;
				     }else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("交易失败，牛奶不足\n");
					return 0;
						}else{
					if(!key)
				      milk-=300;
					}

					if(straw<20){
					printf("交易失败，酸奶不足\n");
					return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://葡萄味
					if(key==1){
						cream+=30;milk+=300;grape+=20;
					}else{

					if(cream<30){
					printf("交易失败，奶油不足\n");
					return 0;
					}else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("交易失败，牛奶不足\n");
					return 0;
					}else{
					if(!key)
					milk-=300;
					}
					if(grape<20){
					printf("交易失败，草莓不足\n");
							return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://酸奶味
				    if(key==1){
						cream+=30;milk+=300;yoghurt+=50;
					}else{
						if(cream<30){
					printf("交易失败，奶油不足\n");
					return 0;
			   }else{
					if(!key)
					cream-=30;
					}
					if(milk<300) {
						printf("交易失败，牛奶不足\n");
						return 0;
					}else{
					if(!key)
					milk-=300;
					}
					if(yoghurt<50){
					printf("交易失败，葡萄不足\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
			}
					break;
				}break;
				case 2://中杯
				 switch(p->taste){
					case 1://草莓味
					    if(key){
						cream+=20;milk+=200;straw+=20;
					}else{
					if(cream<20){
					printf("交易失败，奶油不足\n");
					return 0;
					}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("交易失败，牛奶不足\n");
					return 0;
					}else{
					if(!key)
					milk-=200;
					}
					if(straw<20){
					printf("交易失败，酸奶不足\n");
						return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://葡萄味
					if(key==1){
						cream+=20;milk+=200;grape+=20;
					}else{
					if(cream<20){
					printf("交易失败，奶油不足\n");
					return 0;
					}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("交易失败，牛奶不足\n");
						return 0;
					}else{
					if(!key)
					milk-=200;
					}
					if(grape<20){
					printf("交易失败，草莓不足\n");
						return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://酸奶味
				    if(key==1){
						cream+=20;milk+=200;yoghurt+=50;
					}else{
						if(cream<20){
					printf("交易失败，奶油不足\n");
					return 0;
				}else{
					if(!key)
					cream-=20;
					}
					if(milk<200) {
						printf("交易失败，牛奶不足\n");
					return 0;
						}else{
					if(!key)
					milk-=200;
					}
					if(yoghurt<50){
					printf("交易失败，葡萄不足\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
				}
					break;
				}break;
				case 3://小杯
				switch(p->taste){
					case 1://草莓味
					 if(key==1){
						cream+=10;milk+=100;straw+=20;
					}else{
					if(cream<10){
					printf("交易失败，奶油不足\n");
					return 0;
				}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("交易失败，牛奶不足\n");
						return 0;
					}else{
					if(!key)
					milk-=100;
					}
					if(straw<20){
					printf("交易失败，酸奶不足\n");
						return 0;
					}else{
					if(!key)
					straw-=20;
					}
				}
					break;
					case 2://葡萄味
					if(key==1){
						cream+=10;milk+=100;grape+=20;
					}else{
					if(cream<10){
					printf("交易失败，奶油不足\n");
					return 0;
					}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("交易失败，牛奶不足\n");
					   return 0;
					 }else{
					if(!key)
					milk-=100;
					}
					if(grape<20){
					printf("交易失败，草莓不足\n");
					return 0;
					}else{
					if(!key)
					grape-=20;
					}
				}
					break;
				    case 3://酸奶味
				    if(key==1){
						cream+=10;milk+=100;yoghurt+=50;
					}else{
					if(cream<10){
					printf("交易失败，奶油不足\n");
					return 0;
					}else{
					if(!key)
					cream-=10;
					}
					if(milk<100) {
						printf("交易失败，牛奶不足\n");
						return 0;
						}else{
					if(!key)
				milk-=100;
					}
					if(yoghurt<50){
					printf("交易失败，葡萄不足\n");
						return 0;
					}else{
					if(!key)
					yoghurt-=50;
					}
				}
					break;
            	}break;
			}break;
		case 3://咖啡
			 switch(p->standard){
			 	case 1://大杯
				 switch(p->taste){
				 	case 1://黑咖啡
				 	if(key==1){
						coffee+=20;
					}else{
					 if(coffee<20){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;
				}else{
					if(!key)
					coffee-=20;
					}
				}
					 break;
					 case 2://抹茶味
					 if(key==1){
						coffee+=20;tea+=5;
					}else{
					 if(coffee<20){
					 printf("交易失败，咖啡豆不足\n");
					return 0; }else{
					if(!key)
					coffee-=20;
					}
					 if(tea<5){
					 	printf("交易失败,茶叶不足\n");
					 	return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://卡布奇诺
					 if(key==1){
						coffee+=20;milk+=50;
					}else{
					 if(coffee<20){
					 printf("交易失败，咖啡豆不足\n");
					return 0; }else{
					if(!key)
					coffee-=20;
					}
					 if(milk<50){
					 	printf("交易失败，牛奶不足\n");
					 return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					 break;
				 }break;
				 case 2://中杯
				  switch(p->taste){
				 	case 1://黑咖啡
				 	if(key==1){
						coffee+=15;
					}else{
					 if(coffee<15){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=15;
					}
				}
					 break;
					 case 2://抹茶味
					 if(key==1){
						coffee+=15;tea+=5;
					}else{
					 if(coffee<15){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=15;
					}
					 if(tea<5){
					 	printf("交易失败,茶叶不足\n");
					 return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://卡布奇诺
					 if(key==1){
						coffee+=15;milk+=50;
					}else{
					  if(coffee<15){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;
					}else{
					if(!key)
					coffee-=15;
					}
					 if(milk<50){
					 	printf("交易失败，牛奶不足\n");
					 	return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					 break;
				 }break;
				case 3://小杯
				 switch(p->taste){
				 	case 1://黑咖啡
				 	if(key==1){
						coffee+=10;
					}else{
					 if(coffee<10){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;
					 }else{
					if(!key)
					coffee-=10;
					}
				}
					 break;
					 case 2://抹茶味
					 if(key==1){
						coffee+=10;tea+=5;
					}else{
					 if(coffee<10){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;}else{
					if(!key)
					coffee-=10;
					}
					 if(tea<5){
					 	printf("交易失败,茶叶不足\n");
					 	return 0;
					 }else{
					if(!key)
					tea-=5;
					}
				}
					 break;
					 case 3://卡布奇诺
					 if(key==1){
						coffee+=10;milk+=50;
					}else{
					 if(coffee<10){
					 printf("交易失败，咖啡豆不足\n");
					 return 0;}else{
					if(!key)
					coffee-=10;
					}
					 if(milk<50){
					 	printf("交易失败，牛奶不足\n");
					 	return 0;
					 }else{
					if(!key)
					milk-=50;
					}
				}
					  break;
				 }break;
			 }break;
		case 4://酸奶
			 switch(p->standard){
			 	case 1://大杯
				 switch(p->taste) {
				 	case 1://原味
				 	if(key==1){
						yoghurt+=350;
					}else{
				if(yoghurt<350){
					 printf("交易失败,酸奶不足\n");
					 return 0;}else{
					if(!key)
					yoghurt-=350;
					}
					}
					 break;
					 case 2://草莓味
					 	if(key==1){
						yoghurt+=350;straw+=20;
					}else{
					 if(yoghurt<350){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=350;
					}
					 if(straw<20){
					 		printf("交易失败,草莓不足\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://葡萄味
					 	if(key==1){
						yoghurt+=350;grape+=20;
					}else{
					 if(yoghurt<350){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=350;
					}
				 if(grape<20){
					 		printf("交易失败,葡萄不足\n");
					 		return 0;
					 }else{
					if(!key)
					grape-=20;
					}
				}
					 break;
				}break;
				  case 2://中杯
				  switch(p->taste) {
				 	case 1://原味
				 		if(key==1){
						yoghurt+=250;
					}else{
					 if(yoghurt<250){
					 printf("交易失败,酸奶不足\n");
					 return 0;
			}else{
					if(!key)
					yoghurt-=250;
					}
				}
					 break;
					 case 2://草莓味
					 	if(key==1){
						yoghurt+=250;straw+=20;
					}else{
					 if(yoghurt<250){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=250;
					}
					 if(straw<20){
					 		printf("交易失败,草莓不足\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://葡萄味
					 	if(key==1){
						yoghurt+=250;grape+=20;
					}else{
					 if(yoghurt<250){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=250;
					}
				 if(grape<20){
					 		printf("交易失败,葡萄不足\n");
					 		return 0;
					 }else{
					if(!key)
					grape-=20;
					}
				}
					  break;
				 }break;
				case 3://小杯
				 switch(p->taste) {
				 	case 1://原味
				 		if(key==1){
						yoghurt+=150;
					}else{
					 if(yoghurt<150){
					 printf("交易失败,酸奶不足\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=150;
					}
				}
					 break;
					 case 2://草莓味
					 	if(key==1){
						yoghurt+=150;straw+=20;
					}else{
					  if(yoghurt<150){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
					 }else{
					if(!key)
					yoghurt-=150;
					}
					 if(straw<20){
					 		printf("交易失败,草莓不足\n");
					 		return 0;
					 }else{
					if(!key)
					straw-=20;
					}
				}
					 break;
					 case 3://葡萄味
					 	if(key==1){
						yoghurt+=150;grape+=20;
					}else{
					  if(yoghurt<150){
					 	printf("交易失败,酸奶不足\n");
					 return 0;
				 }else{
					if(!key)
					yoghurt-=150;
					}
				 if(grape<20){
					 		printf("交易失败,葡萄不足\n");
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
    case 1://多糖
        if(key){
            sugar+=30;
        }else{
        if(sugar<30){
    printf("交易失败，白糖不足");
    return 0;
        }else{
        if(!key){
            sugar-=30;
        }
        }
		}break;
        case 2://5分糖
            if(key){
            sugar+=15;
        }else{
        if(sugar<15){
    printf("交易失败，白糖不足");
    return 0;
        }else{
        if(!key){
            sugar-=15;
        }
        }
		}break;
        case 3://无糖
        break;
		}
		return 1;
}
SHOP *Recommend(SHOP*p){
	int judge;
  	p->standard=2;
  	printf("中规格：");
  	if(xiaoshou_jiancha(p,-1)==1){
  		printf("该饮品可以制作1杯中规格您是否购买 ：是：1；否：0\n");
  		scanf("%d",&judge);
  		if(judge){
  		p->standard=2;
  		p->much=1;
  		xiaoshou_jiancha(p,0);
  		return p;
  		}else{
  		printf("您已放弃购买\n");
  		return NULL;
		  }
	  }else{
  p->standard=3;
  printf("小规格:");
  if(xiaoshou_jiancha(p,-1)==1){
  		printf("该饮品可以制作1杯小规格您是否购买 ：是：1；否：0\n");
  		scanf("%d",&judge);
  		if(judge){
  		p->standard=3;
  		p->much=1;
  		xiaoshou_jiancha(p,0);
  		return p;
	  }else{
	  		printf("您已放弃购买\n");
	  		return NULL;
	  }
  }else{
  	printf("该产品已无法制作\n");
  	return NULL;
  }
}
}

int shop_car(){
system("cls");
int choose;
printf("选择购买方式1:手动购买0：文件导入");
scanf("%d",&choose);
if(choose){
PRINTxinxi();
SHOP*head=NULL,*tail=NULL;
int n;//用户所要购买的饮品种类的数量；
char temp[100]={'@'};
char extra[100];//检测用户输入是否正确用的临时数组;
printf("\n\n\n        请输入您要购买多少种饮品,0<n<4||\n");
while(1)
		{
		scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'4'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
        }
    n=extra[0]-'0';
for(int x=1;x<=n;x++){
int judge,i;
SHOP*p=(SHOP*)malloc(sizeof(SHOP));
p->s_next=NULL;
printf("\t请输入饮品种类:\n");
		while(1)
		{
		scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'4'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
        }
		p->drink=extra[0]-'0';
printf("\t请输入饮品规格\n");
	    while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
	}
		p->standard=extra[0]-'0';
printf("\t请输入饮品口味\n");
		 while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
	}
	   p->taste=extra[0]-'0';
printf("\t请输入饮品温度\n");
		while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
	}
		p->temper=extra[0]-'0';
printf("\t请输入饮品甜度\n");
		while(1){
        scanf("%s",extra);
        if(strlen(extra)!=1){
        		printf("您的输入不符合实际情况，请重新输入\n");
		}else{
             if(extra[0]<'1'||extra[0]>'3'){
             		printf("您的输入不符合实际情况，请重新输入\n");
			 }else{
			     printf("输入成功\n");
			 	break;
			 }
		}
	}
	p->sugar=extra[0]-'0';
printf("\t请输入饮品数量\n");
		 p->much=0;
		 while(1){
        scanf("%s",extra);
        for(i=0;i<strlen(extra);i++){
        	if((extra[i]<'0')||(extra[i]>'9')||(extra[0]=='0')){
        		printf("您的输入不符合实际情况，请重新输入\n");
        		judge=0;
        		break;
			}else{
			   	judge=1;
			}
		}
		if(judge){
            printf("输入成功\n");
			break;
		}
	}
	for(i=0;i<strlen(extra);i++){
		p->much+=(extra[i]-'0')*(int)pow(10,strlen(extra)-i-1);
	}
	printf("请您输入时间\n");
	time_input(p->s_date);
     i=1;judge=1;
		while(i<=p->much){//根据饮品数量检查原料是否足够;
        temp[i]=xiaoshou_jiancha(p,-1)+'0';
        if(temp[1]=='0'&&p->standard==3){
        	printf("\t该饮品已经无法制作,抱歉\n");
        	free(p);
            judge=0;
        	break;
		}
		if(temp[1]=='0'&&p->standard!=3){
			printf("将为您推荐其他规格的饮品\n");
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
			printf("该饮品只能制作%d杯,您是否购买,是：1；否：0\n",i-1);
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
	printf("抱歉未能提供您想要的饮品\n");
}else{
    SHOP*o=head;
    PRINTF(o);
    o=head;
    yuanliaojilu(o);
    o=head;
    buy(o);
    printf("购买成功");
}
}else{
dingdan_wenjiandu();
}
return 0;
}

void wenjian_ding(SELL*head){//需要传入订单节点指针 ;
	FILE*fp;
	SELL*p=head;
	int i=1,k;
	fp=fopen("dingdan.txt","w");
	while(p!=NULL){
	fprintf(fp,"\n第%d条订单信息\n",i);
	i++;
	k=10*p->drink+p->taste;
	switch(k){
		case 11:fprintf(fp,"饮品种类：果茶奶茶 \n口味：牛乳味\n");break;
		case 12:fprintf(fp,"饮品种类：果茶奶茶 \n口味：草莓味\n"); break;
		case 13:fprintf(fp,"饮品种类：果茶奶茶 \n口味：葡萄味\n"); break;
		case 21:fprintf(fp,"饮品种类：冰激淋   \n口味：草莓味\n");break;
		case 22:fprintf(fp,"饮品种类：冰激淋   \n口味：葡萄味\n");break;
		case 23:fprintf(fp,"饮品种类：冰激淋   \n口味：酸奶味\n");break;
		case 31:fprintf(fp,"饮品种类：咖啡     \n口味：黑咖啡\n");break;
		case 32:fprintf(fp,"饮品种类：咖啡     \n口味：抹茶味\n");break;
		case 33:fprintf(fp,"饮品种类：咖啡     \n口味：卡布奇诺\n");break;
		case 41:fprintf(fp,"饮品种类：酸奶     \n口味：原味\n");break;
		case 42:fprintf(fp,"饮品种类：酸奶     \n口味：草莓味\n");break;
		case 43:fprintf(fp,"饮品种类：酸奶     \n口味：葡萄味\n");break;
	}
		switch(p->temper) {
	case 1:fprintf(fp,"温度:热\n"); break;
	case 2:fprintf(fp,"温度:常温\n");break;
	case 3:fprintf(fp,"温度:加冰\n"); break;
	}
		switch(p->sugar) {
	case 1:fprintf(fp,"甜度：全糖\n");break;
	case 2:fprintf(fp,"甜度：五分糖\n");break;
	case 3:fprintf(fp,"甜度：无糖\n");break;
	}
		switch(p->standard) {
	case 1:fprintf(fp,"规格：大\n");break;
	case 2:fprintf(fp,"规格：中\n");break;
	case 3:fprintf(fp,"规格：小\n"); break;
	}
	fprintf(fp,"数量:%d杯\n日期:%s\n订单编号:%s",p->much,p->s_date,p->s_number);
	p=p->s_next;
}
fclose(fp);
printf("文件导出成功，请前往dingdan.txt查看");
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
    printf("您可以查询原料使用记录:\n1:一段时间;    2:所有\n");
	scanf("%d",&choose);
	switch(choose){
		case 1:
		while(1){
        printf("请输入开始时间\n");
		scanf("%s",date1);
		printf("请输入结束时间\n");
		scanf("%s",date2);
		if(strcmp(date1,date2)<=0){
			break;
		}else{
			printf("您的时间输入不符合实际情况,请重新输入\n");
		}
	}
	if(p==NULL)
    {printf("当前原料无使用记录");
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
	if(Smilk!=0)printf("\n牛奶使用量：%d\n",Smilk);
	if(Stea!=0)printf("茶使用量：%d\n",Stea);
	if(Scream!=0)printf("奶油使用量：%d\n",Scream);
	if(Scoffee!=0)printf("咖啡豆使用量：%d\n",Scoffee);
	if(Syoghurt!=0)printf("酸奶使用量：%d\n",Syoghurt);
	if(Sstraw!=0)printf("草莓使用量：%d\n",Sstraw);
	if(Sgrape!=0)printf("葡萄使用量：%d\n",Sgrape);
	if(Ssugar!=0)printf("糖使用量：%d\n\n\n",Ssugar);
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
		   }if(Smilk!=0)printf("\n牛奶使用量：%d\n",Smilk);
	if(Stea!=0)printf("茶使用量：%d\n",Stea);
	if(Scream!=0)printf("奶油使用量：%d\n",Scream);
	if(Scoffee!=0)printf("咖啡豆使用量：%d\n",Scoffee);
	if(Syoghurt!=0)printf("酸奶使用量：%d\n",Syoghurt);
	if(Sstraw!=0)printf("草莓使用量：%d\n",Sstraw);
	if(Sgrape!=0)printf("葡萄使用量：%d\n",Sgrape);
	if(Ssugar!=0)printf("糖使用量：%d\n",Ssugar);
		   break;

	}
}


void PRINTxinxi(){
printf("\n                  \t商品信息及代号\n");
printf("\t规格:       [1]大       [2]中       [3]小\n");
printf("\t甜度:       [1]全糖     [2]五分糖   [3] 无糖\n");
printf("\t温度:       [1]热       [2]常温     [3] 冰\n");
printf("\t饮品:       [1]果茶奶茶   大杯:15元  中杯: 13元   小杯:8元\n");
printf("\t饮品:       [2]冰激淋     大杯:10元  中杯: 8元    小杯:5元\n");
printf("\t饮品:       [3]咖啡       大杯:16元  中杯: 14元   小杯:10元\n");
printf("\t饮品:       [4]酸奶       大杯:12元  中杯: 10元   小杯:8元\n");
printf("\t果茶奶茶:   [1]牛乳味  [2]草莓味    [3] 葡萄味\n");
printf("\t冰激淋:     [1]草莓味  [2]葡萄味    [3] 酸奶味\n");
printf("\t咖啡:       [1]黑咖啡  [2]抹茶味    [3] 卡布奇诺\n");
printf("\t酸奶:       [1]原味    [2]草莓味    [3] 葡萄味\n");
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
	printf("您要读入多少条订单信息");
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
	 printf("查询方式：1:一种饮品2：全部饮品\n");
	 int choose;
	 int kind;
	 int taste;
	 int k;
	 int sales=0;
	 scanf("%d",&choose);
	 switch(choose){
	 	case 1:
	 	printf("请输入饮品的种类\n");
	 	scanf("%d",&kind);
	 	printf("请输入饮品的口味\n");
	 	scanf("%d",&taste);
	 	SELL*o=head;
	 	while(o!=NULL){
	 		if(o->drink==kind&&o->taste==taste)
	 		sales+=o->much;
	 		o=o->s_next;
		 }
	 	printf("该饮品销量为%d\n",sales);
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
	 		printf("果茶奶茶牛乳味   销量：%d\n",sales11);
	 		printf("果茶奶茶草莓味   销量：%d\n",sales12);
	 		printf("果茶奶茶葡萄味   销量：%d\n",sales13);
	 		printf("冰激淋草莓味     销量：%d\n",sales21);
	 		printf("冰激淋葡萄味     销量：%d\n",sales22);
	 		printf("冰激淋酸奶味     销量：%d\n",sales23);
	 		printf("咖啡原味黑咖啡   销量：%d\n",sales31);
	 		printf("咖啡抹茶味       销量：%d\n",sales32);
	 		printf("咖啡卡布奇诺     销量：%d\n",sales33);
	 		printf("酸奶原味         销量：%d\n",sales41);
	 		printf("酸奶草莓味       销量：%d\n",sales42);
	 		printf("酸奶葡萄味       销量：%d\n",sales43);
	 		break;}
	 		}
			 }

//------------------------------------------------------
double yuce(int y[35])//（储值数组）拟合并预测
{
    int k_day=7;
    double a,b;//回归系数
    double dx[35],dy[35];

    //数据类型转换
    for(int i=0;i<k_day;i++)
    {
        dx[i]=i+1;
        dy[i]=(double)y[i];
    }

    //中间变量计算
    double hexy=0,hex=0,hey=0,hex2=0;
    for(int i=0;i<k_day;i++)
    {
        hexy+=dx[i]*dy[i];
        hex+=dx[i];
        hey+=dy[i];
        hex2+=dx[i]*dx[i];
    }

    //回归系数计算
    b=(k_day*hexy-hex*hey)/(k_day*hex2-hex*hex);
    a=hey/k_day-b*hex/k_day;

    //预测
    double y_result=0;//预测结果
    y_result=b*8+a;

    return y_result;//返回预测结果
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

int** search_material(STOCKNOTE*q) //p为头
{
    STOCKNOTE*p=q;
   int ii,jj;
   for(ii=0;ii<8;ii++)  //原料种类
   {
       switch(ii)
       {
        case 0://milk
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            for(jj=0;jj<7;jj++) //日期
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
            case 1:printf("\t牛奶近七天的销量分别为：  ");break;
            case 2:printf("\t茶叶近七天的销量分别为：  ");break;
            case 3:printf("\t奶油近七天的销量分别为：  ");break;
            case 4:printf("\t咖啡豆近七天的销量分别为：");break;
            case 5:printf("\t酸奶近七天的销量分别为：  ");break;
            case 6:printf("\t草莓近七天的销量分别为：  ");break;
            case 7:printf("\t葡萄近七天的销量分别为：  ");break;
            case 8:printf("\t白糖近七天的销量分别为：  ");break;
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
    printf("请输入今天的日期：");
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
                printf("牛奶预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",milk);
                if(yuresult>milk)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 2:
                printf("茶叶预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",tea);
                if(yuresult>tea)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 3:
                printf("奶油预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",cream);
                if(yuresult>cream)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 4:
                printf("咖啡豆预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",coffee);
                if(yuresult>coffee)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 5:
                printf("酸奶预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",yoghurt);
                if(yuresult>yoghurt)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 6:
                printf("草莓预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",straw);
                if(yuresult>straw)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 7:
                printf("葡萄预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",grape);
                if(yuresult>grape)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
            case 8:
                printf("白糖预测使用量为：%llf g,\t",yuresult);
                printf("当前库存为%dg,",sugar);
                if(yuresult>sugar)
                    printf("库存不足，请及时补充！\n");
                else
                    printf("当前库存充足。\n");
                break;
        }
    }
}

