#include <stdio.h>
#include <stdio.h>
#include "pthread.h"
int a = 0;

void *th_hello(){
int i;
	while(1)
	{
		printf("Hello World\n");
		for(i=0; i < 10000000; i++);
	}
}	

void *th_aumenta(){
	int i;
	while(1) {
		a = a + 1;
		printf(" Aumentando: %d\n",a);
		for(i=0; i < 50000000; i++);
	}
}
void *th_diminui(){
	int i;
	while(1) {
		a = a-1;
		printf(" Diminuindo: %d\n", a);
		for(i=0; i < 50000000; i++);
		}
}

int main(){
	pthread_t id_hello, id_aumenta, id_diminui;
	int status;
	status = pthread_create(&id_hello , NULL , th_hello , NULL);
	status = pthread_create(&id_aumenta , NULL , th_aumenta , NULL);
	status = pthread_create(&id_diminui , NULL , th_diminui , NULL);
	if(status!=0)
		exit(-1);
	pthread_exit(NULL);

	//Se mudar o tempo ... a thread com maior tempo aparece menos vezes
}