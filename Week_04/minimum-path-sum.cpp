// 1. 当前元素对应的最小路径与相邻元素对应的最小路经有关，因此采用动态规划的方法
// 2. 第一行和第一列中元素对应的最短路径，只与该路径上的元素有关，且答案唯一，将第一行第一列所有元素相加得到最短路径
// 3. 不在第一行和第一列的元素对应的最短路径，与其相邻的元素对应的最短路径有关，相邻元素指的是其左侧元素最短路径和上方元素最短路径。选取其中的最小值，与当前元素相加得到当前元素对应的最短路径。
// 4. 新建二维数组dp用于存放各元素对应的最短路径 
// 时间复杂度O(mn)
// 空间复杂度O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int rows = grid.size();
        int columns = grid[0].size();
        auto dp = vector<vector<int>>(rows,vector<int> (columns)); // 这里出过错，注意这种构造方式
        dp[0][0] = grid[0][0];
        for (int i = 1;i<rows;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1;j<columns;j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for (int i = 1;i<rows;i++){
            for (int j = 1;j<columns;j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[rows-1][columns-1];
    }
};