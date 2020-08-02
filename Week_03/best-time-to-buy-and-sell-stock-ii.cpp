// 方法一：贪心算法 前一天比后一天小，就前一天买进，后一天抛出。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int  i=1;i<prices.size();i++){
            if (prices[i]>prices[i-1]){
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};