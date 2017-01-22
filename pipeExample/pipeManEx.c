
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
  int fd[2];
  pid_t cpid;
  char buf[5];

  /* check args */
  if (argc != 2) { // program takes in 1 string
    // fprintf writes output to the given stream, in this case stderr
    fprintf(stderr, "Usage: %s <string>\n", argv[0]); 
    exit(EXIT_FAILURE);
  }

  /* create pipe */
  if (pipe(fd) == -1) {
    perror("pipe error");
    exit(EXIT_FAILURE);
  }

  /* create child, fork */
  cpid = fork();
  if (cpid == -1) { /* terminate prog if fork fails */
    perror("fork");
    exit(EXIT_FAILURE);
  }


  /* child */
  if (cpid == 0) {    /* Child reads from pipe */
    printf("I am the child\n");
    close(fd[1]);     /* Close unused write end, child only reading */

    while (read(fd[0], buf, 1) > 0)
      write(STDOUT_FILENO, buf, 1);

    write(STDOUT_FILENO, "\n", 1);
    close(fd[0]);
    _exit(EXIT_SUCCESS); /* use _exit() for child processes */
  }

  /* parent */
  else {
    printf("I am the parent\n");
    close(fd[0]);          /* Close unused read end */
    write(fd[1], argv[1], strlen(argv[1]));
    close(fd[1]);          /* Reader will see EOF */
    wait(NULL);                /* Wait for child */
    exit(EXIT_SUCCESS);
  }

}
