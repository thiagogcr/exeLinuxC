/* programa shell.c*/
/* umexemplo de um shell o pai explicitamente espera o filho terminar o filho executa o comando */
int main() {
	int status;
	char comando[10], parametro[10], path[20];
	while (1) {
	gets(comando);
	gets(parametro);
	strcpy(path,"/bin/");
	strcat(path, comando);
	if (fork() != 0)
		waitpid(-1, &status, 0);
	else
	execl(path, path, parametro, 0);
	/* mesma ideia do main: o primeiro parametro eh o nome do comando
	execl(comando, parametro, parametro ... ambiente) por isso
	execl(comando, comando, parametros ... ambiente); */
	/*
	Teste com ./exe.exe
				echo
				"Teste"
	Retornou certo o echo "teste"
	*/
	}
}