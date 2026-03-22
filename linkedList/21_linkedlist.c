// delete a node in a circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);
void make_circular_ll(struct Node* p);
int length_ll(struct Node* p);
struct Node* delete_ll(int pos, struct Node* p);
void display_ll(struct Node* p);

int main(void)
{
    struct Node* head;

    head = input_ll();

    make_circular_ll(head);

    int pos;
    printf("Enter the position at which the node shall be deleted : ");
    scanf("%d", &pos);

    head = delete_ll(pos, head);
    
    display_ll(head);

    return 0;
}

struct Node* input_ll(void)
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
    return create_ll(A, n);
}

struct Node* create_ll(int A[], int n)
{
    if(n == 0)
    {
        return NULL;
    }

    struct Node *first, *t, *last;
    
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
    return first;
}

void make_circular_ll(struct Node* p)
{
    if(p == NULL)
    {
        return;
    }
    struct Node* temp = p;

    while(p->next != NULL) 
    {
        p = p->next;
    }
    p->next = temp;
}

struct Node* delete_ll(int pos, struct Node* p)
{
    if(pos <= 0 || pos > length_ll(p))
    {
        printf("Invalid position\n");
        return p;
    }
    else if(pos == 1)
    {
        struct Node* temp = p;

        do
        {
            p = p->next;
        }while(p->next != temp);
        
        p->next = temp->next;
        
        struct Node* new_head = temp->next;

        free(temp);

        return new_head;
    }
    else
    {
        struct Node* trail = p;
        struct Node* new_head = p;

        for(int i = 0; i < pos-1; i++)
        {
            trail = p;
            p = p->next;
        }
        trail->next = p->next;
        free(p);
        return new_head;
    }
}

void display_ll(struct Node* p)
{
    struct Node* temp = p;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while(p != temp);
}

int length_ll(struct Node* p)
{
    struct Node* temp = p;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    }while(p->next != temp);

    return count;
}








