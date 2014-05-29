#include<stdio.h>

int main(int argc, char * argv[])
{
	int x;
	for(x = atoi(argv[1]); x <= atoi(argv[2]);x++)
	{
		if(x % 2 != 0)
		{
			if(x % 7 == 0)
			{
				if(x % 5 != 0)
				{
				  printf("Saida: %d\n", x);
				}
			}
		}
	}
	return 0;
}