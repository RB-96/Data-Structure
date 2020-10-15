#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node{
	int coeff, pow;

};
node poly[50], poly1[50], poly2[50];
int n1, n2,k;

void create_poly()
{
	printf("\nEnter the number of terms in 1st Polynomial: ");
	scanf("%d", &n1);
	printf("\nEnter the number of terms in 2st Polynomial: ");
	scanf("%d", &n2);
	printf("\n\nEnter the 1st polynomial:\n");
	for(int i=0;i<n1;i++)
	{
		printf("\nEnter co-efficient %d: ", i+1);
		scanf("%d", &poly1[i].coeff);
		printf("\nEnter exponent  %d: ",i+1);
		scanf("%d", &poly1[i].pow);
	}
	printf("\n\nEnter the 2nd polynomial:\n");
	for(int i=0;i<n2;i++)
	{
		printf("\nEnter co-efficient  %d: ",i+1);
		scanf("%d", &poly2[i].coeff);
		printf("\nEnter exponent  %d: ",i+1);
		scanf("%d", &poly2[i].pow);
	}
	
}
void show_poly(node p[], int n)
{
	int i =0;
	while(i < n-1)
	{
		printf("%dX^%d", p[i].coeff, p[i].pow);
		i++;
		printf("+");
		
	}
	printf("%dX^%d", p[n-1].coeff, p[n-1].pow);
}

void mult_poly(node p1[], node p2[])
{
	int m1 = n1;
	int m2 = n2;
	int k=0;
	if(m1>0 && m2>0)
	{
		for(int i =0; i<m1;i++)
		{
			for(int j=0;j<m2; j++)
			{
				poly[k].coeff = p1[i].coeff * p2[j].coeff;
				poly[k].pow = p1[i].pow + p2[j].pow;
				k++;	
			}
		}
	}
	int c = poly[k-1].coeff;
	int p = poly[k-1].pow;
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(poly[i].pow == poly[j].pow)
			{
				poly[i].coeff = poly[i].coeff + poly[j].coeff;
				for(int h=j;h<k;h++)
				{
					poly[h].coeff = poly[h+1].coeff;
					poly[h].pow = poly[h+1].pow;
					--k;
				}
			}
		}
	}
	printf("\nThe resultant polynomial is: ");
	printf("%d X^%d", poly[0].coeff, poly[0].pow);
	for(int i=1; i<k; i++)
	{
		printf("+ %d ", poly[i].coeff);
		printf("X^%d", poly[i].pow);
	}
	printf("+%d X^%d", c, p);
}


int main()
{
	create_poly();
	printf("\n\n");
	show_poly(poly1, n1);
	printf("\n\n");
	show_poly(poly2,n2);
	printf("\n\n");
	mult_poly(poly1, poly2);
	return 0;
}
