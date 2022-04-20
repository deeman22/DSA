
class Solution
{
    public:
    set<string> st ;
    //Function to find the largest number after k swaps.
    
    char findMax(string &s, int indx, int n){
        
        int maxx = s[indx];
        for(int i = indx+1; i<n; i++){
            if(s[i]>maxx)
                maxx = s[i];
        }
        return maxx;
    }
    
    void fun(string &s, int k, int indx, int n, string &ans){
        
        if(k == 0 || indx == n) {
            if(s>ans) ans = s;
            return;
        }
        
        char maxElt = findMax(s, indx, n);
        
        if(maxElt != s[indx]){
            for(int i = n-1; i>indx; i--){
                
                if(s[i]==maxElt) {
                    swap(s[indx], s[i]);
                   // if(s>ans) ans = s;
                    
                    fun(s, k-1, indx+1, n, ans);
                    swap(s[indx], s[i]);
                }
            }
        }
        else{
            fun(s, k, indx+1, n, ans);
        }
    }
    string findMaximumNum(string &str, int k)
    {
       // code here.
       string ans = str;
       fun(str, k, 0, str.length(), ans);
       //auto i = st.begin();
       
       return ans;
    }
};
