#include "tree.h"

int test() {
	TNode* root = NULL;

	//must return NULL
	if (NULL != tree_search(root, 42)) {
		return 1;
	}

	//must return NULL
	if (NULL != tree_search(root, 36)) {
		return 2;
	}

	//must return NOT NULL
	root = tree_create_node(42);
	if (NULL == root) {
		return 3;
	}

	//must return NOT NULL
	if (NULL == tree_search(root, 42)) {
		return 4;
	}

	//must return NOT NULL
	if (NULL == tree_add(root, 36)) {
		return 5;
	}

	//must return NOT NULL
	if (NULL == tree_search(root, 36)) {
		return 6;
	}

	return 0;
}

int main(int argc, char** argv) {
	return test();
}