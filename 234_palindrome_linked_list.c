#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

#define bool int

bool isPalindrome(struct ListNode *head)
{
	bool	res;
	struct ListNode *rever, *tmp1, *tmp2;

	rever = NULL;
	for (tmp1 = head; tmp1 != NULL; tmp1 = tmp1->next) {
		tmp2 = malloc(sizeof(struct ListNode));
		tmp2->val = tmp1->val;
		tmp2->next = rever;
		rever = tmp2;
	}

	res = 1;
	for (tmp1 = head, tmp2 = rever; tmp1 != NULL; tmp1 = tmp1->next,
			tmp2 = tmp2->next)
		if (tmp1->val != tmp2->val) {
			res = 0;
			break;
		}
	while (rever != NULL) {
		tmp1 = rever;
		rever = rever->next;
		free(tmp1);
	}
	return(res);
}

int main(void)
{
}
