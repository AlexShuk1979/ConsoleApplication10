// example.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<conio.h>
struct Data
{
	char* firstName;
	char* patronymic;
	char* lastName;
	int dd, mm, yy, accNum, summa;
};

struct MyStruct
{
	Data* data;
	int count;
};
Data createData(char *v1,char *v2,char *v3,int d,int m,int y, int a, int s)
{
	Data c;
	c.firstName = (char*)malloc(strlen(v1) + 1);
	strcpy(c.firstName, v1);
	c.patronymic = (char*)malloc(strlen(v2) + 1);
	strcpy(c.patronymic, v2);
	c.lastName = (char*)malloc(strlen(v3) + 1);
	strcpy(c.lastName, v3);
	c.dd = d;
	c.mm = m;
	c.yy = y;
	c.accNum = a;
	c.summa = s;
	return c;
}


MyStruct init()
{
	return{ NULL,0 };
}
char* inChar()
{
	char *q;
	printf("введите данные: ");
	char p[15];
	scanf("%s", &p);
	q = (char*)malloc(strlen(p) + 1);
	strcpy(q, p);
	return q;
}
int inDig()
{
	int d;
	scanf("%d", &d);
	return d;
}

void addS(MyStruct* m, Data f)
{
	m->data = (Data*)realloc(m->data, (m->count + 1) * sizeof(f));
	m->data[m->count] = f;
	m->count++;

}
void deleteS(Data c)
{
	free(c.firstName);
	free(c.lastName);
	free(c.patronymic);

}

void removeS(MyStruct* a, int i)
{
	if (i<0 || i>a->count)
	{
		return;
	}
	if (a->count == 0)
	{
		return;
	}
	deleteS(a->data[i]);
	for (int j = i; j < a->count - 1; j++)
		a->data[j] = a->data[j + 1];

	a->count--;
}
void showContact(Data c)
{
	printf("%12s       %14s         %15s    %2d  %2d  %4d  %11d  %10d\n", c.firstName, c.patronymic, c.lastName, c.dd, c.mm, c.yy, c.accNum, c.summa);

}
void showContacts(MyStruct c)
{
	if (c.count == 0)
	{
		printf("Нет записей!\n");
		return;
	}
	for (int i = 0; i < c.count; i++)
	{
		printf("%d. ", i + 1);
		showContact(c.data[i]);
	}
}
Data* findMinStud(Data*S, int count)
{
	int min = 0;

	for (int i = 1; i < count; i++)
	{
		/*if (strcmp(S[i].n, S[min].n) < 0)
			min = i;*/
		if (S[i].mm< S[min].mm)
			min = i;
	}
	return &S[min];
}
void sortPik(MyStruct* cc)
{
	if (cc->count == 0)
	{
		return;
	}
	Data* cs = cc->data;
	int n = cc->count;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Data* min = findMinStud(cs + i, n - i);
			Data tmp = cs[i];
			cs[i] = *min;
			*min = tmp;
		}
	}
}
void userAdd(MyStruct* c)
{
	int n, x=3, s=5;
	addS(c, createData(inChar(), inChar(),inChar(),x,s,x, x, s));
}

void modeS(MyStruct* c,int n)
{
	if (c->count == 0)
	{
		return;
	}
char w;
Data* q = c->data;
	system("cls");
	printf("\n%d. ", n+1);
	showContact(q[n]);
	printf("\n___________________________________________________________________________________\n");

	int  d=(q+n)->dd, m=(q+n)->mm, y=(q+n)->yy, an=(q+n)->accNum, sum=(q+n)->summa;
	char* f = { (q+n)->firstName }, *l= { (q+n)->patronymic }, *p = { (q+n)->lastName },v1[15];


	printf("\nвыберите номер изменяемого поля:\n1-фамилия\n2-имя\n3-отчество\n4-число\n5-месяц\n6-год\n7-номер счета\n8-сумма\n");
	w=_getch();
	switch (w)
	{
	case'1':
		printf("введите фамилию\n");
		scanf("%s",&v1);
		f = (char*)malloc(strlen(v1) + 1);
		strcpy(f, v1);
		break;
	case'2':
		printf("введите имя\n");
		scanf("%s",&v1);
		l = (char*)malloc(strlen(v1) + 1);
		strcpy(l, v1);
		break;
	case'3':
		printf("введите отчество\n");
		scanf("%s", &v1);
		p = (char*)malloc(strlen(v1) + 1);
		strcpy(p, v1);
		break;
	case'7':
		printf("введите номер счета\n");
		scanf("%d", &an);
		break;
	case'8':
		printf("введите сумму\n");
		scanf("%d", &sum);
		break;
	case'4':
		printf("введите день\n");
		scanf("%d", &d);
		break;
	case'5':
		printf("введите месяц\n");
		scanf("%d", &m);
		break;
	case'6':
		printf("введите год\n");
		scanf("%d", &y);
		break;
	default:
		printf("Такого поля не существует!");
		break;
	}
	q[n] = createData(f, l, p,d,m,y,an,sum);
}
void findF(MyStruct c,int n)
{
	if (c.count == 0)
	{
		printf("Нет записей!\n");
		return;
	}
	Data *q = c.data;
	for (int i = 0; i < c.count; i++)
		if (q[i].dd == 0)
		{
			printf("%d. ", i + 1);

			showContact(q[i]);
		}

}
int main()
{
	setlocale(LC_ALL, "Russian");
	MyStruct cc = init();
	addS(&cc, createData("Petrov", "Ruslan", "Fedorovich", NULL, 05, 2018, 2455245, 22500));
	addS(&cc, createData("Egorova", "Dina", "Vital'evna", 21, 10, 2017, 8686886, 50400));
	addS(&cc, createData("Voronin", "Il'ya", "Aleksandrovich", 10, 03, 1978, 45675432, 20500));
	addS(&cc, createData("Kasakov", "Andrey", "Andreevich", 03, 07, 2018, 2455245, 15600));
	showContacts(cc);

	char key;
	do {
		printf("\n\n0-выход\n1-добавление записи\n2-сортировка\n3-вывод на экран\n4-удаление записи\n5-редактирование записи\n6-поиск пустого поля");
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
			printf("\nвведите номер удаляемой записи \n");
			int n;
			scanf("%d", &n);
			n = n - 1;
			if (n>=0&&n < cc.count)
				removeS(&cc, n);
			else
				printf("Такой записи не существует\n");
			showContacts(cc);
			break;
		case'5':
			system("cls");
			printf("\nвведите номер изменяемой записи: ");
			int k;
			scanf("%d", &k);
			k = k - 1;
			if (k>=0 && k < cc.count)
				modeS(&cc,k);
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

