#include <iostream>
#include "SeqList.h"
#include "LinkList.h"
#include "DbLinkList.h"
#include "SeqStack.h"
#include "LinkStack.h"


int main()
{
	LinkStack<int> linkstackobj;
	linkstackobj.Push(12);
	linkstackobj.Push(24);
	linkstackobj.Push(48);
	linkstackobj.Push(100);
	linkstackobj.DisplayList();

	int temp = 0;
	linkstackobj.Pop(temp);
	linkstackobj.DisplayList();
}


int test_seqstack_main()
{
	SeqStack<int> seqstackobj(10);
	seqstackobj.Push(150);
	seqstackobj.Push(200);
	seqstackobj.Push(300);
	seqstackobj.Push(400);
	seqstackobj.DisPlayList();

	int eval = 0;
	seqstackobj.Pop(eval);
	seqstackobj.Pop(eval);
	seqstackobj.DisPlayList();
	return 1;
}


int test_dblinklist_main()
{
	DbLinkList<int> dblinkobj;
	dblinkobj.ListDelete(1);
	dblinkobj.ListInsert(1, 10);
	dblinkobj.ListInsert(2, 20);
	dblinkobj.ListInsert(2, 30);
	dblinkobj.ListDelete(1);
	dblinkobj.DisplayList();

	int temp;
	dblinkobj.GetElem(1, temp);
	dblinkobj.LocateElem(30);
	dblinkobj.ListLength();
	dblinkobj.Empty();
	dblinkobj.ReverseList();
	dblinkobj.DisplayList();
	return 1;
}


int test_linklist_main()
{
	LinkList<int> linkobj;
	linkobj.ListDelete(1);
	linkobj.ListInsert(1, 10);
	linkobj.ListInsert(2, 20);
	linkobj.ListInsert(2, 30);
	linkobj.ListDelete(1);

	int temp;
	linkobj.GetElem(1, temp);
	linkobj.LocateElem(50);
	linkobj.DisplayList();
	linkobj.ListLength();
	linkobj.ReverseList();
	linkobj.DisplayList();
	return 1;
}


int test_seqlist_main()
{
	SeqList<int> seqobj(10);
	seqobj.ListInsert(1, 10);
	seqobj.ListInsert(2, 15);
	seqobj.ListInsert(2, 20);
	seqobj.ListInsert(8, 50);

	seqobj.ListDelete(5);

	int temp;
	seqobj.GetElem(1, temp);
	seqobj.LocateElem(20);

	seqobj.DisplayList();
	seqobj.ListLength();
	seqobj.ReverseList();
	return 1;
}