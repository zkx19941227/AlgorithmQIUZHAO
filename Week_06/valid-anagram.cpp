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
        unordered_map<char,int> umap; // 这里出过错。char不能换成string。str是一串字符串，char是一个单独的字符
        for(char m:s){
            ++umap[m];
        }
        for(char n:t){
            // ！！！判断条件不能是umap.count[n]。因为value值为负数时也代表该元素存在
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