#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<algorithm>

using namespace std;

namespace SortTestHelper
{
	//生成有n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));//随机种子的设置
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}

	//生成一个近乎有序的随机数组
	int* generateNearlyOrderedArray(int n, int swapTimes)
	{
		//生成一个有序数组
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;
		//随机挑选几对元素进行交换
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++)
		{
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

	//打印数组
	template<typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}

	//判断数组排序是不是成功的
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}

	//性能测试
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		//CLOCKS_PER_SEC每秒钟使用时钟周期的个数
		return;
	}

	//复制一个一模一样的整形数组
	int *copyIntArray(int a[], int n)
	{
		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
};


#endif // !1





