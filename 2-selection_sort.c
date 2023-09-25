#include "sort.h"

int lowest_num(int *array, size_t size, size_t idx);
/**
 * selection_sort - Sorts an array of integers in ascending order using
 *	Selection Sort algorithm.
 * @array: Array of integers to be sorted
 * @size: Size of array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, lowest_num_idx;
	int tmp;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		lowest_num_idx = lowest_num(array, size, i);
		tmp = array[i];
		array[i] = array[lowest_num_idx];
		array[lowest_num_idx] = tmp;
		print_array(array, size);
	}
}

/**
 * lowest_num - Returns the index of the lowest number in an array of integers.
 * @array: Array of integers
 * @size: Size of array
 * @idx: Index to begin search from
 * Return: Index of lowest number
 */
int lowest_num(int *array, size_t size, size_t idx)
{
	size_t i;
	int lowest_val = INT_MAX, lowest_idx;

	for (i = idx; i < size; i++)
	{
		if (array[i] < lowest_val)
		{
			lowest_val = array[i];
			lowest_idx = i;
		}
	}

	return (lowest_idx);
}
