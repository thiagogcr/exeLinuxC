#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
void *hello()
{
	while(1)
	{
		printf("Hello World\n");
		printf("Note que a thread hello esta em um while infinito\n\n");
	}
}

int main()
{
	pthread_t id;
	int status;
	status = pthread_create(&id , NULL , hello , NULL);
	if(status!=0)
		exit(-1);
	pthread_exit(NULL);
	/*
		Cria uma thread para fazer a funcao hello entra em loop infinito
	*/
}