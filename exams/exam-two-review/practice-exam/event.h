#ifndef EVENT_H
#define EVENT_H

typedef struct {
    char title[100];
    char date[10]; // YYYY-MM-DD
    char time[6]; // HH:MM
    char location[100];
} event;

typedef struct attendee {
    char name[100];
    char contact[50];
    struct attendee *next;
} attendee;

// Practice Problems:

// 1. Create and initialize an `event`.
// 2. Write a function to add an `attendee` to an event.
// 3. Implement a function to remove an attendee by name.
// 4. Create a function to print all attendees of an event.
// 5. Develop a function to find an event by date.

void createEvent(event *e, char *title, char *date, char *time, char *location);
void addAttendee(event *e, attendee **head, char *name, char *contact);
void removeAttendee(attendee **head, char *name);
void printAttendees(const attendee *head);
event *findEventByDate(const event *events, int n, char *date);

#endif // EVENT_H
