#include <stdlib.h>

#include "list.h"


TItem* list_create() {
	TItem* tmp;
	tmp = (TItem*)malloc(sizeof(TItem));
	tmp->next = NULL;

	return tmp;
}

TItem* list_add(TItem* lst, int value) {
	TItem* new_item;
	
	new_item = (TItem*)malloc(sizeof(TItem));
	if (new_item == NULL)
		return NULL;

	new_item->value = value;
	new_item->next = NULL;

	while (lst->next != NULL)
		lst = lst->next;

	lst->next = new_item;

	return new_item;
}

TItem* list_search(TItem* lst, int value) {
	lst = lst->next;

	while (lst != NULL) {
		if (lst->value == value)
			return lst;
		lst = lst->next;
	}

	return NULL;
}

void list_delete(TItem* lst, TItem* item) {
	TItem* prev;

	prev = lst;
	lst = lst->next;

	while (lst != NULL) {
		if (lst == item) {
			prev->next = lst->next;
			free(item);
			return;
		}

		prev = lst;
		lst = lst->next;
	}
}