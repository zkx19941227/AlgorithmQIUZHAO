class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // 建立动态数组，初始值为0，即false。
        // 空模式无法匹配非空字符串
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0] = true;
        // [0][i]分情况讨论，若出现false直接退出循环
        for (int i = 1; i<n+1; i++){
            if (p[i-1] == '*'){
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i<m+1; i++){
            for (int j = 1; j<n+1; j++){
                if (s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                if (p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};