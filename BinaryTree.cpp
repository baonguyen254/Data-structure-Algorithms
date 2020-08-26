#include<stdio.h>
#include<stdlib.h>
#include <iostream>
struct TreeNode {
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct Binarytree {
	struct TreeNode *root;
};
struct TreeNode *makenode(int value) {
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void treversetree(struct TreeNode *current)
{
	if (current == NULL)
		return;
	treversetree(current->left);
	printf("%3d", current->value);
	treversetree(current->right);

}
void searchtree(struct TreeNode *node, int value)
{
	if (node == NULL)
	{
		printf("\nnot found %d in tree\n", value);
		return;
	}

	if (node->value == value)
	{
		printf("\nfound %d in tree \n", node->value);
		return;
	}
	if (value > node->value)
		searchtree(node->right, value);
	if (value < node->value)
		searchtree(node->left, value);

}
void search2(struct TreeNode *node, int value)
{
	while (node != NULL)
	{
		if (node->value == value)
		{
			printf("found\n");
			return;
		}
		if (value < node->value)
			node = node->left;
		if (value > node->value)
			node = node->right;
	}
	printf("not found\n");
}
void insert(struct Binarytree *tree, int data)
{
	if (tree->root == NULL)
	{
		tree->root = makenode(data);
		return;
	}
	struct TreeNode *node = tree->root;
	while (node != NULL)
	{
		if (node->value == data)
		{
			printf("Duplicate\n");
			return;
		}
		if (data < node->value)
		{
			if (node->left == NULL)
			{
				node->left = makenode(data);
				return;
			}
			node = node->left;
		}
		if (data > node->value)
		{
			if (node->right == NULL)
			{
				node->right = makenode(data);
				return;
			}
			node = node->right;
		}

	}

}
void delete1(struct Binarytree *tree, int value)
{
	struct TreeNode *node = tree->root;
	struct TreeNode *parent = node;
	struct TreeNode *temp = NULL;
	while (node != NULL)
	{
		if (node->value == value)
		{
			printf("\ndeleting node %d\n", value);
			//case 1:node is a leaf
			if (node->left == NULL && node->right == NULL)
			{
				printf("case 1\n");
				if (value < parent->value)
					parent->left = NULL;
				else
					parent->right = NULL;

				//free(parent->value);
				return;
			}
			//case 2
			if (node->right == NULL)
			{
				printf("case 2\n");
				if (value < parent->value)
					parent->left = node->right;
				else
					parent->right = node->right;
				free(node);
				return;
			}
			else if (node->left == NULL)
			{
				printf("case 2\n");
				if (value < parent->value)
					parent->left = node->left;
				else
					parent->right = node->left;
				free(node);
				return;
			}
			// case 3
			if (node->left != NULL && node->right != NULL)
			{
				printf("case 3\n");
				temp = node->left;
				while (temp->right->right != NULL)
					temp = temp->right;
				struct TreeNode *p = temp->right;
				node->value = p->value;
				free(p);
				temp->right = NULL;
				return;

			}
		}
		parent = node;
		if (value < node->value)
			node = node->left;
		if (value > node->value)
			node = node->right;
	}
}
int main()
{
	/*struct TreeNode *root = makenode(5);
	struct TreeNode *left = makenode(3);
	struct TreeNode *right = makenode(10);
	root->left = left;
	root->right = right;
	struct TreeNode *leftleft= makenode(1);
	struct TreeNode *leftright = makenode(4);
	struct TreeNode *rightright = makenode(15);
	struct TreeNode *rightleft = makenode(8);
	left->left = leftleft;
	left->right = leftright;
	right->left = rightleft;
	right->right = rightright;*/


	//searchtree(root, 15);
	//search2(tree, 3);
	struct Binarytree tree;
	tree.root = NULL;
	insert(&tree, 50);
	insert(&tree, 25);
	insert(&tree, 75);
	insert(&tree, 10);
	insert(&tree, 33);
	insert(&tree, 56);
	insert(&tree, 89);
	insert(&tree, 4);
	insert(&tree, 11);
	insert(&tree, 30);
	insert(&tree, 40);
	insert(&tree, 52);
	insert(&tree, 61);
	insert(&tree, 82);
	insert(&tree, 95);
	treversetree(tree.root);
	delete1(&tree, 4);
	treversetree(tree.root);
	delete1(&tree, 10);
	treversetree(tree.root);
	delete1(&tree, 50);
	treversetree(tree.root);
	searchtree(tree.root, 5);

	return 0;
}