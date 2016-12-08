#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;

};

int remove_by_index(struct node ** head, int val);
void printList(struct node *node);
void insert(int val, struct node *node);

int main(int argc, char *argv[]){
	//linked lists first accept values from command line 

	int i;
	int values[argc]; 

	struct node *root;
	struct node *current;

	root = malloc(sizeof(struct node));
	if(root == NULL){
		return 1;	
	}


	current = root;

	for(i = 1; i < argc; i++){
		insert(atoi(argv[i]), current);
		 
	}

	remove_by_index(&root, 0);
	printList(root);
	

	return 0;
}

int remove_by_index(struct node ** head, int val){

	int i = 0;
	int retval = -1;

	struct node * current = *head;
	struct node * temp = NULL;

	if(val == 0){
		//remove head 
		temp = current;
			
	}

	return 0;
}

void insert(int val, struct node *node){
	struct node *current = node;
	
	while(current->next != NULL){
		current = current->next;	
	}
	
	current->next = malloc(sizeof(struct node));
	current->next->data = val;
	current->next->next = NULL;
}

void printList(struct node *node){
	//prints the list in order
	struct node *current = node;

	while(current != NULL){
		printf("%d\n", current->data);
		current = current->next;	
	}
}
