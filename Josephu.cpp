#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX 100
typedef struct node  //���һ������
{
	char data[80];
	struct node* next;
}nodetype, *link;
typedef struct  //ÿһ�е���Ϣ
{
	int num;  //ÿ�и���
	int len;   //����
	link next; //ָ�����ݽڵ�
}headtype;
void InitHead(headtype head[])  //��ʼ��
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		head[i].len = 0;
	}
}
int MenuSelect()  //�˵�
{
	char buff;
	printf("\n1,����  ");
	printf("2,ɾ��  ");
	printf("3,��ʾ  ");
	printf("4,�˳�");
	printf("\n������˵���ţ�");
	while (buff = getchar())
		if (buff <= '4'&&buff >= '1')
		{
			return buff;
		}
}
void EnterData(headtype* head)  //������Ϣ
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
		printf("�������к�(0-99):");
		scanf_s("%d", &line, 100);
		if (line < 0 || line >= MAX)
		{
			printf("��������к�����\n");
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
			printf("����������\n");
			scanf_s("%s", buff, 100);
			do
			{
				if (j > 80 * m - 1)  //��һ���ڵ㲻��ʱ��������һ���ڵ�
				{
					m++;
					p->next = (link)malloc(sizeof(nodetype));
					p = p->next;
				}
				p->data[j % 80] = buff[j];  //�������������ݶ���
				j++;
			} while (buff[j] != '\0');
			p->next = NULL;
			head[i].len = j;
		}
		printf("����Y�������룬����Nֹͣ����");
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
	printf("����������:");
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
			printf("\n��%d�У�", i);
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