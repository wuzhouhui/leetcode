struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *p1, *p2, *tmp, *prev;

	p1 = head;
	p2 = head->next;
	p1->next = p2->next;
	p2->next = p1;
	head = p2;

	tmp = p1;
	p1 = p2;
	p2 = tmp;
	prev = p2;
	p2 = p2->next;
	while (p2) {
		p1 = p2;
		p2 = p2->next;
		if (!p2)
			break;

		p1->next = p2->next;
		p2->next = p1;
		prev->next = p2;

		tmp = p1;
		p1 = p2;
		p2 = tmp;
		prev = p2;
		p2 = p2->next;
	}

	return(head);
}

int main(void)
{}
