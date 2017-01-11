#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//read in line from stdin, returns -1 if misread input
int readInput(char* buffer);

//parse input and return event, returns -1 if faulty input
int parseInput(char *buffer, struct calendarEvent_t *c);

main(int argc, char *argv[]){
	
	// initialize data structure


	// reusing buffer and event throughout process
	char *buffer = NULL; // getline will allocate space for buffer
	struct calendarEvent_t c;

	while(readInput(&buffer) > 0){ // reads in line from stdin
		 if (parseInput(buffer, c) > 0) { // if proper input

		 }
	}
	
	while(charsRead = getline(&buffer,&len,stdin) > 0 ){ // read in line till EoF
		if (parseEmail(buffer, &c) != -1) printCalendarEvent(c);
			switch(c.type){
				case 'C': break; //add event to data structure
				case 'D': break; //delete event from data structure
				case 'X': break; //modify event in data structure
				default: perror("unsupported calendarEvent command");
			}
	}

	free(buffer); // need to free buffer allocated by getline!!!!
	return(0);
}

int readInput(char* buffer){
	long unsigned int len; // length of buffer
	return getline(&buffer,&len,stdin);
}

int parseInput(char *buffer, struct calendarEvent_t *c){
	char *pch = strtok (buffer," ,");
	unsigned int counter = 0;
  		while (pch != NULL){
		    switch(++counter) {
		    	case 1: c->type = pch[0]; break;
		    	case 2: memcpy(c->title,pch, strlen(pch)+1); break;
		    	case 3: memcpy(c->date,pch, strlen(pch)+1); break;
		    	case 4: memcpy(c->time,pch, strlen(pch)+1); break;
		    	case 5: memcpy(c->location,pch, strlen(pch)+1); break;
		    }
		    pch = strtok (NULL, " ,");
		}
	if (counter < 6) return -1;
	return 0;
}

// some data structure needed
	// will use array for now, but code should be able to
	// easily transition to a more fitting data structure

// read in line
	// if C (Create)
		// add new event to data structure
	// else if D (Delete)
		// find event in data structure with same title,date,and time and delete
	// else if X (Modify)
		// find event in data structure with same title and date, modify with new provided time and location