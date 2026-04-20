//implementing a stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int element);
int pop(void);
int peek(int position);
void display(void);

int main(void)
{
    push(5);
    push(23);
    push(30);
    push(31);
    push(32);
    push(35);

    printf("The element deleted is : %d ", pop());

    printf("The element at the 3rd position is : %d ", peek(3));

    printf("Elements in the stack are : ");
    display();
}

void push(int element)
{
    // before pushing, checking if the list is full 
    struct Node* t;
    t = (struct Node*) malloc(sizeof(struct Node));

    if(t == NULL)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        t->data = element;
        t->next = top;
        top = t;
    }
}

int pop(void)
{
    struct Node* t = top;
    int x;

    //before deleting, checking if the list is empty
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        x = t->data;
        top = top->next;
        free(t);
        t = NULL;
    }
    return x;
}
 
int peek(int position)
{
    //checking if stack is empty as then there's nothing to peek
    if(top == NULL)
    {
        printf("There's nothing to peek, we got no elements in the stack for you\n");
        return -1;
    }
    struct Node* p = top;
    
    for(int i = 0; i < position-1 && p!=NULL; i++)
    {
        p = p->next;
    }
    if(p!=NULL)
        return p->data;
    else
    {
        printf("Invalid position\n");
        return -1;
    }
}

void display(void)
{
    struct Node* p = top;

    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int stack_top(void)
{
    //checking if stack is empty
    if(top == NULL)
    {
        printf("No stack top as there are no elements in the stack\n");
        return -1;
    }
    return top->data;
}















