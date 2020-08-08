// 时间复杂度O(mn)
// 以当前元素为正方形的右下角
// dp数组记录当前条件下正方形的最大边长
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols));
        for (int i = 0;i<rows;i++){
            for (int j = 0;j<cols;j++){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    }
                }
                maxSide = max(maxSide,dp[i][j]);
            }
        }
        return maxSide*maxSide;
    }
};