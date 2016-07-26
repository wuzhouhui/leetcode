#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode **pp;
	struct ListNode *p = head;
	int i;

	for (i = 1; i < n; i++)
		p = p->next;
	pp = &head;
	while (p->next) {
		p = p->next;
		pp = &(*pp)->next;
	}
	p = *pp;
	*pp = p->next;
	free(p);
	return(head);
}

main(){}
