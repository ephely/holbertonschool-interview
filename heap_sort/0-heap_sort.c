#include "sort.h"

/**
 * sift_down - Restores ownership of the max heap by lowering an element
 * @array: array
 * @size: size of heap
 * @root: root
 * @total_size: total size
 */
void sift_down(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		sift_down(array, size, largest, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 *             order using the Heap sort algorithm
 * @array: array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	long int i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		sift_down(array, size, (size_t)i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		sift_down(array, (size_t)i, 0, size);
	}
}
