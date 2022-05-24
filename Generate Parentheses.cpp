/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    vector<string> ans ;
    
    void fun (string s, int open, int close){
        
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        
        if(open !=0){
            //string s1 = s;
           
            fun(s+'(', open-1, close);
        }
        if(close > open){
            // string s1 = s;
            // s1 += ')';
            fun(s+')', open, close-1);
        }
        
       
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        fun(s, n,n);
        return ans;
    }
};
