/*本程序实现直接插入排序，使用顺序表*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef struct sqeue {
	int data[MAXSIZE];
	int size;
}sqeue;
/*线性表的打印*/
void print_sqeue(sqeue s)
{
	int i = 0;
	for (i = 0; i < s.size; i++)
	{
		printf("%d\n", s.data[i]);
	}
}

/*线性表初始化*/
void init_sqeue(sqeue* s)
{
	s->size = 0;//size为0表示线性表为空
}

/*线性表的插入,尾插*/
int insert_sqeue(sqeue* s, int val)
{
	s->data[s->size] = val;
	s->size++;
}

/*线性表在某一节点插入*/
int insert_every_sqeue(sqeue* s, int node, int val)
{
	if (node <= 0 || node > s->size+1)
		return -1;
	int i = 0;
	for (i = s->size; i >= node; i--)//
	{
		s->data[i] = s->data[i - 1];
	}
	s->data[node - 1] = val;
	s->size++;
	return 0;
}

/*线性表在任意节点删除*/
int delete_sqeue(sqeue* s, int node)
{
	if (node <= 0 || node > s->size)
		return -1;
	int i = 0;
	for (i = node; i < s->size; i++)
	{
		s->data[i - 1] = s->data[i];//数据整体左移
	}
	s->size--;
}

/*直接插入排序*/
void sort_sqeue(sqeue* s)
{
	int i,j,k;
	int tmp = 0;
	for (i = 1;i <= s->size - 1; i++)
	{
		tmp = s->data[i];
		for (j = 0; j < i; j++)
		{
			if (tmp < s->data[j])
			{
				for (k = i; k > j; k--)
				{
					s->data[k] = s->data[k - 1];
				}
				s->data[j] = tmp;
				break;
			}
		}
	}
}
 void merge(int* arr1,int size1, int* arr2,int size2)
{
	int arr[size1 + size2];
	memset(arr, 0, sizeof(arr));
	int i = 0;//指向两个数组的指针
	int j = 0;
	int k = 0;//指向新建的数组
	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
		{
			arr[k] = arr1[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			k++;
			j++;
		}
	}
	if (i >= size1) //那个数组先排列结束，剩下的数组写到新创建的数组中
	{
		while (j < size2)
		{
			arr[k] = arr2[j];
			k++;
			j++;
		}
	}
	if (j>= size2)
	{
		while (i< size1)
		{
			arr[k] = arr1[i];
			k++;
			i++;
		}
	}
	//把数组arr写入到arr1中
	for (i = 0; i < k; i++)
	{
		arr1[i] = arr[i];
	}

}
void ret_sort(int* arr, int size) //归并排序
{
	if (size<=1)
		return;
	int mid = size/ 2;
	ret_sort(arr, mid);
	ret_sort(arr+mid,size-mid);
	merge(arr,mid, arr + mid,size-mid);
}

//快速排序
void quick_sort(int* arr, int left, int right)
{
	if (left >right)
		return;
	int l1 = left;
	int r1 = right;
	int cmp = arr[left];
	int tmp=0;
	while (l1 < r1)
	{
		while (l1<r1 && arr[r1]>cmp) //从右往左找到一个小于cmp的数
			r1--;
		while (l1 < r1 && arr[l1] <= cmp)//从左往右找到一个大于cmp的数
			l1++;
		tmp = arr[l1];
		arr[l1] = arr[r1];
		arr[r1] = tmp;
	}
	arr[left] = arr[l1];
	arr[l1] = cmp;
	quick_sort(arr, left, l1 - 1);
	quick_sort(arr, l1 + 1, right);
}


int main(int argc, char* argv[])
{
	sqeue s;
	init_sqeue(&s);
	insert_sqeue(&s, 2);
	insert_sqeue(&s, 5);
	insert_sqeue(&s, 4);
	insert_sqeue(&s, 3);
	insert_sqeue(&s, 6);
	insert_every_sqeue(&s, 3, 1);
	//delete_sqeue(&s, 3);
	print_sqeue(s);
	//sort_sqeue(&s);
	//print_sqeue(s);
	//ret_sort(s.data,s.size);
	quick_sort(s.data, 0, s.size - 1);
	print_sqeue(s);
	return 0;

}

