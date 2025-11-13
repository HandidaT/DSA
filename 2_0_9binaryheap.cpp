// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>

void swap(int *x, int *y){// A utility function to swap two elements
	int temp=*x;
	*x=*y;
	*y=temp;
}

class MinHeap{
	int *harr,heap_size,capacity;
public:
	MinHeap(int capacity);
	
	int parent(int i) {return (i-1)/2;}
	int left(int i) {return (2*i)+1;}
	int right(int i) {return (2*i)+2;}
	int getMin() {return harr[0];}
	
	void decreaseKey(int i, int new_val);
	int extractMin();
	void deleteKey(int i);
	void insertKey(int k);
	void MinHeapify(int);
	
	void printArray() {
	  for (int i = 0; i < heap_size; ++i)
	    std::cout << harr[i] << " ";
	  std::cout << "\n";
	}
};

MinHeap::MinHeap(int cap){
	this->heap_size=0;
	this->capacity=cap;
	this->harr=new int[cap];
}

void MinHeap::insertKey(int k){
	if(heap_size==capacity){std::cout<<"Overflow\n";return;}
	heap_size++;
	int i=heap_size-1;
	this->harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(&harr[i], &harr[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::decreaseKey(int i, int new_val){//new_val should be smaller than hart[i]
	harr[i]=new_val;
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(&harr[i], &harr[parent(i)]);
		i=parent(i);
	}
}

int MinHeap::extractMin(){
	if(heap_size<=0) return INT_MAX;
	if(heap_size==1){heap_size--;return harr[0];}
	int min=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return min;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}



void MinHeap::MinHeapify(int i){// A recursive method to heapify a subtree with the root at given index
    int l = left(i);		// This method assumes that the subtrees are already heapified
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

/*
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the minimum element
    int extractMin();
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
  
    // Deletes a key stored at index i
    void deleteKey(int i);
  
    // Inserts a new key 'k'
    void insertKey(int k);
    
	void printArray() {
	  for (int i = 0; i < heap_size; ++i)
	    std::cout << harr[i] << " ";
	  std::cout << "\n";
	}
};
  
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
  
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
  
  
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}*/


//Maxheap////////////////////////////////////////////////////////////////////////////////////////////////////////
class Maxheap{
    int capacity;
    int heap_size;
    int *arr;
public:
    Maxheap(int cap){
        heap_size=0;
    	capacity=cap;
    	arr=new int[capacity];
    }
    
    int getcapacity(){
       return capacity;
    }
    
    int arrsize(){
       return sizeof(arr)/sizeof(arr[0]);
    }
    
    void printarr(){
       for(int i=0;i<heap_size;i++){
          std::cout<<arr[i];
       }
    }
    
    int parent(int i){
       return (i-1)/2;
    }
    
    void insert(int element){
       if(heap_size==capacity){
          std::cout<<"Heap is full";
          return;
       }
       heap_size++;
       int i=heap_size-1;
       arr[i]=element;
       while(i!=0 && arr[parent(i)]<arr[i]){
          swap(&arr[parent(i)],&arr[i]);
          i=parent(i);
       }
    }
};

// Driver program to test above functions
int main()
{/*
    Maxheap* mheap1=new Maxheap(10);
    cout<<mheap1->getcapacity();
    cout<<"\n"<<mheap1->arrsize();
    mheap1->insert(6);
    mheap1->insert(5);
    mheap1->insert(7);
    mheap1->insert(2);
    mheap1->insert(4);
    mheap1->insert(9);
    mheap1->insert(8);
    cout<<"\n";
    mheap1->printarr();

*/
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.printArray();
    std::cout << h.extractMin() << "\n";
    std::cout << h.getMin() << "\n";
    h.decreaseKey(2, 1);
    std::cout << h.getMin()<<"\n";
    h.printArray();
    return 0;
}
