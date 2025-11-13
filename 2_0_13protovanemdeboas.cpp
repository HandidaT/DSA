//https://www.geeksforgeeks.org/proto-van-emde-boas-tree-set-2-construction/?ref=rp
#include <bits/stdc++.h>
using namespace std;

class Proto_Van_Emde_Boas {
public:
	// Total number of keys
	int universe_size;

	// Summary
	Proto_Van_Emde_Boas* summary;

	// Clusters array of Proto-VEB pointers
	vector<Proto_Van_Emde_Boas*> clusters;

	int root(int u)
	{
		return (int)sqrt(u);
	}

	// Function to return cluster numbers
	// in which key is present
	int high(int x)
	{
		return x / root(universe_size);
	}

	// Function to return the position
	// of x in cluster
	int low(int x)
	{
		return x % root(universe_size);
	}

	// Function to return index form
	// cluster number and position
	int generate_index(int cluster, int position)
	{
		return cluster * root(universe_size) + position;
	}

	// Constructor
	Proto_Van_Emde_Boas(int size)
	{
		universe_size = size;

		// Base case
		if (size <= 2) {

			// Set summary to nullptr as there is no
			// more summary for size 2
			summary = nullptr;

			// Vector of two pointers
			// nullptr in starting
			clusters = vector<Proto_Van_Emde_Boas*>(size, nullptr);
		}
		else {

			// Assigning Proto-VEB(sqrt(u)) to summary
			summary = new Proto_Van_Emde_Boas(root(size));

			// Creating array of Proto-VEB Tree pointers of size sqrt(u)
			// first all nullptrs are going to assign
			clusters = vector<Proto_Van_Emde_Boas*>(root(size), nullptr);

			// Assigning Proto-VEB(sqrt(u)) to all its clusters
			for (int i = 0; i < root(size); i++) {
				clusters[i] = new Proto_Van_Emde_Boas(root(size));
			}
		}
	}
};

// Driver code
int main()
{
	Proto_Van_Emde_Boas pveb(4);
}

