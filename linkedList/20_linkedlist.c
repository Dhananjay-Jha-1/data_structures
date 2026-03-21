//insert a node at a given position in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);
void make_circular_ll(struct Node* p);
void insert_ll(int value, int pos, struct Node* p);
void display_ll(struct Node* p);

int main(void)
{
    struct Node* head;

    head = input_ll();
        
    make_circular_ll(head);

    printf("Original linked list : \n\n");
    display_ll(head);
    
    int value, position;
    printf("Enter the value and position at which the node be inserted : ");
    scanf("%d %d", &value, &position);

    insert_ll(value, position, head);

    printf("\nModified linked list : \n");
    display_ll(head);

    return 0;
}

struct Node* input_ll(void)
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    return create_ll(A, n);
}

struct Node* create_ll(int A[], int n)
{
    if(n == 0)
    {
        return NULL;
    }
    struct Node* first, *t, *last;

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
    return first;
}

void make_circular_ll(struct Node* p)
{
    struct Node* temp = p;

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

void insert_ll(int value, int pos, struct Node *p)
{
    struct Node* t;

    if(pos < 0)
    {
        printf("No negative position is allowed\n");
        return;
    }
    else if(pos == 1)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;
        
        struct Node* temp = p;

        while(p->next != temp)
        {
            p = p->next;
        }
        p->next = t;
        t->next = temp;
    }
    else
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;

        for(int i = 0; i < pos-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void display_ll(struct Node* p)
{
    struct Node* temp = p;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while(p != temp);
}





































   

