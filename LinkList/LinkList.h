#pragma once

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define	MAXSIZE 0xfffffff

struct	ListNode;
typedef struct ListNode		LinkList;
typedef struct ListNode		ListNode;
typedef int					ElemType;
typedef struct ListNode*	NextNode;
typedef struct ListNode*	NodePos;

LinkList*	InitList	(LinkList* L);
void		CleanList	(LinkList* L);
int			isEmptyList	(const LinkList* L);
int			isLastNode	(const ListNode* P);
NodePos		FindElem	(const LinkList* L, ElemType X);
void		DeleteElem	(LinkList* L, ElemType X);
void		DeleteFirst	(LinkList* L);
void		InsertAfter	(LinkList* L, ElemType X, NodePos P);
void		InsertElem	(LinkList* L, ElemType X, NodePos P);
void		InsertBefore(LinkList* L, ElemType X, NodePos P);
void		InsertHead	(LinkList* L, ElemType X);
NodePos		FirstNode	(const LinkList* L);
NodePos		EndNode		(const LinkList* L);
LinkList*	ArrayToList (ListNode* L, ElemType* Data, int Size);
void		OutputList	(const ListNode* L);
int			ListSize	(const LinkList* L);


struct ListNode
{
	ElemType elem;
	NextNode next;
};

