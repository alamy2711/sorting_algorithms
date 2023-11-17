#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, current_min, temp;

    for (i = 0; i < size - 1; i++)
    {
        current_min = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[current_min])
            {
                current_min = j;
            }
        }

        temp = array[i];
        array[i] = array[current_min];
        array[current_min] = temp;

    }
}
