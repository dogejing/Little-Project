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
	printf("\n��ӭ�µ��й��ƶ�\n");
	printf("0.�˹�����\n");
	printf("1.ҵ���ѯ\n");
	printf("2.�ֻ���ֵ\n");
	printf("3.ҵ�����\n");
	printf("9.�˳�\n");
        printf("��������Ҫ�ķ���");
        scanf("%d",&i);
        switch(i)
        {
		case 0:rank_0();break;             
		case 1:rank_1();break;             
		case 2:rank_2();break;             
		case 3:rank_3();break;             
		case 9:exit(1);break;               
		default :printf("�������\n");
				printf("�����²�����\n");
					homepage(); 
					break;            
        }
}

int rank_0(void)
{
	int i;
	
		printf("\n");
	printf("��ӭʹ���˹�����\n");
	printf("����Ϊ��ת���˹�����\n����1234Ϊ������\n"); 
	printf("0.�����ϼ��˵�\n");
	printf("�����룺");
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
	printf("1.���Ѳ�ѯ\n");
	printf("2.������ѯ\n");
	printf("3.�ײͲ�ѯ\n");
	printf("0.�����ϼ��˵�\n") ;
        printf("�����룺");
        scanf("%d",&i);
        switch(i)
        {
		case 1:
		printf("����ʹ�ý��Ϊ%dԪ,���Ϊ%dԪ\n",m,n);
			rank_1();
				break;             
		case 2:printf("����ʹ������Ϊ%dM,ʣ������Ϊ%dM\n",k,t); 
			rank_1();
				break;             
		case 3:	printf("��ʹ�õ��ײ�Ϊ�����еش���\n");
				rank_1();
				break;             
		case 0:homepage();
				break;                 
		default :printf("�������\n");
				printf("�����²�����\n");
				rank_1(); 
				break; 
	}            
}

void rank_2(void)
{
    int i,m;
	
		printf("\n");
	printf("�����ֵ�Ľ�");
	scanf("%d",&m);	
	printf("��ֵ�ɹ���\n");
	printf("0.�����ϼ��˵�\n");
	printf("�����룺");
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
	printf("1.�����ײ�����\n");
    printf("2.����ҵ�����\n");
	printf("3.ͨ���ײ�����\n");
	printf("0.�����ϼ��˵�\n");
	printf("�����룺");
    scanf("%d",&i);
    switch(i)
    {
       	case 0:homepage();
       	case 1:printf("����ɹ���");
       	rank_3();
		   		break;
		case 2:printf("����ɹ���");
			rank_3();
		      	break;
		case 3: printf("����ɹ���");
			rank_3();
				break;                 
	}            	
}

int main()
{
	homepage();

	return 0;
}
