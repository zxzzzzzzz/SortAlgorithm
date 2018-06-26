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

//������1��ʼ����n��Ԫ��������뵽һ���ն��У��㷨���Ӷ���O(nlogn)
template<typename T>
void heapSort1(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}

//������1��ʼ��heapify�Ĺ��̣��㷨���Ӷ���O(n)
template<typename T>
void heapSort2(T arr[], int n)//�ȵ�һ���������
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);//������heapify���̣������鹹��ɶ�

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}

//ԭ�ض�����������0��ʼ
//���һ����Ҷ�ӽڵ������(count-1)/2
template<typename T>
void __shiftDown(T arr[], int n, int k)
{
	while (2 * k +1< n)//���Ӳ�Խ��
	{
		int j = 2 * k +1;//�ڴ���ѭ���У�arr[k]��arr[j]����λ��
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


