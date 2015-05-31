/*
 * optimization needed.
 */

struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef	NULL 
#define	NULL ((struct ListNode *)0)
#endif

struct ListNode *detectCycle(struct ListNode *head)
{
	if (!head || !head->next)
		return(NULL);
	if (head->next == head)
		return(head);

	struct ListNode *p1, *p2;
	int	has_cycle;
	
	p1 = head;
	p2 = head;
	while (1) {
		if (!p2) {
			has_cycle = 0;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
		if (p2) {
			p2 = p2->next;
		} else {
			has_cycle = 0;
			break;
		}
		if (p1 == p2) {
			has_cycle = 1;
			break;
		}
	}

	if (!has_cycle)
		return(NULL);
	
	while (1) {
		if (head == p1) {
			break;
		}

		p2 = p1->next;
		while (p2 != p1) {
			if (head == p2)
				break;
			else 
				p2 = p2->next;
		}
		if (head == p2)
			break;
		else 
			head = head->next;
	}
	return(head);
}

int main(void)
{
	return(0);
}
