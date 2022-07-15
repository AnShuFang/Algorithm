/*������ʵ��������ز�������ͷ���*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����ṹ��
typedef struct node {
	int val;
	struct node* next;
}node,*list;

/*ͷ����ʼ��*/
void init_list(list *head)
{
	*head = (list)malloc(sizeof(node));
		(*head)->next = NULL;
}
/*���Ĺ���*/
node* creat_node(int val)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->val = val;
	return p;
}

/*����Ĳ��룬ͷ��*/
void insert_list(list head, int val)
{
	if (head == NULL) //˵������δ��ʼ��
		return;
	node* p = creat_node(val);
	p->next = head->next;
	head->next = p;
}
/*����Ĳ��룬β��*/
void insert_tail(list head, int val)
{
	if (head == NULL) //˵������δ��ʼ��
		return;
	node* node = creat_node(val);//����һ���ڵ�
	list p = head;
	while (p->next != NULL)
	{
		p = p->next;//�ҵ�δ�ڵ�
	}
	p->next = node;
}

/*����Ĵ�ӡ,��ͷ���*/
void print_list(list head)
{
	list p = head->next;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}
/*����Ĵ�ӡ,����ͷ���*/
void print_list1(list head)
{
	list p = head;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}
//�����������ֵ��������
struct node* list_search(struct node* head) //�����������ֵ����������Ӧ�ڵ�
{
	if (NULL == head)
		return head;
	struct node* p = head->next;
	struct node* min = head;
	while (p != NULL)
	{
		if (p->val < min->val)
		{
			min = p;
		}
		p = p->next;
	}
	return min;

}
//ɾ�������Ӧ��Ԫ��
void list_delete(struct node** head, struct node* node) //����ͷ��������ɾ��
{
	if (NULL == *head || NULL == node)
		return;
	if (*head == node)
	{
		*head = (*head)->next;
		return;
	}
	struct node* pre = *head;
	struct node* p = (*head)->next;
	while (p != NULL)
	{
		if (p == node)
		{
			pre->next = p->next;
			break;
		}
		pre = p;
		p = p->next;
	}
}
//����ͷ������������
struct node* sortList(struct node* head) {

	if (NULL == head)
		return head;
	struct node* p = NULL;
	struct node* node = NULL;
	struct node* list = NULL;
	init_list(&list);
	struct node* p1 = list;
	while (head != NULL)
	{
		node = list_search(head);//�ҵ����Ԫ��
		//printf("%d\n", node->val);
		list_delete(&head, node); //ɾ����ӦԪ��
		node->next = NULL;
		p1->next = node;
		p1 = p1->next;
	}
	p1 = list->next;
	free(list);
	return p1;
}

int main(int argc, char* argv)
{
	list head = NULL;
	list p = NULL;
	init_list(&head);
	insert_list(head,5); 
	insert_list(head,3);
	insert_list(head,7);
	insert_list(head,6);
	insert_list(head,2);
	insert_tail(head,8);
	insert_tail(head,1);
	insert_tail(head,9);
	print_list(head);
	p = sortList(head->next);
	print_list1(p);
	return 0;


}