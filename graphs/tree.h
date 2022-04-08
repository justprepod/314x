#ifndef __TREE__
#define __TREE__

#include <stdlib.h>

typedef struct TNode_{
	int key;
	struct TNode_* left, * right;
} TNode;

//создаёт корневой элемент
TNode* tree_create(key);

//обход дерева в глубину, вывод всех ключей в stdout
void tree_traverse(TNode* root);

//поиск ключа в дереве
TNode* tree_search(TNode* root, int key);

//добавление ключа в дерево
TNode* tree_add(TNode *root, int key);

#endif