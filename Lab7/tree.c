#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

typedef struct cell {
	Node * value;
	struct cell *next;
} Stack;

Stack *push (Stack *top, Node * data)
{
	Stack *new;
	new = malloc (sizeof(Stack));
	if (new == NULL)
		return NULL;
	new->value = data;
	if (top == NULL)
	{
		new->next = NULL;
		top = new;
	}
	else
	{
		new->next = top;
		top = new;
	}
	return new;

}

Stack *pop (Stack *top)
{
	Node * data;
	Stack *new;
	new = top;
	if (top == NULL)
		return NULL;
	data = new->value;
	top = new->next;
	return top;
}

typedef struct celling {
	Node * value;
	struct celling *next;
} Queue;

int is_queue_empty (Queue *q)
{
	return (q == NULL);
}

Queue *enqueue(Queue *q, Node * data)
{
	Queue *new, *aux;
	new = malloc(sizeof(Queue));
	new->value = data;
	new->next = NULL;
	if (q == NULL)
		return new;
	aux = q;
	while(aux->next)
		aux = aux->next;
	aux->next = new;
	return q;

}

Queue *dequeue(Queue *q)
{
	Queue *new;
	new = q;
	if (q == NULL)
		return NULL;
	q = new->next;
	free(new);
	return q;
}

Node* queue_front (Queue *queue)
{
	return queue->value;
}

void BFS (Node *root)
{
	if (root == NULL)
		return;
	Queue *queue = NULL;
	queue = enqueue (queue, root);
	while (queue != NULL)
	{
		Node *element = queue_front(queue);
		queue = dequeue(queue);
		printf("%d\n", element->data);
		if (element->left != NULL)
			queue = enqueue(queue, element->left);
		if (element->right != NULL)
			queue = enqueue(queue, element->right);
	}
}

void BFS_two (Node *root)
{
	if (root == NULL)
		return;
	Queue *queue = NULL;
	queue = enqueue (queue, root);
	while (queue != NULL)
	{
		Node *element = queue_front(queue);
		queue = dequeue(queue);
		printf("%d\n", element->data);
		if ((element->left != NULL) && (abs(element->left->data - element->data) < element->data/2))
			queue = enqueue(queue, element->left);
		if ((element->right != NULL) && (abs(element->right->data - element->data) < element->data/2))
			queue = enqueue(queue, element->right);
	}
}


void DFS_non_recursive (Node *root)
{
	if (root == NULL)
		return;
	Stack *list = NULL;
	list = push(list, root);
	while (list != NULL)
	{
		Node *tree = list->value;
		list = pop(list);
		if(tree->right != NULL) 
			{
				list = push(list, tree->right);
			//	printf("\n");
			}
		if(tree->left != NULL) 
			{
				list = push(list, tree->left);	
			//	printf("\n");
			}		
		printf("%d\t", tree->data);
	}
}

void DFS_recursive (Node *root)
{
	Stack *list = NULL;
	list = push(list, root);
	Node *tree = list->value;
	list = pop(list);
	if (tree != NULL)
	{
		if (tree->right != NULL)
		{
			DFS_recursive(tree->right);
		}
		if (tree->left != NULL)
		{
			DFS_recursive(tree->left);
		}
		printf("%d ", tree->data);
	}

}

void DFS_node (Node *root, int n)
{
	if ((root == NULL) || (n > height(root)))
		return;
	Stack *list = NULL;
	list = push(list, root);
	int i = 0;
	while ((list != NULL) && (i < n))
	{
		Node *tree = list->value;
		list = pop(list);
		if(tree->right != NULL) 
			list = push(list, tree->right);
		if(tree->left != NULL) 
			list = push(list, tree->left);
		i++;			
		printf("%d ", tree->data);
	}
}


Node *insert_tree (Node *tree, int data)
{
	if (tree == NULL)
	{
		Node * new = malloc(sizeof(Node));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	else
	{
		srand(time(NULL));
		int randomize = rand() % 69;
		if (randomize % 2 == 0)
			tree->left = insert_tree(tree->left, data);
		else
			tree->right = insert_tree(tree->right, data);
	}
	return tree;
}

int greater (Node *tree, int data)
{
	if (tree == NULL)
		return 1;
	if ((tree->data > data) && (greater(tree->right, data) && (greater(tree->left, data))))
		return 1;
	else
		return 0;
}
int lesser (Node *tree, int data)
{
	if (tree == NULL)
		return 1;
	if ((tree->data < data) && (lesser(tree->right, data) && (lesser(tree->left, data))))
		return 1;
	else
		return 0;
}

int check_if_binary (Node * tree)
{
	if (tree == NULL)
		return 1;
	if((greater(tree->right, tree->data)) && (lesser(tree->left, tree->data)) 
		&& (check_if_binary(tree->right)) && (check_if_binary(tree->left)))
		return 1;
	else
		return 0;
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
	//BFS_two(root);
	Node *tree = NULL;
	tree = insert_tree(tree, 4);
	tree = insert_tree(tree, 12);
	tree = insert_tree(tree, 43);
	tree = insert_tree(tree, 5);
	tree = insert_tree(tree, 2);
	tree = insert_tree(tree, 9);
	tree = insert_tree(tree, 3);
	tree = insert_tree(tree, 6);
	preorder(tree);
	printf("\n");
	DFS_non_recursive(tree);
	printf("\n");
	DFS_recursive(tree);
	printf("\n");
	DFS_node(root, 4);
	printf("\n");
	if (check_if_binary(tree))
		printf("yiiissss\n");
	else
		printf("meh nope\n");
	return 0;
}
