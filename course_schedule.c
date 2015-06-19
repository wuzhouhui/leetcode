/*
 * wrong answer 
 */
#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif 

struct node {
	int	val;
	struct node *next;
};

static struct node *accessed, *path, *tail;

static has_prereq(int **prerequisites, int prerequisitesRowSize, int k)
{
	int	i;
	for (i = 0; i < prerequisitesRowSize; i++) {
		if (prerequisites[i][0] != k)
			continue;
		return(i);
	}
	return(-1);
}

static int is_accessed(int k)
{
	struct node *t = accessed;
	while (t) {
		if (t->val == k)
			return(1);
		t = t->next;
	}
	return(0);
}

static int in_path(int k)
{
	struct node *t = path;
	while (t) {
		if (t->val == k)
			return(1);
		t = t->next;
	}
	return(0);
}

bool canFinish(int numCourses, int **prerequisites,
		int prerequisitesRowSize, int prerequisitesColSize)
{
	if (numCourses <= 1 || prerequisitesRowSize <= 1)
		return(1);

	int	i, next, start, res;
	struct node *t;

	accessed = path = 0;
	for (i = 0; i < numCourses; i++) {
		start = has_prereq(prerequisites, prerequisitesRowSize, i);
		if (start < 0 || is_accessed(i))
			continue;
		while (start >= 0) {

			t = malloc(sizeof(struct node));
			t->val = prerequisites[start][0];
			t->next = path;
			path = t;
			if (!tail)
				tail = path;

			next = prerequisites[start][1];
			if (in_path(next)) {
				res = 0;
				goto clean;
			}
			if (is_accessed(next))
				break;
			start = has_prereq(prerequisites,
					prerequisitesRowSize,
					prerequisites[start][1]);
		}
		if (tail) {
			tail->next = accessed;
			accessed = path;
		}
		path = tail = 0;
	}
	res = 1;
clean:
	while (path) {
		t = path;
		path = path->next;
		free(t);
	}
	while (accessed) {
		t = accessed;
		accessed = accessed->next;
		free(t);
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	/*
	int	x[] = { 1, 0 };
	int	y[] = { 0, 1 };
	int	*p[] = { x, y };
	printf("%d\n", canFinish(2, p, 2, 2));
	*/
	int	**prerequisites = malloc(4 * sizeof(int *));
	prerequisites[0] = malloc(2 * sizeof(int));
	prerequisites[1] = malloc(2 * sizeof(int));
	prerequisites[2] = malloc(2 * sizeof(int));
	prerequisites[3] = malloc(2 * sizeof(int));
	prerequisites[0][0] = 0;
	prerequisites[0][1] = 1;
	prerequisites[1][0] = 3;
	prerequisites[1][1] = 2;
	prerequisites[2][0] = 1;
	prerequisites[2][1] = 3;
	prerequisites[3][0] = 3;
	prerequisites[3][1] = 1;
	printf("%d\n", canFinish(4, prerequisites, 4, 2));
	return(0);
}
