#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	
	float x = atof(argv[1]);
	float y = atof(argv[3]);
	char op = argv[2][0];
	float result;

	switch(op)
	{
		case 'x': 
			result = x * y;
		break;
		
		case '/': 
			result = x / y;
		break;
	
		case '+':
			result = x + y;
		break;
	
		case '-':
			result = x - y;
			break;		
	}

	printf("Resultado: %f \n", result);
	return 0;
}
