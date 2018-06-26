#ifndef QUICKSORT_OPTIMIZED_H
#define QUICKSORT_OPTIMIZED_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"
#include"QuickSort.h"
#include"QuickSort3Ways.h"
//优化的快速排序
using namespace std;

////对arr[l...n]部分进行partition操作
////返回p，使得arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
//template<typename T>
//int __partition1(T arr[], int l, int r)
//{
//	//优化：随机选取基准点
//	swap(arr[l],arr[rand()%(r-l+1)+l]);
//	T v = arr[l];//基准点
//	//arr[l+1...j]<v;arr[j+1...i-1]>v,i是当前考察的元素
//	int j = l;
//	for (int i = l + 1; i <= r; i++)
//	{
//		if (arr[i] < v)
//		{
//			//swap(arr[++j], arr[i]);
//			swap(arr[j+1], arr[i]);
//			j++;
//		}
//	}
//	swap(arr[l],arr[j]);
//	return j;
//}

template<typename T>//优化partition操作：大量重复数据
int __partition2(T arr[], int l, int r)
{
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];//基准点
				 //arr[l+1...i)<=v;arr(j...r]>=v
	int i = l + 1, j = r;
	while (true)
	{
		while (i <= r&&arr[i] < v)i++;
		while (j >= l + 1 && arr[j] > v)j--;
		if (i > j)break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}

//对arr[l...n]部分进行快速排序
template<typename T>
void __quickSort1(T arr[], int l, int r)
{
	//if (l >= r)
	//	return;

	// 优化1：对于小规模数组,使用插入排序
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int p = __partition2(arr, l, r);
	__quickSort1(arr, l, p - 1);
	__quickSort1(arr, p + 1, r);
}

template<typename T>
void quickSort1(T arr[], int n)
{
	srand(time(NULL));
	//调用私有的函数
	__quickSort1(arr, 0, n - 1);
}

#endif // !QUICKSORT_OPTIMIZED_H

