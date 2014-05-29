#include <stdio.h>
#include <stdio.h>
#include <pthread.h>

void *hello(){
	int i;	
	while(1)
	{
		printf("Hello World\n");
		for(i=0; i < 150000000; i++);
	}
}

void *goodbye(){
	int i;
	while(1)
	{
		printf(" Goodbye World\n");
		for(i=0; i < 50000000; i++);
	}
}

int main(){
	pthread_t hello_id; //thread para a funcao hello
	pthread_t goodbye_id;//thread para a funcao goodbye
	int status;//get status
	status = pthread_create(&hello_id , NULL , hello , NULL);//cria thread
	status = pthread_create(&goodbye_id , NULL , goodbye , NULL);//cria thread
	if(status!=0)//só se der falha
		exit(-1);
	pthread_exit(NULL);
}
/*
	Se mudar o tempo ... a thread com maior tempo aparece menos vezes
*/