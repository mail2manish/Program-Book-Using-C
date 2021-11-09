/********************************************************* 
*                                                        *
*														 *
*														 *
*														 *
*		Subject:-      Mini Project                      *
*       Class:-        S.Y.Btech                         *
*       Developed By:- Manish Prakash Jadhav             *
*                      					                 *
*				       							         *
*				       					                 *
*														 *	
**********************************************************/			  


#include<stdio.h>
#include<conio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include<alloc.h>
#include<process.h> //for double ended queue

#define PI 3.142
#define max1 10
#define MAX 2
#define MAXq 50 //simple queue defined value 
#define MAXdq 30 //double ended queue defined value
# define MAXcq 5 //circular queue defined value
#define MAXstack 5 //stack defined value
#define MAXjump 100 //jump search defined value
#define MAXinter 30 //interpolation search defined value
#define MAX_SIZE 5 //merge sort defined value
//struture created for array of structure
struct student
	{
    char name[20];
    int roll_no;
    float marks;
	};

//structure created for array within structure
struct Student
       {
	    int Roll;
	    char Name[25];
		int Marks[3];              //Statement 1 : array of marks
		int Total;
		float Avg;
       };
	
	
	
//for graphs
int q[20],topg=-1,frontg=-1,rearg=-1,g[20][20],vis[20],stackg[20];
int deleteg();
void addg(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void pushg(int item);
int popg();


void bfs(int s,int n)
{
int p,i;
addg(s);
vis[s]=1;
p=deleteg();
if(p!=0)
printf(" %d ",p);
while(p!=0)
{
for(i=1;i<=n;i++)
if((g[p][i]!=0)&&(vis[i]==0))
{
addg(i);
vis[i]=1;
}
p=deleteg();
if(p!=0)
printf(" %d ",p);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
bfs(i,n);
}

void addg(int item)
{
if(rearg==19)
printf("QUEUE FULL");
else
{
if(rearg==-1)
{
q[++rearg]=item;
frontg++;
}
else
q[++rearg]=item;
}
}
int deleteg()
{
int k;
if((frontg>rearg)||(frontg==-1))
return(0);
else
{
k=q[frontg++];
return(k);
}
}

void dfs(int s,int n)
{
int i,k;
pushg(s);
vis[s]=1;
k=popg();
if(k!=0)//edited
printf(" %d ",k);
while(k!=0) 
{
for(i=1;i<=n;i++)
if((g[k][i]!=0)&&(vis[i]!=0))
{
pushg(i);
vis[i]=1;
}
k=popg();
if(k!=0)
printf(" %d ",k);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
dfs(i,n);
}

void pushg(int item)
{
if(topg==19)
printf("Stack overflow ");
else
stackg[++topg]=item;
}

int popg()
{
int k;
if(topg==-1)
return(0);
else
{
k=stackg[topg];
return(k);
}
}

  
 
  
 //singly linked list pre-requsites
  
 void create1();
void display1();
void insert_begin1();
void insert_end1();
void insert_pos1();
void delete_begin1();
void delete_end1();
void delete_pos1();

struct node1
{
    int info;
    struct node1 *next;
};
struct node1 *start=NULL;


void create1()
{
        struct node1 *temp,*ptr;
		clrscr();
        temp=(struct node1 *)malloc(sizeof(struct node1));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
            ptr=ptr->next;
            }
            ptr->next=temp;
        }
}//end of create()


void display1()
{
    struct node1 *ptr;
	clrscr();
	if(start==NULL)
	    {
            printf("\nList is empty:\n");
            return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                printf("%d\t",ptr->info );
                ptr=ptr->next ;
                }//end of while
        }//end of else
}//end of display()


void insert_begin1()
{
        struct node1 *temp;
		clrscr();
        temp=(struct node1 *)malloc(sizeof(struct node1));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            temp->next=start;
            start=temp;
        }
}//end of insert_begin()


void insert_end1()
{
    	struct node1 *temp,*ptr;
		clrscr();
        temp=(struct node1 *)malloc(sizeof(struct node1));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next !=NULL)
            {
            ptr=ptr->next ;
            }
            ptr->next =temp;
        }
}//end of insert_end


void insert_pos1()
{
    struct node1 *ptr,*temp;
	int i,pos;
	clrscr();
	temp=(struct node1 *)malloc(sizeof(struct node1));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->info) ;
        temp->next=NULL;
        if(pos==0)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++)
                {
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                    printf("\nPosition not found:[Handle with care]\n");
                    return;
                    }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }//end of else
}//end of insert_pos


void delete_begin1()
{
        struct node1 *ptr;
		clrscr();
        if(start==NULL)
        {
            printf("\nList is Empty:\n");
            return;
        }
        else
        {
            ptr=start;
            start=start->next ;
            printf("\nThe deleted element is :%d\t",ptr->info);
            free(ptr);
        }
}//end of delete_begin()


void delete_end1()
{
        struct node1 *temp,*ptr;
		clrscr();
        if(start==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                temp=ptr;
                ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",ptr->info);
                free(ptr);
        }
}//end of delete_begin()


void delete_pos1()
{
        int i,pos;
        struct node1 *temp,*ptr;
		clrscr();
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++)
                        {
                            temp=ptr;
                            ptr=ptr->next ;
                            if(ptr==NULL)
                            {
                            printf("\nPosition not Found:\n");
                            return;
                            }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info );
                        free(ptr);
                }
        }//end of else
}




// doubly linked list pre-requisites
struct node2
{
    struct node2 *prev;
    int n;
    struct node2 *next;
}*h,*temp,*temp1,*temp2,*temp4;
 
void insert1();
void insert2();
void insert3();
void traversebeg();
void traverseend(int);
void sort();
void search();
void update();
void delete();
int count = 0;

void create2()
{
    int data;
    temp =(struct node2 *)malloc(1*sizeof(struct node2));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}
 
 
/*  TO insert at beginning */
void insert1()
{
	clrscr();
    if (h == NULL)
    {
    create2();
    h = temp;
    temp1 = h;
    }
    else
    {
    create2();
    temp->next = h;
    h->prev = temp;
    h = temp;
    }
}

 
/* To insert at end */
void insert2()
{
	clrscr();
    if (h == NULL)
    {
    create2();
    h = temp;
    temp1 = h;
    }
    else
    {
    create2();
    temp1->next = temp;
    temp->prev = temp1;
    temp1 = temp;
    }
}

 
/* To insert at any position */
void insert3()
{
    int pos, i = 2;
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;
    clrscr();
	if ((pos < 1) || (pos >= count + 1))
    {
    printf("\n Position out of range to insert");
    return;
    }
    if ((h == NULL) && (pos != 1))
    {
    printf("\n Empty list cannot insert other than 1st position");
    return;
    }
    if ((h == NULL) && (pos == 1))
    {
    create2();
    h = temp;
    temp1 = h;
    return;
    }
    else
    {
        while (i < pos)
        {
        temp2 = temp2->next;
        i++;
        }
    create2();
    temp->prev = temp2;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    temp2->next = temp;
    }
}
 
 
/* To delete an element */
void delete()
{
    int i = 1, pos;
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;
    clrscr();
	if ((pos < 1) || (pos >= count + 1))
    {
    printf("\n Error : Position out of range to delete");
    return;
    }
    if (h == NULL)
    {
    printf("\n Error : Empty list no elements to delete");
    return;
    }
    else
    {
        while (i < pos)
        {
        temp2 = temp2->next;
        i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
            printf("Node deleted from list");
            free(temp2);
            temp2 = h = NULL;
            return;
            }
        }
        if (temp2->next == NULL)
        {
        temp2->prev->next = NULL;
        free(temp2);
        printf("Node deleted from list");
        return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
        temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
        h = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}

 
/* Traverse from beginning */
void traversebeg()
{
    temp2 = h;
	clrscr();
	if (temp2 == NULL)
    {
    printf("List empty to display \n");
    return;
    }
    printf("\n Linked list elements from begining : ");
     while (temp2->next != NULL)
    {
    printf(" %d ", temp2->n);
    temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}
 
 
/* To traverse from end recursively */
void traverseend(int i)
{
	clrscr();
    if (temp2 != NULL)
    {
    i = temp2->n;
    temp2 = temp2->next;
    traverseend(i);
    printf(" %d ", i);
    }
}
 
 
/* To search for an element in the list */
void search()
{
    int data, count = 0;
    temp2 = h;
	clrscr();
    if (temp2 == NULL)
    {
    printf("\n Error : List empty to search for data");
    return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &data);
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
        printf("\n Data found in %d position",count + 1);
        return;
        }
        else
    temp2 = temp2->next;
    count++;
    }
    printf("\n Error : %d not found in list", data);
}

 
/* To update a node value in the list */
void update()
{
    int data, data1;
    printf("\n Enter node data to be updated : ");
    scanf("%d", &data);
    printf("\n Enter new data : ");
    scanf("%d", &data1);
    temp2 = h;
	clrscr();
    if (temp2 == NULL)
    {
    printf("\n Error : List empty no node to update");
    return;
    }
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
        temp2->n = data1;
        traversebeg();
        return;
        }
        else
        temp2 = temp2->next;
    }
     printf("\n Error : %d not found in list to update", data);
}
 
 
/* To sort the linked list */
void sort()
{
    int i, j, x;
    temp2 = h;
    temp4 = h;
	clrscr();
    if (temp2 == NULL)
    {
    printf("\n List empty to sort");
    return;
    }
 
    for (temp2 = h; temp2 != NULL; temp2 = temp2->next)
    {
        for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
        {
            if (temp2->n > temp4->n)
            {
            x = temp2->n;
            temp2->n = temp4->n;
            temp4->n = x;
            }
        }
    }
    traversebeg();
}




//circular linked list pre=requsites
struct node3
{
    int data;
    struct node3 *link;
};

struct node3 *head = NULL, *x, *y, *z;
void create3();
void ins_at_beg3();
void ins_at_pos3();
void del_at_beg3();
void del_at_pos3();
void traverse3();
void search3();
void sort3();
void update3();
void rev_traverse3(struct node3 *p);



/*Function to create a new circular linked list*/
void create3()
{
    int c;
    x = (struct node3 *)malloc(sizeof(struct node3));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("\n If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
    y = (struct node3*)malloc(sizeof(struct node3));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    x->link = y;
    y->link = head;
    x = y;
    printf("\n If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c); 
    }
}


/*Function to insert an element at the begining of the list*/
void ins_at_beg3()
{
    x = head;
    y = (struct node3*)malloc(sizeof(struct node3));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    while (x->link != head)
    {
    x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
}


/*Function to insert an element at any position the list*/
void ins_at_pos3()
{
    struct node3 *ptr;
    int c = 1, pos, count = 1;
    y = (struct node3*)malloc(sizeof(struct node3));
    if (head == NULL)
    {
    printf("cannot enter an element at this place");
    }
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->link != head)
    {
    count++;
    ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
    printf("OUT OF BOUND");
    return;
    }
    while (c < pos)
    {
    z = x;
    x = x->link;
    c++;
    }
    y->link = x;
    z->link = y;
}


/*Function to delete an element at any begining of the list*/
void del_at_beg3()
{
    if (head == NULL) 
    printf("\n List is empty");
    else
    {
    x = head;
    y = head;
    while (x->link !=  head)
    {
    x = x->link;
    }
    head = y->link;
    x->link = head;
    free(y);
    }
}


/*Function to delete an element at any position the list*/
void del_at_pos3()
{
    if (head == NULL)
    printf("\n List is empty");
    else
    {
    int c = 1, pos;
    printf("\n Enter the position to be deleted:");
    scanf("%d", &pos);
    x = head;
    while (c < pos)
    {
    y = x;
    x = x->link;
    c++;
    }
    y->link = x->link;
    free(x);
    }
}


/*Function to display the elements in the list*/
 void traverse3()
{
    if (head == NULL)
    printf("\n List is empty");
    else
    {
    x = head;
    while (x->link !=  head)
    { 
    printf("%d->", x->data);
    x = x->link;
    }
    printf("%d", x->data);
    }
}

/*Function to search an element in the list*/
void search3()
{
    int search_val, count = 0, flag = 0;
    printf("\nenter the element to search\n");
    scanf("%d", &search_val);
    if (head == NULL)
    printf("\nList is empty nothing to search");
    else
    {
    x = head;
    while (x->link !=  head)
    {
    if (x->data == search_val)
    {
    printf("\nthe element is found at %d", count);
    flag = 1;
    break;
    }
    count++;
    x = x->link;
    }
    if(x->data == search_val)
    {
    printf("element found at postion %d", count);
    }
    if (flag == 0)
    {
    printf("\nelement not found");
    }
    }
}

/*Function to sort the list in ascending order*/
 void sort3()
{
    struct node3 *ptr, *nxt;
    int temp;
    if (head == NULL)
    {
    printf("empty linkedlist");
    }
    else
    {
    ptr = head;
    while (ptr->link !=  head)
    {
    nxt = ptr->link;
    while (nxt !=  head)
    {
    if (nxt !=  head)
    {
    if (ptr->data > nxt->data)
    {
    temp = ptr->data;
    ptr->data = nxt->data;
    nxt->data = temp;
    }
    }
    else
    {
    break;
    }
    nxt = nxt->link;
    }
    ptr = ptr->link;
    }
    }
}

/*Function to update an element at any position the list*/
void update3()
{
    struct node3 *ptr;
    int search_val;
    int replace_val;
    int flag = 0;
    if (head == NULL)
    {
    printf("\n empty list");
    }
    else
    {
    printf("enter the value to be edited\n");
    scanf("%d", &search_val);
    fflush(stdin);
    printf("enter the value to be replace\n");
    scanf("%d", &replace_val);
    ptr = head;
    while (ptr->link !=  head)
    {
    if (ptr->data == search_val)
    {
    ptr->data = replace_val;
    flag = 1;
    break;
    }
    ptr = ptr->link;
    }
    if (ptr->data == search_val)
    {
    ptr->data = replace_val;
    flag = 1;
    }
    if (flag == 1)
    {
    printf("\nUPdate sucessful");
    }
    else
    {
    printf("\n update not successful");
    }
    }
}

/*Function to display the elements of the list in reverse order*/
void rev_traverse3(struct node3 *p)
{
    int i = 0;
    if (head == NULL)
    {
    printf("empty linked list");
    }
    else
    {
    if (p->link !=  head)
    {
    i = p->data;
    rev_traverse3(p->link);
    printf(" %d", i);
    }
    if (p->link == head)
    {
    printf(" %d", p->data);
    }
    }
}



//simple queue pre-requisites 
int queue_array[MAXq];
int rear = - 1;
int front = - 1;

//insert function for queue 
void insertQ()
{
	int item;
	if(rear == MAXq - 1)
	printf("Queue Overflow n");
	else
	{
	if(front== - 1)
	front = 0;
	printf("Inset the element in queue : ");
	scanf("%d", &item);
	rear = rear + 1;
	queue_array[rear] = item;
	}
}

// delete function for queue
void deleteq()
{
	if(front == - 1 || front > rear)
	{
	printf("Queue Underflow n");
	return;
	}
	else
	{
	printf("Element deleted from queue is : %dn", queue_array[front]);
	front = front + 1;
	}
}

// display function for queue
void displayq()
{
	int i;
	if(front == - 1)
	printf("Queue is empty n");
	else
	{
	printf("Queue is : n");
	for(i = front; i <= rear; i++)
	printf("%d ", queue_array[i]);
	printf("n");
	}
}


//double ended queue pre-requisites

typedef struct dequeue
{
	int data[MAXdq];
	int rear,front;
}dequeue;

void initializedq(dequeue *p);
int emptydq(dequeue *p);
int fulldq(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void printdq(dequeue *p);

//initialize function for double ended queue
void initializedq(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}

//empty function for double ended queue
int emptydq(dequeue *P)
{
	if(P->rear==-1)
	return(1);
	return(0);
}

//full function for double ended queue
int fulldq(dequeue *P)
{
	if((P->rear+1)%MAXdq==P->front)
	return(1);
	return(0);
}

//insert from rear function for double ended queue
void enqueueR(dequeue *P,int x)
{
	if(emptydq(P))
	{
	P->rear=0;
	P->front=0;
	P->data[0]=x;
	}
	else
	{
	P->rear=(P->rear+1)%MAXdq;
	P->data[P->rear]=x;
	}
}

//insert from front function for double ended queue
void enqueueF(dequeue *P,int x)
{
	if(emptydq(P))
	{
	P->rear=0;
	P->front=0;
	P->data[0]=x;
	}
	else
	{
	P->front=(P->front-1+MAXdq)%MAXdq;
	P->data[P->front]=x;
	}
}

//delete from front function double ended queue
int dequeueF(dequeue *P)
{
	int x;
	x=P->data[P->front];
	if(P->rear==P->front)	//delete the last element
	initializedq(P);
	else
	P->front=(P->front+1)%MAXdq;
	return(x);
}

//delete from rear function for double ended queue
int dequeueR(dequeue *P)
{
	int x;
	x=P->data[P->rear];
	if(P->rear==P->front)
	initializedq(P);
	else
	P->rear=(P->rear-1+MAXdq)%MAXdq;
	return(x);
}

//print function for double ended queue
void printdq(dequeue *P)
{   int i;
	if(emptydq(P))
	{
	printf("\nQueue is empty!!");
	exit(0);
	}
	i=P->front;
	printf("\n queue is:");
	while(i!=P->rear)
	{
	printf("\n%d",P->data[i]);
	i=(i+1)%MAXdq;
	}
	printf("\n%d\n",P->data[P->rear]);
}




// circular queue
int cqueue_arr[MAXcq];
int frontcq = -1;
int rearcq = -1;


void insertcq(int item)
{
	if((frontcq == 0 && rearcq == MAXcq-1) || (frontcq == rearcq+1))
	{
	printf("Queue Overflow n");
	return;
	}
	if(frontcq == -1)
	{
	frontcq = 0;
	rearcq = 0;
	}
	else
	{
	if(rearcq == MAXcq-1)
	rearcq = 0;
	else
	rearcq = rearcq+1;
	}
	cqueue_arr[rearcq] = item ;
}

//delete function for circular queue
void deletioncq()
{
	if(frontcq == -1)
	{
	printf("Queue Underflown");
	return ;
	}
	printf("Element deleted from queue is : %dn",cqueue_arr[frontcq]);
	if(frontcq == rearcq)
	{
	frontcq = -1;
	rearcq=-1;
	}
	else
	{
	if(frontcq == MAXcq-1)
	frontcq = 0;
	else
	frontcq = frontcq+1;
	}
}

//display function for circular queue
void displaycq()
{
	int front_pos = frontcq,rear_pos = rearcq;
	if(frontcq == -1)
	{
	printf("Queue is emptyn");
	return;
	}
	printf("Queue elements :n");
	if( front_pos <= rear_pos )
	while(front_pos <= rear_pos)
	{
	printf("%d ",cqueue_arr[front_pos]);
	front_pos++;
	}
	else
	{
	while(front_pos <= MAXcq-1)
	{
	printf("%d ",cqueue_arr[front_pos]);	
	front_pos++ ;
	}
	front_pos = 0;
	while(front_pos <= rear_pos)
	{
	printf("%d ",cqueue_arr[front_pos]);
	front_pos++;
	}
	}
	printf("n");
}


//stack pre-requisites

int top=-1,stack[MAXstack];
void pushstack();
void popstack();
void displaystack();

//push function for stack
void pushstack()
{
	int val;
	if(top==MAXstack-1)
	{
	printf("\nStack is full!!");
	}
	else
	{
	printf("\nEnter element to push:");
	scanf("%d",&val);
	top=top+1;
	stack[top]=val;
	}
}

//pop function for stack
void popstack()
{
	if(top==-1)
	{
	printf("\nStack is empty!!");
	}
	else
	{
	printf("\nDeleted element is %d",stack[top]);
	top=top-1;
	}
}

//display function for stack
void displaystack()
{
	int i;
	if(top==-1)
	{
	printf("\nStack is empty!!");
	}
	else
	{
	printf("\nStack is...\n");
	for(i=top;i>=0;--i)
	printf("%d\n",stack[i]);
	}
}

//structure data structure pre-requisites
struct Candidate
    {
	int Roll;
	char Name[25];
	int Marks[3];              //Statement 1 : array of marks
	int Total;
	float Avg;
    };
	
	
//tree pre-requisites 
struct nodetree
{
	int data;
	struct nodetree* left;
	struct nodetree* right;
};

//inorder function for the tree
void inorder(struct nodetree* root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d->",root->data);
	inorder(root->right);
}

//preorder function for the tree
void preorder(struct nodetree* root)
{
	if(root==NULL)
	return;
	printf("%d->",root->data);
	preorder(root->left);
	preorder(root->right);
}

//preorder function for the tree
void postorder(struct nodetree* root)
{
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}

//create node structure for tree
struct nodetree* createNode(value)
{
	struct nodetree* newNode=malloc(sizeof(struct nodetree));
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
struct nodetree* insertleft(struct nodetree *root,int value)
{
	root->left=createNode(value);
	return root->left;
}
struct nodetree* insertright(struct nodetree *root,int value)
{
	root->right=createNode(value);
	return root->right;
}


//jump search pre-requisites

int find_element(int element);
int arr[MAXjump],n;

//finde element function for the jump search
int find_element(int element)
{
	int jump_step,prev=0;
	jump_step=floor(sqrt(n));
	/* Finding block in which element lies, if it is present */ 
    while(arr[prev]<element)
	{
    if(arr[jump_step]>element || jump_step>=n)
    {
	break;
    }
    else
    {
    prev=jump_step;
    jump_step=jump_step+floor(sqrt(n));
    }
	}
	/*Finding the element in the identified block */
	while(arr[prev]<element)
	{
    prev++;
	}
	if(arr[prev]==element)
	{
    return prev+1;
	}
	else
	{
    return -1;
	} 
}




//interpolation search pre-requisites
int interpolation_search(int a[], int low, int high, int val)
{
	int midinter;	
	while(low <= high)
	{
	midinter=low + (high-low) * ((val - a[low]) / (a[high] - a[low]));
	if(val == a[midinter])
	return midinter;
	if(val < a[midinter])
	high = midinter - 1;
	else
	low = midinter + 1;
	}
	return -1;
}


//heap sort pre-requisites
void create(int []);
void down_adjust(int [],int);
//function for taking inputs
void create(int heap[])
{
	int i,n;
	n=heap[0]; //no. of elements
	for(i=n/2;i>=1;i--)
	down_adjust(heap,i);
}

//function for adjusting the integers
void down_adjust(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];
	while(2*i<=n && flag==1)
	{
	j=2*i;    //j points to left child
	if(j+1<=n && heap[j+1] > heap[j])
	j=j+1;
	if(heap[i] > heap[j])
	flag=0;
	else
	{
	temp=heap[i];
	heap[i]=heap[j];
	heap[j]=temp;
	i=j;
	}
	}
}


//quick sort pre-requisites

//function for quickly sorting the integers
void quicksort(int number[25],int first,int last)
{
	int i, j, pivot, temp;
	if(first<last)
	{
	pivot=first;
	i=first;
	j=last;
    while(i<j)
	{
    while(number[i]<=number[pivot]&&i<last)
    i++;
    while(number[j]>number[pivot])
    j--;
    if(i<j)
	{
    temp=number[i];
    number[i]=number[j];
    number[j]=temp;
    }
    }
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
   }
}



//merge sort pre-requisites

void merge_sort(int, int);
void merge_array(int, int, int, int);
int arr_sort[MAX_SIZE];
void merge_sort(int i, int j)
{
	int m;
	if (i < j) 
	{
    m = (i + j) / 2;
    merge_sort(i, m);
    merge_sort(m + 1, j);
    // Merging two arrays
    merge_array(i, m, m + 1, j);
	}
}

void merge_array(int a, int b, int c, int d) 
{
	int t[50];
	int i = a, j = c, k = 0;
	while (i <= b && j <= d) 	
	{
    if (arr_sort[i] < arr_sort[j])
    t[k++] = arr_sort[i++];
    else
    t[k++] = arr_sort[j++];
	}	
	//collect remaining elements 
	while (i <= b)
    t[k++] = arr_sort[i++];
	while (j <= d)
    t[k++] = arr_sort[j++];
	for (i = a, j = 0; i <= d; i++, j++)
    arr_sort[i] = t[j];
}




// factorial using recurssive function pre-requisites
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
	return 1;
    }
	else
    {
	return(num * factorial(num - 1));
    }
}




//Fibonacci series using recurssive function pre-requisites
int fibo(int num)
{
    if (num == 0)
    {
    return 0;
    }
    else if (num == 1)
    {
    return 1;
    }
    else
    {
    return(fibo(num - 1) + fibo(num - 2));
    }
}




//no argument and no return type pre-requisites
void fact1()
{
	int fact=1,n,i;
	printf("enter the number:- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	fact=fact*i;
	}
	printf("\nfactorial is:- %d",fact);
}



//no argument and return type pre-requisites
int fact2()
{
	int fact=1,i,n;
	printf("enter the number:- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	fact=fact*i;
	}
	return(fact);
}



//argument and no return type
void fact3(int p)
{
	int i,fact=1;
	for(i=1;i<=p;i++)
	{
	fact=fact*i;
	}
	printf("\nfactorial is:- %d",fact);
}



//argument and return type
void fact4(int p)
{
	int i,fact=1;
	for(i=1;i<=p;i++)
	{
	fact=fact*i;
	}
	printf("\nfactorial is:- %d",fact);
}




int main()
{
	struct student arr_student[MAX];
	struct nodetree* root=createNode(1); //creating structure for the tree traversal techniques
	struct Student S;
	int choice,num,i,j,v;
	int x,op,n,item;
	int stack[100];
	int count,temp,number[30]; //bubble sort requirements
	int heap[30],last; //heap sort data declarations
	int a[30];//merge sort array declarations
	dequeue q;
	initializedq(&q);


	clrscr();
	printf("\t\t\t\tBooks of Program \t\t\n");
	printf("================================================================================");
	printf("               \t!!!!!!!!!!!!!!!!!! CATAGORIES !!!!!!!!!!!!!!!!!!");
	printf("\n\n 1. Arithmetic's & Numbericals""\n\n 2. Searching""\n\n 3. Sorting""\n\n 4. Data Structures""\n\n 5. Pyramids""\n\n 6. Arguments & Parameter Passing""\n\n 7. Areas Of Geometrical Figures""\n\n 8. Computer Networks & File Handling""\n\n 9.Exit");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);


	switch(choice)
{
		case 1:
		{
		clrscr();
		printf("\t\t\t!!!!! Arithmetic's & Numericals !!!!!");
		printf("\n================================================================================");
		printf("\n 1. Calculator""\n 2. Factorial Using Recurssive Function""\n 3. Factorial Without Using Recurssive Function""\n 4. Fibonacci Number Using Recursion""\n 5. Fibonacci Series""\n 6. Find Average of List""\n 7. Find the Sum of A.p Series""\n 8. First N Fibonacci Numbers""\n 9. GCD & LCM""\n 10. Largest Element in the Given List""\n 11. Matrix Arithmetic""\n 12. Reversing Any Number""\n 13. Simple Intrest""\n 14. Smallest Element in the Given List""\n 15. Statistical Properties of Given Integer""\n 16. Back To Main Menu");
		printf("\n================================================================================");
		printf("\n\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
		{
		char operatr;
		int num1, num2;
		float result;
		clrscr();
		printf("Simulation of a Simple Calculator\n");
		printf("================================================================================");
		printf("Enter two numbers \n");
		scanf("%d %d", &num1, &num2);
		fflush(stdin);
		printf("*********************************\n");
		printf("Enter the operator [+,-,*,/] \n");
		scanf("%s", &operatr);
		switch(operatr)
		{
		case '+': result = num1 + num2;
		break;
		case '-': result = num1 - num2;
		break;
		case '*': result = num1 * num2;
		break;
		case '/': result = num1 / num2;
		break;
		default : printf("Error in operationn");
		break;
		}
		printf("\n %d %c %d = %.0f\n", num1, operatr, num2, result);
		getch();
		return(main());
		}//calculator close


		case 2:
		{
		int num;
		int result;
		clrscr();
		printf("Factorial Using Recurssive Function\n");
		printf("================================================================================\n");
		printf("Enter a number to find it's Factorial: ");
		scanf("%d", &num);
		if (num < 0)
		{
		printf("Factorial of negative number not possible\n");
		}
		else
		{
		result = factorial(num);
		printf("The Factorial of %d is %d.\n", num, result);
		}
		getch();
		return(main());
		}//factorial using recurssive function close


		case 3:
		{
		int i, fact = 1, num;
		clrscr();
		printf("Factorial Without Using Recurssive Function\n");
		printf("================================================================================\n");
		printf("Enter the number \n");
		scanf("%d", &num);
		if (num <= 0)
        fact = 1;
		else
		{
        for (i = 1; i <= num; i++)
        {
        fact = fact * i;
        }
		}
		printf("Factorial of %d = %5d\n", num, fact);
		getch();
		return(main());
		}// factorial without using recurssive function
		
		
		case 4:
		{
		int num;
		int result;
		clrscr();
		printf("Fibonacci Number Using Recursion\n");
		printf("================================================================================\n");
		printf("Enter the nth number in fibonacci series: ");
		scanf("%d", &num);
		if (num < 0)
		{
        printf("Fibonacci of negative number is not possible.\n");
		}
		else
		{
        result = fibo(num);
        printf("The %d number in fibonacci series is %d\n", num, result);
		}
		getch();
		return(main());
		}//Fibonacci series using recurssive function close
		
		
		case 5:
		{
		int  fib1 = 0, fib2 = 1, fib3, limit, count = 0;
		clrscr();
		printf("Fibonacci Series\n");
		printf("================================================================================\n");
		printf("Enter the limit to generate the Fibonacci Series \n");
		scanf("%d", &limit);
		printf("Fibonacci Series is ...\n");
		printf("%d\n", fib1);
		printf("%d\n", fib2);
		count = 2;
		while (count < limit)
		{
        fib3 = fib1 + fib2;
        count++;
        printf("%d\n", fib3);
        fib1 = fib2;
        fib2 = fib3;
		}
		getch();
		return(main());		
		}//Fibonacci series without using recurssive function close


		case 6:
		{
		int n, i;
		int num[100];
		float sum = 0.0, avg;
		clrscr();
		printf("Find Average of List\n");
		printf("================================================================================\n");
		printf("Enter the numbers of elements: ");
		scanf("%d", &n);
		while (n > 100 || n < 1) 
		{
		printf("Error! number should in range of (1 to 100).\n");
		printf("Enter the number again: ");
		scanf("%d", &n);
		}
		for (i = 0; i < n; ++i)
		{
		printf("%d. Enter number: ", i + 1);
		scanf("%d", &num[i]);
		sum += num[i];
		}
		avg = sum / n;
		printf("Average = %.0f", avg);
		getch();
		return(main());
		}//average of list close



		case 7:
		{
		int a, d, n, i, tn;
		int sum = 0;
		clrscr();
		printf("Find the Sum of A.p Series\n");
		printf("================================================================================\n");
		printf("Enter the first term value of the A.P. series: ");
		scanf("%d", &a);
		printf("Enter the total numbers in the A.P. series: ");
		scanf("%d", &n);
		printf("Enter the common difference of A.P. series: ");
		scanf("%d", &d);
		sum = (n * (2 * a + (n - 1)* d ))/ 2;
		tn = a + (n - 1) * d;
		printf("Sum of the A.P series is: ");
		for (i = a; i <= tn; i = i + d )
		{
        if (i != tn)
        printf("%d + ", i);
        else
        printf("%d = %d ", i, sum);
		}
		getch();
		return(main());
		}//sum of a.p series close
		
		
		
		case 8:
		{
		int fib1 = 0, fib2 = 1, fib3, num, count = 0;
		clrscr();
		printf("First N Fibonacci Numbers\n");
		printf("================================================================================\n");
		printf("Enter the value of num \n");
		scanf("%d", &num);
		printf("First %d FIBONACCI numbers are ...\n", num);
		printf("%d\n", fib1);
		printf("%d\n", fib2);
		count = 2; /* fib1 and fib2 are already used */
		while (count < num)
		{
        fib3 = fib1 + fib2;
        count++;
        printf("%d\n", fib3);
        fib1 = fib2;
        fib2 = fib3;
		}	
		getch();
		return(main());
		}//First N Fibonacci Numbers
		
		
		
		case 9:
		{
		int num1, num2, gcd, lcm, remainder, numerator, denominator;
		clrscr();
		printf("GCD & LCM\n");
		printf("================================================================================\n");
		printf("Enter two numbers\n");
		scanf("%d %d", &num1, &num2);
		if (num1 > num2)
		{
        numerator = num1;
        denominator = num2;
		}
		else
		{
        numerator = num2;
        denominator = num1;
		}
		remainder = numerator % denominator;
		while (remainder != 0)
		{
        numerator   = denominator;
        denominator = remainder;
        remainder   = numerator % denominator;
		}
		gcd = denominator;
		lcm = num1 * num2 / gcd;
		printf("GCD of %d and %d = %d\n", num1, num2, gcd);
		printf("LCM of %d and %d = %d\n", num1, num2, lcm);
		getch();
		return(main());
		}//GCD & LCM  close
		
		
		
		case 10:
		{
		int a[10],n,i,c;
		clrscr();
		printf("Largest Element in the Given List\n");
		printf("================================================================================\n");
		printf("enter array size:- ");
		scanf("%d",&n);
		printf("\nenter array elements:- \n");
		for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
		if(a[i]>a[i+1])
		{
		c=a[i];
		}
		}
		printf("\nlargest element in the array is:- %d",c);
		getch();
		return(main());
		}//largest element in the given list close
		
		
		
		case 11:
		{
		int c, d, k,r,m=3,p=3,q=3, sum = 0;
		int a[3][3]={{1,2,3},{2,3,4},{5,6,7}}, b[3][3]={{1,2,3},{2,3,4},{5,6,7}}, z[3][3];
		clrscr();
		printf("Matrix Arithmetic\n");
		printf("================================================================================\n");
		printf("matrix 1st\n");
		for(c=0;c<p;c++)
	    {
		for(d=0;d<q;d++)
		{
	    printf("%d\t",a[c][d]);
	    }
	    printf("\n");
	    }
		printf("\nmatrix 2nd\n");
		for(c=0;c<p;c++)
	    {
		for(d=0;d<q;d++)
	    {
	    printf("%d\t",b[c][d]);
	    }
	    printf("\n");
	    }
		printf("\nEnter your choice\n");
		printf("1 for Addition\n2 for Substraction\n3 for Multipliction\n4 for Division");
		printf("\nChoice:");
		scanf("%d",&r);
		switch(r)
		{
		case 1:
		for(c=0;c<p;c++)
	    {
		for(d=0;d<q;d++)
		{
		z[c][d]=a[c][d]+b[c][d];
	    }
	    }
		printf("\n Addition: \n");
		for(c=0;c<p;c++)
    	{
		for(d=0;d<q;d++)
    	{
		printf("\t %d",z[c][d]);
    	}
    	printf("\n");
    	}
		break;
		case 2:
		for(c=0;c<p;c++)
	    {
		for(d=0;d<q;d++)
	    {
		z[c][d]=a[c][d]-b[c][d];
		}
	    }
		printf("\n Substraction: \n");
    	for(c=0;c<p;c++)
    	{
		for(d=0;d<q;d++)
    	{
        printf("\t %d",z[c][d]);
    	}
    	printf("\n");
    	}
		break;
 		case 3:
		for (c = 0; c < m; c++) 
		{
        for (d = 0; d < q; d++) 
        {
        for (k = 0; k < p; k++)
        {
        sum = sum + a[c][k]*b[k][d];
		}
        z[c][d] = sum;
        sum = 0;
        }
		}
        printf("Multipliction:\n");
        for (c = 0; c < m; c++) 
        {
        for (d = 0; d < q; d++)
        {
        printf("\t %d", z[c][d]);
        }
        printf("\n");
		}
		break;
        case 4:
		for (c = 0; c < m; c++) 
		{
        for (d = 0; d < q; d++) 
        {
        for (k = 0; k < p; k++)
        {
        sum = sum + a[c][k]/b[k][d];
        }
        z[c][d] = sum;
        sum = 0;
		}
		}
        printf("Division:\n");
        for (c = 0; c < m; c++) 
        {
        for (d = 0; d < q; d++)
        {
        printf("\t %d", z[c][d]);
        }
        printf("\n");
		}
		break;
		}
		getch();
		return(main());
		}//matrix arithmetics close
		
		
		
		case 12:
		{
		int n,rev=0;
		clrscr();
		printf("Reversing Any Number\n");
		printf("================================================================================\n");
		printf("enter the number:- ");
		scanf("%d",&n);
		while(n>0)
		{
		rev = (rev*10) + (n%10);
		n = n/10;
		}
		printf("\nreverse of given number is:- %d",rev);
		getch();
		return(main());
		}//reversing any number close
		
		
		
		case 13:
		{
		float principal_amt, rate, simple_interest;
		int time;
		clrscr();
		printf("Simple Intrest\n");
		printf("================================================================================\n");
		printf("Enter the values of principal_amt, rate and time \n");
		scanf("%f %f %d", &principal_amt, &rate, &time);
		simple_interest = (principal_amt * rate * time) / 100.0;
		printf("Amount = Rs. %5.2f\n", principal_amt);
		printf("Rate = Rs. %5.2f%\n", rate);
		printf("Time = %d years\n", time);
		printf("Simple interest = %5.2f\n", simple_interest);
		getch();
		return(main());
		}//simple intrest close
		
		
		
		case 14:
		{
		int a[10],n,i,c;
		clrscr();
		printf("Smallest Element in the Given List\n");
		printf("================================================================================\n");
		printf("enter array size:- ");
		scanf("%d",&n);
		printf("\nenter array elements:- \n");
		for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
		if(a[i]<a[i+1])
		{
		c=a[i];
		}
		}
		printf("\nsmallest element in the array is:- %d",c);
		getch();
		return(main());
		}//smallest element in the given list close
		
		
		
		case 15:
		{
		clrscr();
		printf("Statistical Properties of Given Integer\n");
		printf("================================================================================\n");
		printf("\n\n 1. Find the Sum of First N Natural Numbers ""\n\n 2. Check if a given Number is Prime number""\n\n 3. Find Prime Numbers in a given Range""\n\n 4. Back to main menu");
		printf("\n================================================================================");
		printf("\n\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
			int i, num, sum = 0;
			clrscr();
			printf("Find the Sum of First N Natural Numbers\n");
			printf("================================================================================\n");
			printf("Enter an integer number \n");
			scanf ("%d", &num);
			for (i = 1; i <= num; i++)
			{
			sum = sum + i;
			}
			printf ("Sum of first %d natural numbers = %d\n", num, sum);
			getch();
			return(main());
			}//sum of first n natural numebr close
				
				
				
			case 2:
			{
			int num, j, flag;
			clrscr();
			printf("Check if a given Number is Prime number\n");
			printf("================================================================================\n");
			printf("Enter a number \n");
			scanf("%d", &num);
			if (num <= 1)
			{
			printf("%d is not a prime numbers \n", num);
			exit(1);
			}
			flag = 0;
			for (j = 2; j <= num / 2; j++)
			{
			if ((num % j) == 0)
			{
            flag = 1;
            break;
			}
			}
			if (flag == 0)
			printf("%d is a prime number \n", num);
			else
			printf("%d is not a prime number \n", num);
			getch();
			return(main());
			}//prime number close
				
				
				
			case 3:
			{
			int num1, num2, i, j, flag, temp, count = 0;
			clrscr();
			printf("Find Prime Numbers in a given Range\n");
			printf("================================================================================\n");
			printf("Enter the value of num1 and num2 \n");
			scanf("%d %d", &num1, &num2);
			if (num2 < 2)
			{
			printf("There are no primes upto %d\n", num2);
			exit(0);
			}
			printf("Prime numbers are \n");
			temp = num1;
			if ( num1 % 2 == 0)
			{
			num1++;
			}
			for (i = num1; i <= num2; i = i + 2)
			{
			flag = 0;
			for (j = 2; j <= i / 2; j++)
			{
			if ((i % j) == 0)
            {
            flag = 1;
            break;
            }
			}
			if (flag == 0)
			{
            printf("%d\n", i);
            count++;
			}
			}
			printf("Number of primes between %d & %d = %d\n", temp, num2, count);
			getch();
			return(main());
			}//prime number in the given range close
				
				
				
			case 4:
			{
			return(main());
			}
		}//internal choice switch case close
		}//Statistical Properties of Given Integer close
		
		
		
		case 16:
		{
			return(main());
		}//back to main menu close 
		
	}// entire arithmetic & numericals close
	}//entire case 1 close



	case 2:
	{
		clrscr();
		printf("\t\t\t\t!!!! Searching !!!!");
		printf("\n================================================================================");
		printf("\n\n 1. Linear Search""\n\n 2. Binary Search""\n\n 3. Jump Search""\n\n 4. Interpolation Search""\n\n 5.Back to main menu");
		printf("\n================================================================================");
		printf("\n\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int i,a[30],n,x;
				clrscr();
				printf("Linear Search\n");
				printf("================================================================================\n");
				printf("\nEnter the size of the array\n");
				scanf("\n %d",&n);
				printf("\nEnter elements of the array\n");
				for(i=0;i<n;i++)
				scanf("%d",&a[i]);
				printf("\n Enter the number to search\n");
				scanf("%d",&x);
				for(i=0;i<n;i++)
				{
				if(a[i]==x)
				{
				printf("\n%d is present at location %d",x,i+1);
				break;
				}
				}
				if (i==n)
				printf("\n%d is not present in array",x);
				getch();
				return(main());
			}//linear search closed 
	
			case 2:
			{
				int i,first,last,mid,x,a[20],n;
				clrscr();
				printf("Binary Search\n");
				printf("================================================================================\n");
				printf("\n Enter the size of array...:\n");
				scanf("%d",&n);
				printf("\n Enter the %d element of array\n",n);
				for(i=1;i<=n;i++)
				{
				scanf("%d",&a[i]);
				}
				printf("\n Entered the element you want to search\n");
				scanf("%d",&x);
				for(i=1;i<=n;i++)
				first=0;
				last=n-1;
				mid=(first+last)/2;
				while(first<=last)
				{
				if(a[mid]<x)
				first=mid+1;
				else if(a[mid]==x)
				{
				printf("\n element found at location %d",mid+1);
				break;
				}
				else
				last=mid-1;
				mid =(first+last)/2;
				}
				if(first>last)
				printf("\n Element is not present");
				getch();
				return(main());
			}//binary search close
	
			case 3:
			{
				int i,element,result;
				clrscr();
				printf("Jump Search\n");
				printf("================================================================================\n");
				printf("\nEnter the number of elements: ");
				scanf("%d",&n);
				printf("\nEnter the elements of array: \n");
				for(i=0;i<n;i++)
				{
				scanf("%d",&arr[i]);
				}
				printf("\n\nEnter the element you want to search: ");
				scanf("%d",&element);
				result=find_element(element);
				if(result==-1)
				{
				printf("\nElement is not found in the array !\n");
				}
				else
				{
				printf("\nElement %d is present at position %d",element,result);
				}
				getch();
				return(main());	 
			}//jump search close
	
			case 4:
			{
				int arry[MAXinter], i, n, val, pos;
				clrscr();
				printf("Interpolation Search\n");
				printf("================================================================================\n");
				printf("\n Enter the size of the array : ");
				scanf("%d", &n);
				printf("\n Enter %d elements in the array : \n",n);
				for(i = 0; i<n; i++)
				scanf("%d", &arry[i]);
				printf("\n Enter the key element that has to be search : ");
				scanf("%d", &val);
				pos = interpolation_search(arry, 0, n-1, val);
				if(pos == -1)
				printf("\n %d is not found in the array", val);
				else
				printf("\n %d is found in the array at position arry [%d]", val, pos);
				getch();
				return(main());	
			}//interpolation search close
		
			case 5:
			{
				return(main());
			}//back to main menu close
		}//searching option close
	}//entire searching closed

	case 3:
	{
		clrscr();
		printf("\t\t\t\t!!!! Sorting !!!!");
		printf("\n================================================================================");
		printf("\n\n 1. Bubble Sort""\n\n 2. Selection Sort""\n\n 3. Insertion Sort""\n\n 4. Heap Sort""\n\n 5. Quick Sort""\n\n 6. Merge Sort""\n\n 7. Back to main menu");
		printf("\n================================================================================");
		printf("\n\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
			clrscr();
			printf("Bubble Sort\n");
			printf("================================================================================\n");
			printf("How many numbers are u going to enter?: ");
			scanf("%d",&count);
			printf("Enter %d numbers: ",count);
			for(i=0;i<count;i++)
			scanf("%d",&number[i]);
			//This is the main logic of bubble sort algorithm 
			for(i=count-2;i>=0;i--)
			{
			for(j=0;j<=i;j++)
			{
			if(number[j]>number[j+1])
			{
			temp=number[j];
			number[j]=number[j+1];
			number[j+1]=temp;
			}
			}
			}
			printf("Sorted elements: ");
			for(i=0;i<count;i++)
			printf(" %d",number[i]);
			getch();
			return(main());		
			}//bubble sort close
		
		
			case 2:
			{
			clrscr();
			printf("Selection Sort\n");
			printf("================================================================================\n");
			printf("How many numbers u are going to enter?: ");
			scanf("%d",&count);
			printf("Enter %d elements: ", count);
			// Loop to get the elements stored in array
			for(i=0;i<count;i++)
			scanf("%d",&number[i]);
			// Logic of selection sort algorithm
			for(i=0;i<count;i++)
			{
			for(j=i+1;j<count;j++)
			{
			if(number[i]>number[j])
			{
			temp=number[i];
			number[i]=number[j];
			number[j]=temp;
			}
			}
			}
			printf("Sorted elements: ");
			for(i=0;i<count;i++)
			printf(" %d",number[i]);
			getch();
			return(main());
			}//selection sort close
		
		
			case 3:
			{
			clrscr();
			printf("Insertion Sort\n");
			printf("================================================================================\n");
			printf("How many numbers u are going to enter?: ");
			scanf("%d",&count);
			printf("Enter %d elements: ", count);
			// This loop would store the input numbers in array
			for(i=0;i<count;i++)
			scanf("%d",&number[i]);
			// Implementation of insertion sort algorithm
			for(i=1;i<count;i++){
			temp=number[i];
			j=i-1;
			while((temp<number[j])&&(j>=0)){
			number[j+1]=number[j];
			j=j-1;
			}
			number[j+1]=temp;
			}
			printf("Order of Sorted elements: ");
			for(i=0;i<count;i++)
			printf(" %d",number[i]);
			getch();
			return(main());
			}// insertion sort close


			case 4:
			{
			clrscr();
			printf("Heap Sort\n");
			printf("================================================================================\n");
			printf("Enter no. of elements:");
			scanf("%d",&n);
			printf("\nEnter elements:");
			for(i=1;i<=n;i++)
			scanf("%d",&heap[i]);
			//create a heap
			heap[0]=n;
			create(heap);
			//sorting
			while(heap[0] > 1)
			{
			//swap heap[1] and heap[last]
			last=heap[0];
			temp=heap[1];
			heap[1]=heap[last];
			heap[last]=temp;
			heap[0]--;
			down_adjust(heap,1);
			}
			//print sorted data
			printf("\nArray after sorting:\n");
			for(i=1;i<=n;i++)
			printf("%d ",heap[i]);
			getch();
			return(main());
			}// heap sort close
		
		
			case 5:
			{
			clrscr();
			printf("Quick Sort\n");
			printf("================================================================================\n");
			printf("How many elements are u going to enter?: ");
			scanf("%d",&count);
			printf("Enter %d elements: ", count);
			for(i=0;i<count;i++)
			scanf("%d",&number[i]);
			quicksort(number,0,count-1);
			printf("Order of Sorted elements: ");
			for(i=0;i<count;i++)
			printf(" %d",number[i]);
			getch();
			return(main());
			}// quick sort close
		
		
			case 6:
			{
			clrscr();
			printf("Merge Sort\n");
			printf("================================================================================\n");
			printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
			for (i = 0; i < MAX_SIZE; i++)
			scanf("%d", &arr_sort[i]);
			printf("\nYour Data   :");
			for (i = 0; i < MAX_SIZE; i++)
			{
			printf("\t%d", arr_sort[i]);
			}
			merge_sort(0, MAX_SIZE - 1);
			printf("\n\nSorted Data :");
			for (i = 0; i < MAX_SIZE; i++) 
			{
			printf("\t%d", arr_sort[i]);
			}
			getch();
			return(main());	
			}// merge sort close
		
		
			case 7:
			{
			return(main());
			}//back to main menu close
		} // sorting option close
	}//entire case 3 close
	case 4:
	{
	clrscr();
	printf("\t\t\t!!!!!! Data Structures !!!!!!");
	printf("\n===============================================================================");
	printf("\n\n 1. Array""\n\n 2. Graph""\n\n 3. Linked List""\n\n 4. Queue""\n\n 5. Stack""\n\n 6. Structure""\n\n 7. Tree""\n\n 8. Back to main menu");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		{
			clrscr();
			printf("\n\n 1. Array of structure""\n\n 2. Array within struture""\n\n 3. Exit");
			printf("\n================================================================================");
			printf("\n\n Enter your choice :- ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				{
				clrscr();
				printf("Array of structure\n");
				printf("================================================================================\n");
				for(i = 0; i < MAX; i++ )
				{
				printf("\nEnter details of student %d\n\n", i+1);
				printf("Enter name: ");
				scanf("%s", arr_student[i].name);
				printf("Enter roll no: ");
				scanf("%d", &arr_student[i].roll_no);
				printf("Enter marks: ");
				scanf("%f", &arr_student[i].marks);
				}
				printf("\n");
				printf("Name\tRoll no\tMarks\n");
				for(i = 0; i < MAX; i++ )
				{
				printf("%s\t%d\t%.2f\n",
				arr_student[i].name, arr_student[i].roll_no, arr_student[i].marks);
				}
				getch();
				return(main());
				} //array of structure close

				case 2:
				{
				clrscr();
				printf("Array within structure\n");
				printf("================================================================================\n");
				printf("\n\nEnter Student Roll : ");
				scanf("%d",&S.Roll);
				printf("\n\nEnter Student Name : ");
				scanf("%s",&S.Name);
				S.Total = 0;
				for(i=0;i<3;i++)
				{
				printf("\n\nEnter Marks %d : ",i+1);
				scanf("%d",&S.Marks[i]);
				S.Total = S.Total + S.Marks[i];
				}
				S.Avg = S.Total / 3;
				printf("\nRoll : %d",S.Roll);
				printf("\nName : %s",S.Name);
				printf("\nTotal : %d",S.Total);
				printf("\nAverage : %.2f",S.Avg);
				getch();
				return(main());
				} //array within structre close
				
				case 3:
				{
				return(main());
				}//exit close
			} //array option close
		} //array entire close

	case 2:
	{   int n,i,s,ch,j;
	    char c,dummy;
		clrscr();
		printf("Graph\n");
		printf("================================================================================\n");
		printf("ENTER THE NUMBER VERTICES");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
		printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j);
		scanf("%d",&g[i][j]);
		}
		}
		printf("THE ADJACENCY MATRIX IS\n");
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
		printf("%d",g[i][j]);
		}
		printf("\n");
		}
		do
		{
		for(i=1;i<=n;i++)
		vis[i]=0;
		printf("\nMENU");
		printf("\n1.B.F.S");
		printf("\n2.D.F.S");
		printf("\n3.Exit");
		printf("\nENTER YOUR CHOICE");
		scanf("%d",&ch);
		if(ch==3)
		{
		exit(0);
		}
		printf("ENTER THE SOURCE VERTEX :");
		scanf("%d",&s);
		switch(ch)
		{
		case 1:
		bfs(s,n);
		break;
		case 2:
		dfs(s,n);
		break;
		}
		printf("DO U WANT TO CONTINUE(Y/N) ? ");
		scanf("%c",&dummy);
		scanf("%c",&c);
		clrscr();
		}while((c=='y')||(c=='Y'));
		return(main());	
	}//entire graph close

	case 3:
	{
			clrscr();
			printf("\n================================================================================");
			printf("\n\n 1. Singly Linked List""\n\n 2. Doubly Linked List""\n\n 3. Circular Linked List""\n\n 4. Exit");
			printf("\n================================================================================");

			printf("\n\n Enter your choice :- ");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
			clrscr();
			printf("Singly Linked List\n");
			printf("================================================================================\n");
			 while(1)
			{
			printf("\n 1.Create\n");
			printf("\n 2.Display\n");
			printf("\n 3.Insert at the beginning\n");
			printf("\n 4.Insert at the end\n");
			printf("\n 5.Insert at specified position\n");
			printf("\n 6.Delete from beginning\n");
			printf("\n 7.Delete from the end\n");
			printf("\n 8.Delete from specified position\n");
			printf("\n 9.Exit \n");

			printf("Enter your choice:\t");
			scanf("%d",&choice);
			switch(choice)
			{
		    case 1:
		    create1();
		    break;

		    case 2:
		    display1();
		    break;

		    case 3:
		    insert_begin1();
		    break;

		    case 4:
		    insert_end1();
		    break;

		    case 5:
		    insert_pos1();
		    break;

		    case 6:
		    delete_begin1();
		    break;

		    case 7:
		    delete_end1();
		    break;

		    case 8:
		    delete_pos1();
		    break;

		    case 9:
		    exit(0);

		    default:
		    printf("\n Wrong Choice:\n");
			}
			}
			}

			case 2:
			{
				int ch;
				h = NULL;
				temp=temp = NULL;
				clrscr();
				printf("Doubly Linked List\n");
				printf("================================================================================\n");
				while (1)
				{
				printf("\n 1. Insert at beginning\n");
				printf("\n 2. Insert at end\n");
				printf("\n 3. Insert at position i\n");
				printf("\n 4. Delete at i\n");
				printf("\n 5. Display from beginning\n");
				printf("\n 6. Display from end\n");
				printf("\n 7. Search for element\n");
				printf("\n 8. Sort the list\n");
				printf("\n 9. Update an element\n");
				printf("\n 10. Exit\n");

				printf("\n Enter choice : ");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
				insert1();
				break;

				case 2:
				insert2();
				break;

				case 3:
				insert3();
				break;

				case 4:
				delete();
				break;

				case 5:
				traversebeg();
				break;

				case 6:
				temp2 = h;
				if (temp2 == NULL)
				printf("\n Error : List empty to display ");
				else
				{
				printf("\n Reverse order of linked list is : ");
				traverseend(temp2->n);
				}
				break;

				case 7:
				search();
				break;

				case 8:
				sort();
				break;

				case 9:
				update();
				break;

				case 10:
				exit(0);

				default:
				printf("\n Wrong choice menu");
				}
				}
			} //doubly linked list closing

			case 3:
			{
				    int ch;
					clrscr();
					printf("Circular Linked List\n");
					printf("================================================================================\n");
					while (1)
					{
					printf("\n 1.Creation \n 2.Insertion at beginning \n 3.Insertion at remaining \n 4.Deletion at beginning \n 5.Deletion at remaining \n 6.traverse \n 7.Search \n 8.sort \n 9.update \n 10.reverse traverse \n 11. exit \n");
					printf("\n Enter your choice:");
					scanf("%d", &ch);
					switch(ch)
					{
					case 1:
					create3();
					break;

					case 2:
					ins_at_beg3();
					break;

					case 3:
					ins_at_pos3();
					break;

					case 4:
					del_at_beg3();
					break;

					case 5:
					del_at_pos3();
					break;

					case 6:
					traverse3();
					break;

					case 7:
					search3();
					break;

					case 8:
					sort3();
					break;

					case 9:
					update3();
					break;

					case 10:
					rev_traverse3(head);
					break;

					case 11:
					exit(0);

					default:
					printf("\n Wrong choice menu");
					}
					}

			}//circular linked list close

			case 4:
				{
				return(main());
				}//exit close
		} //linked list option close
	} //entire linked list close

	case 4:
	{
			clrscr();
			printf("\n================================================================================");
			printf("\n\n 1. Simple Queue""\n\n 2. Double Ended Queue""\n\n 3. Circular Queue""\n\n 4.Exit");
			printf("\n================================================================================");

			printf("\n\n Enter your choice :- ");
			scanf("%d",&choice);
			switch(choice)
		{
			case 1:
			{
				clrscr();
				printf("Simple Queue\n");
				printf("================================================================================\n");
				while (1)
				{
				printf("\n\n 1.Insert element to queue ");
				printf("\n\n 2.Delete element from queue ");
				printf("\n\n 3.Display all elements of queue ");
				printf("\n\n 4.Quit ");
				printf("Enter your choice : ");
				scanf("%d", &choice);
				switch(choice)
				{
				case 1:
				insertQ();
				break;
				case 2:
				deleteq();
				break;
				case 3:
				displayq();
				break;
				case 4:
				exit(0);
				default:
				printf("\n Wrong choice menu");
				}
				}
			}// simple queue close

			case 2:
			{
				clrscr();
				printf("Double Ended Queue\n");
				printf("================================================================================\n");
				do
				{
				printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
				printf("\n6.Print\n7.Exit\n\nEnter your choice:");
				scanf("%d",&op);
				switch(op)
				{
				case 1:
				printf("\nEnter number of elements:");
				scanf("%d",&n);
				initializedq(&q);
				printf("\nEnter the data:");
				for(i=0;i<n;i++)
				{
				scanf("%d",&x);
				if(fulldq(&q))
				{
				printf("\nQueue is full!!");
				exit(0);
				}
				enqueueR(&q,x);
				}
				break;
				case 2:
				printf("\nEnter element to be inserted:");
				scanf("%d",&x);
				if(fulldq(&q))
				{
				printf("\nQueue is full!!");
				exit(0);
				}
				enqueueR(&q,x);
				break;
				case 3:
				printf("\nEnter the element to be inserted:");
				scanf("%d",&x);
				if(fulldq(&q))
				{
				printf("\nQueue is full!!");
				exit(0);
				}
				enqueueF(&q,x);
				break;
				case 4:
				if(emptydq(&q))
				{
				printf("\nQueue is empty!!");
				exit(0);
				}
				x=dequeueR(&q);
				printf("\nElement deleted is %d\n",x);
				break;
				case 5:
				if(emptydq(&q))
				{
				printf("\nQueue is empty!!");
				exit(0);
				}
				x=dequeueF(&q);
				printf("\nElement deleted is %d\n",x);
				break;
				case 6:
			      printdq(&q);
				break;
				default:
				break;
				}
				}while(op!=7);

			}//double ended queue close

			case 3:
			{
				clrscr();
				printf("Circular Queue\n");
				printf("================================================================================\n");
			do
			{
			printf("1.Insertn");
			printf("2.Deleten");
			printf("3.Displayn");
			printf("4.Quitn");
			printf("Enter your choice : ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1 :
			printf("Input the element for insertion in queue : ");
			scanf("%d", &item);
			insertcq(item);
			break;
			case 2 :
			deletioncq();
			break;
			case 3:
			displaycq();
			break;
			case 4:
			break;
			default:
			printf("Wrong choicen");
			}
			}while(choice!=4);
			}//circular queue close
			
			case 4:
			{
			return(main());
			}//exit from queue option close
		}// queue option close
	} // entire queue closing 
	
	case 5:
	{
		    	int ch;
				clrscr();
				printf("Stack\n");
				printf("================================================================================\n");
				while(1)	//infinite loop, will end when choice will be 4
				{
				printf("\n*** Stack Menu ***");
				printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
				printf("\n\nEnter your choice(1-4):");
				scanf("%d",&ch);
				clrscr();
				switch(ch)
			{
				case 1: pushstack();
				break;
				case 2: popstack();
				break;
				case 3: displaystack();
				break;
				case 4: exit(0);
				default: printf("\nWrong Choice!!");
			}
				}
	}//entire stack close
	
	case 6:
	{
				clrscr();
				printf("Structre\n");
				printf("================================================================================\n");
				printf("\n\nEnter Candidate No : ");
				scanf("%d",&S.Roll);
				printf("\n\nEnter candidate Name : ");
				scanf("%s",&S.Name);
				S.Total = 0;
				for(i=0;i<3;i++)
				{
				printf("\n\nEnter Marks %d : ",i+1);
				scanf("%d",&S.Marks[i]);
				S.Total = S.Total + S.Marks[i];
				}
				S.Avg = S.Total / 3;
				printf("\nNo : %d",S.Roll);
				printf("\nName : %s",S.Name);
				printf("\nTotal : %d",S.Total);
				printf("\nAverage : %.2f",S.Avg);
				getch();
				return(main());
	}// entire structure close
	
	case 7:
	{	
		clrscr();
		printf("Tree\n");
		printf("================================================================================\n");
		printf("Results based on the already entered data:-\n");
		insertleft(root,1);
		insertright(root,2);
		insertleft(root->left,3);
		insertright(root->left,4);
		printf(" Inorder Traversal \n");
		inorder(root);
		printf("\n preorder traversal \n");
		preorder(root);
		printf("\n postorder traversal \n");
		postorder(root);
		getch();
		return(main());
	}//entire tree close
	
	case 8:
	{
	return(main());
	}//back to main menu close
	} //data structure closing 
	} //case 4 closing 
	
	
	case 5:
	{
	clrscr();
	printf("\t\t\t\t!!!! Pyramids !!!!!");
	printf("\n===============================================================================");
	printf("\n\n 1. Half Pyramid""\n\n 2. Inverted Half Pyramid""\n\n 3. Full Pyramid""\n\n 4. Inverted Full Pyramid""\n\n 5. Pascal's Triangle""\n\n 6. Floyd's Triangle""\n\n 7. Back to main menu");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			int i, j, rows;
			clrscr();
			printf("Half Pyramid\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=1; i<=rows; ++i)
			{
			for (j=1; j<=i; ++j)
			{
			printf("* ");
			}
			printf("\n");
			}
			getch();
			return(main());
		}//half pyramid close

		case 2:
		{
			int i, j, rows;
			clrscr();
			printf("Inverted Half Pyramid\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=rows; i>=1; --i)
			{
			for (j=1; j<=i; ++j)
			{
			printf("* ");
			}
			printf("\n");
			}
			getch();
			return(main());
		}//inverted half pyramid close

		case 3:
		{
			int i, space, rows, k=0;
			clrscr();
			printf("Full Pyramid\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=1; i<=rows; ++i,k=0)
			{
			for (space=1; space<=rows-i; ++space)
			{
			printf("  ");
			}
			while (k!=2*i-1)
			{
			printf("* ");
			++k;
			}
			printf("\n");
			}
			getch();
			return(main());
		}//full pyramid close

		case 4:
		{
			int rows, i, j, space;
			clrscr();
			printf("Fully Inverted Pyramid\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=rows; i>=1; --i)
			{
			for (space=0; space<rows-i; ++space)
			printf("  ");
			for (j=i; j<=2*i-1; ++j)
			printf("* ");
			for (j=0; j<i-1; ++j)
			printf("* ");
			printf("\n");
			}
			getch();
			return(main());
		}//inverted full pyramid close

		case 5:
		{
			int rows, coef=1, space, i, j;
			clrscr();
			printf("Pascal's Triangle\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=0; i<rows; i++)
			{
			for (space=1; space <= rows-i; space++)
			printf("  ");
			for (j=0; j<=i; j++)
			{
			if (j==0 || i==0)
			coef = 1;
			else
			coef=coef*(i-j+1)/j;
			printf("%4d", coef);
			}
			printf("\n");
			}
			getch();
			return(main());
		}//pascal's triangle close


		case 6:
		{
			int rows, i, j, number= 1;
			clrscr();
			printf("Floyd's Triangle\n");
			printf("================================================================================\n");
			printf("Enter number of rows: ");
			scanf("%d", &rows);
			for (i=1; i<=rows; i++)
			{
			for (j=1; j<=i; ++j)
			{
			printf("%d ", number);
			++number;
			}
			printf("\n");
			}
			getch();
			return(main());
		}//floyd's triangle close

		case 7:
		{
			return(main());
		}//back to main menu close
	} //pyramid option close 
	} //case 5 close 
	
	
	case 6:
	{
	clrscr();
	printf("\t\t\t!!!!! Arguments & Parameter Passing !!!!");
	printf("\n===============================================================================");
	printf("\n\n 1. No Argument & No Return Type""\n\n 2. No Argument & Return Type""\n\n 3. Argument & No Return Type""\n\n 4. Argument & Return Type""\n\n 5. Back to main menu");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
		clrscr();
		printf("No Argument & No Return Type\n");
		printf("================================================================================\n");
		fact1();
		getch();
		return(main());
		}//no argument & no return type close
		
		
		
		case 2:
		{
		int c;
		clrscr();
		printf("No Argument & Return Type\n");
		printf("================================================================================\n");
		c=fact2();
		printf("\nfactorial is:- %d",c);
		getch();
		return(main());
		}//no argument & return type
		
		
		case 3:
		{
		int a;
		clrscr();
		printf("Argument & No Return Type\n");
		printf("================================================================================\n");
		printf("enter number:- ");
		scanf("%d",&a);
		fact3(a);
		getch();
		return(main());
		}//argument and no return type close


		case 4:
		{
		int a;
		clrscr();
		printf("Argument & Return Type\n");
		printf("================================================================================\n");
		printf("enter number:- ");
		scanf("%d",&a);
		fact4(a);
		getch();
		return(main());
		}//argument and return type
		
		
		case 5:
		{
		return(main());
		}//back to main menu close
	}//entire arguments & parameter passing close
	} //case 6 close
	
	
	case 7:
	{
	clrscr();
	printf("\t\t\t!!!!! Areas Of Geometrical Figures !!!!");
	printf("\n===============================================================================");
	printf("");
	printf("\n 1. Area Of A Circle""\n 2. Area Of A Triangle""\n 3. Area Of Parallelogram""\n 4. Area Of Rhombus""\n 5. Area Of Right Angled Triangle""\n 6. Area Of Trapezium""\n 7. Perimeter Of Triangle""\n 8. Volume Of A Cone""\n 9. Volume Of A Cube""\n 10. Volume Of Cuboids""\n 11. Volume Of Cylinder""\n 12. Volume Of Sphere""\n 13. Back to main menu");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
{
	case 1:
	    {
			float radius, area;
			clrscr();
			printf("Area Of Circle\n");
			printf("================================================================================\n");
			printf("Enter the radius of a circle \n");
			scanf("%f", &radius);
			area = PI * pow(radius, 2);
			printf("Area of a circle = %5.2f\n", area);
			getch();
			return(main());
		}//area of circle close

	case 2:
		{
			int s, a, b, c, area;
			clrscr();
			printf("Area Of Triangle\n");
			printf("================================================================================\n");
			printf("Enter the values of a, b and c \n");
			scanf("%d %d %d", &a, &b, &c);
			s = (a + b + c) / 2;
			area = sqrt(s * (s - a) * (s - b) * (s - c));
			printf("Area of a triangle = %d \n", area);
			getch();
			return(main());
		}//area of triangle close


	case 3:
		{
			float base, altitude;
			float area;
			clrscr();
			printf("Area Of Parallelogram\n");
			printf("================================================================================\n");
			printf("Enter base and altitude of the given Parallelogram: \n ");
			scanf("%f%f", &base, &altitude);
			area = base * altitude;
			printf("Area of Parallelogram is: %.3f\n", area);
			getch();
			return(main());
		}//area of parallelogram close
		
	
	case 4:
		{
			float diagonal1, diagonal2;
			float area;
			clrscr();
			printf("Area Of Rhombus\n");
			printf("================================================================================\n");
			printf("Enter diagonals of the given rhombus: \n ");
			scanf("%f%f", &diagonal1, &diagonal2);
			area = 0.5 * diagonal1 * diagonal2;
			printf("Area of rhombus is: %.3f \n", area);
			getch();
			return(main());
		}//area of rhombus close
		
		
	case 5:
		{
			float height, width;
			float area;
			clrscr();
			printf("Area Of Right Angled Triangle\n");
			printf("================================================================================\n");
			printf("Enter height and width of the given triangle:\n ");
			scanf("%f%f", &height, &width);
			area = 0.5 * height * width;
			printf("Area of right angled triangle is: %.3f\n", area);
			getch();
			return(main());
		}//area of right angled triangle close
		
		
	case 6:
		{
			float a, b, h;
			float area;
			clrscr();
			printf("Area Of Trapezium\n");
			printf("================================================================================\n");
			printf("Enter the value for two bases & height of the trapezium: \n");
			scanf("%f%f%f", &a, &b, &h);
			area = 0.5 * (a + b) * h ;
			printf("Area of the trapezium is: %.3f", area);
			getch();
			return(main());
		}//area of trapezium
		
		
	case 7:
		{
			float a, b, c;
			float perimeter;
			clrscr();
			printf("Perimeter Of Triangle\n");
			printf("================================================================================\n");
			printf("\n Perimeter of triangle \n");
			printf("---------------------------");
			printf("\n Enter the size of all sides of the triangle :\n ");
			scanf("%f%f%f", &a, &b, &c);
			perimeter = a + b + c;
			printf("Perimeter of triangle is: %.3f", perimeter);
			getch();
			return(main());
		}//perimeter of triangle
		
		
	case 8:
		{
			float radius, height;
			float volume;
			clrscr();
			printf("Volume Of Cone\n");
			printf("================================================================================\n");
			printf("Enter value of radius and height of a cone :\n ");
			scanf("%f%f", &radius, &height);
			volume = (1.0/3) * (22 / 7) * radius * radius * height;
			printf("Volume of cone is : %.3f", volume);
			getch();
			return(main());
		}//volume of cone close
		

	case 9:
		{
			float side, volume;
			clrscr();
			printf("Volume Of Cube\n");
			printf("================================================================================\n");
			printf("Enter the length of a side \n");
			scanf("%f", &side);
			volume = pow(side, 3);
			printf("Volume = %6.2f \n",volume);
			getch();
			return(main());
		}//volume of cube close
		

	case 10:
		{
			int width, length, height;
			float volume;
			clrscr();
			printf("Volume Of Cuboid\n");
			printf("================================================================================\n");
			printf("Enter value of width, length & height of the cuboids:\n");
			scanf("%d%d%d", &width, &length, &height);
			volume = width * length * height;
			printf("\n Volume of cuboids is : %.3f", volume);
			getch();
			return(main());
		}//volume of cuboid close

		
	case 11:
		{
			float radius, height;
			float volume;
			clrscr();
			printf("Volume Of Cylinder\n");
			printf("================================================================================\n");
			printf("Enter  value for  radius and height of a cylinder : \n");
			scanf("%f%f", &radius, &height);
			volume = (22 / 7) * radius * radius * height;
			printf("\n Volume of cylinder is : %.3f", volume);
			getch();
			return(main());
		}//volume of cylinder close
		
		
	case 12:
		{
			int radius;
			float volume;
			clrscr();
			printf("Volume Of Sphere\n");
			printf("================================================================================\n");
			printf("Enter radius of the sphere : \n");
			scanf("%d", &radius);
			volume = (4.0/3) * (22/7) * radius * radius * radius;
			printf("Volume of sphere is : %.3f", volume);
			getch();
			return(main());
		}//volume of sphere close
		
		
	case 13:
		{
			return(main());
		}//back to main menu close
	} //area of geometrical figure option close 

	} //case 7 close

	
	case 8:
	{
	clrscr();
	printf("\t\t\t!!!!! Computer Networks & File Handling !!!!");
	printf("\n===============================================================================");
	printf("");
	printf("\n\n 1. Bits Stuffing""\n\n 2. Hamming Error Correction""\n\n 3. Hamming Distance""\n\n 4. Cyclic redundancy check (CRC)""\n\n 5. Stop & Wait Protocol""\n\n 6. File Content Coppying""\n\n 7. Back to main menu");
	printf("\n================================================================================");
	printf("\n\n Enter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			int a[20],b[30],i,j,k,count,n;
			clrscr();
			printf("Bits Stuffing\n");
			printf("================================================================================\n");
			printf("Enter the frame size");
			scanf("%d",&n);
			printf("Enter the frame in the form of 0 &1:");
			for (i=0;i<n;i++)
			scanf("%d",&a[i]);
			i=0;
			count=1;
			j=0;
			while(i<n)
			{
			if(a[i]==1)
			{
			b[j]=a[i];
			for (k=i+1;a[k]==1 && k<n && count<5;k++)
			{
			j++;
			b[j]=a[k];
			count++;
			if (count==5)
			{
			j++;
			b[j]=0;
			count=0;
			}
			i=k;
			}
			}
			else
			{
			b[j]=a[i];
			count=0;
			}
			i++;
			j++;
			}
			printf("After Bit stuffing:");
			for(i=0;i<j;i++)
			printf("%d",b[i]);
			getch();
			return(main());
		}//bit stuffing close

	
	case 2:
		{
			
			int data[7],rec[7],i,c1,c2,c3,c;
			clrscr();
			printf("Hamming Error Correction\n");
			printf("================================================================================\n");
			printf("this works for message of 4bits in size \nenter message bit one by one:  ");
			scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);
			data[6]=data[0]^data[2]^data[4];
			data[5]=data[0]^data[1]^data[4];
			data[3]=data[0]^data[1]^data[2];
			printf("\nthe encoded bits are given below: \n");
			for (i=0;i<7;i++)
			{
			printf("%d ",data[i]);
			}
			printf("\nenter the received data bits one by one: ");
			for (i=0;i<7;i++)
			{
			scanf("%d",&rec[i]);
			}
			c1=rec[6]^rec[4]^rec[2]^rec[0];
			c2=rec[5]^rec[4]^rec[1]^rec[0];
			c3=rec[3]^rec[2]^rec[1]^rec[0];
			c=c3*4+c2*2+c1 ;
			if(c==0) {
			printf("\ncongratulations there is no error: ");
			} 
			else 
			{
			printf("\nerron on the postion: %d\nthe correct message is \n",c);
			if(rec[7-c]==0)
			rec[7-c]=1; else
		 	rec[7-c]=0;
			for (i=0;i<7;i++)
			{
			printf("%d ",rec[i]);
			}
			}
			getch();		
			return(main());
		}//hamming error correction close
	
	case 3:
		{
			int i,length,count=0;
			char v1[8],v2[8];
			clrscr();
			printf("Hamming Distance\n");
			printf("================================================================================\n");
			printf("\nWrite a Program to Find Hamming Distance\n");
			printf("Enter 1st String : ");
			scanf("%s",&v1);
			printf("Enter 2nd String : ");
			scanf("%s",&v2);
			length=strlen(v2);
			for(i=0;i<length;i++)
			{
            if(v1[i]!=v2[i])
            {
            count++;
            }
			}
			printf("\nHamming Distance : %d",count);
			getch();
			return(main());
		}//hamming distance close
		
	case 4:
		{	
			int i,j,keylen,msglen;
			char input[100], key[30],temp[30],quot[100],rem[30],key1[30];
			clrscr();
			printf("Cyclic Redundancy Check\n");
			printf("================================================================================\n");
			printf("Enter Data: ");
			gets(input);
			printf("Enter Key: ");
			gets(key);
			keylen=strlen(key);
			msglen=strlen(input);
			strcpy(key1,key);
			for(i=0;i<keylen-1;i++)
			{
			input[msglen+i]='0';
			}
			for(i=0;i<keylen;i++)
			temp[i]=input[i];
			for(i=0;i<msglen;i++)
			{
			quot[i]=temp[0];
			if(quot[i]=='0')
			for(j=0;j<keylen;j++)
			key[j]='0';
			else
			for(j=0;j<keylen;j++)
			key[j]=key1[j];
			for(j=keylen-1;j>0;j--)
			{
            if(temp[j]==key[j])
            rem[j-1]='0';
            else
            rem[j-1]='1';
			}
			rem[keylen-1]=input[i+keylen];
			strcpy(temp,rem);
			}
			strcpy(rem,temp);
			printf("\nQuotient is ");
			for(i=0;i<msglen;i++)
			printf("%c",quot[i]);
			printf("\nRemainder is ");
			for(i=0;i<keylen-1;i++)
			printf("%c",rem[i]);
			printf("\nFinal data is: ");
			for(i=0;i<msglen;i++)
			printf("%c",input[i]);
			for(i=0;i<keylen-1;i++)
			printf("%c",rem[i]);
			getch();
			return(main());
		}//cyclic redundancy check close

	case 5:
		{
			int i,j,noframes,x,x1=10,x2;
			clrscr();
			printf("Stop & Wait Protocol\n");
			printf("================================================================================\n");
			for(i=0;i<200;i++)
			rand();
			noframes=rand()/200;
			i=1;
			j=1;
			noframes = noframes / 8;
			printf("\n number of frames is %d",noframes);
			getch();
			while(noframes>0)
			{
			printf("\nsending frame %d",i);
			srand(x1++);
			x = rand()%10;
			if(x%2 == 0)
			{
			for (x2=1; x2<2; x2++)
			{
			printf("waiting for %d seconds\n", x2);
			sleep(x2);
			}
			printf("\nsending frame %d",i);
			srand(x1++);
			x = rand()%10;
			}
			printf("\nack for frame %d",j);
			noframes-=1;
			i++;
			j++;
			}
			printf("\n end of stop and wait protocol");
			getch();
			return(main());
		}//stop and wait protocol close

	case 6:
		{

			FILE *fp1,*fp2;
			char ch;
			clrscr();
			printf("File Handling\n");
			printf("================================================================================\n");
			printf("NOTE:-\nmake sure that you have created the -> original.txt <- file with some data in it");
			printf("\nFile is successfully coppied...!""\nYour data has been coppied into -> duplicate.txt <- file ");
			fp1=fopen("original.txt","r");
			fp2=fopen("duplicate.txt","w");
			while((ch=getc(fp1))!=EOF)
			putc(ch,fp2);
			fclose(fp1);
			fclose(fp2);
			getch();
			return(main());
		}//file handling close

	case 7:
		{
			return(main());
		}//back to main menu close
	} // Computer Networks & File Handling  close 
	} //case 8 close 
	
	
	case 9:
	{
	exit(0);
	}
	default:
	{
	printf("\n\n You Have Entered Wrong Choice");
	}
} // catagories option close
return(0);
}//main close
 





