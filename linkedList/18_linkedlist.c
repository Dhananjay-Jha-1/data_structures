// check whether the linked list is linear or circular 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* input_ll(void);
struct Node* create_ll(int A[], int n);
void make_circular_ll(struct Node* p);      //for testing 
int isCircular(struct Node* p);

int main(void)
{
    struct Node* head;
    head = input_ll();
    
    make_circular_ll(head);

    if(isCircular(head) == 1)
        printf("The linked list is circular\n");
    else
        printf("The linked list is linear\n");
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
    return create_ll(A, n);             // returns the pointer to the 1st node of the linked list
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
    return first;                    // returns the pointer to the 1st node of the linked list
}

void make_circular_ll(struct Node* p)
{
    struct Node* temp = p;          
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

int isCircular(struct Node* p)
{
   struct Node* q = p;

   while(q!=NULL && q->next != NULL)
   {
        p = p->next;                  // p traverses the linked list one node at a time
        q = q->next->next;            // q traverses the linked list two nodes at a time
        
        if(p == q)
            return 1;   //circular list
   }
   return 0;
}










