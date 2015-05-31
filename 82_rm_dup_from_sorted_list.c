struct ListNode {
	int	val;
	struct ListNode *next;
};

#include <stdlib.h>

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode **start, **end;
	struct ListNode *t1, *t2;

	start = &head;
	end = &head->next;
	while (*end) {
		while (*end && (*start)->val != (*end)->val) {
			start = &(*start)->next;
			end = &(*end)->next;
		}
		if (*end == NULL)
			break;
		while (*end && (*end)->val == (*start)->val)
			end = &(*end)->next;
		t1 = *start;
		*start = *end;
		*end = NULL;
		while (t1) {
			t2 = t1;
			t1 = t1->next;
			free(t2);
		}
		if (*start == NULL)
			break;
		end = &(*start)->next;
	}
	return(head);
}

int main(void)
{}
