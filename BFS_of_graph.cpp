/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, 
from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
*/
class Solution {
 public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
    //     vector<int> visited(V+1, 0);
    //     vector<int> ans;
    //     // for(int i=0; i< V; i++)}{
            
    //     // }
        
    //     for(int i =0; i<V; i++){
            
    //         if(!visited[i]){
                
    //             queue<int> q;
    //             q.push(i);
    //             visited[i] =1;
                
    //             while(!q.empty()){
                    
    //                 int cur = q.front();
    //                 ans.push_back(cur);
    //                 q.pop();
    //                 //visited[cur] =1;
                    
    //                 for(auto j: adj[cur]){
    //                     if(!visited[j]){
    //                         q.push(j);
    //                         visited[ j ] = 1;
    //                     }
    //                 }
    //             }
                
    //         }
    //   }
        int i=0;
        queue<int> q;
        q.push(i);
        visited[i] =1;
        while(!q.empty()){
                    
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            //visited[cur] =1;
            
            for(auto j: adj[cur]){
                if(!visited[j]){
                    q.push(j);
                    visited[ j ] = 1;
                }
            }
        }
        return ans;
    }
};
