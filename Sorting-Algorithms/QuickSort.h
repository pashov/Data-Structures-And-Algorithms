#pragma once
#include "Swap.h"

//Quick sort - time complexity O(n log(n)), space complexity O(log(n)), unstable
template <typename T>
int partition(T* arr, int left, int right)
{
	T pivot = arr[right];
	int indexSmaller = left - 1;
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
		{
			indexSmaller++;
			swap(arr[i], arr[indexSmaller]);
		}
	}
	swap(arr[indexSmaller + 1], arr[right]);
	return indexSmaller + 1;
}

template <typename T>
void quickSort(T* arr, int left, int right)
{
	if (left < right)
	{
		int partitionIndex = partition(arr, left, right);
		quickSort(arr, left, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, right);
	}
}