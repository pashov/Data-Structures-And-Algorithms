#pragma once

//Merge sort - time complexity O(n log(n)), space complexity O(n), stable
template <typename T>
void merge(T* arr, int leftInd, int midInd, int rightInd)
{
	int i, j, start = leftInd;
	int sizeFirst = midInd - leftInd + 1;
	int sizeSecond = rightInd - midInd;
	T* first = new T[sizeFirst];
	T* second = new T[sizeSecond];

	for (i = 0; i < sizeFirst; i++)
	{
		first[i] = arr[leftInd + i];
	}

	for (j = 0; j < sizeSecond; j++)
	{
		second[j] = arr[midInd + 1 + j];
	}

	i = j = 0;
	while (i < sizeFirst  && j < sizeSecond)
	{
		if (first[i] <= second[j])
		{
			arr[start++] = first[i++];
		}
		else
		{
			arr[start++] = second[j++];
		}
	}

	while (i < sizeFirst)
	{
		arr[start++] = first[i++];
	}

	while (j < sizeSecond)
	{
		arr[start++] = second[j++];
	}
	delete[] first;
	delete[] second;
}

template <typename T>
void mergeSort(T* arr, int leftInd, int rightInd)
{
	if (leftInd < rightInd)
	{
		int midInd = (leftInd + rightInd) / 2;
		mergeSort(arr, leftInd, midInd);
		mergeSort(arr, midInd + 1, rightInd);

		merge(arr, leftInd, midInd, rightInd);
	}
}