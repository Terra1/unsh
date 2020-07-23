#include <stdio.h>
#include <unistd.h>

#define MAX_PROGRAM_NAME_LENGTH 100
#define MAX_ARGS_LENGTH 100

const char termchar = '>';
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
		inloop(); //If the PID is not zero, run the shell using the inloop() function, starting at line 7.
	}
	else { //If the PID turns out to be zero, assume that this program is a duplicate of the existing shell.
		exec_cmd(); //Runs the exec_cmd function, starting at line 17.
	}
}
