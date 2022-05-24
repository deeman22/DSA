/*
Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
 
Example 1:

Input: str = “0102010”
Output: 2
Explanation: Substring str[2, 4] = “102” and
substring str[4, 6] = “201” has equal number
of 0, 1 and 2 
*/
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        unordered_map< string, int> mp;
        int n = str.size();
        int zero =0, one=0, two =0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(str[i] == '0') zero ++;
            else if(str[i] == '1') one ++;
            else two++;
            
            if(one - zero == 0 && two - one == 0) ans++;
            string key = to_string(one-zero)+'_'+to_string(two-one);
            if(mp.find(key) != mp.end()){
                ans += mp[key];
            }
            mp[key]++;
        }
        return ans;
    }
};
