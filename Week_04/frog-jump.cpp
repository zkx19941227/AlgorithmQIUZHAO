#if 0 // 国外大神代码
class Solution {
public:
    bool canCross(vector<int>& stones,int pos = 0,int k =0) {
        for (int i = pos + 1;i<stones.size();i++){
            int gap = stones[i] - stones[pos];
            if (gap>k+1) return false;
            if (gap<k-1) continue;
            if (canCross(stones,i,gap)) return true;
        }
        return pos == stones.size()-1;
    }
};
#endif

#if 1 // 动态规划
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        int n = stones[len-1];
        if((1 + len) * len / 2 < n) return false;
        // 设置一个二维dp数组，数组中的行的索引号代表石头所在的位置，即stones数组中的元素
        // 数组的列设定为set数组，用于储存到达当前石头所在处的步数集合
        // 循环遍历stones数组中的元素，最终查验dp数组的最后一个元素是否为空即可
        // 注意：二维数组的索引号代表石头所在地！！！不是stones的索引号，而是stones数组的具体元素。
        vector<set<int>> dp(n+1);
        dp[1].insert(1);
        for (int i = 1;i<len;i++){
            // 循环dp数组中某石头所在地的集合中的元素，即步数
            // 分别计算从当前位置出发，前进k-1,k,k+1步，得到可以到达的位置，之后更新dp数组的后续元素        
            // 注意，我们在得到下一阶段可到达的位置信息，可能不在stones数组中，这不重要，我们只需按步骤循环完stones数组中的每一个元素，最后查看dp数组中最后一个石头元素是否为空即可
            for (auto k : dp[stones[i]]){
                if (stones[i]+k-1<=n){
                    dp[stones[i]+k-1].insert(k-1);
                }
                if (stones[i]+k<=n){
                    dp[stones[i]+k].insert(k);
                }
                if (stones[i]+k+1<=n){
                    dp[stones[i]+k+1].insert(k+1);
                }
            }
        }
        return !dp[n].empty();
    }
};
#endif