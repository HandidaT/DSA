//a2r10c10
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//Stacks are used in many applications like infix and postfix, etc for example.
//Array implementation of stack##########################################################################################
// A structure to represent a stack
typedef struct Stack{
	int top;
	unsigned capacity;
	int* array;
} Stack;

// function to create a stack of given capacity. It initializes size of stack as -1
Stack* createStack(unsigned capacity){
	Stack *stack=malloc(sizeof(*stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=malloc(sizeof(stack->array) * stack->capacity);
	return stack;
}

int isFull(Stack *stack){
	return stack->top==stack->capacity-1;
}

int StackEmpty(Stack *stack){
	return stack->top==-1;
}

void push(Stack *stack,int data){
	if(isFull(stack)){
		printf("Stack full");
		return;
	}
	stack->array[++stack->top]=data;
}

int pop(Stack *stack){
	if(StackEmpty(stack)) return INT_MIN;
	return stack->array[stack->top--];
}

int peek(Stack *stack){
	if(StackEmpty(stack)){
		return INT_MIN;
	}
	return stack->array[stack->top];
}

//Linked list implementation of stack#############################################################################################
//https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

typedef struct StackNode{
	int data;
	struct StackNode *next;
} StackNode;

StackNode *createStackNode(int data){
	StackNode *newNode=malloc(sizeof(*newNode));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

int ListEmpty(StackNode *top){
	 return !top;//printf("%d",NULL);
}

void pushNode(StackNode **top, int data){
	StackNode *newNode=createStackNode(data);
	newNode->next=(*top);
	(*top)=newNode;
}

int popNode(StackNode **top){
	if(ListEmpty((*top))){
		return INT_MIN;
	}
	StackNode *temp=(*top);
	(*top)=(*top)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}

int peekNode(StackNode *top){
	if(ListEmpty(top)) return INT_MIN;
	return top->data;
}

// Driver program to test above functions
int main()
{//Array implementation of stack
    Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
    free(stack->array);
    free(stack);
    
//////Linked list stack implementation
    StackNode *topNode=createStackNode(7);
    pushNode(&topNode,6);
    pushNode(&topNode,9);
    pushNode(&topNode,3);
    printf("%d\n",popNode(&topNode));
    pushNode(&topNode,2);
    
	while(topNode!=NULL){
		StackNode *temp=topNode;
		printf("%d ",topNode->data);
		topNode=topNode->next;
		free(temp);
	}
	//free(tailNode);
}
