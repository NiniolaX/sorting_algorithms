#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
    Bubble Sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of array.
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
   size_t i, j;
   int tmp, swapped = 0;

   if (size < 2 || array == NULL)
      return;
   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size - 1 - i; j++)
      {
         if (array[j] > array[j + 1])
         {
            /* Swap values */
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            swapped++;
            print_array(array, size);
         }
      }
      if (swapped == 0)
         return;
   }
}