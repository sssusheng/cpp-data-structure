#include <iostream>
#include "SeqList.h"
#include "LinkList.h"

int main()
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