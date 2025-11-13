/*Ques 1:“Given a stair with n steps, implement a method to count how many possible ways are there to reach the top of the staircase, given that, at every step you can either take 1 step, 2 steps, or 3 steps.”


Ques 2: Create a Stock Management application in C++

*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
int data;
struct Node *link;
};

bool isPrime(int n);

int arr[4];


void traverse(struct Node * ptr){
    int index = 0;
    while (ptr != NULL)
    {
        if (isPrime(ptr->data))
        {
            // cout << ptr->data <<endl;
            arr[4] = ptr -> data;
            cout << arr[4] << " ";
        }
        

         
        ptr = ptr -> link ;
    }
    
}

bool isPrime(int n)
{
  
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

     head = (struct Node *)malloc(sizeof(struct Node));
      first = (struct Node *)malloc(sizeof(struct Node));
       second = (struct Node *)malloc(sizeof(struct Node));
        third = (struct Node *)malloc(sizeof(struct Node));

        head->data = 2;
        head->link = first;

        first->data = 3;
        first->link = second;

        second->data = 20;
        second->link = third;

        third->data = 11;
        third->link = NULL;

     traverse(head);

     return 0;
}
