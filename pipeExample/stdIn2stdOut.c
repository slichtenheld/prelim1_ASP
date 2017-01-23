#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	/*
	if (argc != 2) {
    	// fprintf writes output to the given stream, in this case stderr
    	fprintf(stderr, "Usage: %s <string>\n", argv[0]); 
    	exit(EXIT_FAILURE);
  	}
  	*/
  	
	// initialize variables
	char *buffer = NULL; // getline will allocate space for buffer
	int charsRead = 0;
	long unsigned int len = 0; // length of buffer
	
	while(charsRead = getline(&buffer,&len,stdin) > 0 ){ // read in line till EoF
		printf("%d: %s", getpid(), buffer );
	}

  	free(buffer); // need to free buffer allocated by getline!!!!
  	printf( "%d: Exiting...", getpid() );
	return(0);
}