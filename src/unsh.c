#include <stdio.h>
#include <unistd.h>

char termchar = "]";
int pid = pid_t;

void inloop() { //The actual shell function.
	int ready()
	do {
		printf(termchar);
		const char *inputchar[] = getchar( );
		printf("Program Arguments:")
		char *const args[] = getchar( );
		fork();
	} while (ready)
}

void exec_cmd() { //Function for executing programs.
	exec(inputchar, args[]); //Replaces the existing program with the one previously set in inputchar.
}

int main {
	if (pid != 0) { //Checks if the PID is zero.
		inloop();
	}
	else { //If the PID not zero, assume that this program is a duplicate of the existing shell.
		exec_cmd();
	}
}
