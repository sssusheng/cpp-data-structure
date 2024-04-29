#include <iostream>
 #include "SeqList.h"

int main()
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
}