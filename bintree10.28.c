#include <stdio.h>
#include <stdlib.h>

/*Binary tree 10.28.2016
	created by Raphael Miller 
*/

struct binNode{
	int val;
	struct binNode *left;
	struct binNode *right;
};

void PrintPostorder(struct binNode *node);
void PrintPreorder(struct binNode *node);
void PrintInorder(struct binNode *node);
struct binNode *findMin(struct binNode *node);
void insert(struct binNode *node, int val);
struct binNode *delete(struct binNode *node, int val);

int main(int argc, char *argv[]){
	//accept arguments
	int i;
	int bintreeValues[argc];
 
	//arguments accepted
	for(i = 1; i < argc; i++){
		bintreeValues[i] = atoi(argv[i]);
	}
	
	//create binary search tree root
	struct binNode *root = malloc(sizeof(struct binNode));
	struct binNode *current = NULL;

	//set current to root and use current for everything to not lose root to anything. 
	current = root;

	for(i = 1; i < argc; i++){
		insert(current, bintreeValues[i]);
	}

	current = root;

	PrintPostorder(current);
	PrintPreorder(current);
	PrintInorder(current);
}

void insert(struct binNode *node, int val){
	//terminating condition 
	if(node == NULL){
		//place node here
		struct binNode *temp; 
		temp = malloc(sizeof(struct binNode));
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;	

		node = temp;
	}
	//if not in right position 
	if(val < node->val){
		//if less than
		insert(node->left, val);	
	}
	else if(val > node->val){
		//greater than 
		insert(node->right, val);	
	}
	//shouldn't fall through to here
}

struct binNode *delete(struct binNode *node, int val){
	//delete function using finder node, and value needed 
	//terminating condition
	struct binNode *temp;

	if(node == NULL){
		printf("Element not found");
	}
	else if(val < node->val){
		node->left = delete(node->left, val);	
	}
	else if(val > node->val){
		node->right = delete(node->right, val);	
	}	
	else{
		//if a right or left child exists
		if(node->right && node->left){
			
			temp = findMin(node->right);
			node->val = temp->val;
			node->right = delete(node->right, temp->val);		
		}
		else{
			temp = node;
			if(node->left == NULL){
				node = node->right;			
			}
			else if(node->right == NULL){
				node = node->left;			
			}
			free(temp);
		}
	}
	return node;

}

struct binNode *findMin(struct binNode *node){

	return node;
}

void PrintInorder(struct binNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->val);
        PrintInorder(node->right);
}

void PrintPreorder(struct binNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->val);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(struct binNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->val);
}










