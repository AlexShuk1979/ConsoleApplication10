// TestStruct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<conio.h>



struct Date
{
	int dd, mm, yy,accNum, summa;
};

struct FIO
{
	char*firstName;
	char* value;
	char* lastName;
};

struct Contacts
{
	FIO* contactsC;
	Date* date;
	int count;
};





FIO createContact(char*, char*, char* value);
FIO createDefaultContact();
void showContact(FIO c, Date d);
void deleteContact(FIO c);
void showContacts(Contacts c);
void addContact(Contacts* cc, FIO, Date);
void removeContact(Contacts* contactsC, int i);
void sortPik(Contacts cc);
Contacts createContacts();
Date createDate(int, int, int,int,int);
void userAdd(Contacts);

void main()
{
	setlocale(LC_ALL, "Russian");
	Contacts cc = createContacts();
	addContact(&cc, createContact("Petrov", "Ruslan", "Fedorovich"), createDate(10, 05, 2018,2455245, 22500));
	addContact(&cc, createContact("Egorova", "Dina", "Vital'evna"), createDate(21, 10, 2017,8686886, 50400));
	addContact(&cc, createContact("Voronin", "Il'ya", "Aleksandrovich"), createDate(10, 03, 1978,45675432, 20500));
	addContact(&cc, createContact("Kasakov", "Andrey", "Andreevich"), createDate(12, 02, 2005,2455245, 2500));
	addContact(&cc, createContact("Anisimova", "Tatyana", "Ivanovna"), createDate(03, 07, 2018,2455245, 15600));
	addContact(&cc, createContact("Ivanov", "Petr", "Egorovich"), createDate(20, 12, 2005,66586, 154506));
	showContacts(cc);
	char w;
	do
	{
		printf("0-выход\n1-добавление записи\n2-сортировка\n3-вывод на экран\n4-удаление записи\n5-редактирование записи\n6-поиск пустого поля");
		w = _getch();
		/*char f[15], i[15], o[15];
			int an, sum, d, m, y;*/
		switch (w)
		{
			
			system("cls");
		case '1':

			/*printf("добавление записи\n");
			printf("введите фамилию\n");
			gets(f);
			printf("введите имя\n");
			gets(i);
			printf("введите отчество\n");
			gets(o);
			printf("введите номер счета\n");
			scanf("%d", &an);
			printf("введите сумму\n");
			scanf("%d", &sum);
			printf("введите день\n");
			scanf("%d", &d);
			printf("введите месяц\n");
			scanf("%d", &m);
			printf("введите год\n");
			scanf("%d", &y);

			addContact(&cc, createContact(f, i, o), createDate(d, m, y,an, sum));*/
			userAdd(cc);
			system("cls");
			showContacts(cc);

			break;
		case '2':
			system("cls");
			sortPik(cc);
			showContacts(cc); break;
		case '3':
			system("cls");
			showContacts(cc); break;
		case '4':
			system("cls");
			showContacts(cc);
			printf("введите номер удаляемой записи \n");
			int num;
			scanf("%d", &num);
			if (num - 1 < cc.count)
				removeContact(&cc, num - 1);
			showContacts(cc); break;
		case '5':
			printf("\nвведите номер изменяемой записи \n");
			/*int n;
			scanf("%d", &n);
			n = n - 1;
			if (n  < cc.count)
				showContact(cc.contactsC[n], cc.date[n ]);
			gets(f);
			printf("введите фамилию\n");
			gets(f);
			printf("введите имя\n");
			gets(i);
			printf("введите отчество\n");
			gets(o);
			printf("введите номер счета\n");
			scanf("%d", &an);
			printf("введите сумму\n");
			scanf("%d", &sum);
			printf("введите день\n");
			scanf("%d", &d);
			printf("введите месяц\n");
			scanf("%d", &m);
			printf("введите год\n");
			scanf("%d", &y);

			cc.contactsC[n] = createContact(f, i, o);
			cc.date[n] = createDate(d, m, y,an, sum);
			system("cls");*/
			showContacts(cc);
		case 6: break;

		}
	} while (w != '0');

}

FIO createContact(char* q, char* s, char* value)
{
	FIO c;
	c.firstName = (char*)malloc(strlen(q) + 1);
	strcpy(c.firstName, q);
	c.lastName = (char*)malloc(strlen(s) + 1);
	strcpy(c.lastName, s);
	c.value = (char*)malloc(strlen(value) + 1);
	strcpy(c.value, value);
	return c;
}

void userAdd(Contacts cc)
{
	char f[15], i[15], o[15];
	int an, sum, d, m, y;
	printf("добавление записи\n");
	printf("введите фамилию\n");
	gets(f);
	printf("введите имя\n");
	gets(i);
	printf("введите отчество\n");
	gets(o);
	printf("введите номер счета\n");
	scanf("%d", &an);
	printf("введите сумму\n");
	scanf("%d", &sum);
	printf("введите день\n");
	scanf("%d", &d);
	printf("введите месяц\n");
	scanf("%d", &m);
	printf("введите год\n");
	scanf("%d", &y);

	addContact(&cc, createContact(f, i, o), createDate(d, m, y, an, sum));
}
Date createDate(int a, int b, int z,int accNum, int sum)
{
	Date d;
	d.dd = a;
	d.mm = b;
	d.yy = z;
	d.accNum = accNum;
	d.summa = sum;
	return d;
}




void showContact(FIO c,Date d)
{
	printf( "%12s       %10s         %15s    %2d  %2d  %4d  %11d  %10d\n", c.firstName, c.lastName, c.value, d.dd, d.mm, d.yy,d.accNum,d.summa);

}


void deleteContact(FIO c)
{
	free(c.value);
}

void showContacts(Contacts c)
{
	printf("№       Фамилия:            Имя:               Отчество:   День Месяц Год Номер счета  Сумма\n");
	for (int i = 0; i < c.count; i++)
	{
		printf("%d. ", i + 1);
		showContact(c.contactsC[i],c.date[i]);
	}
}

void addContact(Contacts* cc, FIO contact, Date date)
{
	cc->contactsC = (FIO*)realloc(cc->contactsC, (cc->count + 1) * sizeof(contact));
	cc->date = (Date*)realloc(cc->date, (cc->count + 1) * sizeof(date));

	cc->contactsC[cc->count] = contact;
	cc->date[cc->count] = date;

	cc->count++;

}

void removeContact(Contacts* conC, int i)
{
	if (i<0 || i>conC->count)
	{
		return;
	}
	deleteContact(conC->contactsC[i]);
	for (int j = i; j < conC->count - 1; j++)		
		conC->contactsC[j] = conC->contactsC[j + 1];
		
	conC->count--;
}

void sortPik(Contacts cc)
{
	FIO* cs = cc.contactsC;
	int n = cc.count;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(cs[j].firstName, cs[min].firstName) < 0)
				min = j;
		}
		char* p = cs[i].firstName;
		cs[i].firstName = cs[min].firstName;
		cs[min].firstName = p;
	}
}

Contacts createContacts()
{
	return{ NULL, 0, 0 };
}