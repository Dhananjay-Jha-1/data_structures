// reverse a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

// functions reqd. to reverse the linked list

void input_ll(void);
void create_ll(int A[], int n);
int size_ll(struct Node* p);
void reverse_ll(struct Node* p);
void display_ll(struct Node* p);

int main(void)
{
    input_ll();

    reverse_ll(first);
    display_ll(first);
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
    if(n == 0)
    {
        first  = NULL;
        return;
    }
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

int size_ll(struct Node* p)
{
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void reverse_ll(struct Node* p)
{
    int length = size_ll(p);
    int A[length];
    struct Node* q = p;
    for(int i = 0; i < length && p!=NULL; i++)
    {
        A[i] = p->data;
        p = p->next;
    }
    for(int i = length-1; i >= 0 && q!=NULL; i--)
    {
        q->data = A[i];
        q = q->next;
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









