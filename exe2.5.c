/* programa signal1.c:ref.Ribeiro, Uira, Sistemas distribuídos, pg 77 cap 3*/
/* Exemplo que permite v
erificar o codigo retornado pelo exit(..), apos compilar e executar digite
echo $? Para verificar o codigo de saida do programa */
#include <stdio.h>/* para printf e scanf */
#include <unistd.h>/* para fork, getpid e exit */
int main(){
	int i;
	printf("\n digite um numero inteiro >= 0: ");
	scanf("%d",&i); /* experimente com i=0 e i=10 */
	printf("\n PID = %d e vai terminar com o sinal = %d\n", getpid(),i);
	sleep(i);
	printf("\n Fui...\n");
	exit(i); /* termina i!!! */

	/* Ele vai e da um sleep o  de tamanho i que é o que você digitou  */
}