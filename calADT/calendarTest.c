#include <stdio.h>
#include "calendarADT.h"


int main(int argc, char *argv[]) {
	
	Calendar_T cal = Calendar_new();
	printf("empty: %s\n", Calendar_empty(cal) ? "true" : "false");

	struct CalendarItem_t calItem = {"Meeting   ","01/12/2017","15:30","NEB202    "};
	struct CalendarItem_t calItem2 = {"Meeting2   ","01/12/2017","17:00","LAR313    "};


	Calendar_add(cal, &calItem);
	Calendar_add(cal, &calItem2);
	printf("empty: %s\n", Calendar_empty(cal) ? "true" : "false");
	printf("_____________________________________\n\n");
	Calendar_print(cal);

	printf("equal: %s\n", cmp_calItem(calItem,calItem2) ? "true" : "false");

	printf("_____________________________________\n\n");

	Calendar_mod(cal, &calItem2);
		Calendar_print(cal);


	}