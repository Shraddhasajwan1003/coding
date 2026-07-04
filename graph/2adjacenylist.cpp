#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeadajacencylist(int n, int m ){
        // n is no of nodes , m is no. of edges , we have 1 based indexing
        vector<int>adj[n+1];//adjacency list, for undirected graph , so each will have to store twice or go through it twice 
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);//skip this for udirected graphs, in this case TC is O(2*E), E is edges or you call it O(2*m)
        }
    }
    int weighted_adjacencylist(int n,int m){
        //While vector<pair<int,int>> adj[n+1] works in many competitive programming environments like GCC, strictly standard C++ prefers vector<vector<pair<int, int>>> adj(n + 1); to avoid Variable Length Array issues
        vector<pair<int,int>>adj[n+1];
        for(int i =0;i<m;i++){
            int u, v ,wt;
            cin>>u>>v>>wt;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }

};

int main() {
    Solution obj;
    // for finding neighbours of second element/node with thier weights
    // for (auto edge : adj[2]) {
    // int neighbor = edge.first;
    // int weight = edge.second;
    // cout << "Node 2 connects to " << neighbor << " with a weight of " << weight << "\n";}


    //Weighted Edge List (Custom Struct)
// If you are running an algorithm that processes edges globally sorted by weight (like Kruskal's Algorithm for Minimum Spanning Trees), it is much easier to use a single list of custom structures.

// Best for: Sorting edges by weight.

//     struct Edge {
//     int u, v, weight;
// };

// vector<Edge> edges;

// for(int i = 0; i < m; i++) {
//     int u, v, w;
//     cin >> u >> v >> w;
//     edges.push_back({u, v, w});
// }
    return 0;
}