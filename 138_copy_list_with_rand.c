/*
 * correct, but too slow
 */
struct RandomListNode {
	int	label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

#include <stdlib.h>

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (!head)
		return(head);

	struct RandomListNode *newhead, *t1, *t2, *t3;
	int	i;

	newhead = (t1 = NULL);
	for (t2 = head; t2; t2 = t2->next) {
		t3 = malloc(sizeof(struct RandomListNode));
		t3->label = t2->label;
		t3->random = (t3->next = NULL);
		if (!newhead) {
			newhead = t1 = t3;
		} else {
			t1->next = t3;
			t1 = t3;
		}
	}

	for (t1 = head, t2 = newhead; t1; t1 = t1->next, t2 = t2->next) {
		if (!t1->random)
			continue;
		for (i = 0, t3 = head; t3 != t1->random; t3 = t3->next, i++)
			;
		for (t2->random = newhead; i > 0; i--)
			t2->random = t2->random->next;
	}
	return(newhead);
}

int main(void)
{}
