#ifndef MERGESORTBU_H
#define MERGESORTBU_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"MergeSort.h"

using namespace std;

//自底向上迭代的归并排序.对链表存储的比较好
template<typename T>
void mergeSortBU(T arr[], int n)
{
	//for (int sz = 1; sz <= n; sz += sz)
	//	for (int i = 0; i+sz < n; i += sz + sz)
	//		//对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
	//		__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));

	// Merge Sort Bottom Up 优化
	for (int i = 0; i < n; i += 16)
		insertionSort(arr, i, min(i + 15, n - 1));

	for (int sz = 16; sz <= n; sz += sz)
		for (int i = 0; i < n - sz; i += sz + sz)
			if (arr[i + sz - 1] > arr[i + sz])
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}



#endif // !MERGESORTBU_H

