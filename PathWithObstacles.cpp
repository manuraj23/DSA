#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // If the starting cell has an obstacle, no paths are possible
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        // Initialize dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        // Initialize the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Initialize the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        // Fill the dp array
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }

int main() {
    vector<vector<int>> grid = {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 }
    };
    
    cout << uniquePathsWithObstacles(grid);
    
    return 0;
}