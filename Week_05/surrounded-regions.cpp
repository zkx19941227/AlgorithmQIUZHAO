// 内部的O与内部的O组合成一个集体
// 边界的O与一个虚拟结点组合成一个集体
class Solution {
public:
    vector<int> fathers;
    int find(int& x){
        int y = x;
        while (fathers[x] != x){
            x = fathers[x];
        }
        while (fathers[y] != x){
            fathers[y] = x;
        }
        return x;
    }
    void unit(int x,int y){
        int f1 = find(x);
        int f2 = find(y);
        fathers[f1] = f2;
    }
    void solve(vector<vector<char>>& board) {
        if (board.size()==0 || board[0].size() == 0){
            return;
        }
        int m = board.size();
        int n = board[0].size();
        int dummy_pos = n*m;
        // 这里取n*m用于组成与边界的O组合的虚拟节点
        for (int i = 0;i<=n*m;i++){
            fathers.push_back(i);
        }
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (board[i][j] == 'X'){
                    continue;
                }
                // 经过上述判断，已经确定当前位置的元素为O
                int cur_pos = n*i+j;
                if (i == 0 || j == 0 || i == m-1 || j == n-1){
                    unit(cur_pos,dummy_pos);
                    continue;
                }
                if (board[i-1][j] == 'O'){
                    unit(cur_pos,cur_pos - n);
                }
                if (board[i+1][j] == 'O'){
                    unit(cur_pos,cur_pos + n);
                }
                if (board[i][j-1] == 'O'){
                    unit(cur_pos,cur_pos - 1);
                }
                if (board[i][j+1] == 'O'){
                    unit(cur_pos,cur_pos + 1);
                }
            }
        }
        int dummy_father = find(dummy_pos);
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (board[i][j] == 'X'){
                    continue;
                }
                int cur_pos = i*n+j;
                if (find(cur_pos) != dummy_father){
                    board[i][j] = 'X';
                }
            }
        }
    }
};