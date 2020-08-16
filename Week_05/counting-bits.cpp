// 方法一：暴力循环法
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i =0;i<=num;i++){
            int ans = 0;
            long x = i;
            while(x != 0){
                x &= (x-1);
                ans++;
            }
            res.push_back(ans);
        }
        return res;
    }
};
