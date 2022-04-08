#ifndef __TREE__
#define __TREE__

#include <stdlib.h>

typedef struct TNode_{
	int key;
	struct TNode_* left, * right;
} TNode;

//������ �������� �������
TNode* tree_create(key);

//����� ������ � �������, ����� ���� ������ � stdout
void tree_traverse(TNode* root);

//����� ����� � ������
TNode* tree_search(TNode* root, int key);

//���������� ����� � ������
TNode* tree_add(TNode *root, int key);

#endif