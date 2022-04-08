#include <stdio.h>

#include "tree.h"

TNode* tree_create_node(key) {
	TNode* node;

	node = (TNode*)malloc(sizeof(TNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void tree_traverse(TNode* root) {

}

TNode* tree_search(TNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (key == root->key) {
		return root;
	}

	if (key < root->key)
		return tree_search(root->left, key);

	if (key > root->key)
		return tree_search(root->right, key);
}

TNode* tree_add(TNode* root, int key) {

	if (root == NULL) {
		return NULL;
	}

	if (key < root->key) {
		if (root->left == NULL) {
			return root->left = tree_create_node(key);
		}
		else {
			return tree_add(root->left, key);
		}
	}

	if (key > root->key) {
		if (root->right == NULL) {
			return root->right = tree_create_node(key);
		}
		else {
			return tree_add(root->right, key);
		}
	}

	return NULL;
}
