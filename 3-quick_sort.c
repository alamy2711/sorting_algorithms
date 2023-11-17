#include "sort.h"

void swap(int arr[], int index1, int index2);

void quick_sort(int *array, size_t size)
{
	int l = 0, h = size - 1;
	int pivot = array[l];
	int i = l, j = h;

	if (array == NULL || size <= 1)
		return;


	while (i <= j)
	{
		while (i <= j && array[i] <= pivot)
			i++;

		while (i <= j && array[j] > pivot)
			j--;

		if (i < j)
			swap(array, i, j);
		else
			swap(array, l, j);
	}

	print_array(array, size);

	quick_sort(array, j);
	quick_sort(array + j + 1, h - j);
}

void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];

	arr[index1] = arr[index2];
	arr[index2] = temp;
}
