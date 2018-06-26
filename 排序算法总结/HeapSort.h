#ifndef HEAPSORT_H
#define HEAPSORT_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<ctime>
#include<cmath>
#include"MaxHeap.h"

using namespace std;

//索引从1开始，将n个元素逐个插入到一个空堆中，算法复杂度是O(nlogn)
template<typename T>
void heapSort1(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}

//索引从1开始，heapify的过程，算法复杂度是O(n)
template<typename T>
void heapSort2(T arr[], int n)//比第一个堆排序快
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);//调用了heapify过程，将数组构造成堆

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}

//原地堆排序，索引从0开始
//最后一个非叶子节点的索引(count-1)/2
template<typename T>
void __shiftDown(T arr[], int n, int k)
{
	while (2 * k +1< n)//左孩子不越界
	{
		int j = 2 * k +1;//在此轮循环中，arr[k]和arr[j]交换位置
		if (j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}
template<typename T>
void heapSort(T arr[], int n)
{
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

#endif // !HEAPSORT1_H


