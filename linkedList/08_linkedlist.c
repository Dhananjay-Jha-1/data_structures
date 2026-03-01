// To improve linear search, we implement a method called as Move to head
// In this method, we move the node containing the key to the front so that if the key is searched again, it will be found at the first location itself

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void create_ll(int A[], int n);

struct Node* search(struct Node* p, int key);

void display_ll(struct Node* p);

int main(void)
{
    int n;
    printf("Enter the number of elements in the list : ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements :");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create_ll(A, n);

    printf("The original linked list is : ");
    display_ll(first);
    printf("\n");

    int key;
    printf("Enter the key :");
    scanf("%d", &key);
    
    struct Node* temp = NULL;
    temp = search(first, key);
    if(temp)
        printf("The key is found which is %d\n", temp->data);
    else
        printf("The key is not found\n");
 
    printf("After searching :");
    display_ll(first);
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

struct Node* search(struct Node* p, int key)
{
    struct Node *q = NULL;       // this pointer must follow p, i.e. if p is at position -- n, q is at position -- n-1

    while(p!=NULL)
    {
        if(key == p->data)
        {   
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// The display function is to check if move to head algorithm works or not 
void display_ll(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data); 
        p = p->next;
    }
}
















