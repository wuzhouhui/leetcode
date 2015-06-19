#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif 

bool canFinish(int numCourses, int **prerequisites,
		int prerequisitesRowSize, int prerequisitesColSize)
{
	if (numCourses <= 1 || prerequisitesRowSize <= 1)
		return(1);
	
	int	*degrees, i, j , all_done;

	degrees = calloc(numCourses, sizeof(int));
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
			free(degrees);
			return(1);
		}
		if (i >= numCourses) {
			free(degrees);
			return(0);
		}
		degrees[i] = -1;
		for (j = 0; j < prerequisitesRowSize; j++)
			if (prerequisites[j][1] == i)
				degrees[prerequisites[j][0]]--;
	}
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
