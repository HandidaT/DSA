// Note that by default C++ creates a max-heap
// for priority queue
#include <iostream>
#include <vector>
#include <queue>
 

void showpq(std::priority_queue<int> gq)
{
    std::priority_queue<int> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.top();
        g.pop();
    }
    std::cout << '\n';
}

// Priority Queue implementation in C++



// Function to swap position of two elements
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

int parent(int i) {return (i-1)/2;}

// Function to heapify the tree
void heapify(std::vector<int> &hT, int i) {
  int size = hT.size();
  
  // Find the largest among root, left child and right child
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[i])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Function to insert an element into the tree
void insert(std::vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {  hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    //for (int i = size / 2 - 1; i >= 0; i--) {
    //heapify(hT, i);
    while(size!=0 && hT[parent(size)]<hT[size]){
    	swap(&hT[size], &hT[parent(size)]);
    	size=parent(size);
    }
  }
}

// Function to delete an element from the tree
void deleteNode(std::vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Print the tree
void printArray(std::vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    std::cout << hT[i] << " ";
  std::cout << "\n";
}
 
int main()
{
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

/*
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "After deleting an element: ";

  printArray(heapTree);*/
}
