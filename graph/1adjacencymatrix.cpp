#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void weightedgraph_adjacency_matrix(int n, int m){
        int adj[n+1][m+1];
        for(int i=0;i<m;i++){
            int u, v, wt;
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
    }
};

int main() {
    Solution obj;

    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][m+1];//one based indexing , input bhi 1 to n dia tha 
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
//for zero based indexing
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    // Create an n x n adjacency matrix initialized to 0.
    // This replaces `int adj[n][n]` to avoid Variable Length Array (VLA) issues.
    vector<vector<int>> adj(n, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        // Convert 1-based input to 0-based indexing by subtracting 1.
        // (Skip this step if the input vertices are already 0 to n-1)
        u--; 
        v--; 
        
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove for directed graph
    }
    
    return 0;
}

    