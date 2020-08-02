class Solution {
public:
    map<char, string> M = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> res; // 保存结果
    string cur;         // 当前字符串
    // index:  遍历输入数字字符串的索引号
    // digits：输入的数字字符串
    void dfs(int index,string digits){
        if (index == digits.size()){
            res.push_back(cur);
            return;
        }
        for (int i = 0;i<M[digits[index]].size();i++){
            cur.push_back(M[digits[index]][i]);
            dfs(index+1,digits);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return res;
        }
        dfs(0,digits);
        return res;
    }
};