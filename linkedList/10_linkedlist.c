// inserting a node at the right position in a sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void input_sorted_ll(void);

void create_ll(int A[], int n);

void insert_sort(struct Node* p, int value);

void display_ll(struct Node* p);

int main(void)
{
    input_sorted_ll();

    int value;
    printf("Enter the value to be inserted : ");
    scanf("%d", &value);
    insert_sort(first, value);

    display_ll(first);
}

void input_sorted_ll(void)
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements in sorted order : ");
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

void insert_sort(struct Node* p, int value)
{
    struct Node *q = NULL, *t;
    
    //if linked list is NULL
    if(p == NULL)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;
        t->next = NULL;
        first = t;
        return;
    }

    //if the value is smaller than the 1st node, we gotta insert the new node in the 0th position ,i.e., before the 1st node
    if(value < p->data)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;
        t->next = p;
        first = t;
        return;
    }

    //if the value is greater than the 1st node's data
    else
    {
        while(p!=NULL && p->data < value)
        {
            q = p;
            p = p->next;
        }
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = value;
        q->next = t;
        t->next = p;
    }
}

void display_ll(struct Node* p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}









