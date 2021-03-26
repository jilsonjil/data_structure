#include<stdio.h>
#include<stdlib.h>
struct bit
	{
	unsigned char x:1;
	};
int uset []={1,2,3,4,5,6,7,8,9};
int size=9;
void main()
	{
	void readset(struct bit[],int n);
	void printset(struct bit[]);
	void unionset(struct bit[],struct bit[],struct bit[]);
	void intersect(struct bit[],struct bit[],struct bit[]);
	void difference(struct bit[],struct bit[],struct bit[]);
	struct bit a[9]={0},b[9]={0},c[9]={0};
	int n;
	printf("\nno of elements in a:\n");
	scanf("%d",&n);
	readset(a,n);
	printf(" no of elements in b:\n");
	scanf("%d",&n);
	readset(b,n);
	printf("\nSET A=\n");
	printset(a);
	printf("\nSET B=\n");
	printset(b);
	unionset(a,b,c);
	printf("\nAUB=\n");
	printset(c);
	intersect(a,b,c);
	printf("\nAnB=\n");
	printset(c);
	difference(a,b,c);
	printf("\nA-B=\n");
	printset(c);
	}

void readset(struct bit a[],int n)
	{
	int i,x,k;
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
		{
		scanf("%d",&x);
		for(k=0;k<size;k++)
		if(uset [k]==x)
			{
			a[k].x=1;
			break;
			}
		}
	}
void printset(struct bit a[])
	{
	int k;
	printf("{");
	for(k=0;k<size;k++)
	if(a[k].x!=0)
	printf("%d,",uset[k]);
	printf("\b}");
	return;
	}
void unionset(struct bit a[],struct bit b[],struct bit c[])
	{
	int k;
	for(k=0;k<size;k++)no of elements in a:
5
enter 5 elements
9
8
4
5
3
 no of elements in b:
4
enter 4 elements
9 
8
2
1

SET A=
{3,4,5,8,9}
SET B=
{1,2,8,9}
AUB=
{1,2,3,4,5,8,9}
AnB=
{8,9}
A-B=
{3,4,5}
	c[k].x=a[k].x||b[k].x;
	return;no of elements in a:
5
enter 5 elements
9
8
4
5
3
 no of elements in b:
4
enter 4 elements
9 
8
2
1

SET A=
{3,4,5,8,9}
SET B=
{1,2,8,9}
AUB=
{1,2,3,4,5,8,9}
AnB=
{8,9}
A-B=
{3,4,5}
	}
void intersect(struct bit a[],struct bit b[],struct bit c[])
	{
	int k;
	for(k=0;k<size;k++)
	c[k].x=a[k].x & b[k].x;
	return;
	}
void difference(struct bit a[],struct bit b[],struct bit c[])
	{
	int k;
	for(k=0;k<size;k++)
	if (a[k].x==1)
	c[k].x=a[k].x^b[k].x;
	return;
	} 
/*
output
=====
no of elements in a:
5
enter 5 elements
9
8
4
5
3
 no of elements in b:
4
enter 4 elements
9 
8
2
1

SET A=
{3,4,5,8,9}
SET B=
{1,2,8,9}
AUB=
{1,2,3,4,5,8,9}
AnB=
{8,9}
A-B=
{3,4,5}
*/
