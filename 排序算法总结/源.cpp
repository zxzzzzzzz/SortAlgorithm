#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<ctime>
#include<cmath>
#include"BubbleSort.h"
#include"InsertionSort.h"
#include"MergeSort.h"
#include"MergeSortBU.h"
#include"QuickSort.h"
#include"QuickSort_Optimized.h"
#include"QuickSort3Ways.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
#include"MaxHeap.h"
#include"HeapSort.h"
#include"ShellSort.h"

using namespace std;

int main()
{
	int n = 10000;
	cout << "Test for Random Array,size =" << n << ", random range [0," << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	int* arr4 = SortTestHelper::copyIntArray(arr1, n);
	int* arr5 = SortTestHelper::copyIntArray(arr1, n);
	int* arr6 = SortTestHelper::copyIntArray(arr1, n);
	int* arr7 = SortTestHelper::copyIntArray(arr1, n);
	int* arr8 = SortTestHelper::copyIntArray(arr1, n);
	int* arr9 = SortTestHelper::copyIntArray(arr1, n);
	int* arr10 = SortTestHelper::copyIntArray(arr1, n);
	int* arr11 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);
	SortTestHelper::testSort("自底向上的Merge Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("优化的自顶向下递归的Merge Sort", mergeSort, arr6, n);
	SortTestHelper::testSort("优化的Quick Sort", quickSort1, arr7, n);
	SortTestHelper::testSort("3路Quick Sort", quickSort3Ways, arr8, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1, arr9, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr10, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr11, n);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;
	delete[] arr11;


	cout << endl;
	system("pause");
	return 0;
}