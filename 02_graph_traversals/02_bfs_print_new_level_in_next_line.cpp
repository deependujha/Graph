#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *l;

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
            cout << "Node: " << i << "-> ";
            for (auto nbr : l[i])
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    void bfsTraversal()
    {
        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        { // we are running loop to take care for disconnected components
            if (visited[i] == false)
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int len = q.size();
                while (!q.empty())
                {
                    len--;
                    cout << q.front() << " ";
                    for (auto e : l[q.front()])
                    {
                        if (visited[e] == false)
                        {
                            q.push(e);
                            visited[e] = true;
                        }
                    }
                    q.pop();
                    if (len == 0)
                    {
                        cout << endl;
                        len = q.size();
                    }
                }
            }
        }
    }
};

int main()
{
    Graph gr = Graph(5);
    gr.createEdge(0, 3, false);
    gr.createEdge(1, 4, false);
    gr.createEdge(3, 4, false);
    gr.createEdge(0, 1, false);
    gr.createEdge(4, 2, false);
    gr.bfsTraversal();

    // gr.printGraph();
}