#include "Queue.h"

Queue* InitQueue(Queue* Q)
{
	Q = (Queue*)malloc(sizeof(Queue));
	Q->Head = (NodePos)malloc(sizeof(ListNode));
	Q->End = Q->Head;
	Q->Head->next = NULL;
	Q->Head->elem = 0;
	Q->size = 0;
	return Q;
}

int isEmptyQueue(const Queue* Q) { return Q->size == 0; }

int QueueSize(const Queue* Q) { return Q->size; }

void CleanQueue(Queue* Q)
{
	NodePos cur = Q->Head;
	NodePos cur_prev;
	while (cur != NULL)
	{
		cur_prev = cur;
		cur = cur->next;
		free(cur_prev);
	}
	free(cur);
	Q->Head = Q->End = NULL;
	Q->size = 0;
}

void PushQueue(Queue* Q, ElemType X)
{
	NodePos new_node = (NodePos)malloc(sizeof(ListNode));
	new_node->elem = X;
	new_node->next = NULL;
	Q->End->next = new_node;
	Q->End = new_node;
	Q->size++;
}

void PopQueue(Queue* Q)
{
	if (Q->Head == NULL || Q->Head->next == NULL) return;
	NodePos cur = Q->Head->next;
	Q->Head->next =cur->next;
	free(cur);
	Q->size--;
}

ElemType FrontQueue(const Queue* Q) 
{ 
	if (Q->Head == NULL) return;
	if (Q->Head->next != NULL) return Q->Head->next->elem;
	else return -1;
}
