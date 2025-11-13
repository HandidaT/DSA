//Double-ended queue · An input-restricted deque  learn more
//tower of hanoi

//Array implementation of queue. Very similar to c++ vector data structure. Capacity only increases, be wary.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Activations{
	int name;
	int activation;//what about weights?
} Activations;

typedef struct Queue{
	int front,size;
	unsigned capacity;
	Activations *array;
} Queue;

Queue *createQueue(unsigned capacity){
	Queue *q=malloc(sizeof(*q));
	q->front=q->size=0;
	q->capacity=capacity;
	q->array=malloc(sizeof(q->array) * capacity);
	return q;
}

int isFull(Queue *q){
	return q->size==q->capacity;
}

int isEmpty(Queue *q){
	return q->size==0;
}

void enqueue(Queue *q,int data){
	if(isFull(q)){
		q->capacity=q->capacity*2;
		Activations *array1=malloc(sizeof(*array1) * q->capacity);
		for(int i=0;i<q->size;i++){
			printf("front=%d size=%d",i,q->size);
			array1[i].name=q->array[i].name;
		}
		free(q->array);
		q->array=array1;
		printf("Queue is full %d ",q->front);
	}
	q->array[q->size].name=data;
	q->size++;
	printf("%d enqueued to queue\n", data);
}

int dequeue(Queue *q){
	if(isEmpty(q)) return INT_MIN;
	Activations *array1=malloc(sizeof(*array1) * q->capacity);
	for(int i=0;i<(q->size-1);i++){
		printf("dequeue %d front=%d size=%d\n",q->array[i].name,i,q->size);
		array1[i].name=q->array[i+1].name;
	}
	int item=q->array[q->front].name;
	free(q->array);
	q->array=array1;
	//int item1=q->array[q->front].name;////// ERROR HERE if this line is here instead of before//////////
	q->size--;
	return item;
}

int front(Queue *q){
	if(isEmpty(q)) return INT_MIN;
	return q->array[q->front].name;
}

int rear(Queue *q){
	if(isEmpty(q)) return INT_MIN;
	return q->array[q->size-1].name;
}

void display(Queue *q){
	printf("display front=%d size=%d\n",q->front,q->size);
	for(int i=0;i<q->size;i++){
		printf("%d %d",i,q->array[i].name);
	}
	printf("\n");
}

//Circular array implementation of queue. Can increase capacity whenever head is next to tail#########################33
//https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/

//Linked List implementation fo queue. Can keep head and tail and make enqueue/dequeue O(1)############################
//https://www.geeksforgeeks.org/queue-linked-list-implementation/

// Driver program to test above functions./
int main()
{
    struct Queue* queue = createQueue(2);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    display(queue);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    display(queue);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    display(queue);
    printf("Rear item is %d\n", rear(queue));
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    display(queue);
 
     enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    printf("Front item is %d %d\n", queue->front,front(queue));
    printf("Rear item is %d\n", rear(queue));
    printf("Capacity %d\n", queue->capacity);
    free(queue->array);
    free(queue);
    return 0;
}
