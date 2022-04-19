class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid (int grid[N][N], int r, int c, int num){
        
        for(int i =0; i<9; i++){
            if(grid[i][c] == num)
                return false;
            
            if(grid[r][i] == num)
                return false;
            
            if(grid[3*(r/3)+ i/3][3*(c/3) + i%3] == num)
                return false;
        }
        return true;
       
    }
    bool helper(int grid[N][N]){
       
       
       for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){
               if(grid[i][j] == 0){
                   
                   for(int num =1; num<=9; num++){
                       if(isValid(grid, i, j, num)){
                           
                           grid[i][j] = num ;
                           if(helper(grid))
                                return true;
                            else
                                grid[i][j] = 0;
                       }
                       
                   }
                   return false;
               }
           }
       }
       
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        helper(grid);
        printGrid(grid);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<9; i++){
            for(int j=0; j<6; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
