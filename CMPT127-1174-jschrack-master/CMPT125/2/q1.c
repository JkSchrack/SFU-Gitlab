#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void selection_sort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int temp;
		int smallest = i;
		// smallest = first array
		for(int j = i + 1; j < n; j++)
		{
			if(arr[smallest] > arr[j])
			{
				smallest = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		//swap
	}
}

void insertion_sort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int position = i;
		// Shuffle up all sorted items > arr[i]
		while(position > 0 && arr[position - 1] > temp)
		{
			arr[position] = arr[position - 1];
			position--;
		}
		// Insert the current item
		arr[position] = temp;
	}
}

int main()
{
	int size = 20000;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	// sorted

	for (int i = 0; i < size; i++)
	{
		arr[i] = size - i;
	}
	// reversed

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%size;
	}
	// random

	selection_sort(arr, size);
	//insertion_sort(arr, size);

	printf("DONE");

}