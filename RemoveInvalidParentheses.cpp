class Solution {
public:
    set<string> ans, visited;
    int minRemove (string s){
        
        int n = s.length();
        if(n==0) return 0;
        
        stack<char> st;
        int i =0;
        while(i<n){
            if(s[i] == '(' || s[i]== ')'){
                if(st.empty() || s[i]== '(' )
                    st.push(s[i]);
                else if(st.top() == '(' && s[i] ==')')
                    st.pop();
                else 
                    st.push(s[i]);
            }
            i++;
        }
        return st.size() ;
    }
   
    void solve(string s, int mr){
        
        if(visited.find(s) != visited.end())
            return;
        
        visited.insert(s);
        
        if(mr == 0){
            if(minRemove(s) == 0){
                ans.insert(s);
                return;
           }
           else
               return;
        }
        for(int i= 0; i<s.size(); i++){
            
            if(s[i]=='(' || s[i]==')'){
                string left = s.substr(0,i);
                string right = s.substr(i+1);
                solve(left+right, mr-1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int minR = minRemove(s);
        solve(s, minR);
        vector<string> a;
        for(auto i:ans)
            a.push_back(i);
        return a;
    }
};
