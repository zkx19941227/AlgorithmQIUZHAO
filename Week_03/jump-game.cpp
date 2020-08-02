// 贪心算法。搜寻每个元素的最远跳跃距离，不断更新最远距离，最终查看最终
// 距离是否大于等于最后一个元素所在位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxDIstance = 0;
        int len = nums.size();
        for (int i = 0;i<len;i++){
            if (i<=MaxDIstance){
                MaxDIstance = max(MaxDIstance,i + nums[i]);
                if (MaxDIstance >= len-1){
                    return true;
                }
            } else{
                return false;
            }
        }
        return false;
    }
};