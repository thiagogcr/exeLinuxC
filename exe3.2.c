#include<stdio.h>
int main(int argc, char** argv)
{
	int hora,minuto,segundo,total;
	printf("Digite o numero de horas:\n");
	scanf("%d",&hora);
	printf("Digite os minutos:\n");
	scanf("%d",&minuto);
	printf("Digite o numero de segundos:\n");
	scanf("%d",&segundo);
	total=(hora*3600)+(minuto*60)+segundo;
	printf("O total de segundos e: %d\n",total);
	return 0; 
	/*
		pega os paramentros e calculo os segundos
	*/
}