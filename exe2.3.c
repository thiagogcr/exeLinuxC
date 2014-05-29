/* programa fork2.c */
#include <stdio.h> /* para printf */
#include <unistd.h> /* para fork */
#include <sys/types.h>
int main(int argc, char * argv[])
{
	int x;
	printf("ANTES DE fork\n");
	x = fork(); /* cria processo */
	printf("DEPOIS DE fork\n");
	exit(0); /* termina ok */
}