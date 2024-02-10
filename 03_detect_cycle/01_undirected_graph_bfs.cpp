#include <bits/stdc++.h>
using namespace std;

// question link: https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph-_758967
class Graph
{

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        // Write your code here.
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                queue<pair<int, int>> q;
                q.push({-1, i});
                visited[i] = true;
                while (!q.empty())
                {
                    for (auto &e : adj[q.front().second])
                    {
                        if (visited[e] == true && q.front().first != e)
                        {
                            return true;
                        }
                        if (visited[e] == false)
                        {
                            visited[e] = true;
                            q.push({q.front().second, e});
                        }
                    }
                    q.pop();
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}