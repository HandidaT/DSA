// C++ program to demonstrate insertion in a BST recursively.
#include <iostream>


class BST{
	int data;
	BST *left, *right;
public:
	BST():data{0},left{NULL},right{NULL}{};// Default Constructor definition.
	BST(int);
	BST *Insert(BST*,int);
	void Inorder(BST*);
};

BST::BST(int value){// Parameterized Constructor definition.
	data=value;
	left=right=NULL;
}

BST* BST::Insert(BST *root,int value){
	if(!root){// Insert the first node, if root is NULL.
		return new BST(value);
	}// Insert right node data, if the 'value' to be inserted is greater than 'root' node data.
	if(value > root->data) root->right= Insert(root->right,value);// Insert left node data, if the 'value'
	else root->left= Insert(root->left,value);// to be inserted is greater than 'root' node data.
	return root;// Return 'root' node, after insertion.
}

void BST::Inorder(BST *root){// Inorder traversal function. This gives data in sorted order.
	if(!root) return;
	Inorder(root->left);
	std::cout<<root->data<<"\n";
	Inorder(root->right);
}

/*https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
Given a binary search tree and a key, this function
deletes the key and returns the new root
Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}*/

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}
