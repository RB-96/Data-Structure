#include<stdio.h>
# define MAX 50
typedef struct term{
	int row;
	int col;
	int value;
}term;
term a[MAX], b[MAX];

void read_sparse()
{
	int n;
	printf("Enter the numbers of rows: ");
	scanf("%d", &a[0].row);
	printf("\nEnter the numbers of columns: ");
	scanf("%d", &a[0].col);
	printf("\nEnter the numbers of nonzero terms: ");
	scanf("%d", &n);
	printf("\nEnter elements in <row, column, value> fashion\n\n");
	a[0].value = n;
	for(int i=1;i<=n;i++)
	{
		printf("\nEnter %dth <row, vol, value> 3tuples: ", i);
		scanf("%d %d %d", &a[i].row,&a[i].col, &a[i].value );
	}
}
void show_sparse(term c[])
{
	printf("\nThe Sparse matris is: \n");
	printf("ROW     COLUMN    VALUE");
	for(int i=0;i<=c[0].value;i++)
	{
		printf("\n%d    %d     %d", c[i].row, c[i].col, c[i].value);
	
	}
}
void fast_transpose(term a[])
{
	int m,n,t,i,col_num,location; 
	int total_index[MAX]; 
    m=a[0].row;
	n=a[0].col;
	t=a[0].value; 
    b[0].row=n;
	b[0].col=m;
	b[0].value=t;
	int p = t+1; 
    for(i=0;i<n;i++) 
        total_index[i]=0; 
    for(i=1;i<=t;i++) 
    { 
        col_num=a[i].col; 
        total_index[col_num]++; 
    } 
    total_index[p]=1; 
    for(i=1;i<n;i++) 
        total_index[p+i]=total_index[p+i-1]+total_index[i-1]; 

    for(i=1;i<=t;i++) 
    { 
        col_num=a[i].col; 
        location=total_index[p+col_num]; 
        total_index[p+col_num]++; 
        b[location].row=a[i].col; 
        b[location].col=a[i].row; 
        b[location].value=a[i].value; 
    } 
}
main()
{
	read_sparse();
	show_sparse(a);
	fast_transpose(a);
	show_sparse(b);
}
