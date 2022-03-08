#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int value = 5;

int main(){
	// pip[0] = Read     pip[1] = Write
	// Se pipe_status for -1, ocorreu um erro
	int pip[2], pipe_status;
	pid_t pid;

	pipe_status = pipe(pip);
	
	pid = fork(); // Divide o processo 2, um Processo Pai e outro Filho
	
	if (pid == 0) { // Processo Filho
		printf("Entrei no filho!\n");
		
		value += 15;
		
		printf ("CHILD: value = %d\n",value);
		
		// Escreve o valor de value no pipe, para que o Parent possa ler
		write(pip[1], &value, 1);  
		
		return 0;
	}
	else if (pid > 0) { // Processo Pai
		wait(NULL);
		
		// Lê o valor de value do pipe, escrito pelo processo Child
		read(pip[0], &value, sizeof(int)); 

		
		printf("PARENT: value = %d\n",value);
		return 0;
	}
}
