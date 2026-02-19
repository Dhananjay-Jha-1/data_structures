// creating and display linked list 

#include <stdio.h>
#include <stdlib.h>

// alright, so I have to make a node first which has 2 field -- data and pointer to node
struct Node
{
    int data;
    struct Node* next;
};

//lets create the head (first) pointer which is also of the type Node*
struct Node* first = NULL;

void create_linked_list( int A[], int n)
{
    struct Node *temp, *last;
    
    //creating the first node
    //memory allocation for the 1st node, since malloc return a void*, we typecast it to struct Node*
    first = (struct Node*) malloc(sizeof(struct Node));    
    first->data = A[0];
    first->next = NULL;
    last = first;      // now, last also points to the first Node 

    // now creating more nodes, i = 1 because the 1st node is already created
    for(int i = 1; i < n; i++)
    {
        temp = (struct Node*) malloc(sizeof(struct Node)); 
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;    // this is the statement which links the first node to the second node when i=1
        last = temp;
        
    }
}

void display_linked_list(struct Node* p )
{
    while( p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main(void)
{
    int A[] = {1, 2, 3, 4, 5};

    create_linked_list(A, 5);

    display_linked_list(first);

    return 0;
}
