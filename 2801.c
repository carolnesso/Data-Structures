#include <stdio.h>
#include <stdlib.h>

typedef struct adj_list
{
	int data;
	struct adj_list *next;

}adj_list;

typedef struct graph
{
	adj_list **vertices;
	short *visited;

}graph;

adj_list *create_adj_list(int item)
{
	adj_list *new_adj_list = malloc(sizeof(adj_list));
	new_adj_list -> data = item;
	new_adj_list -> next = NULL;

	return new_adj_list;
}

graph *create_graph(int size)
{
	graph *new_graph = malloc(sizeof(graph));
	new_graph -> vertices = malloc(sizeof(adj_list*)*size);
	new_graph -> visited = malloc(size);

	int i;

	for (i = 0; i < size; ++i)
	{
		new_graph -> vertices[i] = create_adj_list(i + 1);
		new_graph -> visited[i] = 0;
	}

	return new_graph;
}

void add_edges(graph *graph, int vertex1, int vertex2)
{
	adj_list *vertex = create_adj_list(vertex2);
	vertex -> next = graph -> vertices[vertex1];
	graph -> vertices[vertex2] = vertex;

	
	// vertex = create_adj_list(vertex1);
	// vertex -> next = graph -> vertices[vertex2];
	// graph -> vertices[vertex2] = vertex;

}

void sorted(adj_list *aux)
{
	adj_list *aux2 = aux;

	while(aux != NULL)
	{
		while(aux2 != NULL)
		{
			if (aux2 -> data > aux -> data)
			{
				int n_aux = aux2 -> data;
				aux2 -> data = aux -> data;
				aux -> data = n_aux;
			}
			aux2 = aux2 -> next;
		}

		aux = aux -> next;
	}
}

void sorted_graph(graph *graph, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		adj_list *aux = graph -> vertices[i] -> next;
		sorted(aux);
	}
}

void dfs(graph *graph, int source)
{
	graph -> visited[source] = 1;
	printf("%d\n", source);

	adj_list *adj_list = graph -> vertices[source];
	printf("aj%d\n", adj_list ->data);

	while(adj_list != NULL)
	{
		if (!graph -> visited[adj_list -> data])
		{
			printf("ss=%d\n", source);
			dfs(graph, adj_list -> data);
		}

		adj_list = adj_list -> next;
	}
}

int main()
{
	int n, p, v1, v2;
	scanf("%d %d", &n, &p);

	graph *universe = create_graph(p);

	int i;
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &v1, &v2);
		add_edges(universe, v1, v2);
		printf("%d %d\n", v1, v2);
	}

	sorted_graph(universe, n);

	dfs(universe, 0);

	return 0;
}