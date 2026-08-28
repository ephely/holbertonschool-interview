#include "binary_trees.h"

/**
 * create_node - create a new node
 * @parent: pointer to parent node
 * @value: integer value to be stored in new node
 *
 * Return: pointer to new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
avl_t *node;

node = malloc(sizeof(avl_t));
if (!node)
return (NULL);

node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;

return (node);
}

/**
 * create_avl_tree - builds an AVL subtree
 * @array: pointer to the first element of the subarray
 * @start: start index of the subarray
 * @end: end index of the subarray
 * @parent: pointer to the parent node
 *
 * Return: pointer to the root of the subtree, or NULL on failure
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
int mid;
avl_t *root;

if (start > end)
return (NULL);

mid = (start + end) / 2;

root = create_node(parent, array[mid]);
if (!root)
return (NULL);

root->left = create_avl_tree(array, start, mid - 1, root);
root->right = create_avl_tree(array, mid + 1, end, root);

return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to convert
 * @size: number of elements in the array
 *
 * Return: pointer to the root of the AVL tree created, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (!array || size == 0)
return (NULL);

return (create_avl_tree(array, 0, (int)size - 1, NULL));
}
