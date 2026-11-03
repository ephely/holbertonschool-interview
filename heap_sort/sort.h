#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void print_array(const int *array, size_t size);
void sift_down(int *array, size_t size, size_t heap_size, size_t root);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
