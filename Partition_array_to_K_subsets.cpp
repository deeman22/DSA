class Solution{
  public:
    bool taken[11];
    bool ans;
    
    void helper(int a[], int n, int k, int target, int k_now, int sum){
        
        if(k_now == k-1 ) {
            ans = true;
            return;
        }
        
        if(sum > target){
            return;
        }
        
        if(sum == target){
            helper(a, n, k, target, k_now+1, 0);
            if(ans==true) return;
        }
        
        for(int i=0; i<n; i++){
            if(!taken[i]){
                taken[i] = true;
                helper(a, n, k, target, k_now, sum+a[i]);
                if(ans ) return ;
                taken[i] = false;
            }
        }
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        //Your code her
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i];
        }
         
        if(sum%k!=0)
            return false;
        if(k>n) return false;
        if(k == 1) return true;
        
        int d = sum/k;
        ans = false;
        memset(taken, false, sizeof(taken));
        
        
        
        helper(a, n, k, d, 0, 0);
        return ans;
    }
};
