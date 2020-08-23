// 通配符匹配
// 当前字符之前的匹配结果+之前已经满足的匹配结果
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() == 0) return 0;
        if (t.size() == 0) return 1;
        int len_t = t.size();
        int len_s = s.size();
        vector<vector<long>> dp(len_t+1,vector<long>(len_s+1));
        for (int i = 0; i<len_s+1; i++){
            dp[0][i] = 1;
        }
        for (int j = 1; j<len_t+1; j++){
            dp[j][0] = 0;
        }
        for (int i = 1; i<len_t+1; i++){
            for (int j =1; j<len_s+1; j++){
                if (t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[len_t][len_s];
    }
};