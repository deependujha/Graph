#include <iostream>
#include <list>
#include <stack>
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

    void dfsTraversalIterative()
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
        { // we are running loop to take care for disconnected components
            if (visited[i] == false)
            {
                stack<int> st;
                st.push(i);
                visited[i] = true;
                while (!st.empty())
                {
                    cout << st.top() << " ";
                    int val = st.top();
                    st.pop();
                    for (auto e : l[val])
                    {
                        if (visited[e] == false)
                        {
                            st.push(e);
                            visited[e] = true;
                        }
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
    gr.createEdge(3, 4, false);
    gr.createEdge(0, 1, false);
    gr.createEdge(4, 2, false);
    gr.createEdge(1, 4, false);
    // gr.bfsTraversal();
    gr.dfsTraversalIterative();

    // gr.printGraph();
}