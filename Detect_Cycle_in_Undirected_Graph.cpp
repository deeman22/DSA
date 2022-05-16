#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V+1] = {0};
        
        //queue<pair<int, int>> q; // curr, prev
        //q.push(0,-1);
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                queue<pair<int, int>> q; // curr, prev
                q.push({i, -1});
                
                while(!q.empty()){
                    
                    int curr = q.front().first ;
                    int prev = q.front().second ;
                    q.pop();
                    visited[curr] = 1;
                    
                    for(auto it: adj[curr]){
                        if(!visited[it]){
                            q.push({it,curr});
                        }
                        else if( it != prev) return true;
                    }
                    
                }
                
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
