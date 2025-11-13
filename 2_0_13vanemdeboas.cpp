//https://www.geeksforgeeks.org/van-emde-boas-tree-set-1-basics-and-construction/
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
  
class Van_Emde_Boas {
  
public:
    int universe_size;
    int minimum;
    int maximum;
    Van_Emde_Boas* summary;
    vector<Van_Emde_Boas*> clusters;
  
    // Function to return cluster numbers
    // in which key is present
    int high(int x)
    {
        int div = ceil(sqrt(universe_size));
        return x / div;
    }
  
    // Function to return position of x in cluster
    int low(int x)
    {
        int mod = ceil(sqrt(universe_size));
        return x % mod;
    }
  
    // Function to return the index from
    // cluster number and position
    int generate_index(int x, int y)
    {
        int ru = ceil(sqrt(universe_size));
        return x * ru + y;
    }
  
    // Constructor
    Van_Emde_Boas(int size)
    {
        universe_size = size;
        minimum = -1;
        maximum = -1;
  
        // Base case
        if (size <= 2) {
            summary = nullptr;
            clusters = vector<Van_Emde_Boas*>(0, nullptr);
        }
        else {
            int no_clusters = ceil(sqrt(size));
  
            // Assigning VEB(sqrt(u)) to summary
            summary = new Van_Emde_Boas(no_clusters);
  
            // Creating array of VEB Tree pointers of size sqrt(u)
            clusters = vector<Van_Emde_Boas*>(no_clusters, nullptr);
  
            // Assigning VEB(sqrt(u)) to all of its clusters
            for (int i = 0; i < no_clusters; i++) {
                clusters[i] = new Van_Emde_Boas(ceil(sqrt(size)));
            }
        }
    }
};
  
// Driver code
int main()
{
    // New Van_Emde_Boas tree with u = 16
    Van_Emde_Boas* akp = new Van_Emde_Boas(4);
}
