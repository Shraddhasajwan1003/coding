#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsiterative(int start, int v, vector<int> adj[], vector<int> dfs)
    {
        vector<int> visited(v, 0);
        visited = {0};
        stack<int> st;
        st.push(start);
        while (!st.empty())
        {
            int node = st.top();
            s.pop();
            if (!visited[node])
            {
                visited[node] = 1;
                dfs.push_back(node);
                // Traverse all neighbors in REVERSE order.
                // Because a stack is Last-In-First-Out (LIFO), pushing the last neighbor
                // first ensures the first neighbor is popped first. This makes the
                // iterative output match the exact order of the recursive version.
                for (int i = adj[node].size() - 1; i >= 0; --i)
                {
                    int u = adj[node][i];
                    if (!visited[u])
                    {
                        st.push(u);
                    }
                }
            }
        }
    }


};

int main()
{
    Solution obj;

    return 0;
}