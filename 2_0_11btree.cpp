// C++ program for B-Tree insertion
#include<iostream>

class BTreeNode{// A BTree node
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int _t, bool _leaf);   // Constructor
// A utility function to insert a new key in the subtree rooted with this node. The assumption is, the node 
    void insertNonFull(int k);//must be non-full when this function is called
//A utility function to split the child y of this node. i is index of y in child array C[].  The Child y must 
    void splitChild(int i, BTreeNode *y);//be full when this function is called
    void traverse();// A function to traverse all nodes in a subtree rooted with this node
    // A function to search a key in the subtree rooted with this node.
    BTreeNode *search(int k);   // returns NULL if k is not present.
// Make BTree friend of this so that we can access private members of this
    friend class BTree;// class in BTree functions
};

class BTree{// A BTree
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree
public:
    BTree(int _t){// Constructor (Initializes tree as empty)
      root = NULL;  t = _t;
    }
    void traverse(){// function to traverse the tree
      if(root) root->traverse();
    }
    BTreeNode* search(int k){//function to search a key in this tree
      return (root == NULL)? NULL : root->search(k);
    }
    void insert(int k);// The main function that inserts a new key in this B-Tree
};

BTreeNode::BTreeNode(int t1, bool leaf1){// Constructor for BTreeNode class
    t = t1;// Copy the given minimum degree and leaf property
    leaf = leaf1;
    keys = new int[2*t-1];// Allocate memory for maximum number of possible keys and child pointers
    C = new BTreeNode *[2*t];
    n = 0;// Initialize the number of keys as 0
}

void BTreeNode::traverse(){//Function to traverse all nodes in a subtree rooted with this node
    int i;// There are n keys and n+1 children, traverse through n keys
    for (i = 0; i < n; i++){// and first n children
        if (leaf == false)// If this is not leaf, then before printing key[i],
            C[i]->traverse();// traverse the subtree rooted with child C[i].
        std::cout << " " << keys[i];
    }
    if (leaf == false) C[i]->traverse();// Print the subtree rooted with last child
}

BTreeNode *BTreeNode::search(int k){// Function to search key k in subtree rooted with this node
    int i = 0;// Find the first key greater than or equal to k
    while (i < n && k > keys[i])
        i++;
    if (keys[i] == k) return this;// If the found key is equal to k, return this node
    if (leaf == true) return NULL;// If key is not found here and this is a leaf node
    return C[i]->search(k);// Go to the appropriate child
}

void BTree::insert(int k){// The main function that inserts a new key in this B-Tree
    if (root == NULL){// If tree is empty
        root = new BTreeNode(t, true);// Allocate memory for root
        root->keys[0] = k;  // Insert key
        root->n = 1;  // Update number of keys in root
    }else{//If tree is not empty
        if (root->n == 2*t-1){// If root is full, then tree grows in height
            BTreeNode *s = new BTreeNode(t, false);// Allocate memory for new root
            s->C[0] = root;// Make old root as child of new root
            s->splitChild(0, root);// Split the old root and move 1 key to the new root
            int i = 0;// New root has two children now.  Decide which of two children is going to have new key
            if (s->keys[0] < k) i++;
            s->C[i]->insertNonFull(k);
            root = s;// Change root
        }else  // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
    }
}
// A utility function to insert a new key in this node. The assumption is, the node must be non-full when this
void BTreeNode::insertNonFull(int k){// function is called
    int i = n-1;// Initialize index as index of rightmost element
    if (leaf == true){// If this is a leaf node{ The following loop does two things
        while (i >= 0 && keys[i] > k){// a) Finds the location of new key to be inserted
            keys[i+1] = keys[i];      // b) Moves all greater keys to one place ahead
            i--;
        }
        keys[i+1] = k;// Insert the new key at found location
        n = n+1;
    }
    else{// If this node is not leaf
        while (i >= 0 && keys[i] > k)// Find the child which is going to have the new key
            i--;
        if (C[i+1]->n == 2*t-1){// See if the found child is full
            splitChild(i+1, C[i+1]);// If the child is full, then split it
// After split, the middle key of C[i] goes up and C[i] is splitted into two.  See which of the two
            if (keys[i+1] < k) i++;// is going to have the new key
        }
        C[i+1]->insertNonFull(k);
    }
}
// A utility function to split the child y of this node. Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *y){
    BTreeNode *z = new BTreeNode(y->t, y->leaf);// Create a new node which is going to store (t-1) keys of y
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)// Copy the last (t-1) keys of y to z
        z->keys[j] = y->keys[j+t];
    if (y->leaf == false){// Copy the last t children of y to z
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    y->n = t - 1;// Reduce the number of keys in y
    for (int j = n; j >= i+1; j--)// Since this node is going to have a new child,
        C[j+1] = C[j];//create space of new child
    C[i+1] = z;// Link the new child to this node
    for (int j = n-1; j >= i; j--)// A key of y will move to this node. Find the location of
        keys[j+1] = keys[j];// new key and move all greater keys one space ahead
    keys[i] = y->keys[t-1];// Copy the middle key of y to this node
    n = n + 1;// Increment count of keys in this node
}

int main(){// Driver program to test above functions
    BTree t(3); // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
 
    std::cout << "Traversal of the constructed tree is ";
    t.traverse();
 
    int k = 6;
    (t.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present";
 
    k = 15;
    (t.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present";
 
    return 0;
}
