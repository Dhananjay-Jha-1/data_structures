// reverse a linked list using recursive function

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void create_linked_list(int A[], int n);

void reverse_display(struct Node* p);

int main(void)
{
    int n;
    printf("Enter the no of elements : ");
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create_linked_list(A, n);

    reverse_display(first);

    return 0;
}

void create_linked_list(int A[], int n)
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

void reverse_display(struct Node *p)
{
    if(p!=NULL)
    {
        reverse_display(p->next);
        printf("%d ", p->data);
    }
}


