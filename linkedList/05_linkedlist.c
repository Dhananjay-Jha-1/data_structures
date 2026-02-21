// find the max element in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void create_ll(int A[], int n);

int max_in_ll(struct Node* p);

int main(void)
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

    create_ll (A, n);

    printf("The maximum element is : %d\n",max_in_ll(first));

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

int max_in_ll(struct Node* p)
{
    int max = p->data;
    
    while(p!=NULL)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}



















