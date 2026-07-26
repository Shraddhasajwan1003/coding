#include <bits/stdc++.h>
using namespace std;
//BFS
class Solution {
public:
    vector<int>BFSofGRAPH(int V ,vector<int>adj[]){//no of vertices, and adjacency list will be given 
        int visited[n]={0};
        visited[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;//bfs ka vector, used in adjacency list ko access krke neighbour dhundne me 
        while(!q.empty()){//empty nhi hoga tbhi ye folloe ho payega 
            int node =q.front();//first element jo dala h use pop krdia , FIFO
            q.pop();
            bfs.push_back(node)//node vo element h jiske abhi neighbour dhundne padege
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }

        }
        
        return bfs;
    }
};

int main() {
    Solution obj;
    int n; cin>>n;
    obj.BFSofGRAPH(int n,vec);
    vector<int>result;
    for(int it : result){
        cout<<it<<" ";

    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count connected components in an undirected graph
    int countComponents(int V, vector<vector<int>>& edges) {
        
        // Create adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Vector to keep track of visited nodes
        vector<int> visited(V, 0);
        
        // Variable to count the number of connected components
        int components = 0;

        // Traverse all nodes in the graph
        for (int i = 0; i < V; ++i) {

            // If the node is not visited, it's a new component
            if (!visited[i]) {
                components++;

                // Start BFS from this node
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                // Perform BFS traversal
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Visit all unvisited neighbors
                    for (auto &nbr : adj[node]) {
                        if (!visited[nbr]) {
                            visited[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }

        // Return the total number of connected components
        return components;
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    // Create solution object
    Solution sol;

    // Print the number of connected components
    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}
