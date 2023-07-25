#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @buff: malloc buffer
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int x, b, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (x = 0; x < size; x++)
	{
		num = array[x];
		for (b = 0; b < lsd; b++)
			if (b > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[x];
		carr[num] += 1;
	}

	for (x = 0, b = 0; x < csize; x++)
	{
		while (carr[x] > 0)
		{
			array[b] = buff[x][carr2[x]];
			carr2[x] += 1, carr[x] -= 1;
			b++;
		}
	}

	print_array(array, size);
}
/**
 * csort - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int x, b, num, csize = 10, **buff;

	for (x = 0; x < size; x++)
	{
		num = array[x];
		for (b = 0; b < lsd; b++)
			if (b > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (x = 0; x < csize; x++)
		if (carr[x] != 0)
			buff[x] = malloc(sizeof(int) * carr[x]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (x = 0; x < csize; x++)
		if (carr[x] > 0)
			free(buff[x]);
	free(buff);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
