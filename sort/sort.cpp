#include<iostream>
#include<stdlib.h>
#define INF 100
//��������Ĭ��Ϊ�ǵݼ����򣨷ǵݼ������ڵ�������Ϊ�п��ܳ�����ͬ���ֵ������

//ֱ�Ӳ�������(�ȶ������һ��������Ȼ�󽫵ڶ�������������)
void InsertSort(int r[], int n)                   //r�����飬nΪ���鳤��
{
	int tmp,j;
	for (int i = 1; i < n; ++i)                      //���ڵ�һ����㣬�������򣬹�ѭ���ӵڶ�����㿪ʼ
	{
		tmp = r[i];
		j = i-1;
		while (j>=0&&tmp<r[j])                //�øý�����Ѿ�����õĽ�����Աȣ�����������λ��
		{
			r[j + 1] = r[j];
			--j;
		}
		r[j + 1] = tmp;                                 //�������λ��Ϊj+1
	}
}

//�۰��������(���ַ�)

//ϣ������(��С��������)

//ð������
void BubbleSort(int r[], int n)
{
	int tmp, flag;
	for (int i = 0; i < n-1; ++i)                                        //���ѭ��n-1�ξ����������
	{
		flag = 0;                                                               //ѭ��ǰ��ʼ��flag��flag�����ж�jѭ�����Ƿ���Ԫ�ؽ���
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
	if (flag==0)                                                              //��ѭ��j֮��flag��ȻΪ0������������Ѿ����
	{
		return;
	}
}

//��������
void QuickSort(int r[], int low, int high)
{
	int i = low;
	int j = high;
	if (low<high)                                                              //�˾������жϵݹ��Ƿ����
	{
		int tmp = r[i];
		while (i<j)
		{
			while (i<j&&r[j]>tmp)                                       //���ҿ�ʼ�ж�����Ŧ�Ĵ�С��ϵ����С�����滻��i��λ�ã�����ݼ�
			{
				--j;
			}
			if (i<j)                                                                 //������ΪС����Ŧ��ԭ����˳�while����Ԫ���滻λ�ã�����Ȩ����i
			{
				r[i] = r[j];
				++i;
			}
			while (i<j&&r[i]<tmp)                                       //ͬ��
			{
				++i;
			}
			if (i<j)
			{
				r[j] = r[i];
				--j;
			}
		}
		r[i] = tmp;                                                              //������i��λ�ø�����Ŧ��ֵ
		QuickSort(r, low, i - 1);                                          //ÿһ�ο��������ܹ�ȷ����Ŧλ�ã������Ҫ����
		QuickSort(r, i + 1, high);                                       //��Ԫ��λ��ȷ���Ļ����õݹ�ֱ�������ǰ������
	}
}

//��ѡ������
void SelectSort1(int r[], int n)                    //����
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
		for (j = i+1; j <n ; j++)                                   //�ӵ�һ������Ԫ�ؿ�ʼ��������СԪ�ص�λ�ã�����k
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

//������
void Sift(int r[], int low, int high)                             //�˴��ݶ������±��1��ʼ���˷������ڽ�low�ϵĽ����е���
{
	int i = low, j = 2 * i;                                             //jΪlow��������
	int tmp=r[i];
	while (j<=high)
	{
		if (j<high&&r[j]<r[j+1])                                  //���������������jָ������������һ��֮��jΪ���������ֵ�±�  
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
		Sift(r, i, n);                                                                 //ѭ��ǰ�벿�֣����ɽ�ԭʼ������жѵĳ�ʼ��
	}
	for (i = n; i >1; i--)                                                        //ѭ��n-1�μ���
	{
		tmp = r[i];
		r[i] = r[1];
		r[1] = tmp;
		Sift(r, 1, i - 1);
	}
}

//��·�鲢����
void merge(int r[],int low,int mid,int high){}                   //������������й鲢
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

//��������

//�û�-ѡ������

//��ѹ鲢��

//������