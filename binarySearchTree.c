#include <stdio.h>
#include <stdlib.h>



/*to make a simple binary search tree. */

struct Node{
	int val;
	struct Node *left;
	struct Node *right;

};

struct Node *find(struct Node *currentNode, int val);
void PrintInorder(struct Node *node);
struct Node* insert_into_binary_tree(struct Node *currentNode, int val);

int main (int argc, char* argv[]){


	//declare node 
	struct Node *root;
	struct Node *current; 

	//this defines the first node root and allocates data for that space
	root = malloc(sizeof(struct Node));

	//init the children
	root->left = NULL;
	root->right = NULL;

	//root does not change otherwise we would lose its memory 
	current = root;

	int i;
	int inputs[argc];

	/*Debug for command line argument -- delete later */
	for(i = 1; i < argc; i++){
		printf("%i ", atoi(argv[i]));
		inputs[i - 1] = atoi(argv[i]);
		insert_into_binary_tree(current, inputs[i]);
	}

	PrintInorder(root);

	struct Node *returnVal = find(root, 35);
	printf("%i", returnVal->val);

	return 0;
}

struct Node *find(struct Node *currentNode, int val){
	if(currentNode == NULL){
		return NULL;	
	}
	if(val > currentNode->val){
		return find(currentNode->right, val);	
	}
	else if(val < currentNode->val){
		return find(currentNode->left, val);
	}
	else{
		return currentNode;	
	}

}


//insert function for bin tree
struct Node* insert_into_binary_tree(struct Node *currentNode, int val){
	
	if(currentNode == NULL){
		//place current node in position	
		struct Node *temp;
		temp = malloc(sizeof(currentNode));
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;	
	}
	if(val > currentNode->val){
		currentNode->right = insert_into_binary_tree(currentNode->right, val);
	} 
	else if(val < currentNode->val){
		currentNode->left = insert_into_binary_tree(currentNode->left, val);
	}
	
	return currentNode;
			

	return 0;
}


void PrintInorder(struct Node *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->val);
        PrintInorder(node->right);
}





