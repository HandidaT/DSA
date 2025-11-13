#include<stdio.h>
#include<stdlib.h>


//Collision resolution by chaining, Singly linked list############################################################################################
// Node for storing an item in a Linked List 
typedef struct node {
	int key;
	int value;
	struct node *next;
} node;
 
// For storing a Linked List at each index of Hash Table
typedef struct arrayitem {
	node *head;// head pointing the first element of Linked List at an index of Hash Table
	node *tail;// tail pointing the last element of Linked List at an index of Hash Table
} arrayitem;
 
arrayitem *array;
int size = 0;         // Determines the no. of elements present in Hash Table
int max = 10;	      // Determines the maximum capacity of Hash Table array
 
// This function creates an index corresponding to the every given key
int hashcode(int key){
	return (key % max);
}
 
//Returns the node (Linked List item) located at given find_index
node* get_element(node *list, int find_index){
	int i = 0;
	node *temp = list;
	while (i != find_index){
		temp = temp->next;
		i++;
	}
	return temp;
}

//This function finds the given key in the Linked List
//Returns it's index
//Returns -1 in case key is not present
int find(node *list, int key){
	int position = 0;
	node *temp = list;
	while (temp != NULL) {
		if (temp->key == key){
			return position;
		}
  		temp = temp->next;
		position++;
	}
	return -1;
}

// To remove an element from Hash Table
void remove_element(int key){
	int index = hashcode(key);
	node *list = array[index].head;
	if (list == NULL){
		printf("This key does not exists\n");
	}
        else{
		int find_index = find(list, key);
		if (find_index == -1) {
			printf("This key does not exists\n");
		}
                else{
 			node *temp = list;
			if (temp->key == key){
  				array[index].head = temp->next;
				printf("This key has been removed\n");
				return;
			}
			while (temp->next->key != key){
 				temp = temp->next;
			}
  			if (array[index].tail == temp->next){
				temp->next = NULL;
				array[index].tail = temp;
			}
                       else{
				temp->next = temp->next->next;
			}
			printf("This key has been removed\n");
		}
	}
}

// For initializing the Hash Table
void init_array(){
	int i = 0;
	for (i = 0; i < max; i++)
        {
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

void rehash();

void insert(int key, int value){
  	float n = 0.0;     
	// n => Load Factor, keeps check on whether rehashing is required or not
	int index = hashcode(key);  
	// Extracting Linked List at a given index
	node *list = array[index].head;
	// Creating an item to insert in the Hash Table
	node *item = malloc(sizeof(*item));
	item->key = key;
	item->value = value;
	item->next = NULL;
	if (list == NULL){
		// Absence of Linked List at a given Index of Hash Table
		printf("Inserting %d(key) and %d(value) \n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size++;
	}
        else{
		// A Linked List is present at given index of Hash Table
		int find_index = find(list, key); 
		if (find_index == -1) {
			//Key not found in existing linked list
			//Adding the key at the end of the linked list
			array[index].tail->next = item;
			array[index].tail = item;
			size++;
		}else{
			//Key already present in linked list
			//Updating the value of already existing key
			node *element = get_element(list, find_index);
			element->value = value;
		}
	}
	//Calculating Load factor
	n = (1.0 * size) / max;
	if (n >= 0.75) {
		//rehashing
		printf("going to rehash\n");
		rehash();
	}
}

void rehash(){
	arrayitem *temp = array;     
	//temp pointing to the current Hash Table array
	int i = 0, n = max;
	size = 0;
	max = 2 * max;
	//array variable is assigned with newly created Hash Table
	//with double of previous array size
	array = malloc(max * sizeof(*temp));
	init_array();
	for (i = 0; i < n; i++) {
		//Extracting the Linked List at position i of Hash Table array
 		node* list = temp[i].head;
		if (list == NULL){
			//if there is no Linked List, then continue
			continue;
		}
                else {
			 //Presence of Linked List at i
			 //Keep moving and accessing the Linked List item until the end.
			 //Get one key and value at a time and add it to new Hash Table array
			while (list != NULL){
				insert(list->key, list->value);
				list = list->next;
			}
		}
	}
	temp = NULL;
}

// Returns size of Hash Table
int size_of_array(){
	return size;
}
 
// To display the contents of Hash Table
void display(){
	int i = 0;
	for (i = 0; i < max; i++){
		node *temp = array[i].head;
		if (temp == NULL){
			printf("array[%d] has no elements\n", i);
		}
               else{
			printf("array[%d] has elements-: ", i);
			while (temp != NULL){
				printf("key= %d  value= %d\t", temp->key, temp->value);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

/*
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
}*/
 
void main() 
{
	//Collision resolution be chaining############################################################3
	int choice, key, value, n, c;
	array = malloc(max * sizeof(*array));
	init_array();
	insert(1, 5);
	insert(2, 6);
	insert(3, 7);
	display();
	remove_element(2);
	display();
/*	
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
*/
}
