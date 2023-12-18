#include "sort.h"

/**
  * quick_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
  * quick_sort_rec - ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int k = 0;

	if (lower < higher)
	{
		k = partition(array, lower, higher, size);
		quick_sort_rec(array, lower, k - 1, size);
		quick_sort_rec(array, k + 1, higher, size);
	}
}

/**
  * partition - ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
int partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, p = 0, a = 0;

	p = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < p)
		{
			a = array[i];
			array[i] = array[j];
			array[j] = a;

			if (a != array[i])
				print_array(array, size);

			++i;
		}
	}

	a = array[i];
	array[i] = array[higher];
	array[higher] = a;

	if (a != array[i])
		print_array(array, size);

	return (i);
}
