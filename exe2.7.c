/* programa signal3.c:ref.Ribeiro, Uira, Sistemas distribuídos, pg 87 cap 3*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void action(int sig){
	printf("0\n Sinal recebido= %d. Terminando o programa \n", sig);
	exit(0);
}

int main(){
	int i;
	printf("\n digite um numero inteiro > 0: ");
	scanf("%d",&i); /* experimente com i=5 e i=10 */
	printf("\n Sinal de alarme será enviado daqui a = %d segundos", i);
	signal(SIGALRM,action);
	alarm(i);
	for(;;);/* loop infinito */
		return(i);
	//Ele você entra com o sinal o programa espera para dar o sinal para parar quando você digita a o
}
