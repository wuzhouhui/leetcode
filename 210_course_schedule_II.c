#include <stdlib.h>

#define STEP 8

static int *sche, p, maxp;

static void add_ans(int n)
{
	if (!sche) {
		maxp = STEP;
		p = 0;
		sche = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += STEP;
		sche = realloc(sche, maxp * sizeof(int));
	}
	sche[p++] = n;
}
int *findOrder(int numCourses, int **prerequisites,
		int prerequisitesRowSize, int prerequisitesColSize,
		int *returnSize)
{
	if (!numCourses) {
		*returnSize = 0;
		return(0);
	}
	
	int	*degrees, i, j , all_done;
	int	res;

	degrees = calloc(numCourses, sizeof(int));
	sche = 0;
	for (i = 0; i < prerequisitesRowSize; i++)
		degrees[prerequisites[i][0]]++;
	while (1) {
		all_done = 1;
		for (i = 0; i < numCourses; i++) {
			if (degrees[i] != -1)
				all_done = 0;
			if (degrees[i] == 0)
				break;
		}
		if (all_done) {
			res = 1;
			goto ret;
		}
		if (i >= numCourses) {
			res = 0;
			goto ret;
		}
		degrees[i] = -1;
		add_ans(i);
		for (j = 0; j < prerequisitesRowSize; j++)
			if (prerequisites[j][1] == i)
				degrees[prerequisites[j][0]]--;
	}
ret:
	free(degrees);
	if (!res) {
		*returnSize = 0;
		if (sche)
			free(sche);
		return(0);
	}
	*returnSize = p;
	return(sche);
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
	return(0);
}
