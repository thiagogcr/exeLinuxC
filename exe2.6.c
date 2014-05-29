/* programa signal2.c: ref.Ribeiro, Uira, Sistemas distribuídos, pg 82 cap 3*/
/* Exemplo em que permite verificar a chamada de sistema para enviar sinais */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h> 
int main(){
	int x,status, i;
	printf("\n PID = %d", getpid());
	x = fork(); /* cria processo */
	if (x==0){ /* codigo do filho */
		printf("\n x = %d PID = %d ", x, getpid());
	while(1){ /* loop infinito */
		printf("\n %d x = %d PID = %d ", i, x, getpid());
		
		i++;//só teste
		}
	}
	else{ /* codigo do pai */
		sleep(5);
		printf("\n x = %d PID = %d ", x, getpid());
		printf("\n enviando sinal para PID = %d ", x);
		kill(x,9);
		wait(&status);
		printf("\n processo = %d terminou com exit = %d\n", x, WEXITSTATUS(status));
	}
	exit(0); /* termina ok */
}