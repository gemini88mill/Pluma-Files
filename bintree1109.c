#include <stdlib.h>
#include <stdio.h>

//binary tree 11.09.2016

//basic node structure of bin tree
struct node{
	int key_value;
	struct node *left;
	struct node *right;
};

void insert(int key, struct node **leaf);
void destroy_tree(struct node *leaf);
struct node *search(int key, struct node *leaf);

int main(){

	//initialize and keep track of root 
	struct node *root = 0;
		
	insert(5, &root);
	insert(13, &root);
	insert(27, &root);
	insert(78, &root);

	struct node *retval = search(6, root);
	
	if(retval == 0){
		printf("not found");
		return 1;	
	}
	printf("%d\n", retval->key_value);	

	return 0;
}

void destroy_tree(struct node *leaf){
	if(leaf != 0){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);	
	}
}

void insert(int key, struct node **leaf){
	if(*leaf == 0){
		*leaf = malloc(sizeof(struct node));
		(*leaf)->key_value = key;

		//init children to null
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	
	} else if (key < (*leaf)->key_value){
		insert(key, &(*leaf)->left);	
	} else if (key > (*leaf)->key_value){
		insert(key, &(*leaf)->right);	
	}
}

struct node *search(int key, struct node *leaf){
	if(leaf != 0){
		if(key == leaf->key_value){
			return leaf;		
		}else if(key < leaf->key_value){
			return search(key, leaf->left);		
		}else{
			return search(key, leaf->right);		
		}
	}else{
		return 0;	
	}
	
}
