#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include <stdio.h>

int test_arr1[1] = { 1 };
int test_arr2[5] = { 1,2,3,4,5 };
int test_arr3[6] = { 1,2,3,4,5,6 };

int main()
{
	LinkList* L = NULL;
	Stack* S = NULL;
	Queue* Q = NULL;
	L = ArrayToList(L, test_arr3, 6);
	DeleteElem(L, 6);
	OutputList(L);
	CleanList(L);

	S = InitStack(S);
	for (int i = 0; i < 5; i++)
		PushStack(S, test_arr2[i]);
	while (!isEmptyStack(S))
	{
		ElemType X = TopStack(S);
		PopStack(S);
		printf("%d\n", X);
	}
	CleanStack(S);

	Q = InitQueue(Q);
	for (int i = 0; i < 5; i++)
		PushQueue(Q, test_arr2[i]);
	while (!isEmptyQueue(Q))
	{
		ElemType X = FrontQueue(Q);
		PopQueue(Q);
		printf("%d\n", X);
	}
	CleanQueue(Q);
	system("pause");
	return 0;
}