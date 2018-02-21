#pragma once
#include "Swap.h"

//Bubble sort - time complexity O(n^2), space complexity O(1), stable
template <typename T>
void bubbleSort(T* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0 ; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapValues(arr[j], arr[j + 1]);
			}
		}
	}
}