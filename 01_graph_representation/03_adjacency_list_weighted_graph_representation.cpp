// Adjacency list for weighted graph

#include <iostream>
#include <list>
using namespace std;

class WeightedGraph
{
private:
    int V;
    list<pair<int, int>> *l;

public:
    WeightedGraph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void createEdge(int node1, int node2, bool directed, int weight)
    {
        l[node1].push_back({node2, weight});
        if (directed == false)
        {
            l[node2].push_back({node1, weight});
        }
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node: " << i << "-> ";
            for (auto nbr : l[i])
            {
                cout << "(" << nbr.first << ", " << nbr.second << "); ";
            }
            cout << endl;
        }
    }
};

int main()
{
    WeightedGraph gr = WeightedGraph(5);
    gr.createEdge(0, 1, true, 10);
    gr.createEdge(2, 4, false, 14);
    gr.createEdge(3, 1, true, 10);
    gr.createEdge(1, 2, false, 3);
    gr.createEdge(0, 4, true, 42);
    gr.printGraph();
    return 0;
}