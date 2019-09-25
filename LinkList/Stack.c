#include "Stack.h"

Stack* InitStack(Stack* S)
{
	S = InitList(S);
	return S;
}

int isEmptyStack(const Stack* S) { return isEmptyList(S); }

void CleanStack(Stack* S) { CleanList(S); }

void PushStack(Stack* S, ElemType X) { InsertHead(S, X); }

void PopStack(Stack* S) 
{ 
	if (S->next != NULL)
		DeleteFirst(S);
}

ElemType TopStack(const Stack* S) 
{
	if (S->next == NULL) return -1;
	return S->next->elem; 
}

int StackSize(const Stack* S) { return ListSize(S); }