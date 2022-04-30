/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int i = 0;
        int res = -2;
        int pos, h ;
        int n = arr.size();
        
        stack<int> starts ; // corresponding height starting index
        stack<int> height ;
        
        starts.push(0);
        height.push(arr[0]);
        
        for(i=1; i<n; i++){
            
            if(height.top() < arr[i]){
                height.push(arr[i]);
                starts.push(i);
            }
            
            else if (height.top() > arr[i] ){
                
                while(!height.empty() && height.top() > arr[i])
                {
                    h = height.top(); height.pop();
                    pos = starts.top(); starts.pop();
                    res = max(res, h *(i- pos ) );
                }
                height.push(arr[i]);
                starts.push(pos);
            }
        }
         
        while(!height.empty()){
            h = height.top(); height.pop();
            pos = starts.top(); starts.pop();
            res = max(res, h *(i- pos ) );
        }
        
        return res;
    }
};
