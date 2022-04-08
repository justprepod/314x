#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int list_test() {
	TItem* lst;
	TItem* tmp;

	lst = list_create();

	//search(2) must return NULL
	if (NULL != list_search(lst, 2))
		return 1;

	//add(2) must return !NULL
	if (NULL == list_add(lst, 2))
		return 2;

	//search(2) must return !NULL
	if (NULL == (tmp = list_search(lst, 2)))
		return 3;

	list_delete(lst, tmp);

	//search(2) must return NULL
	if (NULL != list_search(lst, 2))
		return 4;

	return 0;
}

int main(int argc, char** argv) {
	int result;

	result = list_test();

	return result;
}