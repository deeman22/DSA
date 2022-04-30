/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
*/
int histogram (vector<int> arr, int n){
    int i = 0;
    int res = -2;
    int pos, h ;
    
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

int Solution::maximalRectangle(vector<vector<int> > &matrix) {

    int row = matrix.size();
    int col = matrix[0].size();
    int maxArea = -1;
    vector<int> v(col, 0);
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(matrix[i][j]==1)
            {
                v[j] += 1;
            }
            else
                v[j] = 0;
        }
        
        maxArea = max(maxArea, histogram(v, col));
    }
    
    return maxArea;
}
