#include "sort.h"

int *merge_sort_helper(int *array, size_t size);
/**
 * merge_sort - Sorts an array of integers in ascending order using Merge
 *      Sort algorithm.
 * @array: Array to be sorted
 * @size: Size of array
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
        size_t i;
        int *sorted_array;

        if (array == NULL || size < 2)
                return;

        sorted_array = merge_sort_helper(array, size);

        /* Copy values in sorted array back to array */
        for (i = 0; i < size; i++)
                array[i] = sorted_array[i];

        free(sorted_array);
}


/**
 * merge_sort_helper - Sorts an array of integers using Merge Sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 * Return: Sorted array
 */
int *merge_sort_helper(int *array, size_t size)
{
        size_t mid = size / 2;
        int *left_half = array, *right_half = array + mid;
        int *new;
        size_t i, j, k;

        /* Allocate memory for new array */
        new = malloc(sizeof(int) * size);
        if (new == NULL)
                return (NULL);

        /* Sort left half */
        left_half = merge_sort_helper(left_half, mid);
        right_half = merge_sort_helper(right_half, size - mid);

        /* Merge sorted halves */
        i = j = k = 0;
        while (i < mid && j < size - mid)
        {
                printf("Merging...\n");
                if (left_half[i] < right_half[j])
                {
                        new[k] = left_half[i];
                        i++;
                }
                else
                {
                        new[k] = right_half[j];
                        j++;
                }
                k++;
        }

        /* Copy remaining elements from each half, if any */
        while (i < mid)
                new[k++] = left_half[i++];
        while (j < size - mid)
                new[k++] = right_half[j++];

        return (new);
}