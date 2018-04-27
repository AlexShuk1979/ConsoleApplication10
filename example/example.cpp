// example.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<conio.h>
struct F
{
	char* n;
};
struct D
{
	int d;
};
struct MyStruct
{
	F* f;
	D* d;
	int count;
};
F createF(char *v)
{
	F c;
	c.n = (char*)malloc(strlen(v) + 1);
	strcpy(c.n, v);
	return c;
}
D createD(int v)
{
	D c;
	c.d = v;
	return c;
}

MyStruct init()
{
	return{ NULL,NULL,0 };
}
void addS(MyStruct* m, F f, D d)
{
	m->f = (F*)realloc(m->f, (m->count + 1) * sizeof(f));
	m->d = (D*)realloc(m->d, (m->count + 1) * sizeof(d));

	m->f[m->count] = f;
	m->d[m->count] = d;

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
	deleteS(a->f[i]);
	for (int j = i; j < a->count - 1; j++)
		a->f[j] = a->f[j + 1];

	a->count--;
}
void showContact(F c, D d)
{
	printf("%12s     %10d\n", c.n, d.d);

}
void showContacts(MyStruct c)
{
	for (int i = 0; i < c.count; i++)
	{
		printf("%d. ", i + 1);
		showContact(c.f[i], c.d[i]);
	}
}
F* findMinStud(F*S, int count)
{
	int min = 0;

	for (int i = 1; i < count; i++)
	{
		if (strcmp(S[i].n, S[min].n) < 0)
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
int main()
{
	MyStruct cc= init();
	addS(&cc, createF("dasf"), createD(100));
	showContacts(cc);
	addS(&cc, createF("qwe"), createD(600));
	showContacts(cc);
	removeS(&cc, 0);
	showContacts(cc);
	addS(&cc, createF("qe"), createD(630));
	addS(&cc, createF("adqwe"), createD(6));
	showContacts(cc);

	sortPik(&cc);
	showContacts(cc);
	return 0;
}

