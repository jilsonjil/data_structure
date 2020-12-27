#include <stdio.h>
#include <stdlib.h>
#define size 5

void insertcq(int[], int); //function prototype
void deletecq(int[]);
void searchcq(int[]);

int front =  - 1;
int rear =  - 1;

int main()
{
    int n, ch;    //variable declaration
    int queue[size];
    do
    {
        printf("\n\n Circular Queue:\n1. Insert \n2. Delete\n3. Search\n0. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insertcq(queue, n);
                break;
            case 2:
                deletecq(queue);
                break;
            case 3:
                searchcq(queue);
                break;
            default: printf("Wrong choice..");
        }
    }while (ch != 0);
}


void insertcq(int queue[], int item) //to insert element in a circular queue
{  if(rear+1==front)//condition to check queue is full
    {
        printf("queue is full");
    }

    else
    {
    rear=rear+1;
    queue[rear] = item;
    }
}

void deletecq(int queue[]) // to delete the element from the queue
{
    int item;
    if (front !=  rear)//condition to check queue is not empty

    {
        front=front+1;
        item=queue[front];
        printf("%d deleted",item);

    }
    else
    {
        printf("\n queue is empty");

    }
}

void searchcq(int queue[])// to search the element from the queue
{
    int item;
    printf("Enter the element you want to search: ");
    scanf("%d",&item);
    for(int i=front;i<=rear;i++)
    {
        if(item==queue[i])
            {
                printf("\nElement found at the position %d", i);
            }
    }
}



/*
 OUTPUT
-----------


 Circular Queue:
1. Insert
2. Delete
3. Search
0. Exit
Enter Choice : 1

Enter number: 2


 Circular Queue:
1. Insert
2. Delete
3. Search
0. Exit
Enter Choice : 1

Enter number: 6


 Circular Queue:
1. Insert
2. Delete
3. Search
0. Exit
Enter Choice : 3
Enter the element you want to search: 6

Element found at the position 1

 Circular Queue:
1. Insert
2. Delete
3. Search
0. Exit
Enter Choice : 2
2 deleted

*/
