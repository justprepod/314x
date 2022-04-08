#ifndef __LIST__
#define __LIST__

typedef struct TItem__ {
	int value;
	struct TItem__* next;
} TItem;

TItem* list_create();

/*
return pointer to added element, NULL otherwise
*/
TItem *list_add(TItem*, int);

/*
* returns pointer to first element containing
* searched value, NULL if not found
*/
TItem* list_search(TItem*, int);

/*
* removes element from list
*/
void list_delete(TItem*, TItem*);


#endif