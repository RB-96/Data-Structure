#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	node *link;
};
node *start = NULL;
void show_list(node *head)
{
	if(!head)
	{
		printf("NULL");
	}
	else
	{
		printf("%d->",head->info);
		show_list(head->link);
	}
}
void insert(node *new_node)
{
	if(!start)
	{
		start = new_node;
	}
 	else if(new_node->info < start->info && start->link == NULL)
	{
		new_node->link = start;
		start = new_node;
	}
	else if(new_node->info > start->info && start->link == NULL)
	{
		new_node->link = start->link;
		start->link = new_node;
	}
	else 
	{
		node *ptr;
		ptr = start;
		while(ptr->link != NULL && ptr->link->info<new_node->info)
		{
			ptr = ptr->link;
		}
		new_node->link = ptr->link;
		ptr->link = new_node;
	}

}
void create_node()
{
	int data;
	printf("\nEnter the data to be inserted:");
	scanf("%d", &data);
	node *new_node = (node *)malloc(sizeof(node));
	new_node->info = data;
	new_node->link = NULL;
	insert(new_node);
}
void delete_node(int data)
{
	if(!start)
	{
		printf("\nEmpty list");
	}
	else if(start->link==NULL)
	{
		if (data == start->info)
			delete(start);
		else
			printf("\nData not present.");	
	}
	else if(data == start->info && start->link!=NULL)
	{
		node *temp;
		temp = start;
		start = start->link;
		delete(temp);
	}
	else 
	{
		node *ptr = start;
		int flag = 0;
		while(ptr->link->link != NULL)
		{
			if(data == ptr->link->info)
			{
				node *temp = ptr->link;
				ptr->link = ptr->link->link;
				delete(temp);
				
			}
			else if(data < ptr->link->info)
			{
				flag = 1;
				ptr=ptr->link;
			}
			else if(data > ptr->link->info)
			{
				ptr = ptr->link;
			}
		}
		if(flag = 1)
		{
			printf("\nData not found.");
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.INSERT INTO LIST\n2.DELETE FROM LIST\n3.DISPLAY\n4.EXIT\n\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: create_node();
					break;
			case 2: int n;
					printf("\nEnter the data to be deleted: ");
					scanf("%d", &n);
					delete_node(n);
					break;
			case 3: printf("\n");
					show_list(start);
					printf("\n");
					break;
			case 4: exit(0);
		}	
	}
	
}
