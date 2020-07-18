class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        if(len == 0){
            return 0;
        }
        for(int i = 1;i<len;i++){
            if (nums[i] != nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};