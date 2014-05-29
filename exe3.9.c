/* programa procons.c -ref SOM–2a. ed. Tanenbaum pg 82 cap 2 */
/* Exemplo de produtor/consumidor usando threads */
/* Rodrigo Otavio R. Antunes */
/* Baseado no exemplo do Tanenbaum */
#include <sys/time.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h> //só pra usar bool

#define MAX 20 // tamanho da fila circular
#define ROUND 100 // numero de iteracoes
#define DRES 500000

char buffer[MAX]; // fila circular
int inptr=0, outptr=0, inbuffer=0; // apontadores para a fila
struct timespec delay;
struct timeval tv;
pthread_mutex_t mutex; // mutex
sem_t s_produtor, s_consumidor; // semaforos para produtor e consumidor
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

// Exibe o conteudo da fila e o valor dos semaforos
void mostrabuffer(char *mens)
{
	int i, s_pro, s_con;
	printf("%-10s ", mens);
	for (i=0; i<MAX; i++) {
		printf("%c", buffer[i]);
	}
	sem_getvalue(&s_produtor, &s_pro);
	sem_getvalue(&s_consumidor, &s_con);
	printf(" p=%03d c=%03d (%03d)\n", s_pro, s_con, inbuffer);
}

// insere um novo caractere na fila
void push(char c)
{
	if (inbuffer<MAX) {
		pthread_mutex_lock(&mutex); // inicio da sessao critica
		buffer[inptr]=c;
		inptr=(inptr+1)%MAX;
		inbuffer++;
	pthread_mutex_unlock(&mutex); // final da sessao critica
	}
}

// retira um caractere da fila
char pop(void)
{
	char c;
	if (inbuffer>0) {
	pthread_mutex_lock(&mutex); // inicio da sessao critica
	c=buffer[outptr];
	buffer[outptr]=' ';
	outptr=(outptr+1)%MAX;
	inbuffer--;
	pthread_mutex_unlock(&mutex); // final da sessao critica
	}
return(c);
}

// Produtor: sorteia uma letra e insere na fila
void produtor(void *ptr)
{
	int n=ROUND;
	char c;
	while (n>0) {
		sem_wait(&s_produtor); // aguarda um espaco na fila
		c=rand()%26+'A';
		push(c);
		mostrabuffer("push");
		n--;
		sem_post(&s_consumidor);
		tv.tv_sec=0;
		tv.tv_usec=((int)rand())%DRES;
		select(0, NULL, NULL, NULL, &tv); // delay randomico
		if(killBySiginal())
			break;		
	}
	pthread_exit(0);
}

// Consumidor: retira da fila um elemento e mostra na tela
void consumidor(void *ptr)
{
	int n=ROUND;
	char c;
	while (n>0) {
		sem_wait(&s_consumidor); // aguarda um item na fila
		c=pop();
		mostrabuffer("pop");
		n--;
		sem_post(&s_produtor);
		tv.tv_sec=0;
		tv.tv_usec=((int)rand())%DRES;
		select(0, NULL, NULL, NULL, &tv); // delay randomico
		if(killBySiginal())
			break;		
	}
	pthread_exit(0);
}

/* Programa principal
-
cria duas threads, uma produtora e
* outra consumidora e aguarda a finalizacao de ambas */
main()
{
	printf("Thiago Gonçalves Cardoso Resnede\n");
	printf("Rafael Abadala Burle\n");
	printf("Matheus Gama\n");
	printf("Marcelo Cézar de almeida Junior\n");
	printf("Matheus Souza Silva\n");
	
	pthread_t produtor_t, consumidor_t;
	char *message1 = "abdafsfasdfasdfasdfasdfasdfasdcd";
	char *message2 = "hkljhklhkjhlhkhkjlkhkjh";
	int i;
	srand(time(NULL));
	for (i=0; i<MAX; i++); 
		buffer[i]=' '; // prepara a fila
	sem_init(&s_produtor, 0, MAX); // produtor inicia com semaforo no maximo
	sem_init(&s_consumidor, 0, 0); // consumidor inicia com semaforo = 0
	mostrabuffer("init");
	// cria threads
	pthread_create(&produtor_t, NULL, (void*)&produtor, NULL);
	pthread_create(&consumidor_t, NULL, (void*)&consumidor, NULL);
	// aguarda o final das threads
	pthread_join(produtor_t, NULL);
	pthread_join(consumidor_t, NULL);
	mostrabuffer("end");
	sem_destroy(&s_produtor);
	sem_destroy(&s_consumidor);
	exit(0);
}