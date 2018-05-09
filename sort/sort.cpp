#include<iostream>
#include<stdlib.h>
#define INF 100
//以下排序默认为非递减排序（非递减不等于递增，因为有可能出现相同数字的情况）

//直接插入排序(先对数组第一个数排序，然后将第二个数插入排序)
void InsertSort(int r[], int n)                   //r是数组，n为数组长度
{
	int tmp,j;
	for (int i = 1; i < n; ++i)                      //对于第一个结点，无需排序，故循环从第二个结点开始
	{
		tmp = r[i];
		j = i-1;
		while (j>=0&&tmp<r[j])                //让该结点与已经排序好的结点作对比，决定其插入的位置
		{
			r[j + 1] = r[j];
			--j;
		}
		r[j + 1] = tmp;                                 //结点插入的位置为j+1
	}
}

//折半插入排序(二分法)

//希尔排序(最小增量排序)

//冒泡排序
void BubbleSort(int r[], int n)
{
	int tmp, flag;
	for (int i = 0; i < n-1; ++i)                                        //最多循环n-1次就能排序完成
	{
		flag = 0;                                                               //循环前初始化flag，flag用于判断j循环中是否有元素交换
		for (int j = 0; j < n-1; ++j)
		{
			if (r[j]>r[j+1])
			{
				tmp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = tmp;
				flag=1;
			}
		}
	}
	if (flag==0)                                                              //若循环j之后flag仍然为0，则表明排序已经完成
	{
		return;
	}
}

//快速排序
void QuickSort(int r[], int low, int high)
{
	int i = low;
	int j = high;
	if (low<high)                                                              //此句用于判断递归是否继续
	{
		int tmp = r[i];
		while (i<j)
		{
			while (i<j&&r[j]>tmp)                                       //从右开始判断与枢纽的大小关系，若小于则替换到i的位置，否则递减
			{
				--j;
			}
			if (i<j)                                                                 //若是因为小于枢纽的原因而退出while，则元素替换位置，主导权交给i
			{
				r[i] = r[j];
				++i;
			}
			while (i<j&&r[i]<tmp)                                       //同上
			{
				++i;
			}
			if (i<j)
			{
				r[j] = r[i];
				--j;
			}
		}
		r[i] = tmp;                                                              //将最终i的位置赋上枢纽的值
		QuickSort(r, low, i - 1);                                          //每一次快速排序能够确定枢纽位置，因此需要将其
		QuickSort(r, i + 1, high);                                       //他元素位置确定的话，用递归分别作用于前后两端
	}
}

//简单选择排序
void SelectSort1(int r[], int n)                    //自制
{
	int ok=0,min,tmp,i,j;
	while (ok!=n)
	{
		min = INF;
		for (i=ok; i < n; i++)
		{
			if (r[i]<min)
			{
				min = r[i];
				j = i;
			}
		}
		tmp = r[ok];
		r[ok] = r[j];
		r[j] = tmp;
		++ok;
	}
}
void SelectSort(int r[], int n)
{
	int i, j, k;
	int tmp;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i+1; j <n ; j++)                                   //从第一个无序元素开始，查找最小元素的位置，赋给k
		{
			if (r[k]>r[j])
			{
				k = j;
			}
		}
		tmp = r[i];
		r[i] = r[k];
		r[k] = tmp;
	}
}

//堆排序
void Sift(int r[], int low, int high)                             //此处暂定数组下标从1开始，此方法用于将low上的结点进行调整
{
	int i = low, j = 2 * i;                                             //j为low的左子树
	int tmp=r[i];
	while (j<=high)
	{
		if (j<high&&r[j]<r[j+1])                                  //如果右子树更大，则j指向右子树，这一步之后，j为子树中最大值下标  
		{
			++j;
		}
		if (tmp<r[j])
		{
			r[i] = r[j];
			i = j;
			j = 2 * i;
		}
		else
		{
			break;
		}
	}
	r[i] = tmp;
}
void heapSort(int r[], int n)
{
	int i;
	int tmp;
	for (i = n / 2; i >= 1; i--)
	{
		Sift(r, i, n);                                                                 //循环前半部分，即可将原始数组进行堆的初始化
	}
	for (i = n; i >1; i--)                                                        //循环n-1次即可
	{
		tmp = r[i];
		r[i] = r[1];
		r[1] = tmp;
		Sift(r, 1, i - 1);
	}
}

//二路归并排序
void merge(int r[],int low,int mid,int high){}                   //将两段数组进行归并
void mergeSort(int r[], int low, int high)
{
	if (high>low)
	{
		int mid = (high + low) / 2;
		mergeSort(r, low, mid);
		mergeSort(r, mid + 1, high);
		merge(r, low, mid, high);
	}
}

//基数排序

//置换-选择排序

//最佳归并树

//败者树