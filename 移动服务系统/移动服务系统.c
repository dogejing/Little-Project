#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  homepage(); 
int  rank_0();
int  rank_1();
void rank_2();
void rank_3();

void  homepage(void)
{
	int i;
	
		printf("\n");
	printf("\n欢迎致电中国移动\n");
	printf("0.人工服务\n");
	printf("1.业务查询\n");
	printf("2.手机充值\n");
	printf("3.业务办理\n");
	printf("9.退出\n");
        printf("输入您需要的服务：");
        scanf("%d",&i);
        switch(i)
        {
		case 0:rank_0();break;             
		case 1:rank_1();break;             
		case 2:rank_2();break;             
		case 3:rank_3();break;             
		case 9:exit(1);break;               
		default :printf("输入错误！\n");
				printf("请重新操作！\n");
					homepage(); 
					break;            
        }
}

int rank_0(void)
{
	int i;
	
		printf("\n");
	printf("欢迎使用人工服务！\n");
	printf("正在为你转接人工服务\n工号1234为您服务！\n"); 
	printf("0.返回上级菜单\n");
	printf("请输入：");
    scanf("%d",&i);
    switch(i)
    {
       	case 0:homepage();
			break;                 
	}     
}

int  rank_1(void)
{
    int i;
    int m,n,t,k;
    
    	printf("\n");
    srand((int)time(NULL));
    m = rand()%105;
    n = rand()%88;
    k = rand()%1022;
    t = rand()%2450;
	printf("1.话费查询\n");
	printf("2.流量查询\n");
	printf("3.套餐查询\n");
	printf("0.返回上级菜单\n") ;
        printf("请输入：");
        scanf("%d",&i);
        switch(i)
        {
		case 1:
		printf("当月使用金额为%d元,余额为%d元\n",m,n);
			rank_1();
				break;             
		case 2:printf("当月使用流量为%dM,剩余流量为%dM\n",k,t); 
			rank_1();
				break;             
		case 3:	printf("您使用的套餐为：动感地带。\n");
				rank_1();
				break;             
		case 0:homepage();
				break;                 
		default :printf("输入错误！\n");
				printf("请重新操作！\n");
				rank_1(); 
				break; 
	}            
}

void rank_2(void)
{
    int i,m;
	
		printf("\n");
	printf("输入充值的金额：");
	scanf("%d",&m);	
	printf("充值成功！\n");
	printf("0.返回上级菜单\n");
	printf("请输入：");
    scanf("%d",&i);
    switch(i)
    {
       	case 0:homepage();
			break;                 
	}    
        
}

void rank_3(void)
{
    int i;
	
	printf("\n");
	printf("1.流量套餐升级\n");
    printf("2.短信业务办理\n");
	printf("3.通话套餐升级\n");
	printf("0.返回上级菜单\n");
	printf("请输入：");
    scanf("%d",&i);
    switch(i)
    {
       	case 0:homepage();
       	case 1:printf("办理成功！");
       	rank_3();
		   		break;
		case 2:printf("办理成功！");
			rank_3();
		      	break;
		case 3: printf("办理成功！");
			rank_3();
				break;                 
	}            	
}

int main()
{
	homepage();

	return 0;
}
