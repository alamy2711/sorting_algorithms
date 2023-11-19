#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * hell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: Number of integers
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap = 1;
	int tmp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = gap / 3)
	{
		for (i = 0; i < size; i++)
		{
			j = i;
			tmp = array[i];
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
