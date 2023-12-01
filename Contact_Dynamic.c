#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact_Dynamic.h"

void InitContact(struct Contact* ps)
{
	struct PeoInfo* ptr = (PeoInfo*)malloc(sizeof(PeoInfo)*3);
	if (ptr != NULL)
	{
		ps->data = ptr;
	}
	ps->capacity = 3;
	ps->size = 0;
}
static void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(ps->data,(ps->capacity+2)* sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
		}
	}
}
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);
	printf("ENTER NAME:>");
	scanf("%s",ps->data[ps->size].name);
	printf("ENTER AGE:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("ENTER SEX:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("ENTER TELE:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("ENTER ADDR:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("SUCCESSFULLY\n");
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("THE CONTACT IT EMPTY\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","NAME","AGE","SEX","TELE","ADDR");
		for (i=0;i<ps->size;i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}


static int FindByName(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("THE CONTACT IT EMPTY\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("ENTER NAME:>");
		scanf("%s",name);
		int pos=FindByName(ps,name);
		if (pos == -1)
		{
			printf("NOT EXIST\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < ps->size-1; j++)
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("DELETE SUCCESSFULLY\n");
		}
	}
}

void SearchContact(const struct Contact* ps)
{
	printf("ENTER NAME:>");
	char name[MAX_NAME];
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos == -1)
	{
		printf("NOT EXIST\n");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "NAME", "AGE", "SEX", "TELE", "ADDR");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	printf("ENTER NAME:>");
	char name[MAX_NAME];
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos == -1)
	{
		printf("NOT EXIST\n");
	}
	else
	{
		printf("ENTER NAME:>");
		scanf("%s", ps->data[pos].name);
		printf("ENTER AGE:>");
		scanf("%d", &(ps->data[pos].age));
		printf("ENTER SEX:>");
		scanf("%s", ps->data[pos].sex);
		printf("ENTER TELE:>");
		scanf("%s", ps->data[pos].tele);
		printf("ENTER ADDR:>");
		scanf("%s", ps->data[pos].addr);
		printf("SUCCESSFULLY\n");
	}
}
void SortContact(struct Contact* ps)
{
	int i = 0;
	int j = 0;
	for (i=0;i<ps->size-1;i++)
	{
		int flag = 1;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->data[j].age > ps->data[j + 1].age)
			{
				struct PeoInfo tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	printf("SUCCESSFULLY\n");
}

void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
