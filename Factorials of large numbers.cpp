class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int sz = 1;
        
        
        for(int x =2; x<=N; x++){
            int carry = 0;
            for(int i = sz-1; i>=0; i--){
                int tmp = (ans[i]*x + carry ) ;
                carry = tmp /10 ;
                ans[i] = tmp%10 ;
            }
            while(carry){
                ans.insert(ans.begin(), carry %10 );
                carry /= 10;
                sz++;
            }
        }
        return ans;
    }
};
