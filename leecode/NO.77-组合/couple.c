//����ʹ�û����㷨����ݹ��ศ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 //����ȫ�ֱ����洢�����һά����洢��ʱ���
int** result;
int size = 0; //size��¼��ά��������һά�������
int* path;
int cnt = 0;

void backtrancing(int n, int k, int stratindex) //ȷ���ݹ麯���Ĳ����뷵��ֵ
{
    //�ж���ֹ����,��¼���
    if (cnt == k)
    {
        int i = 0;
        int* tmp = (int*)malloc(sizeof(int) * k);
        for (i = 0; i < k; i++)
        {
            tmp[i] = path[i];
        }
        result[size] = tmp;
        size++;
        return;
    }
    int i = 0;
    for (i = stratindex; i <= n; i++)
    {
        path[cnt] = i;
        cnt++;
        backtrancing(n, k, i + 1);
        cnt--;
    }
    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * k);//����k��ֵȷ���洢������ֵ
    memset(path, 0, sizeof(int) * k);
    result = (int**)malloc((sizeof(int*)) * 10001);
    memset(result, 0, sizeof(int*) * 10001);
    backtrancing(n, k, 1);
    *returnSize = size;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        (*returnColumnSizes)[i] = k;
    }
    return result;
}


int main(int argc, char* argv[])
{
    int** ret = NULL;
    int returnSize = 0;
    int* returnColumnSizes = (int*)malloc(sizeof(int) * 10001);
    ret = combine(4, 2, &returnSize, &returnColumnSizes);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d %d\n", ret[i][0], ret[i][1]);
    }
    return 0;
}