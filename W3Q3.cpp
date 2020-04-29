/*
    Number of Islands

    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    Example 1:
    Input:
    11110
    11010
    11000
    00000
    Output: 1

    Example 2:
    Input:
    11000
    11000
    00100
    00011
    Output: 3
*/

class Solution {
public:
    void merge(vector<vector<char>>& grid, int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();

        if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1')
            return;

        grid[i][j]='X';

        merge(grid, i-1, j);
        merge(grid, i+1, j);
        merge(grid, i, j-1);
        merge(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid.size()==0 || grid[0].size()==0)
            return 0;
 
        int m = grid.size();
        int n = grid[0].size();

        int count=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    merge(grid, i, j);
                }
            }
        }

    return count;
        
    }
};