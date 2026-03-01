// Insertion of a new node at any position in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void input_ll(void);

void create_ll(int A[], int n);

void insert(int value, int pos);

void display_ll(struct Node* p);

int main(void)
{
    input_ll();
    
    int value, position;
    printf("Value : ");
    scanf("%d", &value);
    printf("Position : ");
    scanf("%d", &position);
    
    printf("The original linked list is : ");
    display_ll(first);
    printf("\n");

    insert(value, position);
    
    printf("The linked list after insertion : ");
    display_ll(first);

    return 0;
}

void input_ll(void)
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements :");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    create_ll(A, n);
}

void create_ll(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;   
        last = t;
    }
}

void insert(int value, int pos)
{
    struct Node *t, *p;

    //for insertion before the 1st node
    if(pos == 0)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;
        t->next = first;
        first = t;
    }
    //for insertion of a node at any given postion
    else if(pos > 0)
    {
        p = first;
        for(int i = 0; i < pos && p!=NULL; i++)
        {
            p = p->next;                             // now p is pointing to a node after which we should add the Node
        }
        if(p)
        {
            t = (struct Node*) malloc(sizeof(struct Node));
            t->data = value;
            t->next = p->next;
            p->next = t;
        }
        else
            printf("The position is not suitable for the size of the linked list\n");
    }
}

void display_ll(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
























