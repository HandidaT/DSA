/** C implementation for
	Red-Black Tree Insertion
	This code is provided by
	costheta_z **/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent each
// node in a red-black tree
typedef struct node {
	int d; // data
	int c; // 1-red, 0-black
	struct node* p; // parent
	struct node* r; // right-child
	struct node* l; // left child
} node;

// global root for the entire tree
node* root = NULL;

// function to perform BST insertion of a node
node* bst(node* trav,node* temp){
	if (trav == NULL) return temp;// If the tree is empty, return a new node
	if (temp->d < trav->d){// Otherwise recur down the tree
		trav->l = bst(trav->l, temp);
		trav->l->p = trav;
	}
	else if (temp->d > trav->d){
		trav->r = bst(trav->r, temp);
		trav->r->p = trav;
	}
	return trav;// Return the (unchanged) node pointer
}

// Function performing right rotation of the passed node
void rightrotate(node* temp){
	node* left = temp->l;
	temp->l = left->r;
	if (left->r) left->r->p = temp;
	left->p = temp->p;
	if (!temp->p) root = left;
	else if (temp == temp->p->l) temp->p->l = left;
	else temp->p->r = left;
	left->r = temp;
	temp->p = left;
}

// Function performing left rotation
// of the passed node
void leftrotate(node* temp){
	node* right = temp->r;
	temp->r = right->l;
	if (right->l) right->l->p = temp;
	right->p = temp->p;
	if (!temp->p) root = right;
	else if (temp == temp->p->l) temp->p->l = right;
	else temp->p->r = right;
	right->l = temp;
	temp->p = right;
}

// This function fixes violations
// caused by BST insertion
void fixup(node* root, node* pt){
	node* parent_pt = NULL;
	node* grand_parent_pt = NULL;

	while ((pt != root) && (pt->c != 0) && (pt->p->c == 1)){
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;
		// Case : A
		//Parent of pt is left child of Grand-parent of pt
		if (parent_pt == grand_parent_pt->l){
			node* uncle_pt = grand_parent_pt->r;
			//Case : 1
			//The uncle of pt is also red. Only Recoloring required
			if (uncle_pt != NULL && uncle_pt->c == 1){
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}else {//Case : 2
				//pt is right child of its parent. Left-rotation required
				if (pt == parent_pt->r) {
					leftrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}// Case : 3
				//pt is left child of its parent. Right-rotation required
				rightrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}else {//Case : B Parent of pt is right. child of Grand-parent of pt
			node* uncle_pt = grand_parent_pt->l;
			//Case : 1 The uncle of pt is also red. Only Recoloring required
			if ((uncle_pt != NULL) && (uncle_pt->c == 1)){
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}else {//Case : 2 pt is left child of its parent. Right-rotation required
				if (pt == parent_pt->l) {
					rightrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}//Case : 3 pt is right child of its parent. Left-rotation required
				leftrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
	}
	root->c = 0;
}

void inorder(node* trav){// Function to print inorder traversal of the fixated tree
	if (trav == NULL) return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}

// driver code
int main()
{
	int n = 7;
	int a[7] = { 7, 6, 5, 4, 3, 2, 1 };
	for (int i = 0; i < n; i++) {
		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array
		node *temp=malloc(sizeof(*temp));
		temp->r = NULL;
		temp->l = NULL;
		temp->p = NULL;
		temp->d = a[i];
		temp->c = 1;
		// calling function that performs bst insertion of
		// this newly created node
		root = bst(root, temp);
		// calling function to preserve properties of rb
		// tree
		fixup(root, temp);
	}

	printf("Inorder Traversal of Created Tree\n");
	inorder(root);

	return 0;
}

