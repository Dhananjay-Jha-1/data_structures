//display a circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);
void make_circular_ll(struct Node* p);  // have to visit again
void display_ll(struct Node* p);

int main(void)
{
    struct Node* head = NULL;

    head = input_ll();

    make_circular_ll(head);

    display_ll(head);

    return 0;
}

struct Node* input_ll(void)
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
    return create_ll(A, n);
}

struct Node* create_ll(int A[], int n)
{
    if(n == 0)
    {
        return NULL;
    }

    struct Node *first, *t, *last;

    first = (struct Node*)malloc(sizeof(struct Node));
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
    p->next = temp;           // the last node points to the first node making the linked list circular
}

void display_ll(struct Node* p)
{
    struct Node* temp = p;

    do
    {
        printf("%d ", p->data);
        p = p->next;

    } while(p != temp);
}













