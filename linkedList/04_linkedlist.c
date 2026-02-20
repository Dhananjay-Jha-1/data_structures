// write a function to return the sum of all the elements in the linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first;

void create_ll(int A[], int n);

int sum_ll(struct Node* p);

int main(void)
{
    int n;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create_ll(A, n);

    printf("%d",sum_ll(first));

    return 0;
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

int sum_ll(struct Node* p)
{
    int sum = 0;
    while(p!=NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}





























