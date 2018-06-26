#ifndef MERGESORT_H
#define MERGESORT_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include"SortTestHelper.h"
#include"InsertionSort.h"
//�Զ����µݹ�Ĺ鲢����
using namespace std;

//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T* aux = new T[r - l + 1];//�����ռ�
							  //T aux[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)//�ж������ĺϷ���
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)//�ж������ĺϷ���
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

//�ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	//if (l >= r)
	//	return;

	// �Ż�������С��ģ����,ʹ�ò�������
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	//�Ż���ǰ������Ͳ���ִ����
	if (arr[mid]>arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1); //˽�е��Ӻ���
}

#endif
