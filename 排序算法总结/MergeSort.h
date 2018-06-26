#ifndef MERGESORT_H
#define MERGESORT_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"SortTestHelper.h"
#include"InsertionSort.h"
//自顶向下递归的归并排序
using namespace std;

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T* aux = new T[r - l + 1];//辅助空间
							  //T aux[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)//判断索引的合法性
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)//判断索引的合法性
		{
			arr[k] = aux[i - l];
			i++;
		}

		else if (aux[i - l] < aux[j - l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else
		{
			arr[k] = aux[j - l];
			j++;
		}
	}
	//delete[] aux;
}

//递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	//if (l >= r)
	//	return;

	// 优化：对于小规模数组,使用插入排序
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	//优化：前后有序就不用执行了
	if (arr[mid]>arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1); //私有的子函数
}

#endif
