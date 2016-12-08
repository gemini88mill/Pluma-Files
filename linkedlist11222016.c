//linked lists in c 
//by raphael miller 

#include <stdlib.h>
#include <stdio.h>

struct node{
	int val;
	struct node * next;
};

void insert(struct node *node, int val);
void printLinkedList(struct node * root);

int main(){

	struct node * root = malloc(sizeof(struct node));
	struct node * current;

	current = root;
	insert(current, 5);
	insert(current, 5);
	insert(current, 5);	
	
	//insert() 
	//delete()
	//search()
	printLinkedList(root);

	//struct node * root = NULL;

	return 0;
}

void insert(struct node *node, int val){
	struct node * current = node;
	
	while(current->next != NULL){
		current = current->next;	
	}
	
	current->next = malloc(sizeof(struct node));
	current->next->val = val;
	current->next->next = NULL;
}

void delete(struct node ** root, int val){
	
	int i = 0;
	int retval = -1;

	
}

void search(){
}

void printLinkedList(struct node * root){
	struct node * current = root;

	while(current->next != NULL){
		printf("%d ", current->val);
		current = current->next;	
	}
	
	
}
