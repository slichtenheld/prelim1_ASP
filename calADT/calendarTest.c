#include <stdio.h>
#include "calendarADT.h"


int main(int argc, char *argv[]) {
	
	Calendar_T cal = Calendar_new();
	printf("empty: %s\n", Calendar_empty(cal) ? "true" : "false");

	struct CalendarItem_t calItem = {"Meeting   ","01/12/2017","15:30","NEB202    "};
	struct CalendarItem_t calItem2 = {"Meeting   ","01/12/2017","15:30","NEB202    "};


	Calendar_add(cal, &calItem);
	Calendar_add(cal, &calItem2);
	printf("empty: %s\n", Calendar_empty(cal) ? "true" : "false");
	Calendar_print(cal);

	printf("equal: %s\n", cmp_calItem(calItem,calItem2) ? "true" : "false");


	}