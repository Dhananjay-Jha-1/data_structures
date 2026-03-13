// merge two linked list 
// merging is the process wherein 2 sorted linked lists are combined to form a single sorted list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);

struct Node* merge_ll(struct Node* first, struct Node* second);

void display_ll(struct Node* p);


int main(void)
{
    struct Node *first = NULL, *second = NULL, *new = NULL;

    printf("Input for first linked list : \n");
    first = input_ll();                                         
    printf("Input for second linked list : \n");
    second = input_ll();                                            
    
    new = merge_ll(first, second);

    printf("\n\n");
    printf("The merged linked list is : \n");
    display_ll(new);
}

struct Node* input_ll(void)
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

    return create_ll(A, n);
}

struct Node* create_ll(int A[], int n)
{
    struct Node *head, *t, *last;
    
    if(n == 0)
    {
        return NULL;
    }

    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;                              
}

struct Node* merge_ll(struct Node* first, struct Node* second)
{
    if(first == NULL)
    {
        return second;
    }
    struct Node *new, *last;
    if(first->data < second->data)
    {
        new = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        new = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }
    while(first!= NULL && second!=NULL)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
        if(first!=NULL)
        {
            last->next = first;
        }
        else
        {
            last->next = second;
        }
    }
    return new;
}

void display_ll(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

















