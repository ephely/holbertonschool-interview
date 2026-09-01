#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, or 0 if tree is NULL
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_parent - Finds the parent node for the new node insertion position
 * @root: Pointer to the root node of the heap
 * @idx: Index of the new node to insert (1-based)
 * Return: Pointer to the parent node
 */
static heap_t *get_parent(heap_t *root, size_t idx)
{
	size_t parent_idx = idx / 2;
	size_t mask = 1;

	while (mask <= parent_idx / 2)
		mask <<= 1;

	mask >>= 1;
	while (mask > 0)
	{
		if (parent_idx & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}

	return (root);
}

/**
 * sift_up - Restores the Max Heap property by swapping values upwards
 * @node: Pointer to the newly inserted node
 * Return: Pointer to the node storing the inserted value after heapifying
 */
static heap_t *sift_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = get_parent(*root, size + 1);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if ((size + 1) % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (sift_up(new_node));
}


