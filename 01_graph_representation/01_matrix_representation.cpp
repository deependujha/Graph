// A matrix representation of a graph.
// nodes are numbered from 0 to node-1.
#include <iostream>
using namespace std;

int main()
{
	int nodes;
	cin >> nodes;

	int matrix[nodes][nodes];
	int edges;
	cin >> edges;
	while (edges--)
	{
		int node1, node2;
		cin >> node1 >> node2;
		bool directed;
		cin >> directed;
		matrix[node1][node2] = 1;
		if (directed)
			matrix[node2][node1] = 1;
	}

	return 0;
}