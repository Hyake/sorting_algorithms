#include "sort.h"

/**
 * _swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value
 * @j: second value
 *
 * Return: No Return
 */
void _swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int x, y, pivot = array[max];

	for (x = min, y = max; 1; x++, y--)
	{
		while (array[x] < pivot)
			x++;

		while (array[y] > pivot)
			y--;

		if (x >= y)
			return (x);
		_swap(array, x, y);
		print_array(array, size);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int w;

	if (min < max)
	{
		w = partition(array, min, max, size);
		quicksort(array, min, w - 1, size);
		quicksort(array, w, max, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
