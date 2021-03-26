#include <stdio.h>
#include <stdlib.h>
struct node {                                                       // Linked List Node 
    int val;
    struct node *prev, *next;
};
struct node* start = NULL;


void insert(int data)                                                  //FUNCTION INSERT 
{


    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));        //memory allocation
    temp->prev = NULL;
    temp->next = NULL;

    temp->val = data;
    printf("\n %d INSERTED  ",data);
    temp->next = NULL;                                      //ASSIGNING NEXT TO NULL
    trav = start;

								 // If start is NULL 
    if (start == NULL) {
        start = temp;
    }
    									// Changes Links
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}
void delete( )
{
    struct node *ptr, *temp;
    int n;
    printf("Enter the value : ");
    scanf("%d",&n);
    if(start==NULL)                               //CHECKING LIST IS EMPTY 
    {
    	printf("\n> List Empty");
    	return;
    }
    temp = start;
   if(temp->val==n)                                 //DELETE IF DATA IS FIRST NODE 
   {
   	temp=temp->next;
   	start=temp;
   	printf("\n>%d deleted sucessfully",n);
   	return;
   }
    while(1)
   {
        if(temp->val==n)
   	       break;
        if(temp->next==NULL){
   	       printf("\n>%d Not found ",n);
   	       return;
   	       }
        temp = temp -> next;
     }

    if(temp -> next == NULL)                   //DELETE IF DATA IS LAST NODE 
    	temp->prev->next=NULL;
    else
    {
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
free(temp);
    }
  printf("\n> %d Deleted sucessfully",n);
}
void display()
{
    struct node *ptr;
    if(start==NULL)
        printf("list empty");
    else
        {
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->val);
        ptr=ptr->next;
    }
}
}
void search()
{
    int n;
    struct node *newnode = start;
  if(start == NULL)
    printf("\nList is Empty!!");
  else{
    printf("Enter the number you want to search:");
    scanf("%d", &n);
    do{
      if(newnode->val==n){
        printf("\n The number is found ");
        return;
      }
      newnode = newnode->next;
    }while(newnode != NULL);
    printf("\nThe number is not found ");
  }
}
void main()
{
	int data;
    int choice,a;
    while (1) {

        printf("\n1  : INSERT\n2  : DELETE\n3  : DISPLAY\n4  : SEARCH\n5  : EXIT");
	printf("\nEnter Choice : ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
        	printf("\nEnter Data to be Insert : ");
           scanf("%d", &data);                               		 //READING DATA TO INSERT 
            insert(data);
            break;

        case 2:
           delete();
            break;

        case 3:
		display();
		break;

        case 4:search();
		break;

        case 5:
            exit(0);
            break;

        default:
            printf("Incorrect Choice\n");

        }

    }

}
/*
output
------
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 3
list empty
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 2
Enter the value : 1

> List Empty
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 1

Enter Data to be Insert : 5

 5 INSERTED  
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 1

Enter Data to be Insert : 8

 8 INSERTED  
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 1

Enter Data to be Insert : 9

 9 INSERTED  
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 2
Enter the value : 9

> 9 Deleted sucessfully
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 3
5
8

1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 4
Enter the number you want to search:5

 The number is found 
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 2
Enter the value : 5

>5 deleted sucessfully
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 2
Enter the value : 8

>8 deleted sucessfully
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT
Enter Choice : 2
Enter the value : 5

> List Empty
1  : INSERT
2  : DELETE
3  : DISPLAY
4  : SEARCH
5  : EXIT

*/

