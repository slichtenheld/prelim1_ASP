#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[]) {


	pid_t cpid1, cpid2;

	//execl("/bin/ls", "ls", NULL);
	int r = execl("testprog", "testprog", "asfdasdf", (char *) NULL);

	if (r == -1) { 
    	perror("exec error");
    	exit(EXIT_FAILURE);
  	}
}