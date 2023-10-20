#include <stdio.h>
#include <stdlib.h>

int parentlist[255] = {};

struct edge
{
	int source;
	int destination;
};

struct graph
{
	int verticescount;
	int edgescount;
	edge *edges;
};

graph *creategraph(int verticescount, int edgescount)
{
	graph *newgraph = (graph*)malloc(sizeof(graph));
	newgraph->verticescount = verticescount;
	newgraph->edgescount = edgescount;
	newgraph->edges = (edge*)malloc(sizeof(edge));
	return newgraph;
}

void makeset(int vcount)
{
	for(int i=0; i<vcount; i++)
	{
		parentlist[i] = i;
	}
}

int findparent(int vertex)
{
	if(parentlist[vertex] == vertex)
	{
		return vertex;
	}
	
//	return findparent(parentlist[vertex]);
	parentlist[vertex] = findparent(parentlist[vertex]);
	return parentlist[vertex];
}

void join(int vertexA, int vertexB)
{
	int parentA = findparent(vertexA);
	int parentB = findparent(vertexB);
	parentlist[parentA] = parentB;
}

bool issameset(int vertexA, int vertexB)
{
	return (findparent(vertexA) == findparent(vertexB)) ? true : false;
}

bool Union(graph *graph)
{
	for(int i=0; i<graph->edgescount; i++)
	{
		int sourceparent = findparent(graph->edges[i].source);
		int destinationparent = findparent(graph->edges[i].destination);
		
		if(sourceparent == destinationparent)
		{
			return true;
		}
		parentlist[sourceparent] = destinationparent;
	}
	return false;
}

bool iscyclic(graph *graph)
{
	makeset(graph->verticescount);
	return Union(graph);
}

int main()
{
	makeset(5);
	join(0,1);
	join(1,2);
	join(2,3);
	join(3,4);
	
	if(issameset(0,4)) puts("True\n");
	else puts("False\n");
	
	graph *graph = creategraph(6,5);
	graph->edges[0].source = 0;
	graph->edges[0].destination = 1;
	
	graph->edges[0].source = 0;
	graph->edges[0].destination = 2;
	
	graph->edges[0].source = 1;
	graph->edges[0].destination = 3;
	
	graph->edges[0].source = 3;
	graph->edges[0].destination = 4;
	
	graph->edges[0].source = 2;
	graph->edges[0].destination = 5;
	
	if(iscyclic(graph)) puts("This graph is cyclic");
	else puts("This graph isn't cyclic");
		
	return 0;
}
