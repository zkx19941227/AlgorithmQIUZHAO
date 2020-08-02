// end边界，当前步数中所能到达的最远距离
// MaxDistance,以end为边界的范围内，下一次跳跃可到达的最远位置，为下一次end所在之处。
// 假设总是可以到达最后
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int MaxDistance = 0;
        int step = 0;
        int len = nums.size();
        for (int i =0;i<len - 1;i++){
            if (MaxDistance>=i){
                MaxDistance = max(MaxDistance,nums[i] + i);
                if (i == end){
                    end = MaxDistance;
                    step = step+1;
                }
            }
        }
        return step;
    }
};