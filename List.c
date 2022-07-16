#include "List.h"

//��̬����һ���µĽڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//˫�����ʼ��
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//˫��������
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}

//˫�����ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β�壨1��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//β��-insert��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

//ͷ��-first��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	// phead newnode first
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

//ͷ��-��first��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;

}

//ͷ��-insert��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;

	ListInsert(phead->next, x);
}

//ͷɾ-��first��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;

}

//ͷɾ-erase��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;

	//free(first);
	//first = NULL;

	ListErase(phead->next);
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;

	free(tail);
	tail = NULL;

}

//βɾ-erase��
void ListPopBack(ListNode* phead)
{
	assert(phead);
	/*assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;

	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);
}

//����
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// posλ��֮ǰ����x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}