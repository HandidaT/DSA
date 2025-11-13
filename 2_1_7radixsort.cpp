// C++ implementation of Radix Sort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

//implementation of radix sort using bin/bucket sort#########################################################################
 
// structure for a single linked list to help further in the
// sorting
struct node {
    int data;
    node* next;
};
 
// function for creating a new node in the linked list
struct node* create(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
 
    return temp;
}
 
// utility function to append node in the linked list
// here head is passed by reference, to know more about this
// search pass by reference
void insert(node*& head, int n)
{
    if (head == NULL) {
        head = create(n);
        return;
    }
 
    node* t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = create(n);
}
 
// utility function to pop an element from front in the list
// for the sake of stability in sorting
int del(node*& head)
{
    if (head == NULL)
        return 0;
    node* temp = head;
    // storing the value of head before updating
    int val = head->data;
 
    // updation of head to next node
    head = head->next;
 
    delete temp;
    return val;
}
 
// utility function to get the number of digits in the
// max_element
int digits(int n)
{
    int i = 1;
    if (n < 10)
        return 1;
 
    while (n > (int)pow(10, i))
        i++;
    return i;
}
 
void radix_sort_b(vector<int>& arr)
{
    // size of the array to be sorted
    int sz = arr.size();
 
    // getting the maximum element in the array
    int max_val = *max_element(arr.begin(), arr.end());
 
    // getting digits in the maximum element
    int d = digits(max_val);
 
    // creating buckets to store the pointers
    node** bins;
 
    // array of pointers to linked list of size 10 as
    // integers are decimal numbers so they can hold numbers
    // from 0-9 only, that's why size of 10
 
    bins = new node*[10];
 
    // initializing the hash array with null to all
    for (int i = 0; i < 10; i++)
        bins[i] = NULL;
 
    // first loop working for a constant time only and inner
    // loop is iterating through the array to store elements
    // of array in the linked list by their digits value
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < sz; j++) // bins updation
            insert(bins[(arr[j] / (int)pow(10, i)) % 10],
                   arr[j]);
 
        int x = 0, y = 0;
        // write back to the array after each pass
 
        while (x < 10) {
            while (bins[x] != NULL)
                arr[y++] = del(bins[x]);
            x++;
        }
    }
}
 
// a utility function to print the sorted array
void print_b(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function Call
	radixsort(arr, n);
	print(arr, n);
//implementation of radix sort using bin/bucket sort#########################################################################
    vector<int> arr_b = { 573, 25, 415, 12, 161, 6 };
 
    // function call
    radix_sort_b(arr_b);
    cout<<"\n";
    print_b(arr_b);
}

