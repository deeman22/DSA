/*
Problem Description

Given a string A consisting only of lowercase characters, we need to check whether it is possible to make 
this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.
*/
bool check (string s, int i, int j){

    while(i<=j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int solve(string A) {
  
    int i=0;
    int j = A.size()-1;
    
    while(i <= j){
        if(A[i] == A[j]){
            i++;
            j--;
        }
        else{
           if (check(A, i+1, j) || check(A,i, j-1)) return true;
           else return false;
        }
    }
    return true;
}
