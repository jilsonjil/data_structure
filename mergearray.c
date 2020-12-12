#include<stdio.h>
void main()
{
int a[]={1,2,3,4,5};        
int b[]={6,10,12,13,14,15,};     
int c[20];                      
int i,j,k;                      
void merge(int a[],int,int b[],int,int c[]);// function prototype
merge(a,5,b,6,c); //function call
printf("array after merging:\n");
for(i=0;i<(5+6);i++)
{
	printf(" %d\n",c[i]);
}

} 


void merge(int a[],int m,int b[],int n,int c[]) //function definition
{

	int i=0,j=0,k=0;
	while(i<m && j<m)
	{
		if(a[i]<b[j])  
	   { 
		c[k]=a[i];    //  comparing values from array A an array B and the smaller value will be moved to array c
		k++; i++;     //k value incresed as a item added & i value incressed as 1 item is moved 
        }
        else
        {
        	c[k]=b[j];    //if a[i]>b[j] then b[j] will be moved to array c
         	k++;j++;    //k value incresed as a item added & i value incressed as 1 item is moved           
        }
	}

  //copying restofthe elements from array a if any element left
	while(i<m)
	{
		c[k]=a[i];
		i++;
		k++;
	}
//copying restofthe elements from array b if any element left 
	while(j<n)
	{
		c[k]=b[j];
		k++;
		j++;
	}


}