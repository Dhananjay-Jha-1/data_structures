// recursive function to display a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

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

void recursive_display(struct Node* p)
{
    if (p!=NULL)
    {
        printf("%d ", p->data);
        recursive_display(p->next);
    }   
}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5};

    create_linked_list(A, 5);

    recursive_display(first);

    return 0;
}
