#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"

using namespace std;

//对arr[l...n]部分进行partition操作
//返回p，使得arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
	T v = arr[l];//基准点
				 //arr[l+1...j]<v;arr[j+1...i-1]>v,i是当前考察的元素
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			//swap(arr[++j], arr[i]);
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

//对arr[l...n]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	//if (l >= r)
	//	return;

	// 优化1：对于小规模数组,使用插入排序
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n)
{
	//调用私有的函数
	__quickSort(arr, 0, n - 1);
}
#endif // !QUICKSORT

