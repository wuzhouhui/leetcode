
struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *tmp, *newhead, **pptr;
	int	l, i;

	for (l = 0, tmp = head; tmp; tmp = tmp->next)
		l++;

	if ((k %= l) == 0)
		return(head);

	pptr = &head;
	for (i = 1; i <= (l - k); i++)
		pptr = &(*pptr)->next;

	tmp = newhead = *pptr;
	*pptr = 0;
	
	while (tmp->next) 
		tmp = tmp->next;
	tmp->next = head;
	return(newhead);
}

int main(void)
{

}
