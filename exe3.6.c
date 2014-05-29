#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int pause(void);

void* funcao_thread(void *arg ){
	printf("\n Thread com PID = %d ", getpid());
}

int main(){
	int i,j;
	pthread_t t1;
	printf("\n Processo com PID = %d ", getpid());
	pthread_create(&t1, NULL,&funcao_thread, NULL);
	printf("\n Identificador do thread = %d segundos", t1);
	sleep(1);
	exit(0);
}
/*
	cria uma thread e retorna seu id
*/