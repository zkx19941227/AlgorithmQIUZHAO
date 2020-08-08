// 与最大回文子串的方式差不多
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_word1 = word1.size();
        int len_word2 = word2.size();
        if (len_word1 * len_word2 == 0) return len_word1 + len_word2;
        int dp[len_word1 + 1][len_word2 + 1];
        for (int i = 0;i<len_word1 + 1;i++){
            dp[i][0]=i;
        }
        for (int j = 0;j<len_word2 + 1;j++){
            dp[0][j] = j;
        }
        for (int i = 1;i<len_word1 + 1;i++){
            for (int j = 1;j<len_word2 + 1;j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[len_word1][len_word2];
    }
};