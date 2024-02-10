#include <bits/stdc++.h>
using namespace std;

bool dfsCode(int V, vector<int> adj[])
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            stack<pair<int, int>> st;
            st.push({-1, i});

            while (!st.empty())
            {
                int currTopEle = st.top().second;
                int currTopEleParent = st.top().first;
                visited[currTopEle] = true;
                st.pop();
                for (auto &e : adj[currTopEle])
                {
                    if (visited[e] == false)
                    {
                        st.push({currTopEle, e});
                    }
                    else
                    {
                        // visited == true
                        if (currTopEleParent != e)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
     
    return 0;
}