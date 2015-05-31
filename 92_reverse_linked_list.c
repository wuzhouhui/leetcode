struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef NULL 
#define NULL ((struct ListNode *)0)
#endif

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *ptr, *prev, *revptr, *next, *revtail;
	int	i;

	ptr = head;
	prev = NULL;
	for (i = 1; i < m; i++) {
		prev = ptr;
		ptr = ptr->next;
	}

	revptr = NULL;
	revtail = next = ptr;
	for (i = m; i <= n; i++) {
		ptr = next;
		next = next->next;
		ptr->next = revptr;
		revptr = ptr;
	}

	if (!prev)
		head = revptr;
	else 
		prev->next = revptr;
	revtail->next = next;
	return(head);
}

int main(void)
{}
