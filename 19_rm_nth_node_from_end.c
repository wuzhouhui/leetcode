struct ListNode {
	int	val;
	struct ListNode *next;
};

#include <stdlib.h>

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	if (!head)
		return(NULL);

	struct ListNode **beg, *end;

	beg = &head;
	end = head;
	while (n > 0) {
		end = end->next;
		n--;
	}
	while (end) {
		end = end->next;
		beg = &(*beg)->next;
	}
	end = *beg;
	*beg = end->next;
	free(end);
	return(head);
}

int main(void)
{}
