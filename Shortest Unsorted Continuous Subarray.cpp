//581
/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int s = 0;
        int e = n-1;
        while(s < n-1 && nums[s] <= nums[s+1]) s++;
        if(s == n-1) return 0;
        while(e >0 && nums[e-1] <= nums[e]) e--;
        
        int Min = INT_MAX;
        int Max = INT_MIN;
        for(int i = s; i<= e; i++){
            Min = (nums[i] < Min) ? nums[i] : Min ;
            Max = (nums[i] > Max) ? nums[i] : Max ;
        }
        int i =0;
        int j =n-1;
        while(i <= s && nums[i] <= Min) i++;
        while(j >= e && nums[j] >= Max) j--;
        
        return j-i+1;
        
     
    }
};
