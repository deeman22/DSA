/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
*/

class Solution {
public:
    //bool isSub
    int repeatedStringMatch(string a, string b) {
        
        int i= 0;
        string a1="";
        
        while(a1.size() < b.size()){
            a1 += a;
            i++;
        }
        // std::size_t found2 = a1.find(b);
        // found2!=std::string::npos
        size_t found = a1.find(b);
        if (found != string::npos) return i;
        a1 += a; i++;
        found = a1.find(b);
        if (found != string::npos) return i;
        else return -1;
    }
};
