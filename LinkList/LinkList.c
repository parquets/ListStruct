#include "LinkList.h"

LinkList* InitList(LinkList* L)
{	
	L = (ListNode*)malloc(sizeof(LinkList));
	L->elem = 0;
	L->next = NULL;
}

void CleanList(LinkList* L)
{
	NodePos cur_pos = L->next;
	NodePos next_pos;
	L->next = NULL;
	while (cur_pos != NULL)
	{
		next_pos = cur_pos->next;
		free(cur_pos);
		cur_pos = next_pos;
	}
}

int	isEmptyList(const LinkList* L) { return L->next == NULL; }

int	isLastNode(const ListNode* P) { return P->next == NULL; }

NodePos	FindElem(const LinkList* L, ElemType X)
{
	NodePos cur_pos = L;
	while (cur_pos != NULL && cur_pos->elem != X)
		cur_pos = cur_pos->next;
	return cur_pos;
}

void DeleteElem(LinkList* L, ElemType X)
{
	NodePos cur_pos  = L->next;
	NodePos prev_pos = L;
	while (cur_pos != NULL && cur_pos->elem != X)
	{
		prev_pos = cur_pos;
		cur_pos  = cur_pos->next;
	}
	if (cur_pos != NULL)
	{
		prev_pos->next = cur_pos->next;
		free(cur_pos);
		L->elem--;
	}
}

void DeleteFirst(LinkList* L)
{
	if (L->next == NULL) return;
	NodePos Tmp = L->next;
	L->next = Tmp->next;
	free(Tmp);
}

void InsertAfter(LinkList* L, ElemType X, NodePos P)
{
	NodePos new_node;
	new_node = (NodePos)malloc(sizeof(ListNode));
	new_node->elem = X;
	new_node->next = P->next;
	P->next = new_node;
}

void InsertElem(LinkList* L, ElemType X, NodePos P) { InsertAfter(L, X, P); }

void InsertBefore(LinkList* L, ElemType X, NodePos P)
{
	InsertAfter(L, X, P);
	ElemType Tmp = P->elem;
	P->elem = P->next->elem;
	P->next->elem = Tmp;
}

void InsertHead(LinkList* L, ElemType X)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->elem = X;
	new_node->next = L->next;
	L->next = new_node;                     
}

NodePos	FirstNode(const LinkList* L) { return L->next; }

NodePos	EndNode(const LinkList* L)
{
	NodePos cur_pos = L;
	while (cur_pos->next != NULL)
		cur_pos = cur_pos->next;
	return cur_pos;
}

LinkList* ArrayToList(ListNode* L, ElemType* Data, int Size)
{
	if(L == NULL) L = InitList(L);
	NodePos cur = L;
	for (int i = 0; i < Size; i++)
	{
		InsertAfter(L, Data[i], cur);
		cur = cur->next;
	}
	return L;
}

void OutputList(const ListNode* L)
{
	NodePos cur_pos = L->next;
	while (cur_pos != NULL)
	{
		printf("%d ", cur_pos->elem);
		cur_pos = cur_pos->next;
	}
	printf("\n");
}

int ListSize(const LinkList* L)
{ 
	int res = 0;
	NodePos cur = L->next;
	while (cur != NULL)
	{
		res++;
		cur = cur->next;
	}
	return res;
}