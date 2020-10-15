#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct stack{
	int data;
	stack *next;
}stack;
stack *top[MAX];
void push(int i, int item)
{
	stack *temp = (stack *)malloc(sizeof(stack));
	temp->data = item;
	temp->next = top[i];
	top[i]=temp;
}
int pop(int i)
{
	if(top[i]->next==NULL)
	{
		printf("\nStack Underflow");
	}
	else if(top[i]->next != NULL)
	{
		stack *temp;
		int item;
		temp = top[i];
		item = top[i]->data;
		top[i]= top[i]->next;
		free(temp);
		return(item);
	}
	
}
void display(int i)
{
	printf("\n");
	if(top[i]->next == NULL)
	{
		printf("\nEmpty stack\n");
	}
	else if(top[i]->next != NULL)
	{
		stack *ptr = top[i];
		while(ptr->next->next != NULL)
		{
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("%d",ptr->data);
	}
}

int main()
{
	int n;
	printf("\nHow many stack you want to handle? ");
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		top[i] = (stack *)malloc(sizeof(stack));
		top[i]->next = NULL;
		top[i]->data = -1;
	}
	while(1)
	{
		int  ch;
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: {
					printf("Enter <stack , Element>:  ");
					int i;
					int item;
					scanf("%d %d", &i, &item);
					push(i,item);
					break;
					}
				
			case 2: {
					printf("\nEnter Stack number: ");
					int j;
					scanf("%d",&j);
					int e = pop(j);
					printf("\nPoped item is: %d", e);
					break;
					}
			
			case 3: {
					printf("\nEnter Stack number: ");
					int k;
					scanf("%d", &k);
					display(k);
					break;
					}
			case 4: exit(0);
		}
	}
	return 0;
}
