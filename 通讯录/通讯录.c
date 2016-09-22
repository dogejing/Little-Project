/********************************************************************************
*                                                                               
*   函数功能：             
*   输入    ：                                           
*   输出    ：                                                                                   
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

ADD * creat(ADD **head);                                        //（链表创建函数）
ADD * insert(ADD **head,ADD **new);            	   	  //（插入节点函数）
int print_list(ADD **head);                           //（输出链表函数）
ADD * input_one(ADD **p);                             //（输入插入节点函数） 
ADD *find_name(ADD **head,ADD **find_new);              //（查找人名节点函数） 
ADD * find_num(ADD **head,ADD **find_new);             // (查找电话节点函数) 
int print_find(ADD **find_new);                       //（输出单个节点函数）
ADD * insert_twolist(ADD **head1,ADD **head2);        // (链表合并函数) 
ADD * clear_list(ADD **head);                         //（删除该链表函数） 
int instruction();                                    //说明书
int input_order();                                    //输入指令 
ADD * delect_one(ADD **head,ADD **find_new);           //删除单个节点 
int save(ADD **head);                                  //导出数据 
//int read(ADD **head,ADD **input_new);                   //导入数据 

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
*   函数功能：  接受输入的指令，并比较             
*   输入    ：      键盘输入                                     
*   输出    ：       比较参数                                                                            
*                                                                               
********************************************************************************/
int input_order()
{
	int m;
	ADD *head,*head1,*head2,*input_new,*find_new;
	
	printf("\n");
	printf("请输入指令：");
	if(scanf("%d",&m) != 1)
	{
		printf("error!  ");
		exit(1);
	}
	
	
	switch (m)
	{
		case 0:instruction();break;
		case 1:printf("创建一个通讯录\n");
				creat(&head);
				break;
		case 2:printf("输出通讯录\n");
				print_list(&head);
				break;
		case 3:printf("创建第二个通讯录\n");
				creat(&head1);
				break;
		case 4:printf("合并两个通讯录\n");
				insert_twolist(&head,&head1);
				break;
		case 5:printf("在通讯录中添加联系人\n");
				input_one(&input_new);
				break;
		case 6:printf("通过姓名查找联系人\n");
				find_name(&head,&find_new);
				break;
		case 7:printf("通过电话查找联系人\n");
				find_num(&head,&find_new);
				break;
		case 8:printf("删除该联系人\n"); 
				delect_one(&head,&find_new);
				break;
		case 9:printf("清空整个通讯录\n");
				clear_list(&head);
				break;
		case 10:printf("导出联系人\n");
				save(&head);
				break; 
/*		case 11:printf("导入联系人\n");
				read(&head,&input_new);
				break; */
		default:
				printf("错误的指令");
				break; 
	}
	
	
} 

/********************************************************************************
*                                                                               
*   函数功能：  说明书            
*   输入    ：                                      
*   输出    ：                                                                                   
*                                                                               
********************************************************************************/
int instruction()        
{
	printf("您好！欢迎使用杨大汪通讯录\n您可以通过输入以下指令进行操作：\n");
	printf("0  打开说明书\n");
	printf("1  创建一个通讯录\n");
	printf("2  输出通讯录\n");
	printf("3  创建第二个通讯录\n");
	printf("4  合并两个通讯录\n");
	printf("5  在通讯录中添加联系人\n");
	printf("6  通过姓名查找联系人\n");
	printf("7  通过电话查找联系人\n");
	printf("8  删除该联系人\n"); 
	printf("9  清空整个通讯录\n");
	printf("10 导出联系人\n");
//	printf("11 导入联系人\n");
}


/********************************************************************************
*                                                                               
*   函数功能：  输出查找到的节点           
*   输入    ：  头地址 ，查找到的节点地址                                         
*   输出    ：                                                                                   
*                                                                               
********************************************************************************/
ADD * delect_one(ADD **head,ADD **find_new) 
{
	ADD *p;
	
	p = (*head);
	if((*find_new) == (*head))  //删除头结点 
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
*   函数功能：  将链表2插入链表1的后面       (链表合并函数)    
*   输入    ：    链表1 链表2 的头结点地址                                       
*   输出    ：   合成的链表头结点地址                        
*   数据包　：                                                           
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
*   函数功能：创建n个节点的链表   存储信息         （链表创建函数）     
*   输入    ：无   键盘输入  联系人的数目n  联系人信息                                              
*   输出    ：head 首地址                               
*   数据包　：                                                           
*                                                                               
********************************************************************************/
ADD * creat(ADD **head)
{	
	ADD *tail,*new;
	int count = 0;
	int n;
	
	printf("输入联系人的数目");
	scanf("%d",&n);
	getchar();
	while(count < n)
	{
		new = (ADD *)malloc(sizeof(ADD));
		if(NULL == new)
		{
			printf("内存申请失败！");
			exit (1); 
		}
		printf("\n输入名字：");
		gets(new->name);

		printf("\n输入电话：");
		gets(new->num);
//		getchar();        //吸收回车 
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
*   函数功能：在链表中的尾部插入一个新的节点               （插入节点函数）  
*   输入    ： 链表的头结点，被插入节点的地址                                          
*   输出    ：  完成插入操作后链表的头节点                         
*   数据包　：                                                        
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
*   函数功能：整体输出链表                （输出链表函数） 
*   输入    ：链表头指针                                           
*   输出    ： 无  屏幕输出                          
*   数据包　：                                                           
*                                                                               
********************************************************************************/
int print_list(ADD **head)
{
	ADD *p;
	
	p = (*head);
	printf("\n");
	printf("      姓名                电话            \n");
	while(p != NULL)
	{
		printf("      %-20s%-20s\n",p->name,p->num);
		p = p->next;
	}
}

/********************************************************************************
*                                                                               
*   函数功能：输入插入的节点，信息             （输入插入节点函数） 
*   输入    ：    键盘输入插入节点的信息                                         
*   输出    ：该节点的地址                      
*   数据包　：                                                           
*                                                                               
********************************************************************************/
ADD * input_one(ADD **p)
{
	(*p) = (ADD *)malloc(sizeof(ADD));
	getchar();
	printf("\n输入名字：");
	gets((*p)->name);
	printf("\n输入电话：");
	getchar();        //吸收回车
	gets((*p)->num);
	
	
//	return p;
} 

/********************************************************************************
*                                                                               
*   函数功能：输入人名，查找该节点             （查找人名节点函数） 
*   输入    ： head  键盘输入人名                                          
*   输出    ：  查找到的节点                           
*   数据包　：                                                           
*                                                                               
********************************************************************************/
ADD * find_name(ADD **head,ADD **find_new)
{
	ADD *p;
	char str[20];
	
	printf("输入查询的人名：");
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
	printf("没有发现这个人！");
	
	return 0;
}

/********************************************************************************
*                                                                               
*   函数功能：输入电话，查找该节点             （查找电话节点函数） 
*   输入    ： head  键盘输入电话                                          
*   输出    ：  查找到的节点                           
*   数据包　：                                                           
*                                                                               
********************************************************************************/
ADD * find_num(ADD **head,ADD **find_new)
{
	ADD *p;
	char str[20];
	
	printf("输入查询的电话：");
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
	printf("没有发现这个电话！");
	
	return 0;
}

/********************************************************************************
*                                                                               
*   函数功能：  输出查找的人                （输出单个节点函数） 
*   输入    ：   查找的地址                                        
*   输出    ：        屏幕                   
*   数据包　：                                                           
*                                                                               
********************************************************************************/
int print_find(ADD **find_new)
{
	ADD *p;
	
	p = (*find_new);
	printf("      姓名                电话            \n");
	printf("      %-20s%-20s\n",p->name,p->num);
} 

/********************************************************************************
*                                                                               
*   函数功能：             清空链表           （删除该链表） 
*   输入    ：      需要输出链表的首地址                                     
*   输出    ：        删除后链表的首地址                   
                                                                  
********************************************************************************/
ADD * clear_list(ADD **head)
{
	ADD *p,*q;
	
	p = (*head)->next;   //p指向表头节点 
	while(p)  //遍历链表 ，直到表尾 
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*head) = NULL;  //将头结点置空
	
//	return head; 
}

/********************************************************************************
*                                                                               
*   函数功能：  导出通讯录           
*   输入    ：   输入首地址                                          
*   输出    ：   文件操作  输出文件address                                                                                
*                                                                               
********************************************************************************/
int save(ADD **head)
{
	FILE *fp;
	ADD *p;
	TEMP *temp = (TEMP *)malloc(sizeof(TEMP));
	
//	memset(temp,0,sizeof(TEMP));//初始化temp
	if((fp = fopen("address.txt","w+")) == NULL)
	{
		printf("cannot open file!\n");
		return;
	}
	p = (*head);
	while(NULL != p)
	{
		memset(temp,0,sizeof(TEMP));//初始化temp
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
