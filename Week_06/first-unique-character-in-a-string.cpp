// 哈希表存储频次，进而找到第一次频次为1的下标
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) return -1;
        unordered_map<char,int> umap;
        for (auto ch:s) umap[ch]++;
        for (int i = 0; i<s.size(); i++){
            if (umap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};