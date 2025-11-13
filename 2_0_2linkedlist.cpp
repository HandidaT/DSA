#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

void Insert(int data,int n){
    Node *temp1=new Node;
    temp1->data=data;
    temp1->next= NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    Node *temp2=head;
    for(int i=0;i<n-2;i+=1){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void Delete(int n){
    Node *temp1=head;
    if(n==1){
        head=temp1->next;
        delete temp1;
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    Node *temp2=temp1->next;
    temp1->next=temp2->next;
    delete temp2;
};

void iterative_reverse(){
    Node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current != NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void recursive_reverse(Node *p){
    if (p->next==NULL){
        head=p;
        cout<<head->data;
        return;
    }
    recursive_reverse(p->next);
    p->next->next=p;
    p->next=NULL;
    cout<<p->data;
};

void iterative_print(){
    Node *temp=head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    // cout<<endl;
}


// Recursive function to reverse print.
void recursive_print(Node *p){
    if (p==NULL){
        cout<<endl;
        return;
    }                        // To make this recursive function print
    recursive_print(p->next);// normally, move the cout<<p->data; 
    cout<<p->data;           // statement above the recursive call. 
};

int main() {
    head=NULL;
    int length;
    cout<<"How many numbers: ";
    cin>>length;
    for(int i=0;i<length;i+=1){
        int num;
        int position;
        cout<<"Enter the number: ";
        cin>>num;
        cout<<"Enter the position: ";
        cin>>position;
        Insert(num,position);
        iterative_print();
    }

    string y;
    cout<<"Enter 'y' to delete items or 'r' to reverse list: ";
    cin>>y;
    if (y=="y"){
        for(int i=0;i<length;i+=1){
            int position;
            cout<<"Enter position: ";
            cin>>position;
            Delete(position);
            iterative_print();
        }
    }
    else if (y=="r"){
        string method;
        cout<<"Enter 'r' for recursive method or any key for iterative method: ";
        cin>>method;
        if(method=="r"){
            cout<<"Recursive reverse ";
            recursive_reverse(head);
            cout<<endl<<"iterative print";
            iterative_print();
            cout<<endl<<"recursive reverse print";
            recursive_print(head);           
        }
        else{
            iterative_reverse();
            iterative_print();
        }
    }
    return 0;
}
