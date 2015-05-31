#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif

struct ListNode {
	int	val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
	if (!head || !head->next)
		return(0);
	if (head->next == head)
		return(1);

	struct ListNode *p1, *p2;
	int	res;

	p1 = head;
	p2 = head;
	while (1) {
		if (!p1 || !p2) {
			res = 0;
			break;
		}
		if (p1)
			p1 = p1->next;
		if (p2)
			p2 = p2->next;
		if (p2) {
			p2 = p2->next;
		} else {
			res = 0;
			break;
		}
		if (p1 == p2) {
			res = 1;
			break;
		}
	}
	return(res);
}

int main(void)
{
	return(0);
}
