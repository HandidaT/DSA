#include <stdio.h>
#include <stdlib.h>

//Singly linked list######################################################
typedef struct SNode{
	int data;
	struct SNode *next;
} SNode;

SNode *head;

void SInsertAtEnd(int data){
	SNode *newNode=malloc(sizeof(*newNode));
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return;
	}
	SNode *temp1=head;
	SNode *tempprev;
	while(temp1!=NULL){
		tempprev=temp1;
		temp1=temp1->next;
	}
	tempprev->next=newNode;
}

void SInsertAtPosition(int data, int n){
	SNode *newnode = malloc(sizeof(*newnode));
	newnode->data=data;
	newnode->next=NULL;
	if(n==1){
		newnode->next=head;
		head=newnode;
		return;
	}
	SNode *temp1=head;
	for(int i=0;i<n-2;i++){
		temp1=temp1->next;
	}
	newnode->next=temp1->next;
	temp1->next=newnode;
}

void SNodeDelete(int n){
	SNode *temp1=head;
	if(n==1){
		head=temp1->next;
		free(temp1);
		return;
	}
	for(int i=0;i<n-2;i++){
		temp1=temp1->next;
	}
	SNode *temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}

void SIterativeReverse(){
    SNode *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current != NULL){
        next=current->next;
        current->next=prev;//Next's next is prev/NULL
        prev=current;
        current=next;
    }
    head=prev;
}

void SRecursiveReverse(SNode *p){
    if (p->next==NULL){
        head=p;
        return;
    }
    SRecursiveReverse(p->next);
    p->next->next=p;//This will execute only after base condition is reached
    p->next=NULL;
}

void SIterativePrint(){
	SNode *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void SRecursivePrint(SNode *p){
	if(p==NULL){return;}
	printf("%d ",p->data);
	SRecursivePrint(p->next);
}

void SListSearch(SNode *p,int n){
	while(p!=NULL){
		if(p->data==n){printf("%d found\n", n);return;}
		p=p->next;
	}
	printf("%d not found\n", n);
}

//Doubly linked list#####################################################
// A complete working C program to
// demonstrate all insertion
// methods

// A linked list node
struct dNode {
	int data;
	struct dNode* next;
	struct dNode* prev;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
void DInsertAtFront(struct dNode** head_ref, int new_data)
{
	/* 1. allocate node */
	struct dNode* new_node
		= (struct dNode*)malloc(sizeof(struct dNode));

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head and previous as NULL
	*/
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the
* given node */
void DInsertAfter(struct dNode* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct dNode* new_node
		= (struct dNode*)malloc(sizeof(struct dNode));

	/* 3. put in the data */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void DInsertAtEnd(struct dNode** head_ref, int new_data)
{
	/* 1. allocate node */
	struct dNode* new_node
		= (struct dNode*)malloc(sizeof(struct dNode));

	struct dNode* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;
}

// This function prints contents of linked list starting
// from the given node
void DPrintList(struct dNode* node)
{
	struct dNode* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
	printf("\n");
}

//Circular linked list##################################################
// C program to implement the above approach

/* structure for a node */
struct cNode
{
	int data;
	struct cNode *next;
};

/* Function to insert a node at the beginning of a Circular
linked list */
void CInsertAtStart(struct cNode **head_ref, int data)
{
	struct cNode *ptr1 = (struct cNode *)malloc(sizeof(struct cNode));
	struct cNode *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* If linked list is not NULL then set the next of last node */
	if (*head_ref != NULL)
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1;
}

/* Function to print nodes in a given Circular linked list */
void cprintList(struct cNode *head)
{
	struct cNode *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
}




int main(){
//Singly linked list
	head=NULL;
	SInsertAtEnd(5);
	SInsertAtEnd(7);
	SInsertAtEnd(3);
	SInsertAtEnd(4);
	SInsertAtEnd(9);
	SInsertAtPosition(99,2);
	SInsertAtPosition(98,5);
	SIterativePrint();
	SNodeDelete(2);
	printf("Delete\n");
	SIterativePrint();
	printf("\n");
	SIterativeReverse();
	printf("Iterative Reverse\n");
	SRecursivePrint(head);
	SRecursiveReverse(head);
	printf("\n");
	SRecursivePrint(head);
	printf("\n");
	SListSearch(head,99);
	
	
//Doubly linked list
	printf("\nDoubly linked list\n");
	struct dNode* dhead = NULL;

	// Insert 6. So linked list becomes 6->NULL
	DInsertAtEnd(&dhead, 6);

	// Insert 7 at the beginning. So linked list becomes
	// 7->6->NULL
	DInsertAtFront(&dhead, 7);

	// Insert 1 at the beginning. So linked list becomes
	// 1->7->6->NULL
	DInsertAtFront(&dhead, 1);

	// Insert 4 at the end. So linked list becomes
	// 1->7->6->4->NULL
	DInsertAtEnd(&dhead, 4);

	// Insert 8, after 7. So linked list becomes
	// 1->7->8->6->4->NULL
	DInsertAfter(dhead->next, 8);

	printf("Created DLL is: ");
	DPrintList(dhead);
	
	/* Initialize lists as empty */
	struct cNode *chead = NULL;

	/* Created linked list will be 11->2->56->12 */
	CInsertAtStart(&chead, 12);
	CInsertAtStart(&chead, 56);
	CInsertAtStart(&chead, 2);
	CInsertAtStart(&chead, 11);

	printf("Contents of Circular Linked List\n ");
	cprintList(chead);
	printf("\nEnd\n");
}
