// 时间复杂度O（MN）
// 空间复杂度O（MN）
class Solution {
public:
    void DFSmaking(vector<vector<char>>& grid , int i, int j){
        // 数组指针越界，当前位置不为1时，返回
        if (i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        DFSmaking(grid,i+1,j);
        DFSmaking(grid,i-1,j);
        DFSmaking(grid,i,j+1);
        DFSmaking(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();    // 二维数组行数
        if (n == 0) return 0;
        int m = grid[0].size(); // 二维数组列数
        for (int i =0;i<n;i++){
            for (int j =0;j<m;j++){
                if (grid[i][j] == '1'){
                    count++;
                    DFSmaking(grid,i,j);
                }
            }
        }
        return count;
    }
};