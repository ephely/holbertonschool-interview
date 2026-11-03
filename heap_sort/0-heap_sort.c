#include "sort.h"

/**
 * sift_down - Sifts down an element in a binary heap
 * @array: The array of integers representing the heap
 * @size: The total size of the array
 * @heap_size: The size of the active heap
 * @root: The index of the root of the subtree to sift down
 */
void sift_down(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t largest, left, right;
	int tmp;

	while (2 * root + 1 < heap_size)
	{
		left = 2 * root + 1;
		right = 2 * root + 2;
		largest = root;

		if (array[left] > array[largest])
			largest = left;
		if (right < heap_size && array[right] > array[largest])
			largest = right;

		if (largest == root)
			break;

		tmp = array[root];
		array[root] = array[largest];
		array[largest] = tmp;
		print_array(array, size);

		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}