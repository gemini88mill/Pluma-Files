//Linked Lists 10.31.2016

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int delete(struct node *node, int value);
void print_list(struct node *node);
void iter_insert(struct node *node, int data);

int main(int argc, char *argv[]){
	
	printf("hello world!");

	struct node *head; 
	struct node *current;
	int i;

	head = malloc(sizeof(struct node));
	head->next = NULL;	

	current = head;	

	//iterative insert 
	for(i = 1; i < argc; i++){
		iter_insert(current, atoi(argv[i]));
		current = current->next;	
	}

	print_list(head);

	int return_delete_val = delete(head->next, 16);

	return 0;
}

void iter_insert(struct node *node, int data){
	if(node->next == NULL){
		node->next = malloc(sizeof(struct node));
		node->next->data = data;	
	}
}

void print_list(struct node *node){
	while(node != NULL){
		printf("%d\t", node->data);
		node = node->next;
	}
}

int delete(struct node *node, int value){

	//if value found,
	if(node->data == data){
			
	} 	
		
	return 0;
}
