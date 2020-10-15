#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int coeff, exp;
	node *next;
} ;
node *eqn1 = NULL, *eqn2 = NULL, *eqn3 = NULL;

void dispPoly(node *start) 
{
	if(!start) 
	{
		printf("Empty list\n\n");
		return;
	}
	node *temp = start;
	
	int i;
	for(i = 1; temp->next; i++) 
	{
		printf("%dX^%d + ",temp->coeff, temp->exp);
		temp = temp->next;
	}
	
	printf("%dX^%d ",temp->coeff, temp->exp);

}
node *insNode(node *start, int a, int b) 
{
	node *head = (node*)malloc(sizeof(node));
	head->coeff = a;
	head->exp = b;
	if(start) 
	{
		node *temp = start;
		while(temp->next) 
		{
			temp = temp->next;
		}
		temp->next = head;
	}
	else 
	{
		start = head;
	}
	return start;
}
node *getPoly(node *start) 
{
	int a, b, i, n;
	printf("Enter number of terms in equation: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++) 
	{
		printf("\nTerm %d\nCoefficient: ", i);
		scanf("%d", &a);
		printf("Exponent: ");
		scanf("%d", &b);
		start = insNode(start, a, b);
	}
	printf("Entered polynomial is  ");
	dispPoly(start);
	printf("\n");
	return start;
}
void mulPoly() 
{
	if(!eqn1 || !eqn2) 
	{
		printf("0\n");
	}
	else 
	{
		node *temp = eqn1, *temp2, *prev;
		while(temp) 
		{
			temp2 = eqn2;
			while(temp2) 
			{
				eqn3 = insNode(eqn3, (temp->coeff * temp2->coeff), (temp->exp + temp2->exp));
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp = eqn3;
		while(temp) 
		{
			temp2 = temp->next;
			prev = temp;
			while(temp2) 
			{
				if(temp->exp == temp2->exp) 
				{
					temp->coeff += temp2->coeff;
					prev->next = temp2->next;
				}
				temp2 = temp2->next;
				prev = prev->next;
			}
			temp = temp->next;
		}
		dispPoly(eqn3);
	}
}

main() 
{
	int ch;
	printf("Enter polynomial 1: \n");
	eqn1 = getPoly(eqn1);
	printf("Enter polynomial 2: \n");
	eqn2 = getPoly(eqn2);
	printf("\n\nResult of polynomial multiplication is : ");
	mulPoly();
	printf("\n");
}
