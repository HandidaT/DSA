#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*//Direct address table ###################################################################
class Directaddr_table{
public:
   int *T;
   Directaddr_table(int n):T{new int[n]()}{};

   void search(int key){
     std::cout<<T[key]<<std::endl;
   }

   void insert(int key,int value){
      T[key]=value;
      std::cout<<"inserted";
   }

   void del(int key){
      T[key]=0;
   }

   ~Directaddr_table(){delete[] T;}
};*/

//Open addressing, linear probing#######################################################################
template <typename Ke, typename Va>// template for generic type

class HashNode{// Hashnode class
public:
	Ke key;
	Va value;
	
	HashNode(Ke key, Va value){
		this->key=key;
		this->value=value;
	}
};

template <typename K, typename V>// template for generic type
class HashMap{
	HashNode<K,V> **arr;// hash element array
	HashNode<K,V> *dummy;// dummy node
	int size;// current size
	int capacity;
public:
	HashMap(){
		capacity=20;// Initial capacity of hash array
		size=0;
		arr=new HashNode<K,V>*[capacity];
		dummy=new HashNode<K,V>(-1,-1);// dummy node with value and key -1
		for(int i=0;i<capacity;i++){// Initialise all elements of array as NULL
			arr[i]=NULL;
		}
	}

	// This implements hash function to find index for a key
	int hashCode(K key){ return key%capacity; }

	// Function to add key value pair
	void insertNode(K key, V value)
	{
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);

		// Apply hash function to find index for given key
		int hashIndex = hashCode(key);

		// find next free space
		while (arr[hashIndex] != NULL
			&& arr[hashIndex]->key != key
			&& arr[hashIndex]->key != -1) {
			hashIndex++;
			hashIndex %= capacity;
		}

		// if new node to be inserted
		// increase the current size
		if (arr[hashIndex] == NULL
			|| arr[hashIndex]->key == -1)
			size++;
		arr[hashIndex] = temp;
	}

	// Function to delete a key value pair
	V deleteNode(int key)
	{
		// Apply hash function
		// to find index for given key
		int hashIndex = hashCode(key);

		// finding the node with given key
		while (arr[hashIndex] != NULL) {
			// if node found
			if (arr[hashIndex]->key == key) {
				HashNode<K, V>* temp = arr[hashIndex];

				// Insert dummy node here for further use
				arr[hashIndex] = dummy;

				// Reduce size
				size--;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}

		// If not found return null
		return NULL;
	}

	// Function to search the value for a given key
	V get(int key)
	{
		// Apply hash function to find index for given key
		int hashIndex = hashCode(key);
		int counter = 0;

		// finding the node with given key
		while (arr[hashIndex] != NULL) { // int counter =0; // BUG!

			if (counter++ > capacity) // to avoid infinite loop
				return NULL;

			// if node found return its value
			if (arr[hashIndex]->key == key)
				return arr[hashIndex]->value;
			hashIndex++;
			hashIndex %= capacity;
		}

		// If not found return null
		return NULL;
	}

	// Return current size
	int sizeofMap(){return size;}

	// Return true if size is 0
	bool isEmpty(){return size == 0;}

	// Function to display the stored key value pairs
	void display()
	{
		for (int i = 0; i < capacity; i++) {
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key
					<< " value = "
					<< arr[i]->value << endl;
		}
	}
};

//Open addressing, Quadratic probing#######################################################################
// Function to print an array
void printArray(int arr[], int n)
{
    // Iterating and printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
 
// Function to implement the
// quadratic probing
void hashing(int table[], int tsize,
             int arr[], int N)
{
    // Iterating through the array
    for (int i = 0; i < N; i++)
    {
        // Computing the hash value
        int hv = arr[i] % tsize;
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1)
            table[hv] = arr[i];
        else
        {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            for (int j = 0; j < tsize; j++)
            {
                // Computing the new hash value
                int t = (hv + j * j) % tsize;
                if (table[t] == -1)
                {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    printArray(table, N);
}





int main() {
/*
//Direct address table ###################################################################
	Directaddr_table Dt(5);
	Dt.insert(1,5);
	Dt.search(1);*/

//Open addressing, linear probing#######################################################################
	HashMap<int, int>* h = new HashMap<int, int>;
	h->insertNode(1, 1);
	h->insertNode(2, 2);
	h->insertNode(2, 3);
	h->display();
	cout << h->sizeofMap() << endl;
	cout << h->deleteNode(2) << endl;
	cout << h->sizeofMap() << endl;
	cout << h->isEmpty() << endl;
	cout << h->get(2);
	
//Open addressing, Quadratic probing#######################################################################
    int arr[] = {50, 700, 76,
                 85, 92, 73, 101};
    int N = 7;
 
    // Size of the hash table
    int L = 7;
    int hash_table[7];
 
    // Initializing the hash table
    for (int i = 0; i < L; i++)
    {
        hash_table[i] = -1;
    }
 
    // Quadratic probing
    hashing(hash_table, L, arr, N);
}
