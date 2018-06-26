#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>

void bubbleSort(T arr[], int n)
{
	int flag = true;
	for (int i = 0; i < n - 1 && flag; i++)//若flag为false，则提前退出循环
	{
		flag = false;
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true; //如果有数据交换，则flag为true
			}
		}
	}
}


#endif //OPTIONAL_02_SHELL_SORT_BUBBLESORT_H
