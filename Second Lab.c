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

// 225. Implement Stack using Queues
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked list
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Queue
typedef struct 
{
    Node* front;
    Node* rear;
} Queue;

// As done before function to create new node
Node* newNode(int data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Initialize queue with both front and rear being set to null because nothing is in it yet
void initQueue(Queue* queue) 
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if queue is empty
bool isQueueEmpty(Queue* queue) 
{
    return queue->front == NULL;
}

// Enqueue an element (push to rear)
void enqueue(Queue* queue, int data) 
{
    Node* node = newNode(data);
    if (queue->rear == NULL) 
    {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node; //Add the new node @ the rear FIFO
    queue->rear = node;
}

// Dequeue an element (pop from front)
int dequeue(Queue* queue) 
{
    if (isQueueEmpty(queue))
    {    
        return -1; // Make sure we don't underflow
    }
    Node* temp = queue->front; //Temp to store front node
    int data = temp->data; //Transfer data to front
    queue->front = queue->front->next; //Moving on to next node
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return data; // Returns the dequeued value
}

// Set up Stack with two queues
typedef struct 
{
    Queue queue1; // Main queue
    Queue queue2; // Temp queue for operations
} MyStack;

//Initializing stack
MyStack* myStackCreate() 
{
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->queue1); //Intializing queues into stack 
    initQueue(&stack->queue2); 
    return stack;
}

// Push element onto stack
void myStackPush(MyStack* obj, int x) 
{
    enqueue(&obj->queue1, x); //Enqueues into queue1
}

// Remove element from top of stack
int myStackPop(MyStack* obj) {
    if (isQueueEmpty(&obj->queue1)) 
    {    
        return -1; //stops underflow
    }
    while (obj->queue1.front->next != NULL)  //Move elements from Stack1 to Stack2 for Operations
    {
        enqueue(&obj->queue2, dequeue(&obj->queue1));
    }
    int topElement = dequeue(&obj->queue1);
    
    while (!isQueueEmpty(&obj->queue2))  // After removing element move everything back to Stack1
    {
        enqueue(&obj->queue1, dequeue(&obj->queue2));
    }
    return topElement;
}

// Get the top element
int myStackTop(MyStack* obj) 
{
    if (isQueueEmpty(&obj->queue1)) 
    {
        return -1;
    }
    while (obj->queue1.front->next != NULL)
    {
        enqueue(&obj->queue2, dequeue(&obj->queue1));
    }
    int topElement = obj->queue1.front->data;
    enqueue(&obj->queue2, dequeue(&obj->queue1));
    
    while (!isQueueEmpty(&obj->queue2)) 
    {
        enqueue(&obj->queue1, dequeue(&obj->queue2));
    }
    return topElement;
}

// Check if stack is empty
bool myStackEmpty(MyStack* obj) 
{
    return isQueueEmpty(&obj->queue1);
}

// Memory
void myStackFree(MyStack* obj) 
{    
    free(obj);
}
