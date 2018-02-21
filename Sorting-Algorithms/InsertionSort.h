#pragma once

//Insertion sort - time complexity O(n^2) space complexity O(1), stable
template <typename T>
void insertionSort(T* arr, int size)
{
	int j;
	T save;
	for (int i = 1; i < size; i++)
	{
		j = i - 1;
		save = arr[i];
		while (j >= 0 && arr[j] > save)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = save;
	}
}