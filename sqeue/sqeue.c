/*������ʵ��ֱ�Ӳ�������ʹ��˳���*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef struct sqeue {
	int data[MAXSIZE];
	int size;
}sqeue;
/*���Ա�Ĵ�ӡ*/
void print_sqeue(sqeue s)
{
	int i = 0;
	for (i = 0; i < s.size; i++)
	{
		printf("%d\n", s.data[i]);
	}
}

/*���Ա��ʼ��*/
void init_sqeue(sqeue* s)
{
	s->size = 0;//sizeΪ0��ʾ���Ա�Ϊ��
}

/*���Ա�Ĳ���,β��*/
int insert_sqeue(sqeue* s, int val)
{
	s->data[s->size] = val;
	s->size++;
}

/*���Ա���ĳһ�ڵ����*/
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

/*���Ա�������ڵ�ɾ��*/
int delete_sqeue(sqeue* s, int node)
{
	if (node <= 0 || node > s->size)
		return -1;
	int i = 0;
	for (i = node; i < s->size; i++)
	{
		s->data[i - 1] = s->data[i];//������������
	}
	s->size--;
}

/*ֱ�Ӳ�������*/
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
	int i = 0;//ָ�����������ָ��
	int j = 0;
	int k = 0;//ָ���½�������
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
	if (i >= size1) //�Ǹ����������н�����ʣ�µ�����д���´�����������
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
	//������arrд�뵽arr1��
	for (i = 0; i < k; i++)
	{
		arr1[i] = arr[i];
	}

}
void ret_sort(int* arr, int size) //�鲢����
{
	if (size<=1)
		return;
	int mid = size/ 2;
	ret_sort(arr, mid);
	ret_sort(arr+mid,size-mid);
	merge(arr,mid, arr + mid,size-mid);
}

//��������
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
		while (l1<r1 && arr[r1]>cmp) //���������ҵ�һ��С��cmp����
			r1--;
		while (l1 < r1 && arr[l1] <= cmp)//���������ҵ�һ������cmp����
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

