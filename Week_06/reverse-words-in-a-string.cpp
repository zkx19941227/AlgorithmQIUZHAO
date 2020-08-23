class Solution {
public:
    string reverseWords(string s) {
        if (s == " " || s.size() == 0 || s == "    " || s == "   ") return "";
        stack<char> st;
        string res;
        int len = s.size();
        reverse(s.begin(),s.end());
        for (int i = 0 ; i<len; i++){
            // 字符串开头若是空格，直接跳过
            if (s[i] == ' ' && st.empty()){
                continue;
            }
            // 按顺序压字母
            st.push(s[i]);
            // 碰到空格，说明当前单词已经压完，可以弹出压入数组
            if (st.top() == ' '){
                auto ch = st.top();
                st.pop();
                while (!st.empty()){
                    res.push_back(st.top());
                    st.pop();
                }
                res.push_back(ch);
                continue;
            } 
            // 遍历完字符串后，检查栈中是否还有元素，继续压入
            if (i == s.size() -1){
                while (!st.empty()){
                    res.push_back(st.top());
                    st.pop();
                }
            }
        }
        // 字符串最后是空格的话弹出最后一个空格
        if (res.back() == ' '){
            res.pop_back();
        }
        return res;
    }
};