//fibinacci.c 
//created by raphael miller
//11.01.2016

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	/*if more than one argument, send error message*/

	if(argc > 2){
		printf("incorrect format, only one argument accepted");
		return 1;	
	}

	printf("Hello world");

	return 0;


}
