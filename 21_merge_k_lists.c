struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef NULL 
#define NULL ((struct ListNode *)0)
#endif

static struct ListNode *merge2(struct ListNode *h1, struct ListNode *h2)
{
	struct ListNode *res, *tail, *t;

	res = tail = NULL;
	while (h1 && h2) {
		if (h1->val < h2->val) {
			t = h1;
			h1 = h1->next;
		} else {
			t = h2;
			h2 = h2->next;
		}
		if (!res) {
			res = tail = t;
		} else {
			tail->next = t;
			tail = t;
		}
	}
	if (h1) {
		if (!res)
			res = h1;
		else
			tail->next = h1;
	}
	if (h2) {
		if (!res)
			res = h2;
		else 
			tail->next = h2;
	}
	return(res);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	if (!listsSize)
		return(NULL);
	if (listsSize == 1)
		return(lists[0]);

	int	m;
	struct ListNode *h1, *h2;

	m = listsSize >> 1;
	h1 = mergeKLists(lists, m);
	h2 = mergeKLists(lists + m, listsSize - m);
	return(merge2(h1, h2));
}

int main(void)
{}
