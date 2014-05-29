/* programa arglc.c - ref: Aprendendo C++ Jamsa - Makron Books pg 71 */
/* exibe na tela os parametros da linha de comando */
#include <stdio.h>
/* para printf */
int main(int argc, char * argv[])
{
	int i;
	printf("\n Voce digitou o comando %s ", argv[0]);
	printf("com os seguintes parametros : ");
	for (i=0; i < argc ; i++)
		printf("\nargv[%d] = %s ",i, argv[i]);
	printf("\n\n");
	return 0;
}