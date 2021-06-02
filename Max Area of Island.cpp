class Solution {
public:
    int maxArea(int i,int j,vector<vector<int>>& grid){
        int count =0;
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return 0;
        grid[i][j]=0;//once we traverse a cell we replace it with 0 so that we dont traverse it again
        count+=maxArea(i+1,j,grid);
        count+=maxArea(i-1,j,grid);
        count+=maxArea(i,j+1,grid);
        count+=maxArea(i,j-1,grid);
        return 1+count;//1 +  is for the current cell
        
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        // we are traversing through grid and if we hit an island i.e. 1 
        //we are calling the maxArea that will traverse all the 1's and return the area
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                
                if(grid[i][j]){
                    ans = max(ans , maxArea(i,j,grid));
                }
            }
        }
        return ans;
    }
};
//Time Complexity: O(N * M) where N and M are the lengths of the sides of the grid
//Space Complexity: O(L) where L is the size of the largest island, representing the maximum recursion stack
//or O(N * M + L) if we create an N * M matrix in order to not modify the input