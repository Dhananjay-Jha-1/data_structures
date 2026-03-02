//  delete a node in a linked list

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
void display_ll(struct Node* p);
int delete_ll(int position);

int main(void)
{
    input_ll();
    
    int position;
    printf("Enter the position at which the node must be deleted : ");
    scanf("%d", &position);
    printf("The value deleted at the node was %d :", delete_ll(position));
    
    display_ll(first);

    return 0;
}

void input_ll(void)
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    create_ll(A, n);
}

void create_ll(int A[], int n)
{
    struct Node *t, *last;
    
    if(n == 0)
    {
        first = NULL;
        return;
    }
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

int delete_ll(int position)
{
    struct Node* p = first, *q = NULL;
    int deleted_value = 0;
    //now we have some cases 
    //empty list --> p = NULL
    if(p == NULL)
    {
        printf("No node to be deleted ");
        return -1;
    }
    //delete first node
    if(position == 1)
    {
        first = p->next;
        deleted_value = p->data;
        free(p);
        return deleted_value;
    }

    for(int i = 0; i < position-1 && p; i++)
    {
        q = p;   
        p = p->next;
    }
    if(p)
    {
        q->next = p->next;
        deleted_value = p->data;
        free(p);
    }
    return deleted_value;
}

void display_ll(struct Node* p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}











