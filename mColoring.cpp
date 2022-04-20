bool isSafe (int node, int color, int n, int colors[], bool graph[101][101]){
    
    for(int i =0; i<n; i++){
        if(graph[node][i] == 1 && colors[i] == color)
            return false;
    }
    return true;
}

bool helper(int node, int n, int m, int colors[], bool graph[101][101]){
    
    if(node == n){
        return true;
    }
    
    for(int color=1; color<= m; color++ ){
        
        if( isSafe(node, color, n, colors, graph) ){
            
            colors[node] = color;
            if(helper(node+1, n, m, colors, graph)) return true;
            colors[node] = 0; // if not true
            
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int colors[n] = {0};
    return helper(0, n, m, colors, graph);
    
}
