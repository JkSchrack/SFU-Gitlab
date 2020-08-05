#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include <stdio.h>

void mergesortA(int arr[], int len)
{
	if (len > 1)
	{
		int times = 0;
		double size = len;
		while (size > 1)
		{
			size = size / 2;
			times += 1;
		}
		// Number of times to divide

		int repeats;
		int space = 1;

		for (int i = 1; i < times; i++) 
		{
			space = space * 2; // compare 2 elements, then 4 then all 8
			repeats = len / space; // 4 groups of 2, then 2 groups of 4

			printf("%i\n", repeats);
			printf("%i\n", space);

			for(int j = 1; j <= repeats; j++)
			{
				int start = (j - 1) * space;
				int end = j * space - 1;
				int mid = (end - start + 1) / 2;
				mergeA(arr, start, mid, end);
				// Index: 0-1, 2-3, 4-5, 6-7 then 0-3, 4-7 then 0-8
			}
		}
		//printf("%i\n", times);
	}
}
 

int* MergeTwoArray((int arr[], int brr[], int LowA, int HighA, int LowB, int HighB)
{
	mergesort(arr[], LowA, HighA);
	mergesort(brr[], LowB, HighB);
	// sort first two arrays individually

	int sizeA = sizeof(arr) / sizeof(int);
	int sizeB = sizeof(brr) / sizeof(int);
		
	int sizeC = sizeA + sizeB;
	int *crr = malloc(sizeC * sizeof(int));
	if (crr == NULL)
	{
		return NULL;
	}
	// create new array

	for (int i = 0; i < sizeA; i++)
	{
		crr[i] = arr[i];
	}

	for (int i = 0; i < sizeB; i++)
	{
		crr[sizeA + i] = brr[i];
	}
	//fill new array with sorted other arrays

	int LowC = LowA + LowB;
	int HighC = HighA + HighB;

	mergesort(crr, LowC, HighC);

	return crr;
}

int main()
{
	int arr[8] = {8, 6, 4, 2, 10, 12, 14, 16};
	int brr[8] = {7, 5, 3, 1, 9, 11, 13, 15};
	int len = 8;

	mergesortA(arr, len);

	for (int i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			printf("%i\n", arr[i]);
		}
		else
		{
			printf("%i", arr[i]);	
		}
	}
}