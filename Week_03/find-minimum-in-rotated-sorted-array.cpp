// 最小值肯定在数组右半部分，判断中点与最小值的位置来移动左右指针
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left<right){
            int mid = left + (right - left)/2;
            if (nums[mid] <= nums[right]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};