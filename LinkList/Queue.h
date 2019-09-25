#pragma once

#include "LinkList.h"

struct	Queue;
typedef struct Queue Queue;

Queue*		InitQueue		(Queue* Q);
int			isEmptyQueue	(const Queue* Q);
int			QueueSize		(const Queue* Q);
void		CleanQueue		(Queue* Q);
void		PushQueue		(Queue* Q, ElemType X);
ElemType	FrontQueue		(const Queue* Q);
void		PopQueue		(Queue* Q);


struct Queue
{
	int		size;
	NodePos Head;
	NodePos End;
};
