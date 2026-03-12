// reversing a linked list by reversing it's link

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
void reverse_ll(struct Node* p);
void display_ll(struct Node* p);

int main(void)
{
    input_ll();

    reverse_ll(first);
    
    printf("The linked list has been reversed as per you wish, Monsieur\n");
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
    if (n == 0)
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

// so the idea for reversing the linked list by reversing the links is :
// we need sliding pointers (p,q,r). slide and reverse the links is how we shall proceed
void reverse_ll(struct Node* p)
{
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL)
    {
        //sliding
        r = q;
        q = p;
        p = p->next;

        //reversing links
        q->next = r;
    }
    first = q;
}

void display_ll(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}












