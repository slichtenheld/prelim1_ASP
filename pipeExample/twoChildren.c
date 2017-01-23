#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

	int fd[2];
	pid_t cpid1, cpid2;
	char buf[5];

	/* check args */
	if ( argc != 2 ) { // program takes in 1 string
    	// fprintf writes output to the given stream, in this case stderr
		fprintf(stderr, "Usage: %s <string>\n", argv[0]); 
    	exit(EXIT_FAILURE);
  	}

  	/* Create Pipe to be used by children */
  	if (pipe(fd) == -1) { 
    	perror("pipe error");
    	exit(EXIT_FAILURE);
  	}

  
	cpid1 = fork(); /* creates first child */
	if ( cpid1 > 0 ) { /* parent */
  		printf("PID: %d | PARENT\n", getpid());

  		cpid2 = fork(); /* creates second child */

		if ( cpid2 > 0 ) { /* parent */
  			/* All of parents code should be here so that isn't run by children */

	  		printf("PID: %d | PARENT\n", getpid());
	  		/* Parent does not need access to pipe */
  			close(fd[0]);
  			close(fd[1]);
  			wait(NULL);     /* Wait for children */
    		exit(EXIT_SUCCESS);
	  	}
	  	else if ( cpid2 == 0 ) { /* child 2 */
	  		printf("PID: %d, PPID: %d | CHILD2\n", getpid(), getppid());
	  		close(fd[0]);          /* Close unused read end */
    		write(fd[1], argv[1], strlen(argv[1]));
    		close(fd[1]);          /* Reader will see EOF */
    		wait(NULL);                /* Wait for child */
    		exit(EXIT_SUCCESS);
	  	}
	  	else if ( cpid2 == -1 ) { /* error */
	  		perror("fork error\n");
    		exit(EXIT_FAILURE);
	  	}

  	}
  	else if ( cpid1 == 0 ) { /* child 1 */
  		printf("PID: %d, PPID: %d | CHILD1\n", getpid(), getppid());
  		close(fd[1]);     /* Close unused write end, child only reading */

    	while (read(fd[0], buf, 1) > 0)
      	write(STDOUT_FILENO, buf, 1);

    	write(STDOUT_FILENO, "\n", 1);
    	close(fd[0]);
    	_exit(EXIT_SUCCESS); /* use _exit() for child processes */
  	}
  	else if ( cpid1 == -1 ) { /* error */
  		perror("fork error\n");
    	exit(EXIT_FAILURE);
  	}
}