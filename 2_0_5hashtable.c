#include<stdio.h>
#include<stdlib.h>
/*
//Collision resolution by chaining, Singly linked list############################################################################################
// Node for storing an item in a Linked List 
typedef struct node {
	int key;
	int value;
	struct node *next;
} node;

typedef struct arrayitem {// For storing a Linked List at each index of Hash Table
	node *head;// head pointing the first element of Linked List at an index of Hash Table
	node *tail;// tail pointing the last element of Linked List at an index of Hash Table
} arrayitem;

arrayitem *array;
int size = 0;         // Determines the no. of elements present in Hash Table
int max = 10;	      // Determines the maximum capacity of Hash Table array

int hashcode(int key){// This function creates an index corresponding to the every given key
	return (key % max);
}

node* get_element(node *list, int key){//Returns node preceding to the desired node and NULL if desired node not present
	node *temp = list, *tempprev=malloc(sizeof(*tempprev));
	tempprev->next=temp;
	while (temp != NULL){
		if(temp->key==key) return tempprev;
		tempprev=temp;
		temp = temp->next;
	}
	free(tempprev);
	return temp;//return NULL as element not present
}

void remove_element(int key){
	int index=hashcode(key);
	node *list=array[index].head;
	if(list==NULL) printf("The key doesn't exist");
	else{
		node *element=get_element(list,key);
		if(element==NULL) printf("The key doesn' exist");
		else{
			node *elementnext=element->next;
			if(array[index].head==element->next){
				array[index].head=element->next->next;
				array[index].tail=element->next->next;//if element is head then it is also tail
				printf("This key has been removed\n");
			}
			if(array[index].tail==element->next) array[index].head==element;
			else element=element->next->next;
			free(elementnext);
			free(element);
			printf("This key has been removed\n");
		}
	}
}

void init_array(){// For initializing the Hash Table
	for(int i=0;i<max;i++){array[i].head=array[i].tail=NULL;}
}

void rehash();

void insert(int key, int value){
	float n=0.0;// n => Load Factor, keeps check on whether rehashing is required or not
	int index=hashcode(key);
	node *list=array[index].head;// Extracting Linked List at a given index
	node *item=malloc(sizeof(*item));// Creating an item to insert in the Hash Table
	item->key=key;
	item->value=value;
	item->next=NULL;
	if(list==NULL){// Absence of Linked List at a given Index of Hash Table
		printf("Inserting %d(key) and %d(value) \n", key, value);
		array[index].head = array[index].tail = item;
		size++;
	}else{// A Linked List is present at given index of Hash Table
		node *element=get_element(list, key);
		if(element==NULL){//Key not found so adding the key at the end of the linked list
			array[index].tail->next=item;
			array[index].tail=item;
			size++;
		}else element->next->value=value;//Updating the value of already existing key
	}
	n=(1.0 *size) / max;//Calculating Load factor
	if(n>=0.75){//rehashing
		printf("going to rehash\n");
		rehash();
	}
}

void rehash(){
	arrayitem *temp = array;//temp pointing to the current Hash Table array
	int i = 0, n = max;
	size = 0;
	max = 2 * max;//array variable is assigned with newly created Hash Table
	array = malloc(max * sizeof(*temp));//with double of previous array size
	init_array();
	for (i = 0; i < n; i++) {//Extracting the Linked List
 		node* list = temp[i].head;//at position i of Hash Table array
		if (list == NULL){ continue;//if there is no Linked List, then continue
		}//Presence of Linked List at i Keep moving and accessing the
                else {//Linked List item until the end. Get one key and value
			while (list != NULL){//at a time and add it to new Hash Table array
				insert(list->key, list->value);
				list = list->next;
			}
		}
	}
	free(temp);
}

// Returns size of Hash Table
int size_of_array(){
	return size;
}
 
// To display the contents of Hash Table
void display(){
	for (int i = 0; i < max; i++){
		node *temp = array[i].head;
		if (temp == NULL) printf("array[%d] has no elements\n", i);
               else{
			printf("array[%d] has elements-: ", i);
			while (temp != NULL){
				printf("key= %d  value= %d\t", temp->key, temp->value);
				temp = temp->next;
			}printf("\n");
		}
	}
}*/


//Open addressing, Linear probing####################################################################33
struct HashNode {
    int key;
    int value;
};
  
const int capacity = 20;
int size = 0;

struct HashNode** arr;
struct HashNode* dummy;

void insert_linearprobing(int key, int value){
	struct HashNode *temp=malloc(sizeof(*temp));
	temp->key=key;
	temp->value=value;
	int hashIndex=key%capacity;
    // Find next free space
	while(arr[hashIndex]!=NULL && arr[hashIndex]->key!=key && arr[hashIndex]->key!=-1){
		hashIndex++;
		hashIndex%=capacity;
	}
	if(arr[hashIndex]==NULL || arr[hashIndex]->key==-1) size++;
	arr[hashIndex]=temp;
}
  
// Function to delete a key value pair
int delete (int key)
{// Apply hash function to find
    // index for given key
    int hashIndex = key % capacity;
    // Finding the node with given
    // key
    while (arr[hashIndex] != NULL) {
        // if node found
        if (arr[hashIndex]->key == key) {
            // Insert dummy node here
            // for further use
            arr[hashIndex] = dummy;
            // Reduce size
            size--;
            // Return the value of the key
            return 1;
        }
        hashIndex++;
        hashIndex %= capacity;
    }
    // If not found return null
    return 0;
}
  
// Function to search the value
// for a given key
int find(int key)
{
    // Apply hash function to find
    // index for given key
    int hashIndex = (key % capacity);
  
    int counter = 0;
  
    // Find the node with given key
    while (arr[hashIndex] != NULL) {
  
        int counter = 0;
        // If counter is greater than
        // capacity
        if (counter++ > capacity)
            break;
  
        // If node found return its
        // value
        if (arr[hashIndex]->key == key)
            return arr[hashIndex]->value;
  
        hashIndex++;
        hashIndex %= capacity;
    }
  
    // If not found return
    // -1
    return -1;
}
 
void main() 
{/*
	//Collision resolution be chaining############################################################3
	int choice, key, value, n, c;
	array = malloc(max * sizeof(*array));
	init_array();
	insert(1, 5);
	insert(0, 3);
	insert(2, 6);
	insert(3, 7);
	display();
	remove_element(2);
	display();*/

    //Open addressing, linear probing#####################################################################
    // Space allocation
    arr = malloc(sizeof(*arr) * capacity);
    // Assign NULL initially
    for (int i = 0; i < capacity; i++)
        arr[i] = NULL;
  
    dummy = malloc(sizeof(*dummy));
  
    dummy->key = -1;
    dummy->value = -1;
  
    insert_linearprobing(1, 5);
    insert_linearprobing(2, 15);
    insert_linearprobing(3, 20);
    insert_linearprobing(4, 7);
  
    if (find(4) != -1)
        printf("Value of Key 4 = %d\n", find(4));
    else
        printf("Key 4 does not exists\n");
  
    if (delete (4))
        printf("Node value of key 4 is deleted "
               "successfully\n");
    else {
        printf("Key does not exists\n");
    }
  
    if (find(4) != -1)
        printf("Value of Key 4 = %d\n", find(4));
    else
        printf("Key 4 does not exists\n");

}
