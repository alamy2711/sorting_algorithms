#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * hell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: Number of integers
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, gap = 1;
	int tmp, j;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = gap / 3)
	{
		for (i = 0; i < size; i++)
		{
			j = i;
			while (array[j] > array[j + gap] && j >= 0 && j + gap < size)
			{
				tmp = array[j + gap];
				array[j + gap] = array[j];
				array[j] = tmp;
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
