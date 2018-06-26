#ifndef MERGESORTBU_H
#define MERGESORTBU_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"MergeSort.h"

using namespace std;

//�Ե����ϵ����Ĺ鲢����.������洢�ıȽϺ�
template<typename T>
void mergeSortBU(T arr[], int n)
{
	//for (int sz = 1; sz <= n; sz += sz)
	//	for (int i = 0; i+sz < n; i += sz + sz)
	//		//��arr[i...i+sz-1]��arr[i+sz...i+2*sz-1]���й鲢
	//		__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));

	// Merge Sort Bottom Up �Ż�
	for (int i = 0; i < n; i += 16)
		insertionSort(arr, i, min(i + 15, n - 1));

	for (int sz = 16; sz <= n; sz += sz)
		for (int i = 0; i < n - sz; i += sz + sz)
			if (arr[i + sz - 1] > arr[i + sz])
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}



#endif // !MERGESORTBU_H

