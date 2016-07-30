struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (k <= 1)
		return(head);
	struct ListNode *newhead, *rev, *p;
	struct ListNode **pprev = &newhead;
	while (head) {
		rev = 0;
		int i = 1;
		while (head && i <= k) {
			p = head;
			head = head->next;
			i++;
			p->next = rev;
			rev = p;
		}
		if (i <= k) {
			p = rev;
			rev = 0;
			while (p) {
				struct ListNode *t = p;
				p = p->next;
				t->next = rev;
				rev = t;
			}
		}
		while (rev) {
			p = rev;
			rev = rev->next;
			*pprev = p;
			pprev = &p->next;
		}
	}
	*pprev = 0;
	return(newhead);
}

main(){}
