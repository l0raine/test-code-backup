#include "stdafx.h"

#include <iostream> 
#include <ctime> 
const int SIZE = 100; 
const int MAX = 1000; 
using namespace std; 

//交换数据 
void Swap(int &a, int &b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 

// 冒泡排序 从最后一个数字 逐一从后往前从小到大交换
void BubbleSort(int *arr, int size) 
{ 
	int i = 0, j = 0; 
	//依次将最大的数字逐轮放于(数组0-i)的最后面 
	for(i=0; i<size-1; i++) 
	{
		//将最大的数字放于数组i-(size-1)的最后面  
		for(j=size-1; j>i; j--) 
		{
			if(arr[j] < arr[j-1]) 
				Swap(arr[j], arr[j-1]); 
		}
	}
} 

//选择排序 类似于冒泡排序 但是只是通过寻找下标找最小值 效率比冒泡排序高
void SelectionSort(int *arr, int size) 
{ 
	int i = 0, j = 0, min = 0; 
	//找出从a[i]到a[size-1]的最小元素的位置 
	for(i=0; i<size-1; i++) 
	{ 
		min = i; 
		for(j=i+1; j<size; j++) 
			if(arr[min] > arr[j]) 
				min = j; 
		//将a[i]与a[min]的数据交换 
		Swap(arr[i], arr[min]); 
	} 
} 

//插入排序 
void InsertSort(int *arr, int size) 
{ 
	int fOut = 0, loc = 0, temp = 0; 
	for(fOut=1; fOut<size; fOut++) 
	{
		if(arr[fOut] < arr[fOut-1]) 
		{ 
			temp = arr[fOut]; 
			loc = fOut; 
			do 
			{ 
				arr[loc] = arr[loc-1]; 
				loc--; 
			}while(loc>0 && arr[loc-1]>temp); 
			arr[loc] = temp; 
		} 
	}

} 

//快速排序 
int Partition(int *arr, int first, int last) 
{ 
	int i, small, x; 
	//为了减少最差情况的出现频率而作的一种优化 
	swap(arr[first], arr[ (first+last)/2 ]); 
	x = arr[first]; 
	small = first; 
	for(i=first+1;i<=last;i++) 
		if(arr[i] < x) 
		{ 
			small++; 
			swap(arr[small], arr[i]); 
		} 
		swap(arr[first], arr[small]); 
		return small; 
} 

void RecQuick(int *arr, int first, int last) 
{ 
	int pivotLoc; 
	if(first < last) 
	{ 
		pivotLoc = Partition(arr, first, last); 
		RecQuick(arr, first, pivotLoc-1); 
		RecQuick(arr, pivotLoc+1, last); 
	} 
} 

//快速排序
void QuickSort(int *arr, int size) 
{ 
	RecQuick(arr, 0, size-1); 
} 

//计数排序 
void CountSort(int *arr, int size) 
{ 
	int temp[MAX] = {0}; 
	int i, j; 
	for(i=0;i<size;i++) 
		temp[arr[i]]++; 
	j = 0; 
	for(i=0;i<MAX;i++) 
	{ 
		while(0 != temp[i]) 
		{ 
			arr[j] = i; 
			temp[i]--; 
			j++; 
		} 
	} 
} 

//归并排序 
void Merge(int *arr, int start, int mid, int end) 
{ 
	int temp1[SIZE], temp2[SIZE]; 
	int n1, n2; 
	int i, j, k; 
	n1 = mid - start + 1; 
	n2 = end - mid; 
	//拷贝前半部分数组 
	for(i=0;i<n1;i++) 
		temp1[i] = arr[start + i]; 
	//拷贝后半部分数组 
	for(i=0;i<n2;i++) 
		temp2[i] = arr[mid + i + 1]; 
	//把后面的元素设置的很大 
	temp1[n1] = temp2[n2] = INT_MAX; 
	i = j = 0; 
	//  逐个扫描两部分数组然后放到相应的位置去 
	for(k=start;k<=end;k++) 
	{ 
		if(temp1[i] <= temp2[j]) 
		{ 
			arr[k] = temp1[i]; 
			i++; 
		} 
		else 
		{ 
			arr[k] = temp2[j]; 
			j++; 
		} 
	} 
} 

void RecMerge(int *arr, int start, int end) 
{ 
	int i; 
	if(start < end) 
	{ 
		i = (start + end) / 2; 
		RecMerge(arr, start, i); 
		RecMerge(arr, i+1, end); 
		Merge(arr, start, i, end); 
	} 
} 

//归并排序
void MergeSort(int *arr, int size) 
{ 
	RecMerge(arr, 0, size-1); 
} 

//堆排序 
void Heapify(int *arr, int low, int high) 
{ 
	int large; 
	int temp = arr[low]; 
	large = 2 * low + 1; 
	while(large <= high) 
	{ 
		if(large<high && arr[large]<arr[large+1]) 
			large = large + 1; 
		if(temp > arr[large]) 
			break; 
		else 
		{ 
			arr[low] = arr[large]; 
			low = large; 
			large = 2 * low + 1; 
		} 
	} 
	arr[low] = temp; 
} 

void BuildHeap(int *arr, int size) 
{ 
	int i; 
	for(i=size/2-1;i>=0;i--) 
		Heapify(arr, i, size-1); 
} 

//堆排序
void HeapSort(int *arr, int size) 
{ 
	int i;                  //lastOfOrder 
	BuildHeap(arr, size); 
	for(i=size-1;i>=0;i--) 
	{ 
		swap(arr[0], arr[i]); 
		Heapify(arr, 0, i-1); 
	} 
} 
//希尔排序 
void ShellSort(int *arr, int size) 
{ 
	int i, j, k, temp; 
	//i 为增量 
	for(i=size/2;i>0;i/=2) 
	{ 
		for(j=i;j<size;j+=i) 
		{ 
			temp = arr[j]; 
			k = j; 
			while(k-i>=0 && temp<arr[k-i]) 
			{ 
				arr[k] = arr[k-i]; 
				k -= i; 
			} 
			arr[k] = temp; 
		} 
	} 
} 

//希尔排序以n=10 的一个数组49, 38, 65, 97, 26, 13, 27, 49, 55, 4为例 
void shellsort1(int a[], int n) 
{ 
	int i, j, gap; 

	for (gap = n / 2; gap > 0; gap /= 2)    //步长 
	{
		for (i = 0; i < gap; i++)                  //按组排序       
		{ 
			for (j = i + gap; j < n; j += gap)     
			{ 
				if (a[j] < a[j - gap]) 
				{ 
					int temp = a[j]; 
					int k = j - gap; 
					while (k >= 0 && a[k] > temp) 
					{ 
						a[k + gap] = a[k]; 
						k -= gap; 
					} 
					a[k + gap] = temp; 
				} 
			} 
		}
	} 
} 
//shellsort1的简化版
void shellsort2(int a[], int n) 
{ 
	int j, gap; 

	for (gap = n / 2; gap > 0; gap /= 2) 
	{
		for (j = gap; j < n; j++)      //从数组第gap个元素开始 
		{
			if (a[j] < a[j - gap])   //每个元素与自己组内的数据进行直接插入排序     
			{ 
				int temp = a[j]; 
				int k = j - gap; 
				while (k >= 0 && a[k] > temp) 
				{ 
					a[k + gap] = a[k]; 
					k -= gap; 
				} 
				a[k + gap] = temp; 
			} 
		}
	}
}


//输出数组里的数据 
void Print(int *arr, int size) 
{ 
	int i; 
	for(i=0;i<size;i++) 
	{ 
		printf("%6d ", arr[i]); 
		if(0 == (i+1) % 10) 
			cout << endl; 
	} 
	cout << endl; 
} 
//主函数 
//先随机选择100 个整型数据放入数组中，并输出 
//然后将其从小到大排序，并输出 
int main() 
{ 
	int arr[SIZE] = {0}, i = 0; 
	cout << "The array is: " << endl; 
	srand((unsigned)time(0)); 
	for(i=0;i<SIZE;i++) 
		arr[i] = rand() % MAX; 
	Print(arr, SIZE); 
	//请选择其中一个排序算法，以运行该程序 
	BubbleSort(arr, SIZE);      //冒泡排序 
	SelectionSort(arr, SIZE);   //选择排序
	CountSort(arr, SIZE);       //计数排序 
	InsertSort(arr, SIZE);      //插入排序 
	QuickSort(arr, SIZE);       //快速排序
	MergeSort(arr, SIZE);       //归并排序
	HeapSort(arr, SIZE);        //堆排序
	ShellSort(arr, SIZE);       //希尔排序 
	cout << "After sorting, the array is:" << endl; 
	Print(arr, SIZE); 
	return 0; 
} 

