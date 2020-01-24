#include <stdio.h>
#include <unistd.h>

char termchar = "]";
pid_t pid = getpid();

void inloop() { //Runs the shell.
	for(;;) {
		printf(termchar);
		const char *inputchar[] = getchar( );
		printf("Program Arguments:")
		char *const args[] = getchar( );
		fork();
	}
}

void exec_cmd() { //Function for executing programs.
	exec(inputchar, args[]); //Replaces the existing program with the one previously set in inputchar.
}

int main {
	if (pid != 0) { //Checks if the PID is not zero.
		inloop(); //If the PID is not zero, run the shell using the inloop() function, starting at line 7.
	}
	else { //If the PID turns out to be zero, assume that this program is a duplicate of the existing shell.
		exec_cmd(); //Runs the exec_cmd function, starting at line 17.
	}
}
