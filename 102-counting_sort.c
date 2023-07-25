#include "sort.h"
#include <stdio.h>
/**
 * _bigest -  Give me the largest number in a array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *array, size_t size)
{
	size_t x;
	int y = 0;

	for (x = 0; x < size; x++)
	{
		if (y < array[x])
			y = array[x];
	}

	return (y);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int x;

	ptr = malloc((size) * sizeof(int));

	for (x = 0; x < size; x++)
		ptr[x] = 0;

	return (ptr);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t x, j;
	int k = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (size < 2)
		return;
	/*Know the largest number in the array*/
	k = _bigest(array, size);
	/*Make the help array*/
	ptr = _memset(k + 1);
	if (!ptr)
		return;
	/*Set the values for sorting*/
	for (x = 0; x < size; x++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[x])
				ptr[j] += 1;
	/*Modificate the count in the array*/
	for (x = 0; (int)x < k; x++)
		ptr[x + 1] = ptr[x] + ptr[x + 1];
	print_array(ptr, k + 1);
	/*Create the sort array*/
	sort_ar = malloc(size * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}

	for (x = 0; x < size; x++)
	{
		sort_ar[ptr[array[x]] - 1] = array[x];
		ptr[array[x]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sort_ar[j];

	free(sort_ar);
	free(ptr);
}
