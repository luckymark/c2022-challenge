#include"p11_linkedList.h"
int main() {
	Node*listHead=createList();printList(listHead);
	Node* swapListHead = swapList(listHead); printList(swapListHead);
	listHead=swapList(swapListHead);
	int first5 = searchFirstNode(listHead, 5), next5 = searchNextNode(listHead, 5, first5);
	if (first5 != -1) { printf("\nNO:%d is the first 5", first5); }
	if (next5 != -1) { printf("\nNO:%d is the next 5", next5); }
	return 0;
}