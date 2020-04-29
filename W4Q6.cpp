/*
    Maximal Square

    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    Example:
    Input: 
        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0
    Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int ans=0;
        int dp[matrix.size()][matrix[0].size()];

        for(int i=0; i<matrix.size(); i++){
            dp[i][0] = matrix[i][0]-'0';
            ans = max(ans, dp[i][0]);
        }

        for(int j=0; j<matrix[0].size(); j++){
            dp[0][j] = matrix[0][j]-'0';
            ans = max(ans, dp[0][j]);
        }

        for(int i=1; i<matrix.size(); i++)
            for(int j=1; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]=='1')
                {
                    int m = min(dp[i-1][j], dp[i][j-1]);
                    m = min(m, dp[i-1][j-1]);
                    dp[i][j] = m+1;

                    ans = max(ans, m+1);
                }
                else
                    dp[i][j]=0;   
            }
        return ans*ans;
    }
};