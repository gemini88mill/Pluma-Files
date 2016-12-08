//binary tree 
//11.13.2016

#include <stdio.h>
#include <stdlib.h>

struct binNode{
	int data;
	struct binNode *left;
	struct binNode *right;
};

void insertNode(int data, struct binNode **tree);
void deleteNode();
void searchNode(struct binNode **tree);
void printTree(struct binNode *node);

int main(){
	printf("Hello World");

	//init rootNode
	struct binNode *root;
	root = malloc(sizeof(struct binNode));
	root = NULL;

	struct binNode *current;

	current = root;

	insertNode(5, &current);
	insertNode(7, &current);

	printTree(current);

}

//insert must be double pointer, points to tree
void insertNode(int data, struct binNode **tree){
	struct binNode *node;	
	
	//check if node is null
	if(node == NULL){
		//init node
		node = malloc(sizeof(struct binNode));
		//add values to node
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		
		*tree = node;
		return;
	
	} else {
		if(node->data > data){
			insertNode(data, &(*tree)->left);		
		}else if(node->data < data){
			insertNode(data, &(*tree)->right);		
		}
	}
}

void deleteNode(){}

void searchNode(struct binNode **tree){
	
}

void printTree(struct binNode *node){
	if(node == NULL){
		return;	
	}else{
		printf("%d", node->data);
		printTree(node->left);
		printTree(node->right);
	}

	//	printf("%d", node->data);	
}





