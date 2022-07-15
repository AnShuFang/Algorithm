/*本程序实现链表相关操作，带头结点*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表结构体
typedef struct node {
	int val;
	struct node* next;
}node,*list;

/*头结点初始化*/
void init_list(list *head)
{
	*head = (list)malloc(sizeof(node));
		(*head)->next = NULL;
}
/*结点的构造*/
node* creat_node(int val)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->val = val;
	return p;
}

/*链表的插入，头插*/
void insert_list(list head, int val)
{
	if (head == NULL) //说明链表未初始化
		return;
	node* p = creat_node(val);
	p->next = head->next;
	head->next = p;
}
/*链表的插入，尾插*/
void insert_tail(list head, int val)
{
	if (head == NULL) //说明链表未初始化
		return;
	node* node = creat_node(val);//构造一个节点
	list p = head;
	while (p->next != NULL)
	{
		p = p->next;//找到未节点
	}
	p->next = node;
}

/*链表的打印,带头结点*/
void print_list(list head)
{
	list p = head->next;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}
/*链表的打印,不带头结点*/
void print_list1(list head)
{
	list p = head;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}
//查找链表最大值，并返回
struct node* list_search(struct node* head) //查找链表最大值，并返回相应节点
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
//删除链表对应的元素
void list_delete(struct node** head, struct node* node) //不带头结点链表的删除
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
//不带头结点链表的排序
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
		node = list_search(head);//找到最大元素
		//printf("%d\n", node->val);
		list_delete(&head, node); //删除相应元素
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