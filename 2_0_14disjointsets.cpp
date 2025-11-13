// C++ implementation of disjoint set
#include <iostream>
using namespace std;

class DisjSet{
	int *rank,*parent,n;
public:
	DisjSet(int n){
		rank=new int[n];
		parent= new int[n];
		this->n=n;
		makeSet();
	}

	void makeSet(){
		for(int i=0;i<n;i++){ parent[i]=i; }
	}
	
	int find(int x){
		if(parent[x]!=x){
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}
	
	void Union(int x, int y){
	int xset=find(x);
	int yset=find(y);
	if(xset==yset) return;
	if(rank[xset]<rank[yset]) parent[xset]=yset;
	else if(rank[xset]>rank[yset]) parent[yset]=xset;
	else{
		parent[yset]=xset;
		rank[xset]=rank[xset]+1;
	}
	}
};














/*
class DisjSet {
    int *rank, *parent, n;
public:
    DisjSet(int n){// Constructor to create and initialize sets of n items
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    
    void makeSet(){// Creates n single item sets
        for (int i = 0; i < n; i++) { parent[i] = i; }
    }

    int find(int x){// Finds set of given item x
        if (parent[x] != x) {// Finds the representative of the set that x is an element of
            parent[x] = find(parent[x]);// if x is not the parent of itself Then x is not the representative of his set,
        }   // so we recursively call Find on its parent and move i's node directly under the representative of this set
        return parent[x];
    }

    void Union(int x, int y){// Do union of two sets represented by x and y.
        int xset = find(x);// Find current sets of x and y
        int yset = find(y);
        if (xset == yset) return;// If they are already in same set
        // Put smaller ranked item under bigger ranked item if ranks are different
        if (rank[xset] < rank[yset]) { parent[xset] = yset; }
        else if (rank[xset] > rank[yset]) { parent[yset] = xset; }
        else {// If ranks are same, then increment rank
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};*/
  
int main(){
    DisjSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
  
    return 0;
}
