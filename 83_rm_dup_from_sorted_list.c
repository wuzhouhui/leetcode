#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *newhead, *newtail, *tmp;

	newhead = newtail = head;
	head = head->next;
	while (head) {
		if (head->val == newtail->val) {
			tmp = head;
			head = head->next;
			free(tmp);
			continue;
		}
		newtail->next = head;
		newtail = newtail->next;
		head = head->next;
	}

	newtail->next = 0;
	return(newhead);
}

int main(void)
{

}
