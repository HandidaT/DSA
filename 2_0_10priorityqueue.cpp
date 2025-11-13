// Note that by default C++ creates a max-heap for priority queue
#include <iostream>
#include <vector>
#include <queue>

// Priority Queue implementation in C++ STL #########################3
void showpq(std::priority_queue<int> gq)
{
    std::priority_queue<int> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.top();
        g.pop();
    }
    std::cout << '\n';
}

// Max Priority Queue implementation########################3
//https://www.geeksforgeeks.org/priority-queue-using-binary-heap/
int H[50];
int size = -1;

int parent(int i){return (i - 1) / 2;}
int leftChild(int i){return ((2 * i) + 1);}
int rightChild(int i){return ((2 * i) + 2);}

void swap(int *x, int *y){// A utility function to swap two elements
	int temp=*x;
	*x=*y;
	*y=temp;
}
 
// Function to shift up the node in order to maintain the heap property
void shiftUp(int i){
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(&H[parent(i)], &H[i]);
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void MinHeapify(int i){
    int maxIndex = i,l = leftChild(i),r = rightChild(i);
    if (l <= size && H[l] > H[maxIndex]) maxIndex = l;
    if (r <= size && H[r] > H[maxIndex]) maxIndex = r;
    if (i != maxIndex) {
        swap(&H[i], &H[maxIndex]);
        MinHeapify(maxIndex);
    }
}

// Function to insert a new element in the Binary Heap
void insert(int p){
    size = size + 1;
    H[size] = p;
    shiftUp(size);// Shift Up to maintain heap property
}
 
// Function to extract the element with maximum priority
int extractMax(){
    int result = H[0];
    H[0] = H[size];// Replace the value at the root with the last leaf
    size = size - 1;
    // Shift down the replaced element to maintain the heap property
    MinHeapify(0);
    return result;
}
 
// Function to change the priority of an element
void changePriority(int i, int p){
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) shiftUp(i);
    else MinHeapify(i);
}

int getMax(){// Function to get value of the current maximum element
    return H[0];
}

void remove(int i){// Function to remove the element located at given index
    H[i] = getMax() + 1;
    shiftUp(i);// Shift the node to the root of the heap
    extractMax();// Extract the node
}
 
int main()
{// Priority Queue implementation in C++ STL #########################3
	std::priority_queue<int> gquiz;
	gquiz.push(3);
	gquiz.push(4);
	gquiz.push(9);
	gquiz.push(5);
	gquiz.push(2);

	std::cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	std::cout << "\ngquiz.size() : " << gquiz.size();
	std::cout << "\ngquiz.top() : " << gquiz.top();

	std::cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

// Max Priority Queue implementation########################3
	insert(3);
	insert(4);
	insert(9);
	insert(5);
	insert(2);
	int i = 0;
	std::cout << "Priority Queue : ";
	while (i <= size) {
		std::cout << H[i] << " ";
		i++;
	}
	extractMax();
	i=0;
	std::cout << "\nAfter removing max: ";
	while (i <= size) {
		std::cout << H[i] << " ";
		i++;
	}
}
