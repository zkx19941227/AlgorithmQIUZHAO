// 方法一：贪心法
// 将两个数组从小到大排序，优先满足胃口小的小朋友
// 小朋友的胃口小于等于饼干大小时，即满足胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        int res = 0;
        while (i<g.size() && j<s.size()){
            if (g[i] <= s[j]){
                res = res+1;
                i++;
            }
            j++;
        }
        return res;
    }
};