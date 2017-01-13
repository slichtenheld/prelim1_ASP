#include "calendarADT.h"
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h> // for string compare

#define CAPACITY 1024



struct Calendar_t {
	int count;
	CalendarItem_T data[CAPACITY];
};

Calendar_T Calendar_new(void){
	
	Calendar_T cal; 
	
	printf("Size of Calendar: %lu\n", sizeof *cal);
	cal = malloc(sizeof *cal);

	if (cal==NULL) perror("NEW, calendar is null");
	cal->count = 0; //array is empty
	return cal;
}

int Calendar_empty(Calendar_T cal){
	if (cal==NULL) perror("EMPTY, calendar is null");
	return (cal->count == 0);
}

int Calendar_full(Calendar_T cal){
	if (cal==NULL) perror("FULL, calendar is null");
	return (cal->count == CAPACITY-1);
}

void Calendar_add(Calendar_T cal, CalendarItem_T item){
	if (cal==NULL) {
		perror("ADD, calendar is null");
		return;
	}
	if (cal->count < CAPACITY){
		cal->data[cal->count++] = item;
	}
	else perror("calendar is full");
}

void Calendar_del(Calendar_T cal, CalendarItem_T item){
	if (cal==NULL) perror("DEL, calendar is null");

	// check if anythings are equal
	// shift everything up starting at match
}

void Calendar_mod(Calendar_T cal, CalendarItem_T item){
	if (cal==NULL) perror("MOD, calendar is null");
	// check if anything is equal
	// replace time and location
	//print out "date:location"
}

void Calendar_print(Calendar_T cal){
	if (cal==NULL) perror("MOD, calendar is null");
	for (int i = 0; i < cal->count; i++){
		print_calItem(*(cal->data[i]));
	}
}


/****private methods****/
void print_calItem(struct CalendarItem_t c){
	printf("Title: %s\nDate: %s\nTime: %s\nlocation: %s\n\n", c.title, c.date, c.time, c.location);
}

int cmp_calItem(struct CalendarItem_t c, struct CalendarItem_t d){
	if (strcmp(c.title,d.title) != 0 ||
		strcmp(c.date,d.date)   !=0) {
		return 0;
	}
	else return 1;
}
