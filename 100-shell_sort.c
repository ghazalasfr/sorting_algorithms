
#include "sort.h"

/**
 * shell_sort - ...
 * @array: ...
 * @size: ...
 *
 * Return: ...
*/

void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, k = 1, m = 0;

	if (!array || size < 2)
		return;

	while (k < (int) size / 3)
		k = k * 3 + 1;

	while (k > 0)
	{
		j = k;
		while (j < (int) size)
		{
			m = array[j];
			i = j;

			while (i > k - 1 && array[i - k] >= m)
			{
				array[i] = array[i - k];
				i = i - k;
			}

			array[i] = m;
			j++;
		}
		print_array(array, size);
		k = (k - 1) / 3;
	}
}
