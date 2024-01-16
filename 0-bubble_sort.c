#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int bubbly;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = size - 1; i > 0; i--)
	{
		bubbly = 0;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);

				bubbly = 1;
			}
		}
		if (!bubbly)
			break;
	}
}
