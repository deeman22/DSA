class Solution {
public:
    unordered_map<string, bool> mp;
    int dp[301];
    
    bool solve(string s, int n, int sz){
        
        if(n == 0) return true;
        
        for(int i=1; i<=n; i++){
            
            if(dp[sz+i] == 0){
                
                if(mp[s.substr(0,i)]){  
                    dp[sz+i] = 1;
                    if(solve(s.substr(i,n), n-i, sz+i))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i< wordDict.size(); i++)
            mp[wordDict[i]] = true;
        
        return solve(s, s.size(), 0);
    }
};
