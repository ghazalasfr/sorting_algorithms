
#include "sort.h"

/**
 * counting_sort - ...
 * @array: ...
 * @size: ...
 * Return: ...
 */

void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k;
	int *x, *y;

	if (size < 2)
		return;
	k = 0;
	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	j = k + 1;
	x = malloc(sizeof(int) * j);
	if (x == NULL)
		return;
	for (i = 0; i < j; i++)
		x[i] = 0;
	y = malloc(sizeof(int) * size);
	if (y == NULL)
	{
		free(x);
		return;
	}
	for (i = 0; i < size; i++)
		x[array[i]]++;

	for (i = 1; i < j; i++)
		x[i] = x[i] + x[i - 1];
	print_array(x, j);
	for (i = 0; i < size; i++)
		y[--x[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = y[i];

	free(x);
	free(y);
}
