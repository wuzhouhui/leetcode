#include <stdlib.h>

struct queue {
	int	val;
	struct queue *next;
};

static struct queue *q1_head, *q1_tail, *q2_head, *q2_tail;

static int diff(const char *w1, const char *w2)
{
	int	dist;
	for (dist = 0; *w1 && *w2; w1++, w2++)
		if (*w1 != *w2)
			dist++;
	return(dist);
}

static void clean_q(void)
{
	while (q1_head) {
		q1_tail = q1_head;
		q1_head = q1_head->next;
		free(q1_tail);
	}
	while (q2_head) {
		q2_tail = q2_head;
		q2_head = q2_head->next;
		free(q2_tail);
	}
}

static int q1_emp(void)
{
	return(q1_head == 0);
}

static void q1_enq(int i)
{
	if (!q1_head) {
		q1_head = q1_tail = calloc(1, sizeof(struct queue));
		q1_head->val = i;
		return;
	}
	q1_tail->next = calloc(1, sizeof(struct queue));
	q1_tail = q1_tail->next;
	q1_tail->val = i;
}

static void q2_enq(int i)
{
	if (!q2_head) {
		q2_head = q2_tail = calloc(1, sizeof(struct queue));
		q2_head->val = i;
		return;
	}
	q2_tail->next = calloc(1, sizeof(struct queue));
	q2_tail = q2_tail->next;
	q2_tail->val = i;
}

static int q1_deq(void)
{
	struct queue *tmp = q1_head;
	int	i = tmp->val;
	q1_head = q1_head->next;
	free(tmp);
	return(i);
}

static int q2_deq(void)
{
	struct queue *tmp = q2_head;
	int	i = tmp->val;
	q2_head = q2_head->next;
	free(tmp);
	return(i);
}

int transform(char *start, char *end, char **dict, int dict_size)
{
	int	i, dist;
	char	*word;

	if (!start || !end || !start[0] || !end[0] || !dict_size)
		return(0);

	for (i = 0; i < dict_size; i++) {
		if (diff(start, dict[i]) == 1) {
			q1_enq(i);
			q2_enq(1);
		}
	}
	
	while (!q1_emp()) {
		word = dict[q1_deq()];
		dist = q2_deq();
		if (diff(end, word) == 1) {
			clean_q();
			return(dist + 2);
		}
		if (dist == dict_size)
			continue;
		for (i = 0; i < dict_size; i++) {
			if (diff(word, dict[i]) == 1) {
				q1_enq(i);
				q2_enq(dist + 1);
			}
		}
	}

	return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", transform(argv[1], argv[2], argv + 3, argc - 3));
	return(0);
}
