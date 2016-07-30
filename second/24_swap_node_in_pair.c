struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	struct ListNode *newhead, *p1 = 0, *p2 = 0;
	struct ListNode **pprev= &newhead;
	while (head) {
		p1 = head; head = head->next;
		if (!(p2 = head))
			break;
		else
			head = head->next;
		*pprev = p2; pprev = &p2->next;
		*pprev = p1; pprev = &p1->next;
		p1 = p2 = 0;
	}
	if (p1) {
		*pprev = p1;
		pprev = &p1->next;
	}
	*pprev = 0;
	return(newhead);
}

main(){}
