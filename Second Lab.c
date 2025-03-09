// 232. Implement Queue using Stacks
#include <stdio.h>
#include <stdlib.h>

//Setting Up Linked List
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;
// Setting Up Stack
typedef struct 
{
    Node* top;
} Stack;

// Function for newNode
Node* newNode(int data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Intializing Stack with the Top being NULL since nothing is in it yet
void initStack(Stack* stack) 
{
    stack->top = NULL;
}

//IsEmpty to check if stack is empty or not
int isEmpty(Stack* stack) 
{
    return stack->top == NULL;
}

// Push() function to put new value on top of stack
void push(Stack* stack, int data) 
{
    Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Pop() to remove item from top of stack
int pop(Stack* stack) 
{
    if (isEmpty(stack))
    {
      return -1; //Notifies me if Underflow
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;// Returned what value was popped
}

// Setting up Queue
typedef struct 
{
    Stack stack1; //Incoming
    Stack stack2; //Reverse for dequeuing later on
} MyQueue;

// Create queue
MyQueue* myQueueCreate() 
{
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    initStack(&queue->stack1);
    initStack(&queue->stack2);
    return queue;
}

// Push element to the back of queue
void myQueuePush(MyQueue* obj, int x) 
{
    push(&obj->stack1, x); // This part will always push to stack1
}

// Pop just like above but for queue
int myQueuePop(MyQueue* obj) 
{
    if (isEmpty(&obj->stack2)) // However if stack2 is empty, we can transfer elements from stack1
    {
        while (!isEmpty(&obj->stack1)) 
        {
            push(&obj->stack2, pop(&obj->stack1));
        }
    }
    return pop(&obj->stack2); // Pop from stack2 so everything is in the correct order
}

// Get front element
int myQueuePeek(MyQueue* obj) 
{
    if (isEmpty(&obj->stack2)) //if empty move to stack1
    {
        while (!isEmpty(&obj->stack1))  //if empty move to stack2
        {
            push(&obj->stack2, pop(&obj->stack1));
        }
    }
    return obj->stack2.top->data; //return the top element for stack2
}

bool myQueueEmpty(MyQueue* obj) 
{
    return isEmpty(&obj->stack1) && isEmpty(&obj->stack2); //if queue = empty both stacks are empty
}

// Memory
void myQueueFree(MyQueue* obj) 
{
    free(obj);
}
