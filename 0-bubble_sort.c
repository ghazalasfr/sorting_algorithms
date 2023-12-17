#include "sort.h"

/**
  * bubble_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: none
  */
void bubble_sort(int *array, size_t size)
{
	int i = 0, y = 0, nbremax = 0, x = 1;

	if (!array || size < 2)
		return;

	nbremax = size - 1;

	for (; i < nbremax; ++i)
	{
		if (array[i] > array[i + 1])
		{
			y = array[i];
			array[i] = array[i + 1];
			array[i + 1] = y;
			x = 1;
			print_array(array, size);
		}

		if (x == 1 && i == nbremax - 1)
			i = -1, x = 0, --nbremax;
	}
}
