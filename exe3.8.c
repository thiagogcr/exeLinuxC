#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX 300000

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;
bool stop = false;

void *killBySiginal()
{
	char c;
	printf("Digite o Sinal:\n");
	scanf(" %c",&c);
	if(c == "T"){
		printf("Parou com o Sinal %s", &c);
		stop = true;				
	}
	stop = false;
	sleep(1);
}

void *producer(void *ptr)
{
	int i;
	for (i = 1; i < MAX; i++)
	{
		pthread_mutex_lock(&the_mutex);
		while( buffer != 0 )
			pthread_cond_wait(&condp, &the_mutex);
		buffer = i;
		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&the_mutex);
		if(killBySiginal())
			break;
	}
	pthread_exit(0);
}

void *cosumer(void *ptr)
{	
	int i;
	for (i = 1; i < MAX; i++)
	{
		pthread_mutex_lock(&the_mutex);
		while( buffer == 0 )
			pthread_cond_wait(&condc, &the_mutex);
		buffer = 0;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&the_mutex);		
	}
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	printf("Thiago Gonçalves Cardoso Resnede\n");
	printf("Rafael Abadala Burle\n");
	printf("Matheus Gama\n");
	printf("Marcelo Cézar de almeida Junior\n");
	printf("Matheus Souza Silva\n");
	pthread_t pro, con;
	pthread_mutex_init(&the_mutex, 0);
	pthread_cond_init(&condc, 0);
	pthread_cond_init(&condp, 0);
	pthread_create(&con, 0, cosumer, 0);
	pthread_create(&con, 0, producer, 0);
	pthread_join(pro, 0);
	pthread_join(con, 0);
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);
	return 0;
}

/*
 É um semaforo 
*/