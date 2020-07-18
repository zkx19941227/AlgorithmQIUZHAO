class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()){
            return res;
        }
        int index = 0;// 最终数组的寻找序号
        unordered_map<string,int> umap; // 临时存放排序后的字符串数组及对应的在res中的索引数
        for (int i = 0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            if (umap.count(str)){
                res[umap[str]].push_back(strs[i]);
            } else {
                vector<string> vectem;
                vectem.push_back(strs[i]);
                res.push_back(vectem);
                umap[str] = index;
                index++;// 索引值更新
            }
        }
        return res;
    }
};