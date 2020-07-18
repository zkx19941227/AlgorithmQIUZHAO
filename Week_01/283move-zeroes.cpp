class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // 用于储存非零元素的指针
        for(int i = 0;i<nums.size();i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                if (i != j){
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};