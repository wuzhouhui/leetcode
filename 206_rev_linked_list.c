struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);
	
	struct ListNode *newhead, *tmp;

	newhead = 0;
	while (head) {
		tmp = head;
		head = head->next;
		tmp->next = newhead;
		newhead = tmp;
	}
	return(newhead);
}

int main(void)
{}
