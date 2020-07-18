#if 0 // 暴力法，直接排序，将排序后的数组进行对比，查看是否相等
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
#endif

#if 1 // 方法二：构造哈希表
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<int,int> umap;
        for(char m:s){
            ++umap[m];
        }
        for(char n:t){
            if(umap[n] > 0){
                --umap[n];
            } else{
                return false;
            }
        }
        return true;
    }
};
#endif