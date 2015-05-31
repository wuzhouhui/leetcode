
struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef NULL 
#define NULL ((struct ListNode *)0)
#endif

struct ListNode *partition(struct ListNode *head, int x)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *ptr1, *ptr2, *prev1, *prev2;

	prev1 = NULL;
	for (ptr1 = head; ptr1; ptr1 = ptr1->next) {
		if (ptr1->val >= x) {
			prev1 = ptr1;
			continue;
		}

		if (!prev1)
			continue;

		prev2 = NULL;
		for (ptr2 = head; ptr2 != ptr1; ptr2 = ptr2->next) {
			if (ptr2->val >= x)
				break;
			prev2 = ptr2;
		}
		if (ptr2 == ptr1)
			continue;

		/* remove ptr1 */
		prev1->next = ptr1->next;

		/* insert ptr1 into right place */
		if (prev2 == NULL) {
			ptr1->next = head;
			head = ptr1;
		} else {
			ptr1->next = prev2->next;
			prev2->next = ptr1;
		}

		ptr1 = prev1;
	}

	return(head);
}

int main(void)
{}
