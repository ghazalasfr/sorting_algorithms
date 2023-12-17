
#include "sort.h"

/**
  * selection_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: ...
  */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 1, x = 0, min = 0, max = size - 1;

	if (size < 2)
		return;

	while (i < max)
	{
		if (j == size)
		{
			if (i != min)
			{
				x = array[i];
				array[i] = array[min];
				array[min] = x;
				print_array(array, size);
			}

			++i;
			min = i;
			j = i + 1;
			continue;
		}

		if (array[min] > array[j])
			min = j;

		++j;
	}
}
