#include <stddef.h>
#include "slide_line.h"

/**
 * shift_left - Shifts non-zero numbers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void shift_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * merge_left - Merges adjacent identical numbers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size && line[i] != 0; i++)
	{
		if (i + 1 < size && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
}

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_left(int *line, size_t size)
{
	shift_left(line, size);
	merge_left(line, size);
	shift_left(line, size);
}

/**
 * shift_right - Shifts non-zero numbers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void shift_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 1, j = (int)size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * merge_right - Merges adjacent identical numbers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void merge_right(int *line, size_t size)
{
	int i;

	for (i = (int)size - 1; i >= 0 && line[i] != 0; i--)
	{
		if (i - 1 >= 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			i--;
		}
	}
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_right(int *line, size_t size)
{
	shift_right(line, size);
	merge_right(line, size);
	shift_right(line, size);
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}