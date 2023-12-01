#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact_Dynamic.h"
void menu()
{
	printf("*********************************\n");
	printf("*******1.add          2.del******\n");
	printf("*******3.search       4.modify***\n");
	printf("*******5.show         6.sort*****\n");
	printf("*******0.exit              ******\n");
	printf("*********************************\n");
}
void test()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);

	do
	{
		menu();
		printf("PLEASE ENTER:>");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			printf("EXIT\n");
			break;
		default:
			printf("ERROR SELECT\n");
			break;
		}

	} while (input);
	
}
int main()
{
	test();
	return 0;
}
