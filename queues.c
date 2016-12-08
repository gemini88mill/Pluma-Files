//	create a data structure that implements a queue that accepts numbers 
//	and commands from the command line
//	when called it should look like this 

/*	./a.out [value][command]*/

#include <stdio.h>
#include <stdlib.h>

void createQueue(int max_elements);
void enqueue();
void dequeue();
void front();

int main(int argc, char *argv[]){
	//accepts two arguments, collect first argument which is the value 
	
	if(argv[1] == "createQueue"){
		createQueue((argc - 1));
		
	}
	
	printf("Hello world\n");

	return 0;
}

void createQueue(int max_elements){
	int elements = malloc(sizeof(int) * max_elements);
}
