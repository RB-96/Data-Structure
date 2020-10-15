#include<stdio.h>
#include<malloc.h>
#include<conio.h>

typedef struct polynomial
{
	int pow;
	int coeff;
	polynomial *next;
}polynom;
polynom *poly, *poly1, *poly2;
void create(polynom *node)
{
	char ch;
	do
	{
		printf("\nenter coefficient: ");
		scanf("%d", &node -> coeff);
		printf("\nenter power: ");
		scanf("%d", &node -> pow );
		node -> next = (polynom *)malloc(sizeof(polynom));
		node = node -> next;
		node -> next = NULL;
		printf("\n\tcontinue:(y / n)");
		ch = getch();
	}while(ch == 'y' || ch == 'Y');
}

void show(polynom *node)
{
	while(node -> next != NULL)
	{
		printf("%dX^%d", node -> coeff, node -> pow);
		node = node -> next;
		if(node -> next != NULL)
		{
			printf("+");
		}
	}
}

void addpoly(polynom *poly1, polynom *poly2, polynom *poly)
{
	while(poly1 -> next && poly2 -> next)
	{
		if(poly1 -> pow > poly2 -> pow)
		{
			poly -> coeff = poly1 -> coeff;
			poly -> pow = poly1 -> pow;
			poly1 = poly1 -> next;
		}
		else if(poly2 -> pow > poly1 -> pow)
		{
			poly -> coeff = poly2 -> coeff;
			poly -> pow = poly2 -> pow;
			poly2 = poly2 -> next;
		}
		else
		{
			poly -> coeff = poly1 -> coeff + poly2 -> coeff;
			poly -> pow = poly1 -> pow;
			poly1 = poly1 -> next;
			poly2 = poly2 -> next;
		}
		poly -> next = (polynom *)malloc(sizeof(polynom));
		poly = poly -> next;
		poly -> next = NULL;
	}
	while (poly1 -> next || poly2 -> next)
	{
		if(poly1 -> next)
		{
			poly -> coeff = poly1 -> coeff;
			poly -> pow = poly1 -> pow;
			poly1 = poly1 -> next;
		}
		if(poly2 -> next)
		{
			poly -> coeff = poly2 -> coeff;
			poly -> pow = poly2 -> pow;
			poly2 = poly2 -> next;
		}
		poly -> next = (polynom *)malloc(sizeof(polynom));
		poly = poly -> next;
		poly -> next = NULL;
	}
}


int main()
{
	char ch;
	do
	{
		poly = (polynom *)malloc(sizeof(polynom));
		poly1 = (polynom *)malloc(sizeof(polynom));
		poly2 = (polynom *)malloc(sizeof(polynom));
		printf("\nEnter the 1st polynomial: ");
		create(poly1);
		printf("\nEnter the second polynomial: ");
		create(poly2);
		printf("\n1st polynomial: ");
		show(poly1);
		printf("\n2nd polynomial: ");
		show(poly2);
		addpoly(poly1, poly2, poly);
		printf("\nAdded polynomial: ");
		show(poly);
		printf("\nAnother two polynomial want to insert? (y / n): ");
		ch = getch();
	}while(ch == 'Y' || ch == 'y');
	
	return 0;
}
