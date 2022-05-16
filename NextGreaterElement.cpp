#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        //int n = arr.size();
        vector<long long> ans(n,0);
        
        for(int i=n-1; i>=0; i--){
            
            if(st.empty()){
                ans[i] = -1;
                st.push(arr[i]);
            } 
            else {
                while(!st.empty() && st.top() <= arr[i]) st.pop();
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
                st.push(arr[i]);
            }
        
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  
