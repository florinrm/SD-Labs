#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
} Node;

int maximum (int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

Node *insert (Node *tree, int data)
{
	if (tree == NULL)
	{
		Node * new = malloc(sizeof(Node));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	else if (tree->data >= data)
		tree->left = insert(tree->left, data);
	else
		tree->right = insert(tree->right, data);
	return tree;
}

int search (Node *tree, int data)
{
	if (tree == NULL)
		return 0;
	else if (tree->data == data)
		return 1;
	else if (tree->data > data)
		return search(tree->left, data);
	else
		return search(tree->right, data);
}


Node *tree_min (Node *tree)
{
	if (tree == NULL)
		return NULL;
	Node *new = tree;
	while (new->left != NULL)
		new = new->left;
	return new;
}

int max (Node *tree)
{
	if (tree == NULL)
		return -1;
	Node *new = tree;
	while (new->right != NULL)
		new = new->right;
	return new->data;
}

int height (Node *tree)
{
	if (tree == NULL)
		return 0;
	return maximum(height(tree->left), height(tree->right)) + 1;
}

void preorder(Node *tree)
{
	if (tree == NULL)
		return;
	printf("%d ", tree->data);
	preorder(tree->left);
	preorder(tree->right);
}

int count (Node *tree)
{
	int c = 1;
	if (tree == NULL)
		return 0;
	c = c + count(tree->left);
	c = c + count(tree->right);
	return c;
}

void inorder(Node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	printf("%d ", tree->data);
	inorder(tree->right);
}

void postorder(Node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	printf("%d ", tree->data);
}

Node *delete (Node *tree, int data)
{
	if (tree == NULL)
		return NULL;
	if (tree->data == data)
	{
		if ((tree->right == NULL) && (tree->left == NULL))
		{
			tree = NULL;
		}		
		else if (tree->right == NULL)
			tree = tree->left;
		else if (tree->left == NULL)
			tree = tree->right;
		else if ((tree->right != NULL) && (tree->left != NULL))
		{
			Node *aux = tree_min(tree->right);
			tree->data = aux->data;
			tree->right = delete(tree->right, aux->data);
		}
	}
	else if (tree->data > data)
		tree->left = delete(tree->left, data);
	else if (tree->data < data)
		tree->right = delete(tree->right, data);
	return tree;
}


int main ()
{
	Node *root = NULL;
	root = insert(root, 8); 
	root = insert(root, 3); 
	root = insert(root, 10);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 14);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 13); 
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n"); 
	printf("%d\n", search(root, 6));
	printf("%d\n", search(root, 420)); 
	printf("\n");
	root = delete(root, 13);
	root = delete(root, 8);
	root = delete(root, 6);
	inorder(root);
	printf("\n");
	printf("The number of elements is %d\n", count(root));
	printf("The maximum value is %d\n", max(root));
	printf("The height is %d\n", height(root));
	return 0;
}