#ifndef QUICKSORT3WAYS_H
#define QUICKSORT3WAYS_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"InsertionSort.h"
#include"MergeSort.h"
#include"SortTestHelper.h"
#include"QuickSort.h"
//3路快速排序：大量重复元素
using namespace std;

//3路快速排序处理 arr[l...r]
//将arr[l,,,r]分为 <v; ==v; >v三部分
//之后递归对<v;>v两部分继续进行3路快速排序
template<typename T>
void __quickSort3Ways(T arr[], int l, int r)
{
	if (r - l <= 15) 
	{
		insertionSort(arr, l, r);
		return;
	}

	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];//基准点

	int lt = l;//arr[l+1...lt]<v
	int gt = r + 1;//arr[gt+1...r]>v
	int i = l + 1;//arr[lt+1...i]==v
	while (i < gt)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v)
		{
			swap(arr[i], arr[gt-1]);
			gt--;
		}
		else//arr[i]==v
		{
			i++;
		}
	}
	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n)
{
	srand(time(NULL));//设置随机种子
	//调用私有的函数
	__quickSort3Ways(arr, 0, n - 1);
}


#endif // !3_QUICKSORT_H

