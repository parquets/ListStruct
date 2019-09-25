#pragma once

#include "LinkList.h"

typedef LinkList Stack;

Stack*		InitStack	(Stack* S);
void		CleanStack	(Stack* S);
void		PushStack	(Stack* S, ElemType X);
void		PopStack		(Stack* S);
ElemType	TopStack		(const Stack* S);
int 		isEmptyStack(const Stack* S);
int			StackSize	(const Stack* S);