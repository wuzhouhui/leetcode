#include <stdio.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

static void merge_sort(struct ListNode **);
static void front_back_split(struct ListNode *, struct ListNode **,
		struct ListNode **);
static struct ListNode *sorted_merge(struct ListNode *, struct ListNode *);

struct ListNode *sortList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);
	merge_sort(&head);
	return(head);
}

static void merge_sort(struct ListNode **headptr)
{
	struct ListNode *head;
	struct ListNode *a, *b;

	if (!(head = *headptr) || !head->next)
		return;

	front_back_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*headptr = sorted_merge(a, b);
}

static void front_back_split(struct ListNode *head, struct ListNode **a,
		struct ListNode **b)
{
	if (!head || !head->next) {
		*a = head;
		*b = NULL;
		return;
	}

	struct ListNode *p1, *p2;
	int	flag = 0;
	
	p1 = head;
	head = head->next;
	p2 = head;
	head = head->next;
	*a = p1;
	*b = p2;
	while (head) {
		if (flag == 0) {
			flag = 1;
			p1->next = head;
			p1 = p1->next;
		} else {
			flag = 0;
			p2->next = head;
			p2 = p2->next;
		}
		head = head->next;
	}
	p1->next = p2->next = NULL;
}

static struct ListNode *sorted_merge(struct ListNode *a, struct ListNode *b)
{
	if (!a)
		return(b);
	if (!b)
		return(a);
	struct ListNode *head = NULL;
	struct ListNode *tail = NULL;

	if (a->val < b->val) {
		head = tail = a;
		a = a->next;
	} else {
		head = tail = b;
		b = b->next;
	}
	while (a && b) {
		if (a->val < b->val) {
			tail->next = a;
			tail = tail->next;
			a = a->next;
		} else {
			tail->next = b;
			tail = tail->next;
			b = b->next;
		}
	}

	tail->next = NULL;
	if (a)
		tail->next = a;
	if (b)
		tail->next = b;

	return(head);
}

int main(void)
{
}
