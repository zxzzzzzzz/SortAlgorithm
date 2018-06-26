#ifndef SHELLSORT
#define SHELLSORT

#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"

using namespace std;

template<typename T>
void shellSort(T arr[], int n) {

	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1;
	// 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...

	while (h >= 1) {

		// h-sort the array
		for (int i = h; i < n; i++) {

			// 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
			T e = arr[i];
			int j;
			for (j = i; j >= h && e < arr[j - h]; j -= h)
				arr[j] = arr[j - h];
			arr[j] = e;
		}

		h /= 3;
	}
}

#endif // !SHELLSORT

