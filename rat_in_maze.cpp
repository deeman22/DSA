#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    int visited[5][5];
    
    void solve (vector<vector<int>> &m, int n, int i, int j ,string s ) {
        
        //if(visited[i][j]==1) return ;
        if(m[i][j] == 0) return;
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return ;
        }
        
        // down
        if(i+1 < n && visited[i+1][j]== 0  && m[i+1][j] == 1){ //&& visited[i+1][j]== 0
            visited[i][j] = 1;
            solve(m, n, i+1, j, s+'D');
            visited[i][j] = 0;
        }
        //left
        if( j-1 >=0 &&  visited[i][j-1]==0  &&m[i][j-1] == 1 ){ //&& visited[i][j-1]==0 
            visited[i][j] = 1;
            solve(m, n, i, j-1, s+'L');
            visited[i][j] = 0;
        }
        // right
        if( j+1<n && visited[i][j+1]==0  && m[i][j+1] == 1 ){ //&& visited[i][j+1]==0 
            visited[i][j] = 1;
            solve(m, n, i, j+1, s+'R');
            visited[i][j] = 0;
        }
        // up
        if(i-1 >= 0 && visited[i-1][j]==0 && m[i-1][j] == 1){ //&& visited[i-1][j]==0 
            visited[i][j] = 1;
            solve(m, n, i-1, j, s+'U');
            visited[i][j] = 0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n ) {
        // Your code goes here
        //int visited[5][5];
        memset(visited, 0 , sizeof(visited));
        solve(m, n, 0, 0,"");
        return ans;
    }
};

int main(){
 return 0;
