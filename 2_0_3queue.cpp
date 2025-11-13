/*
In this file, three types of queue implementations are presented.
Inbuilt c++ queue from <queue> header file is also demonstrated.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>

//Queue--------------------

//Array implementation of queue
class Arr_queue{
public:
   int front, rear, capacity,*array;

   Arr_queue(int c){
     front = 0,rear = 0;
     capacity=c;
     array=new int[capacity];
   }

   void enqueue(int data){
     if(capacity == rear){
         std::cout<<"Queue is full";
     }
     else{
         array[rear]=data;
         rear++;
     }
   }

   void dequeue(){
      if(front==rear){
          std::cout<<"empty";
      }
      else{
          for(int i=0;i<capacity;i++){
              array[i]=array[i+1];
          }
          rear--;
      }
      std::cout<<front<<"--"<<rear<<"--"<<capacity<<"\n";
   }

   void display(){
      for(int i=0;i<rear;i++){
          std::cout<<array[i];
      }
      std::cout<<"\n";
   }
};

//Circular array implementation of queue

//Stack


//main function
int main(){
    //Array implementation of queue
    Arr_queue *q=new Arr_queue(3);
    q->enqueue(3);
    q->enqueue(6);
    q->display();
    q->dequeue();
    q->display();
}