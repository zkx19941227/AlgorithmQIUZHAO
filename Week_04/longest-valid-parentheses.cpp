// 方法一 栈 
# if 0
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        stack<int> st;
        int curlenth = 0;
        int maxlenth = 0;
        st.push(-1);
        int len = s.size();
        for (int i = 0; i<len; i++){
            if (s[i] == '('){
                st.push(i);
                continue;
            } else {
                st.pop();
                if (st.empty()){
                    st.push(i);            
                } else {
                    curlenth = i - st.top();
                    maxlenth = max(maxlenth,curlenth);
                }
            }
        }
        return maxlenth;
    }
};
#endif

// 方法二：动态规划
#if 1
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) return 0;
        int maxlen = 0;
        int len = s.size();
        vector<int> dp(len,0);
        for (int i = 1;i<len;i++){
            if (s[i] == ')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '('){
                if (i-dp[i-1]-2 < 0){
                    dp[i] = 2 + dp[i-1];
                } else {
                    dp[i] = 2 + dp[i-1]+dp[i-dp[i-1]-2];
                }
                maxlen = max(maxlen,dp[i]);
            }
        }
        return maxlen;
    }
};
#endif