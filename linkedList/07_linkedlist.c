// Searching in a linked list 
// Binary search is not suitable for a linked list as we cannot directly jump in the middle of the list, we have to traverse the list

// linear search in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void create_ll(int a[], int n);

struct Node* search(struct Node* p, int key);

int main(void)
{
    int n;
    printf("enter the number of elements : ");
    scanf("%d", &n);

    int a[n];
    printf("enter the elements : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    create_ll(a, n);
    
    int key;
    printf("enter the key : ");
    scanf("%d", &key);
    
    struct Node* temp;
    temp = search(first, key);
    
    if(temp)  
        printf("the key is found which is %d", temp->data);
    else
        printf("key is not found");

    return 0;
}

void create_ll(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

struct Node* search(struct Node* p, int key)
{
    while(p!=NULL)
    {
        if(p->data == key)    return p;
        p = p->next;
    }
    return NULL;
}










