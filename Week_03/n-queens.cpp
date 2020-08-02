class Solution {
public:
    // 设置结果变量
    vector<vector<string>> res;
    // 设置回溯函数
    void backtrack(vector<string>& board,int row){ // 指针变量只占4个字节，远远小于普通变量
        // 设置停止条件
        if (row == board.size()){
            res.push_back(board);
            return;
        }
        // 获取棋盘列数
        int n = board[row].size();
        // 回溯主体
        for (int col=0;col<n;col++){
            if (!isValid(board,row,col)){
                continue;
            }
            board[row][col] = 'Q';
            backtrack(board,row+1);
            board[row][col] = '.';
        }
    }
    // 设置辅助判断函数
    bool isValid(vector<string>& board,int row,int col){
        int n = board[row].size();
        // 检查当前列是否含有皇后
        for (int i = row - 1;i>=0;i--){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        // 检查当前元素右上方是否有皇后
        for (int i = row-1,j = col +1;i>=0 && j<n;i--,j++){ // 这里出过错，注意连续定义两个Int类型的方式
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        // 检查当前元素左上方是否有皇后
        for (int i = row-1,j = col -1;i>=0 && j>=0;i--,j--){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    // 主函数
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(board,0);
        return res;
    }
};