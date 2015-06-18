#include <stdlib.h>

#define NEIGHBORS_MAX_SIZE	100

struct UndirectedGraphNode {
	int	label;
	struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
	int	neighborsCount;
};

struct link_node {
	struct UndirectedGraphNode *val;
	struct link_node *next;
};

static struct link_node *head;

static struct UndirectedGraphNode *is_accessed(int label)
{
	struct link_node *t = head;

	while (t) {
		if (t->val->label == label)
			return(t->val);
		t = t->next;
	}
	return(0);
}

static void add_accessed(struct UndirectedGraphNode *graph)
{
	struct link_node *t = malloc(sizeof(struct link_node));
	t->val = graph;
	t->next = head;
	head = t;
}

static struct UndirectedGraphNode *do_clone(struct UndirectedGraphNode *graph)
{
	if (!graph)
		return(0);

	struct UndirectedGraphNode *new_graph;
	int	i;

	if (new_graph = is_accessed(graph->label))
		return(new_graph);


	new_graph = malloc(sizeof(struct UndirectedGraphNode));
	new_graph->label = graph->label;
	new_graph->neighborsCount = graph->neighborsCount;
	add_accessed(new_graph);
	for (i = 0; i < graph->neighborsCount; i++)
		new_graph->neighbors[i] = do_clone(graph->neighbors[i]);

	return(new_graph);
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph)
{
	if (!graph)
		return(0);

	head = 0;

	struct link_node *t;
	struct UndirectedGraphNode *new_graph = do_clone(graph);

	while (head) {
		t = head;
		head = head->next;
		free(t);
	}

	return(new_graph);
}

int main(void)
{
	struct UndirectedGraphNode graph;
	struct UndirectedGraphNode *new_graph;

	graph.label = 0;
	graph.neighborsCount = 2;
	graph.neighbors[0] = &graph;
	graph.neighbors[1] = &graph;

	new_graph = cloneGraph(&graph);
	return(0);
}
