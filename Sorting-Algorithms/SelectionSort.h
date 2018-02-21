#pragma once
#include "Swap.h"

//Selection sort - time complexity O(n^2), space complexity O(1), unstable 
template <typename T>
void selectionSort(T* arr, int size)
{
	int minInd;
	for (int i = 0; i < size - 1; i++)
	{
		minInd = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minInd] > arr[j])
			{
				minInd = j;
			}
		}
		swapValues(arr[i], arr[minInd]);
	}
}