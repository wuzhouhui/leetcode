#include <stdlib.h>

#define NEIGHBORS_MAX_SIZE	100

struct UndirectedGraphNode {
	int label;
	struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
	int neighborsCount;
};

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph)
{
	if (!graph)
		return(NULL);

}
