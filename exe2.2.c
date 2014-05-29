/* programa fork1.c - ref  SOC - SGG-CAMPUS pg 71 */

#include <stdio.h>/*para fork, getpid, wait e exit */
#include <unistd.h>/*para printf */
#include <sys/types.h> /*para fork, getpid, wait e exit */
#include <stdlib.h>
int main(int argc, char * argv[])
{
	int x;
	x = fork(); /* cria processo */
	
	if(x<0) {/* ocorreu erro */
		fprintf(stderr,"fork falhou");
		exit(-1);
	}
	else if(x==0){ /* codigo do filho */
		printf("\nPID = %d :\n\n",getpid());
		execlp("/bin/ls","ls",NULL); /* carrega e executa um comando do linux (ls) */
		exit(0);
	}
	else{ /* codigo do pai */
		wait(NULL); /* pai espera o filho */
		printf("\nPID = ",getpid());
		printf("x = %d ",x);
		exit(0); /* termina ok */
	}
	return 0;
}