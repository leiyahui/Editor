#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX 100
typedef struct node  //存放一行数据
{
	char data[80];
	struct node* next;
}nodetype, *link;
typedef struct  //每一行的信息
{
	int num;  //每行个数
	int len;   //长度
	link next; //指向数据节点
}headtype;
void InitHead(headtype head[])  //初始化
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		head[i].len = 0;
	}
}
int MenuSelect()  //菜单
{
	char buff;
	printf("\n1,输入  ");
	printf("2,删除  ");
	printf("3,显示  ");
	printf("4,退出");
	printf("\n请输入菜单序号：");
	while (buff = getchar())
		if (buff <= '4'&&buff >= '1')
		{
			return buff;
		}
}
void EnterData(headtype* head)  //输入信息
{
	link p;
	int line;
	int i;
	int j;
	int m;
	int k;
	char buff[100];
	while (1)
	{
		memset(buff, 0, 100);
		printf("请输入行号(0-99):");
		scanf_s("%d", &line, 100);
		if (line < 0 || line >= MAX)
		{
			printf("您输入的行号有误\n");
			return;
		}
		else
		{
			i = line;
			head[i].num = line;
			head[i].next = (link)malloc(sizeof(nodetype));
			p = head[i].next;
			j = 0;
			k = 0;
			m = 1;
			printf("请输入文字\n");
			scanf_s("%s", buff, 100);
			do
			{
				if (j > 80 * m - 1)  //当一个节点不够时，再增加一个节点
				{
					m++;
					p->next = (link)malloc(sizeof(nodetype));
					p = p->next;
				}
				p->data[j % 80] = buff[j];  //将缓冲区的数据读入
				j++;
			} while (buff[j] != '\0');
			p->next = NULL;
			head[i].len = j;
		}
		printf("输入Y继续输入，输入N停止输入");
		getchar();
		if (getchar() == 'N')
			return;
	}

}
void Deleteline(headtype* head)  //
{
	link p;
	link q;
	int line;
	printf("请输入行数:");
	scanf_s("%d", &line, 1);
	if (line<0 || line >= MAX)
	{
		return;
	}
	else
	{
		p = head[line].next;
		while (p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}

	head[line].len = 0;
}
void List(headtype* head)
{
	link p, q;
	int i;
	int j;
	int n;
	int m;
	for (i = 0; i < MAX; i++)
	{
		p = head[i].next;
		n = head[i].len;
		m = 1;
		if (n > 0)
		{
			printf("\n第%d行：", i);
			for (j = 0; j < n; j++)
			{
				if (j > 80 * m - 1)
				{
					p = p->next;
					m++;
				}
				else
				{
					printf("%c", p->data[j % 80]);
				}
			}
		}
	}
	getchar();
}
void main()
{
	headtype head[MAX];
	char choice;
	InitHead(head);
	while (1)
	{
		choice = MenuSelect();
		switch (choice)
		{
		case '1':EnterData(head); break;
		case '2':Deleteline(head); break;
		case '3':List(head); break;
		case '4':return;
		}
	}

}