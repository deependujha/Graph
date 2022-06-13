#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    int V;        // vertices
    list<int> *l; // dynamic memory allocation in heap
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void createEdge(int node1, int node2, bool directed)
    {
        l[node1].push_back(node2);
        if (directed == false)
            l[node2].push_back(node1);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node- " << i << "-> ";
            for (auto nbr : l[i])
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph gr = Graph(5);
    gr.createEdge(0, 1, false);
    gr.createEdge(2, 1, false);
    gr.createEdge(0, 3, false);
    gr.createEdge(3, 1, true);
    gr.createEdge(4, 2, true);
    gr.printGraph();

    return 0;
}