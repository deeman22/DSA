class Solution{
public:
    unordered_map<int, bool> hs;
    bool solve(int indx, int &left, int &right, int n, int arr[]){
        
        
        
        
        for(int i = indx; i<n; i++){
            
            if(hs[left+ arr[i]] || hs[right-arr[i]]) continue;
            
            if(left + arr[i] == right-arr[i])
                return true;
            
            if(left + arr[i] < right-arr[i]){
                left += arr[i];
                right -= arr[i];
            
                if( solve(i+1, left, right, n, arr))
                    return true;
            
                hs[left] = hs[right] = true;
                left -= arr[i];
                right += arr[i];
                
            }
        }
        if(left == right) return true;
        else return false;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int right = 0;
        int left= 0;
        for(int i=0; i<N; i++) right += arr[i];
        
        return solve(0, left, right, N, arr);
    }
};
