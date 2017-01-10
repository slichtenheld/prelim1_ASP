#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calendarEvent_t {
	char type;
	char title[11];
	char date[11];
	char time[6];
	char location[11];
};
void printCalendarEvent(calendarEvent_t c);
int parseEmail(char * buffer, calendarEvent_t *c);

main(int argc, char *argv[]){
	
	// initialize variabeles
	char *buffer = NULL; // getline will allocate space for buffer
	int charsRead = 0;
	long unsigned int len = 0; // length of buffer

	//printf("Enter a string\n");
	struct calendarEvent_t c;// = {'C',"Meeting   ","01/12/2017","15:30","NEB202    "};
	//printCalendarEvent(c);
	
	while(charsRead = getline(&buffer,&len,stdin) > 0 ){ // read in line till EoF
		if (parseEmail(buffer, &c) != -1) printCalendarEvent(c);
	}

	free(buffer); // need to free buffer allocated by getline!!!!
	return(0);
}

void printCalendarEvent(calendarEvent_t c){
	printf("%c,%s,%s,%s,%s\n",c.type, c.title, c.date, c.time, c.location);
}

int parseEmail(char * buffer, calendarEvent_t *c){ // returns -1 if doesn't have everything
	char *pch = strtok (buffer," ,");
	unsigned int counter = 0;
  		while (pch != NULL){
		    switch(counter++) {
		    	case 0: break; //do nothing, ignore "Subject:"
		    	case 1: c->type = pch[0]; break;
		    	case 2: memcpy(c->title,pch, strlen(pch)+1); break;
		    	case 3: memcpy(c->date,pch, strlen(pch)+1); break;
		    	case 4: memcpy(c->time,pch, strlen(pch)+1); break;
		    	case 5: memcpy(c->location,pch, strlen(pch)+1); break;
		    	//default: perror("error parseEmail");
		    }
		    pch = strtok (NULL, " ,");
		}
	if (counter < 6) return -1;
	return 0;
}

// until end of File
	// read in line
	// parse it
	// printout
	// repeat


//		printf("Size read: %d, Length of Buffer %lu\n", charsRead, len);

// parse stuff into tokens
/*
char *pch = strtok (buffer," ,.-");
  		while (pch != NULL){
		    printf ("%s\n",pch);
		    pch = strtok (NULL, " ,.-");
		}
*/