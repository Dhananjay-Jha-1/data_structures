// concatenation of 2 linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);
struct Node* join_ll(struct Node* p, struct Node* q);
void display_ll(struct Node* p);

int main(void)
{   
    struct Node* first = NULL, *second = NULL;
    struct Node* new = NULL;

    printf("First linked list : \n");
    first = input_ll();                   // input_ll() returns the 1st node of the linked list,  hence first points to the 1st node of the ll
    printf("Second linked list : \n");
    second = input_ll();                 // likewise, (hopefully) second points to the 1st node of the linked list

    new = join_ll(first, second);
    
    printf("The linked list after concatenation is : \n");
    display_ll(new);
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
    return create_ll(A, n);                     // returns the address of the 1st node to main
}

struct Node* create_ll(int A[], int n)
{
    if(n == 0)
    {
        return NULL;
    }
    struct Node *head, *t, *last;

    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;                // returns the address of the 1st node to input_ll() 
}

struct Node* join_ll(struct Node* p, struct Node* q)
{
    struct Node* temp = p;

    if(p == NULL)
    {   
        return q;        // if the first list is empty, the second list's elements must be printed, right 
    }

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return temp;
}

void display_ll(struct Node* p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}






