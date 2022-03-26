#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "common.h"
#include "common_threads.h"

volatile int counter;
int loops = 0;

void *worker(void *arg) {
	for(int i=0; i < loops; i++){
		counter++;
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage threads <value>: main\n");
		exit(1);
    	}

	loops = atoi(argv[1]);
	pthread_t p1, p2;
	printf("Initial value : %d\n", counter);

	Pthread_create(&p1, NULL, worker, "A"); 
	Pthread_create(&p2, NULL, worker, "B");
	
	// join waits for the threads to finish
	Pthread_join(p1, NULL); 
	Pthread_join(p2, NULL); 
	
	printf("Final value: %d\n", counter);
	return 0;
}

