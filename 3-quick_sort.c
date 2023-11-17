#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @array: The array containing the elements
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
		}
	}

	swap(array, i + 1, high);
	return i + 1;
}

/**
 * quick_sort_lomuto - Sorts an array of integers in ascending order
 *                     using the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */

void quick_sort_lomuto(int *array, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high);

		print_array(array + low, high - low + 1);

		quick_sort_lomuto(array, low, partition_index - 1);
		quick_sort_lomuto(array, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_lomuto(array, 0, size - 1);
}
