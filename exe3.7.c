#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define NUMBER_OF_THREADS 10

void* print_hello_world(void *tid ){
	printf("Hello World. Greetings from thread, %d\n", tid);
}

int main(int argc, char *argv[]){
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	for (i = 0; i < NUMBER_OF_THREADS; ++i)
	{
		printf("Main here. creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void*)i );
		if(status != 0){
			printf("Oops. pthread_create returned error code %sd0", status);
			exit(-1);
		}
	}
	exit(NULL);
}
/*
 ele impirmi e fala que vai criar a thread na linha 15 e mostra o valor de i;
 e ele continua rodando ... quando ele cria a thread ele mostra o mesmo valor de i ... por isso que fica fora de ordem
 pq ele não executa o for na mesma velocidade que cria uma thread

*/