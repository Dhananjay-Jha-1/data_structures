// implementation of stack using array

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

void create_stack(struct stack* st);
void display_stack(struct stack st); 
void push(struct stack* st, int value);
int pop(struct stack* st);
int peek(struct stack st, int position);
int is_empty(struct stack st);
int is_full(struct stack st);
int stack_top(struct stack st);
void free_stack(struct stack* st);

int main(void)
{
    struct stack st;

    create_stack(&st);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 40);
    
    pop(&st); 
    
    printf("The elements in the stack are : \n");
    display_stack(st);

    printf("The element at position 2 is : %d ",peek(st, 2)); 
    
    free_stack(&st);

    return 0;
}


void create_stack(struct stack* st)
{
    printf("Enter the size of the stack : ");
    scanf("%d", &st->size);

    st->top = -1;

    st->arr = (int*)malloc(st->size * sizeof(int));
}

void display_stack(struct stack st)
{
    if(st.top == -1)
    {
    printf("The list is empty\n");
        return;
    }

    while(st.top >= 0)
    {
        printf("%d ", st.arr[st.top]);
        st.top--;
    }
}

void push(struct stack* st, int value)
{
    if(st->top == st->size - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    st->top++;
    st->arr[st->top] = value;
}

int pop(struct stack* st)
{
    int x = -1;
    
    if(st->top == -1)
    {
        printf("Stack underflow\n");
        return x;
    }

    x = st->arr[st->top];
    st->top--;

    return x;
}

int peek(struct stack st, int position)
{
    int index = st.top - position + 1;

    if(index < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    
    return st.arr[index];
}

int is_empty(struct stack st)
{
    if(st.top == -1)
    {
        return 1;   //true
    }
    else
    {
        return 0;  
    }
}

int is_full(struct stack st)
{
    if(st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_top(struct stack st)
{
    if(is_empty(st))
    {
        return -1;
    }
    else
    {
        return st.arr[st.top];
    }
}

//The OS frees it up but I am just doing it as a good little habbit
void free_stack(struct stack* st)
{
    if(st == NULL)
        return;

    free(st->arr);
    st->arr = NULL;   //avoids dangling pointer

}







