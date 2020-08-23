class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0 || s == " ") return"";
        int len = s.size();
        vector<vector<bool>> dp(len,vector<bool>(len));
        string res;
        // 从后向前遍历，利用一个二维dp数组记录过程信息
        for (int i = len-1; i>=0; i--){
            for (int j = i; j<len; j++){
                dp[i][j] = (s[i] == s[j]) && (j-i<=2 || dp[i+1][j-1]);
                if (dp[i][j] && j-i+1 > res.size()){
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};