#include "sort.h"

/**
  * quick_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: None!
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_rec(array, 0, size - 1, size);
}

/**
  * quick_rec - ...
  * @array: ...
  * @l: ...
  * @h: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_rec(int *array, int l, int h, size_t size)
{
	int k = 0;

	if (l < h)
	{
		k = partition(array, l, h, size);
		quick_rec(array, l, k - 1, size);
		quick_rec(array, k + 1, h, size);
	}
}

/**
  * partition - ...
  * @array: ...
  * @l: ...
  * @h: ...
  * @size: ...
  *
  * Return: Nothing!
  */
int partition(int *array, int l, int h, size_t size)
{
	int i = 0, j = 0, p = 0, z = 0;

	p = array[h];
	i = l;

	for (j = l; j < h; ++j)
	{
		if (array[j] < p)
		{
			z = array[i];
			array[i] = array[j];
			array[j] = z;

			if (z != array[i])
				print_array(array, size);

			++i;
		}
	}

	z = array[i];
	array[i] = array[h];
	array[h] = z;

	if (z != array[i])
		print_array(array, size);

	return (i);
}
