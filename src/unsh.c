#include <stdio.h>
#include <unistd.h>

#define MAX_PROGRAM_NAME_LENGTH 100
#define MAX_ARGS_LENGTH 100

const char termchar = '>'; //Sets the "terminal character" used at the start of each new command.
pid_t pid;

char programName[MAX_PROGRAM_NAME_LENGTH];
char* args[MAX_ARGS_LENGTH];

void inloop() { //Runs the shell.
	for(;;) {
		printf(&termchar);
		fgets(programName, MAX_PROGRAM_NAME_LENGTH, stdin);
		getchar();
		printf("Program Arguments:");
		fgets(*args, MAX_ARGS_LENGTH, stdin);
		getchar();
		fork();
	}
}

void exec_cmd() { //Function for executing programs.
	execvp(programName,args); //Replaces the existing program with the one previously set in inputchar.
}

int main() {
	pid = getpid();
	if (pid != 0) { //Checks if the PID is not zero.
		inloop(); //If the PID is not zero, run the shell using the inloop() function.
	}
	else { //If the PID turns out to be zero, assume that this program is a duplicate of the existing shell.
		exec_cmd(); //As the PID is zero, the program can safely pass over to exec_cmd(), which allows the shell to run the program set in the variable "programName".
	}
}
