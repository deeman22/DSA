/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
*/

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack <int> st;
        for(int i=0; i<n; i++) st.push(i);
        
        while(st.size() > 1){
            
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b] == 1 ) st.push(b);
            else st.push(a);
        }
        
        int celeb = st.top() ;
        int peoples = 0;
        
        for(int i=0; i<n ; i++){
            if(M[celeb][i] == 1) return -1;
            if(M[i][celeb] == 1) peoples++;
        }
        if(peoples != n-1) return -1;
        else return celeb;
    }
};
