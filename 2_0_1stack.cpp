//Double-ended queue · An input-restricted deque  learn more
//tower of hanoi

//Array implementation of queue. Very similar to c++ vector data structure. Capacity only increases, be wary.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue)){
         queue->capacity=queue->size*2;//capacity only increases
         int *array1=malloc(sizeof(*array1) * queue->capacity);
		 for(int i=queue->front,j=0;i<queue->size;i++,j++){
		     array1[j]=queue->array[i];
	     }
	     queue->front=0;
	     free(queue->array);
	     queue->array=array1;
	     printf("Queue is full %d",queue->front);
         //return;
    }
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}/*
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
     int *array1=malloc(sizeof(*array1) * queue->capacity);
	 for(int i=queue->front;i<2;i++){
	     array1[i]=queue->array[i];
     }
     free(queue->array);
     queue->array=array1;
    queue->size = queue->size - 1;
    return item;
}*/
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void display(struct Queue* queue){
	for(int i=queue->front;i<queue->rear+1;i++){
	   printf("%d %d\n",i,queue->array[i]);
	}
}
 
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
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    display(queue);
 
    printf("Front item is %d %d\n", queue->front,front(queue));
    printf("Rear item is %d %d\n", queue->rear,rear(queue));
    printf("Capacity %d\n", queue->capacity);
    free(queue->array);
    free(queue);
    return 0;
}
