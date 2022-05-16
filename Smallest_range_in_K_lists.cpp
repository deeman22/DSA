#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        pair <int, int> ans;
        ans = {0, INT_MAX} ;
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
        // value , row , index
        int max = 0;
        
        for(int i=0;i<k;i++){
            pq.push( {a[i][0], {i,0}} );
            
            if(a[i][0] > max) 
                max = a[i][0] ;
        }
        
        while(!pq.empty()){
            
            //pair<int, pair<int, int> p = pq.top();
            auto p = pq.top();
            int min = p.first;
            int row = p.second.first;
            int index = p.second.second;
            pq.pop();
            
            
            if(ans.second - ans.first > max - min)
            {   
                ans.first = min;
                ans.second = max;
            }
            //cout << ans.second - ans.first<<". ";
            if(index >= n-1) 
                return ans;
            
            else{
                pq.push({ a[row][index+1],{row,index+1}});
                if(a[row][index+1] > max)
                    max = a[row][index+1];
            } 
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}
