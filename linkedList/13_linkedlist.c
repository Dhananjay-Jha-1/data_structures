// remove duplicate elements from a sorted linked list

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

void remove_duplicates(struct Node* p);

void display_ll(struct Node* p);

int main(void)
{
    input_ll();

    remove_duplicates(first);

    printf("The list with the removed duplicates is :");
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
        first = NULL;
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

void remove_duplicates(struct Node* p)
{
    struct Node* q = p->next;
    while(q!=NULL)
    {
        if(q->data != p->data)
        {
           p = q;
           q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
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









