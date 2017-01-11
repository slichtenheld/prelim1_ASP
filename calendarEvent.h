#ifndef CALENDER_EVENT_H_
#define CALENDER_EVENT_H_

struct calendarEvent_t {
	char type;
	char title[11];
	char date[11];
	char time[6];
	char location[11];
};

#endif