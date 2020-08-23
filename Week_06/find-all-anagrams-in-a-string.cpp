class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window,need;
        int left = 0,right = 0;
        int valid = 0;
        vector<int> res;
        for (auto t:p) need[t]++;
        while (right<s.size()){
            char tem_in = s[right];
            right++; // 开区间
            if (need.count(tem_in)){
                window[tem_in]++;
                if (need[tem_in] == window[tem_in]){
                    valid++;
                }
            }
            while (right-left >= p.size()){
                if (valid == need.size()){
                    res.push_back(left);
                }
                char tem_out = s[left];
                left++;
                if (need.count(tem_out)){
                    if (need[tem_out] == window[tem_out]){
                        valid--;
                    }
                    window[tem_out]--;
                }
            }
        }
        return res;
    }
};