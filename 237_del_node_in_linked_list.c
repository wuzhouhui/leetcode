#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
	if (node == NULL)
		return;

	struct ListNode *tmp;

	tmp = node->next;
	node->val = node->next->val;
	node->next = node->next->next;
	free(tmp);
}

int main(void)
{
}
