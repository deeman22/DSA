// FRACTIONAL KNAP SACK
/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
*/

class Solution {
public:
    static bool myComp(vector<int> v1 , vector<int> v2){
        return (v1[1] > v2[1]) ;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), myComp);
        int k = truckSize, i=0;
        int ans = 0;
        int n = boxTypes.size();
        while(i < n && k >= boxTypes[i][0] ){
            ans += boxTypes[i][0]*boxTypes[i][1];
            k -= boxTypes[i][0];
            i++;
        }
        if(i<n)ans += boxTypes[i][1]*k;
        return ans;
        
        
    }
};
