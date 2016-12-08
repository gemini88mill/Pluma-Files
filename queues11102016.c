//Queues 11.10.2016

//Created by Raphael Miller 

#include <stdlib.h>
#include <stdio.h>

struct Queue{
	int capacity;
	int size;
	int front;
	int rear;
	int *elements;
};

struct Queue * createQueue(int maxElements);
void enqueue(struct Queue *q, int element);
void dequeue(struct Queue *q);
int front(struct Queue *q);

int main(){
	
	int maxElements = 5; //defines max number of elements 

	struct Queue *q = createQueue(maxElements);
	enqueue(q, 4);
	dequeue(q);
	front(q);
	
	return 0;
}

struct Queue * createQueue(int maxElements){
	//create a queue for the given number of max elements 

	//init Queue
	struct Queue *q = malloc(sizeof(struct Queue));
	
	//init properties
	q->capacity = maxElements;
	q->size = 0;
	q->front = 0;
	q->rear = -1;
	q->elements = malloc(sizeof(int)*maxElements);

	return q;
}

void enqueue(struct Queue *q, int element){
	if(q->size == q->capacity){
		printf("Queue is full");	
	}
}

void dequeue(struct Queue *q){
	/*if queue is zero then it is empty*/
	if(q->size == 0){
		printf("Queue is empty");
		return;	
	}else{
		//removing an element adds 1 to front 
		q->size--;
		q->front++;
		
		if(q->front == q->capacity){
			q->front = 0;		
		}	
	}
	return;
}

int front(struct Queue *q){
	if(q->size == 0){
		printf("Queue is empty");
		exit(0);	
	}	

	return q->elements[q->front];
}














