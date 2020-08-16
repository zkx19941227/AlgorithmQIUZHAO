class Solution {
private:
    vector<int> fathers;
public:
    int find(int m){
        while (fathers[m] != m){
            m = fathers[m];
        }
        return m;
    }
    void unit(int x, int y){
        int i = find(x);
        int j = find(y);
        fathers[i] = j;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        int count = 0;
        // 以每位同学为一个独立的个体进行初始化
        for (int i = 0; i<n; i++){
            fathers.push_back(i); // 出过错，注意数组初始化没有指定数组大小时，不能直接指定数组的索引。
        }
        // 循环遍历数组。若对应的元素为1时，合并两个元素为一个整体
        for (int i = 0; i<n-1; i++){
            for (int j = i+1; j<n; j++){
                if (M[i][j]){
                    unit(i,j);
                }
            }
        }
        // 查验最后有几个父节点，就代表有几个群体
        for (int i = 0; i<n; i++){
            if (fathers[i] == i){
                count++;
            }
        }
        return count;
    }
};