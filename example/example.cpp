// example.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<conio.h>
struct F
{
	char* n;
	int d,m;
};

struct MyStruct
{
	F* f;
	int count;
};
F createF(char *v,int a,int b)
{
	F c;
	c.n = (char*)malloc(strlen(v) + 1);
	strcpy(c.n, v);
	c.d = a;
	c.m = b;
	return c;
}


MyStruct init()
{
	return{ NULL,0 };
}
void addS(MyStruct* m, F f)
{
	m->f = (F*)realloc(m->f, (m->count + 1) * sizeof(f));

	m->f[m->count] = f;

	m->count++;

}
void deleteS(F c)
{
	free(c.n);

}

void removeS(MyStruct* a, int i)
{
	if (i<0 || i>a->count)
	{
		return;
	}
	if (a->count == 0)
		return;
	deleteS(a->f[i]);
	for (int j = i; j < a->count - 1; j++)
		a->f[j] = a->f[j + 1];

	a->count--;
}
void showContact(F c)
{
	printf("%12s     %10d %3d\n", c.n, c.d, c.m);

}
void showContacts(MyStruct c)
{
	for (int i = 0; i < c.count; i++)
	{
		printf("%d. ", i + 1);
		showContact(c.f[i]);
	}
}
F* findMinStud(F*S, int count)
{
	int min = 0;

	for (int i = 1; i < count; i++)
	{
		/*if (strcmp(S[i].n, S[min].n) < 0)
			min = i;*/
		if (S[i].m< S[min].m)
			min = i;
	}
	return &S[min];
}
void sortPik(MyStruct* cc)
{
	F* cs = cc->f;
	int n = cc->count;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			F* min = findMinStud(cs + i, n - i);
			F tmp = cs[i];
			cs[i] = *min;
			*min = tmp;
		}
	}
}
void userAdd(MyStruct* c)
{
	int n, x, s;
	F* q = c->f;
	char p[15];
	scanf("%s", &p);
	scanf("%d", &x);
	scanf("%d", &s);
	addS(c, createF(p, x, s));
}

void modeS(MyStruct* c)
{
	printf("\n������� ����� ���������� ������ \n");
	int n,x,s;
	F* q = c->f;
	char p[15];
	scanf("%d", &n);
	n = n - 1;
	if (n  < c->count)
		showContact(q[n]);
	scanf("%s", &p);
	scanf("%d", &x);
	scanf("%d", &s);


	q[n] = createF(p, x, s);
}
void findF(MyStruct c,int n)
{
	F *q = c.f;
	for (int i = 0; i < c.count; i++)
		if (q[i].d == 0)
		{
			printf("%d. ", i + 1);

			showContact(q[i]);
		}

}
int main()
{
	setlocale(LC_ALL, "Russian");
	MyStruct cc = init();
//	
	addS(&cc, createF("", NULL,30));
	addS(&cc, createF("",0,33));
	addS(&cc, createF("ce", 330,525));
	addS(&cc, createF("adqwe", 6,5));
	showContacts(cc);

	char key;
	do {
		printf("0-�����\n1-���������� ������\n2-����������\n3-����� �� �����\n4-�������� ������\n5-�������������� ������\n6-����� ������� ����");
		key = _getch();
		switch (key)
		{
			
		case'1':
			system("cls");
			userAdd(&cc);
			showContacts(cc);
			break;
		case'2':
			system("cls");
			sortPik(&cc);	
			showContacts(cc);
			break;
		case'3':
			system("cls");
			showContacts(cc);
			break;
		case'4':
			system("cls");
			removeS(&cc, 0);
			showContacts(cc);
			break;
		case'5':
			system("cls");
			modeS(&cc);
			showContacts(cc);
			break;
		case'6':
			system("cls");
			findF(cc, 0);
			break;
		}
		} while (key != '0');
return 0;
 }

