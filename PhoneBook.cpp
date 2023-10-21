#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define SIZE 100
typedef struct data{
	char name[8];
	char number[15];
} Book;

Book book [SIZE];
int last;

void sort();
void swap(Book*, Book*);
int select(char[]);
void read();
void write();
void add();
void display();
void search();

void sort()
{
	int min;
		for(int i = 0; i < last-1; i++)
		{
			min = i;
			for(int j = i+1; j < last; j++)
			{
				if(strcmp(book[j].name, book[min].name) < 0)
				{
					min = j;
				}
			}
			swap (&book[min], &book[i]);
		}
}

void swap(Book *first, Book *second)
{
	Book temp = *first;
	*first = *second;
	*second = temp;
}

void read()
{
	FILE *file;
	file = fopen("data.txt", "r");
		if(file == NULL)
		{
			strcpy(book[0].name, "Null");
			strcpy(book[0].number, "Null");
		}
		else
		{
			int i = 0;
				while(!feof(file))
				{
					fscanf(file, "%s %s\n", book[i].name, book[i].number);
					i++;
				}
				last = i;
		}
		fclose(file);
}

void write()
{
	FILE *fp;
	fp = fopen("data.txt", "w");
		if(fp == NULL)
		{
			printf("Data cannot be saved.\n");
			return;
		}
		else
		{
			for(int i = 0; i <= last; i++)
			{
				fprintf(fp, "%s %s\n", book[i].name, book[i].number);
			}
		}
		fclose(fp);
}	

int select(char key[])
{
	int mid = 0;
	int l = 0;
	int r = last - 1;
		while(l <= r)
		{
			mid = (l + r) / 2;
				if(strcmp(book[mid].name, key) > 0)
				{
					r = mid - 1;
				}
				else if(strcmp(book[mid].name, key) < 0)
				{
					l = mid + 1;
				}
				else
				{
					return mid;
				}		
		}
		return -1;
}

void add()
{
	system("cls");
	char name[8];
	char num[15];
	printf("ADD A DATA\n");
	printf("==========\n");
	printf("\n");
	printf("Name	: "); scanf("%s", name);
	printf("Number	: "); scanf("%s", num);
	
		if(last == SIZE-1)
		{
			printf("Phone Book is full. Press ENTER key to continue.\n");
			getch();
		}
		else
		{
			strcpy(book[last].name, name);
			strcpy(book[last].number, num);
			last++;
			printf("Data has been added. Press ENTER key to continue.\n");
			getch();
		}
}


void display()
{
	system("cls");
	sort();
	printf("NAME\tPHONE NUMBER\n");
		for(int i = 0; i < last; i++)
		{
			printf("%s\t%s\n", book[i].name, book[i].number);
		}
		printf("Press ENTER key to continue.\n");
		getch();
}

void search()
{
	system("cls");
	char name[8];
	printf("SEARCH FOR A PHONE NUMBER\n");
	printf("=========================\n");
	printf("\n");
	printf("Enter a name: "); scanf("%s", name);
	
	int in = select(name);
		if(in != -1)
		{
			printf("%s : %s\n", book[in].name, book[in].number);
		}
		else
		{
			printf("%s is not on the phone book.", name);
		}
		printf("Press ENTER key to continue.\n");
		getch();
}

int main()
{
	last = 0;
	int opt = -1;
	read();
		while(opt != 4)
		{
			system("cls");
			printf("DIGITAL PHONE BOOK\n");
			printf("==================\n");
			printf("\n");
			printf("1. Add a number.\n");
			printf("2. Search a number.\n");
			printf("3. Display all numbers.\n");
			printf("4. Exit program.\n");
			printf("Select an option: "); scanf("%d", &opt);
			
			switch(opt)
			{
				case 1:
					add();
					break;
				case 2:
					search();
					break;
				case 3: 
					display();
					break;
				case 4:
					break;
				default:
					printf("Please input a valid option.\n");
					getch();
					break;
			}
		}
		write();
	return 0;	
}
