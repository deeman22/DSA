// https://www.interviewbit.com/problems/distribute-candy/

int candy(vector<int> &A) {

    int n = A.size();
    vector<int> l2r(n,1);
    vector<int> r2l(n,1);
    

    for(int i=1; i<n; i++)
    {
        if(A[i]>A[i-1]) 
            l2r[i] = l2r[i-1]+1;
    }
    
    for(int i=n-2; i>=0; i--)
    {
        if(A[i]>A[i+1]) 
            r2l[i] = r2l[i+1]+1;
    }

    int ans = 0;
    for(int i=0; i<n; i++) 
        ans += max(l2r[i], r2l[i]);

    return ans;
}
