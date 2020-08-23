class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) return 0;
        int maxlen = 0;
        int len = s.size();
        // 记录当前有效括号的最大长度
        vector<int> dp(len,0);
        for (int i = 1; i<len; i++){
            if (s[i] == ')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '('){
                if (i-dp[i-1]-2<0){
                    dp[i] = 2+dp[i-1];
                } else {
                    dp[i] = 2+dp[i-1]+dp[i-dp[i-1]-2];
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};