// to check if the linked list is sorted or not

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void input_ll(void);

void create_ll(int A[], int n);

int check_sorted(struct Node* p);

int main(void)
{
    input_ll();
   
    if(check_sorted(first) != 0)
        printf("The linked list is sorted\n");
    else
        printf("The linked list is not sorted\n");
}

void input_ll(void)
{
    int n;
    printf("Enter the number of elements in the list : ");
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

int check_sorted(struct Node* p)
{
    int x = INT_MIN;
    while(p!=NULL)
    {
        if(p->data < x)      
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// just adding a small comment for commiting with a proper msg again, I f'ed up the last msg





































