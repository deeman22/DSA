/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.
*/

class Solution
{
    public:
        int trailz(int n){
           int s=0;
            while(n>=5){
               s+=(n/5);
               n/=5;
            }
           return s;
        }
        
        int findNum(int n)
        {
        //complete the function here
            // int i =1;
            // int fiv = 5;
            // int count = 1;
            
            // while(count < n){
            //     i++;
            //     fiv = i*5 ;
            //     count = trailz(fiv);
            // }
            // return fiv;
            
            int low = 1, high = n*5 , mid, temp ;
            while(low <= high){
                
                mid = low+(high-low)/2;
                temp = trailz(mid) ;
                if(temp == n && mid%5 == 0) return mid;
                else if (temp < n) low = mid+1;
                else high = mid-1;
            }
            //return mid+1;
        }
};
