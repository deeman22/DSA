// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int res = 1;

      // top down
//     void fun(vector<int>& nums, int indx, int maxNow,int count, int n){
        
//         if(indx == n){
//             if(count > res)
//                 res = count;
//             return;
//         }
        
//         for(int i = indx; i<n; i++){
//             if(maxNow < nums[i]){ 
//                 fun(nums, i+1, nums[i], count+1, n);
//             }
//         }
//         if(count > res) res = count;
        
//     }
    
    // bottom up
    int helper (vector<int>& nums, int indx, int prevIndx, int n, vector<vector<int>> &hs){
        
        if(indx == n) return 0;
        if(hs[indx][prevIndx+1] != -1) return hs[indx][prevIndx+1];
        int len = 0 + helper(nums, indx+1, prevIndx, n, hs);
        if(prevIndx == -1 || nums[indx] > nums[prevIndx]){
            len = max(len,1+ helper(nums, indx+1, indx, n, hs));
        }
        return hs[indx][prevIndx+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        vector<vector<int>> hs (n, vector<int>(n+1,-1));
        
        
        //fun(nums, 0, INT_MIN, 0, nums.size());
        //return res;
        //return helper(nums, 0, -1, n, hs);
        
        
        // using set
        set<int> lis;
	    for ( auto num : nums ) {
		    if( lis.count( num ) ) continue;
            
		    lis.insert( num );
		    auto it = lis.upper_bound( num );
		    if( it != lis.end() )
            lis.erase( it );
	    }
	    return lis.size();
    }
};
