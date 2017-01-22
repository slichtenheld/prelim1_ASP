#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	if (argc != 2) {
    	// fprintf writes output to the given stream, in this case stderr
    	fprintf(stderr, "Usage: %s <string>\n", argv[0]); 
    	exit(EXIT_FAILURE);
  	}
  	printf("%s\n",argv[1] );
}