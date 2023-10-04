#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	printf("Please don't hurt me.\n");
	printf("Peace all around. Please don't take my ship.\n");
	char* argument[] ={"./takeover.out", "Sit down Boa!"};
//	execvp("./takeover.out", argument); // Where Takeover.out takesover
	// Run strace and see if execvp() is running. Try another exec then.
	char* nameOfShip = "Nice guys!!";
	printf("Name of the captain: %s\n", nameOfShip);
}
