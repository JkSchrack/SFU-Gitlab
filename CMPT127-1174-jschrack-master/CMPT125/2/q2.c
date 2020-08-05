#include <stdio.h>

void swap(int arr[], int i, int j) 
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void ssort_down(int arr[], int n) 
{
	for(int i = n - 1; i >= 0; i--)
	{
		int temp;
		int biggest = i;
		// smallest = first array
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[biggest] < arr[j])
			{
				biggest = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[biggest];
		arr[biggest] = temp;
		//swap
	}
}

int max(int arr[], int start, int end) 
{
	if(end == start)
	{
		return start;
	}
	else
	{
		int position = max(arr, start, end - 1);
		if (arr[position] > arr[end])
		{
			return position;
		}
		else if (arr[position] <= arr[end]) 
		{
			return end;
		}
	}

}

void rec_ssort(int arr[], int n)
{
	if (n > 0)
	{
		int biggest = max(arr, 0, n); // 2c
		swap(arr, n, biggest); // 2a
		rec_ssort(arr, n - 1);
	}
}


int main()
{
	int arr[5] = {3, 2, 4, 5, 1};
	int n = 5;
	int start = 0;
	int end = 4;

	//int result = max(arr, start, end);
	//ssort_down(arr, 5);

	//printf("%i\n", max(arr, start, end));

	rec_ssort(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("%i\n", arr[i]);
	}
}