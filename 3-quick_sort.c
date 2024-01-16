#include "sort.h"

/**
 * partition - sort an array of integers using quick_sort
 *
 * @array: array to sort
 * @min: minimum value
 * @max: max value
 * @size: the size of the array to sort
 * Return: index + 1
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swp, pvot;

	pvot = array[max];
	i = min - 1;
	for (j = min; j < max; j++)
	{
		if (array[j] < pvot)
		{
			i++;
			if (i != j)
			{
				swp = array[i];
				array[i] = array[j];
				array[j] = swp;
				print_array(array, size);
			}
		}
	}
	if (array[max] < array[i + 1])
	{
		swp = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort - sorts an array (a partition recursively)
* @array: array to be sorted
* @min: min index of the partition
* @max: max index of the partition
* @size: array size
*/
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pvot;

	if (min < max)
	{
		pvot = partition(array, min, max, size);
		quicksort(array, min, pvot - 1, size);
		quicksort(array, pvot + 1, max, size);

	}
}

/**
* quick_sort - sorts an array with quick sort algo
* @array: The array to be sorted
* @size: The size of the array to be sorted
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
