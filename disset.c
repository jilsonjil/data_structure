#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct rep *repptr;
	struct node *next;
};
struct rep
	{
	struct node* head, *tail;
	};
struct nodaddr
	{
	int key;
	struct node* obj_node_ptr;
	struct nodaddr *next;
	};
struct nodaddr* ndr=0;
void makeset(int a) //create a set for an object
	{
	struct nodaddr *t=(struct nodaddr*)malloc(sizeof(struct nodaddr)); //create a set reference
	struct rep *newset=(struct rep*)malloc(sizeof(struct rep));        //create a new set
	struct node *n=(struct node*)malloc(sizeof(struct node));          
	n->value=a;                  //fill values
	n->repptr=newset;
	n->next=0;
	newset->head=newset->tail=n; //initialize head and tail
	t->obj_node_ptr=n;           //to store object node ,pointer and key
	t->key=a;
	t->next=ndr;
	ndr=t;
	}
struct rep *find(int x) // function to retrun pointer to representative containing x
	{
	struct nodaddr* t=ndr;
	while(t->key!=x && t!=0)
	t=t->next;
	return t->obj_node_ptr->repptr;
	}
void unionset(int key1,int key2)// union function for joining two subsets  of a universe. 
	{
	struct rep *set1,*set2;
	struct node *t1;
	set1=find(key1);
	set2=find(key2);
	t1=set2->head;
	while(t1!=0)
		{
		t1->repptr=set1;
		t1=t1->next;
		}
	set1->tail->next=set2->head;  //set the tail of set1 to tail of set2
	set1->tail=set2->tail;
	free(set2);             //deletes set2. 
	}
/*void display_sett(int a)     //display set
	{
	struct rep *r;
	r=find(a);
	printf("set members containing %d:/n",a);
	while(r->head!=0)
		{
		printf("%d",r->head->value);
		r->head=r->head->next;
		}
	}*/
void main()
	{
	makeset(10);
	makeset(20);     //a new set is made with one object only 
	makeset(30);
	makeset(40);
	makeset(50);
	printf("\n find(10)=%p",find(10));
	printf("\n find(20)=%p",find(20));
	printf("\n find(30)=%p",find(30));
	printf("\n find(40)=%p",find(40));
	unionset(10,20);
	printf("\n after union  of 10 and 20 find(20)=%p",find(20));
	unionset(30,40);
	printf("\n after union  of 30 and 40 find(40)=%p",find(40));
	unionset(20,40);
	printf("\n after union  of 20 and 40 find(40)=%p",find(40));
	}

/*
output
=====
find(10)=0x737030
 find(20)=0x737090
 find(30)=0x7370f0
 find(40)=0x737150
 after union  of 10 and 20 find(20)=0x737030
 after union  of 30 and 40 find(40)=0x7370f0
 after union  of 20 and 40 find(40)=0x737030
*/
