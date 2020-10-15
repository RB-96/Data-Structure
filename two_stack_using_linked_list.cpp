#include<stdio.h>
#include<stdlib.h>
//#define MAX 5

typedef struct stack{
	int data;
	stack *next;
};
stack s[2];
stack *top1=NULL, *top2=NULL;
void push1(int val)
{
	if(top1!=NULL)
	{
		stack *temp = (stack*)malloc(sizeof(stack));
		temp->data = val;
		temp->next = top1;
		top1 = temp;
	}
	else if(top1 == NULL)
	{
		top1 = (stack *)malloc(sizeof(stack));
		top1->data = val;
		top1->next = NULL;
	}
	
}
void push2(int val)
{
	if(top2!=NULL)
	{
		stack *temp = (stack*)malloc(sizeof (stack));
		temp->data = val;
		temp->next = top2;
		top2 = temp;
	}
	else if(top2 == NULL)
	{
		top2 = (stack *)malloc(sizeof(stack));
		top2->data = val;
		top2->next = NULL;
	}
}
void pop1()
{
	if(top1 == NULL)
	{
		printf("\nStack 1 underflow");
	}
	else if(top1 != NULL)
	{
		stack *temp;
		temp = top1;
		top1 = top1->next;
		delete(temp);
	}
}
void pop2()
{
	if(top2 == NULL)
	{
		printf("\nStack 1 underflow");
	}
	else if(top2 != NULL)
	{
		stack *temp;
		temp = top2;
		top2 = top2->next;
		delete(temp);
	}
}
void display()
{
	printf("\nStack 1:\n");
	stack *ptr1=top1;
	if(top1 != NULL)
	{
		while(ptr1->next!=NULL)
		{
			printf("%d -> ", ptr1->data);
			ptr1 = ptr1->next;
		}
		printf("%d",ptr1->data);
	}
	else if(top1 == NULL)
	{
		printf("\nStack 1 Underflow");
	}
	
	printf("\nStack 2:\n");
	ptr1=top2;
	if(top2 != NULL)
	{
		while(ptr1->next!=NULL)
		{
			printf("%d -> ", ptr1->data);
			ptr1 = ptr1->next;
		}
		printf("%d",ptr1->data);
	}
	else if(top2 == NULL)
	{
		printf("\nStack 2 Underflow");
	}
}
int main()
{
	int ch;
	int val1, val2;
	while(1)
	{
		printf("\n1. Stack 1 push\n2. Stack 1 pop\n3. Stack 2 push\n4. Stack 2 pop\n");
		printf("5. Disaplay\n6. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\n Enter the number to be pushed on stack : ");
					scanf("%d",&val1);
					push1(val1);
					break;
			case 2: pop1();
					break;
			case 3: printf("\n Enter the number to be pushed on stack : ");
					scanf("%d",&val2);
					push2(val2);
					break;
			case 4: pop2();
					break;
			case 5: display();
					break;
			case 6: exit(0);	
		}
	}
	return 0;
}
