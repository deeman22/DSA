/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
*/
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        int len = s.length();
        
        int ans = 0;
        for(int i=0; i<len; i++){
            if(s[i] == '(' || st.empty()) 
                st.push(i);
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    int end = st.empty()?-1:st.top();
                    ans = max(ans, i-end);
                }
                else st.push(i);
            }
        }
        return ans;
    }
};
