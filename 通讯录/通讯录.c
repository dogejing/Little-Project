/********************************************************************************
*                                                                               
*   �������ܣ�             
*   ����    ��                                           
*   ���    ��                                                                                   
*                                                                               
********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct address 
{
	char name[20];
	char num[20];
	struct address *next;
}ADD;

typedef struct temp 
{
	char name[20];
	char num[20];
}TEMP;

ADD * creat(ADD **head);                                        //��������������
ADD * insert(ADD **head,ADD **new);            	   	  //������ڵ㺯����
int print_list(ADD **head);                           //�������������
ADD * input_one(ADD **p);                             //���������ڵ㺯���� 
ADD *find_name(ADD **head,ADD **find_new);              //�����������ڵ㺯���� 
ADD * find_num(ADD **head,ADD **find_new);             // (���ҵ绰�ڵ㺯��) 
int print_find(ADD **find_new);                       //����������ڵ㺯����
ADD * insert_twolist(ADD **head1,ADD **head2);        // (����ϲ�����) 
ADD * clear_list(ADD **head);                         //��ɾ������������ 
int instruction();                                    //˵����
int input_order();                                    //����ָ�� 
ADD * delect_one(ADD **head,ADD **find_new);           //ɾ�������ڵ� 
int save(ADD **head);                                  //�������� 
//int read(ADD **head,ADD **input_new);                   //�������� 

int main(void)
{
	
	
	instruction();
	while(1)
	{
		input_order();
	}
	return 0;
}


/********************************************************************************
*                                                                               
*   �������ܣ�  ���������ָ����Ƚ�             
*   ����    ��      ��������                                     
*   ���    ��       �Ƚϲ���                                                                            
*                                                                               
********************************************************************************/
int input_order()
{
	int m;
	ADD *head,*head1,*head2,*input_new,*find_new;
	
	printf("\n");
	printf("������ָ�");
	if(scanf("%d",&m) != 1)
	{
		printf("error!  ");
		exit(1);
	}
	
	
	switch (m)
	{
		case 0:instruction();break;
		case 1:printf("����һ��ͨѶ¼\n");
				creat(&head);
				break;
		case 2:printf("���ͨѶ¼\n");
				print_list(&head);
				break;
		case 3:printf("�����ڶ���ͨѶ¼\n");
				creat(&head1);
				break;
		case 4:printf("�ϲ�����ͨѶ¼\n");
				insert_twolist(&head,&head1);
				break;
		case 5:printf("��ͨѶ¼�������ϵ��\n");
				input_one(&input_new);
				break;
		case 6:printf("ͨ������������ϵ��\n");
				find_name(&head,&find_new);
				break;
		case 7:printf("ͨ���绰������ϵ��\n");
				find_num(&head,&find_new);
				break;
		case 8:printf("ɾ������ϵ��\n"); 
				delect_one(&head,&find_new);
				break;
		case 9:printf("�������ͨѶ¼\n");
				clear_list(&head);
				break;
		case 10:printf("������ϵ��\n");
				save(&head);
				break; 
/*		case 11:printf("������ϵ��\n");
				read(&head,&input_new);
				break; */
		default:
				printf("�����ָ��");
				break; 
	}
	
	
} 

/********************************************************************************
*                                                                               
*   �������ܣ�  ˵����            
*   ����    ��                                      
*   ���    ��                                                                                   
*                                                                               
********************************************************************************/
int instruction()        
{
	printf("���ã���ӭʹ�������ͨѶ¼\n������ͨ����������ָ����в�����\n");
	printf("0  ��˵����\n");
	printf("1  ����һ��ͨѶ¼\n");
	printf("2  ���ͨѶ¼\n");
	printf("3  �����ڶ���ͨѶ¼\n");
	printf("4  �ϲ�����ͨѶ¼\n");
	printf("5  ��ͨѶ¼�������ϵ��\n");
	printf("6  ͨ������������ϵ��\n");
	printf("7  ͨ���绰������ϵ��\n");
	printf("8  ɾ������ϵ��\n"); 
	printf("9  �������ͨѶ¼\n");
	printf("10 ������ϵ��\n");
//	printf("11 ������ϵ��\n");
}


/********************************************************************************
*                                                                               
*   �������ܣ�  ������ҵ��Ľڵ�           
*   ����    ��  ͷ��ַ �����ҵ��Ľڵ��ַ                                         
*   ���    ��                                                                                   
*                                                                               
********************************************************************************/
ADD * delect_one(ADD **head,ADD **find_new) 
{
	ADD *p;
	
	p = (*head);
	if((*find_new) == (*head))  //ɾ��ͷ��� 
	{
		(*head) = p->next;
		free((*find_new));
		
		return 0;
	} 
	while(p->next != (*find_new))
	{
		p = p->next;
	}
	p->next = (*find_new)->next;
	(*find_new)->next = NULL;
	free((*find_new));
}

/********************************************************************************
*                                                                               
*   �������ܣ�  ������2��������1�ĺ���       (����ϲ�����)    
*   ����    ��    ����1 ����2 ��ͷ����ַ                                       
*   ���    ��   �ϳɵ�����ͷ����ַ                        
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
ADD * insert_twolist(ADD **head1,ADD **head2)
{
	ADD *p1,*p2;
	
	p1 = (*head1);
	p2 = (*head2);
	while(p1->next != NULL)
	{
		p1 = p1->next;
	}
	p1->next = p2;
	
//	return head1;
}

/********************************************************************************
*                                                                               
*   �������ܣ�����n���ڵ������   �洢��Ϣ         ��������������     
*   ����    ����   ��������  ��ϵ�˵���Ŀn  ��ϵ����Ϣ                                              
*   ���    ��head �׵�ַ                               
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
ADD * creat(ADD **head)
{	
	ADD *tail,*new;
	int count = 0;
	int n;
	
	printf("������ϵ�˵���Ŀ");
	scanf("%d",&n);
	getchar();
	while(count < n)
	{
		new = (ADD *)malloc(sizeof(ADD));
		if(NULL == new)
		{
			printf("�ڴ�����ʧ�ܣ�");
			exit (1); 
		}
		printf("\n�������֣�");
		gets(new->name);

		printf("\n����绰��");
		gets(new->num);
//		getchar();        //���ջس� 
		count++;
		if(1 == count)
		{
			(*head) = new;
		}
		else
		{
			tail->next = new;
			new->next = NULL;
		}
		tail = new;
	}
	
//	return head; 
}

/********************************************************************************
*                                                                               
*   �������ܣ��������е�β������һ���µĽڵ�               ������ڵ㺯����  
*   ����    �� �����ͷ��㣬������ڵ�ĵ�ַ                                          
*   ���    ��  ��ɲ�������������ͷ�ڵ�                         
*   ���ݰ�����                                                        
*                                                                               
********************************************************************************/
ADD * insert(ADD **head,ADD **new)
{
	ADD *p;
	
	if((*head) == NULL)
	{
		(*head)= (*new);
		(*new)->next = NULL;
	}
	else
	{
		p = (*head);
		while(NULL != p->next)
		{
			p = p->next;
		}
		p->next = (*new);
		(*new)->next = NULL;
	}
	
//	return head;
}

/********************************************************************************
*                                                                               
*   �������ܣ������������                ������������� 
*   ����    ������ͷָ��                                           
*   ���    �� ��  ��Ļ���                          
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
int print_list(ADD **head)
{
	ADD *p;
	
	p = (*head);
	printf("\n");
	printf("      ����                �绰            \n");
	while(p != NULL)
	{
		printf("      %-20s%-20s\n",p->name,p->num);
		p = p->next;
	}
}

/********************************************************************************
*                                                                               
*   �������ܣ��������Ľڵ㣬��Ϣ             ���������ڵ㺯���� 
*   ����    ��    �����������ڵ����Ϣ                                         
*   ���    ���ýڵ�ĵ�ַ                      
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
ADD * input_one(ADD **p)
{
	(*p) = (ADD *)malloc(sizeof(ADD));
	getchar();
	printf("\n�������֣�");
	gets((*p)->name);
	printf("\n����绰��");
	getchar();        //���ջس�
	gets((*p)->num);
	
	
//	return p;
} 

/********************************************************************************
*                                                                               
*   �������ܣ��������������Ҹýڵ�             �����������ڵ㺯���� 
*   ����    �� head  ������������                                          
*   ���    ��  ���ҵ��Ľڵ�                           
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
ADD * find_name(ADD **head,ADD **find_new)
{
	ADD *p;
	char str[20];
	
	printf("�����ѯ��������");
	getchar();
	gets(str);
	p = (*head);
	while(p != NULL)
	{
		if(strcmp(p->name,str) == 0)
		{
			(*find_new) = p;
			print_find(&p);
			return 0;
		}
		p = p->next;
	}
	printf("û�з�������ˣ�");
	
	return 0;
}

/********************************************************************************
*                                                                               
*   �������ܣ�����绰�����Ҹýڵ�             �����ҵ绰�ڵ㺯���� 
*   ����    �� head  ��������绰                                          
*   ���    ��  ���ҵ��Ľڵ�                           
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
ADD * find_num(ADD **head,ADD **find_new)
{
	ADD *p;
	char str[20];
	
	printf("�����ѯ�ĵ绰��");
	getchar();
	gets(str);
	p = (*head);
	while(p != NULL)
	{
		if(strcmp(p->num,str) == 0)
		{
			(*find_new) = p;
			print_find(&p);
			return 0;
		}
		p = p->next;
	}
	printf("û�з�������绰��");
	
	return 0;
}

/********************************************************************************
*                                                                               
*   �������ܣ�  ������ҵ���                ����������ڵ㺯���� 
*   ����    ��   ���ҵĵ�ַ                                        
*   ���    ��        ��Ļ                   
*   ���ݰ�����                                                           
*                                                                               
********************************************************************************/
int print_find(ADD **find_new)
{
	ADD *p;
	
	p = (*find_new);
	printf("      ����                �绰            \n");
	printf("      %-20s%-20s\n",p->name,p->num);
} 

/********************************************************************************
*                                                                               
*   �������ܣ�             �������           ��ɾ�������� 
*   ����    ��      ��Ҫ���������׵�ַ                                     
*   ���    ��        ɾ����������׵�ַ                   
                                                                  
********************************************************************************/
ADD * clear_list(ADD **head)
{
	ADD *p,*q;
	
	p = (*head)->next;   //pָ���ͷ�ڵ� 
	while(p)  //�������� ��ֱ����β 
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*head) = NULL;  //��ͷ����ÿ�
	
//	return head; 
}

/********************************************************************************
*                                                                               
*   �������ܣ�  ����ͨѶ¼           
*   ����    ��   �����׵�ַ                                          
*   ���    ��   �ļ�����  ����ļ�address                                                                                
*                                                                               
********************************************************************************/
int save(ADD **head)
{
	FILE *fp;
	ADD *p;
	TEMP *temp = (TEMP *)malloc(sizeof(TEMP));
	
//	memset(temp,0,sizeof(TEMP));//��ʼ��temp
	if((fp = fopen("address.txt","w+")) == NULL)
	{
		printf("cannot open file!\n");
		return;
	}
	p = (*head);
	while(NULL != p)
	{
		memset(temp,0,sizeof(TEMP));//��ʼ��temp
		strcpy(temp->name,p->name);
		strcpy(temp->num,p->num);
		if(fwrite(temp,sizeof(TEMP),1,fp) != 1)
		{
			printf("file write error!\n");
		}
		p = p->next;
	}
	fclose(fp);
}

/*int read(ADD **head,ADD **input_new)
{
	ADD *p;
	TEMP *temp = (TEMP *)malloc(sizeof(TEMP));
	FILE *fp;
	
	(*input_new) = malloc(sizeof(ADD));
	p = (*head);
	if((fp = fopen("address.txt","r")) == NULL)
	{
		printf("cannot open file!");
		return 0;
	}
	if(feof(fp))
	{
		memset(temp,0,sizeof(TEMP));
		fread(temp,sizeof(TEMP),1,fp);
		strcpy((*input_new)->name,temp->name);
		strcpy((*input_new)->num,temp->num);
		(*input_new)->next = NULL;
		insert(head,input_new);

		p->next = p;
		p->next = NULL;
	}	
}*/	
