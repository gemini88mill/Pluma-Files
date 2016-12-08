//Dynamic Memory Allocation 

#include <stdio.h>
#include <stdlib.h>

struct books{
	char author[50];
	int id;	
};

int main(){

	//array memory allocation 
	int *array = malloc(sizeof(int) * 4);
	/*array is listed as a pointer, allocate space with the amount 
	of the int size + number of arrays expected */
	
	int **array2 = malloc(sizeof(int) * sizeof(int));
	/*Uses a double pointed array, In order for proper function much like 
	Arraylist of array lists, 2d arrays are treated like accessing a pointer
	to an array of pointers.*/
	
	struct books *myStruct = malloc(sizeof(struct books));
	/*struct carries the definition of said struct allocation of the type 
	def is valid */

	free(array2);
	free(array);
	free(myStruct);
}
