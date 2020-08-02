// 方法一，暴力法
// 方法二，二分搜索法
# if 0
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0;i<nums.size();i++){
            if (nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};
# endif

#if 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
       if (nums.empty()) return -1;
       int left = 0;
       int right = nums.size() - 1;
       while (left <= right){
           int mid = left + (right - left)/2;
           if (nums[mid] == target) return mid;
           if (nums[mid] > nums[right]){
               if (nums[mid] > target && target >= nums[left]){
                   right = mid -1;
               } else {
                   left = mid + 1;
               }
           }
           else if (nums[mid] <= nums[right]){
               if (target > nums[mid] && target <= nums[right]){
                   left = mid + 1;
               } else {
                   right = mid - 1;
               }
           }    
       }
       return -1;
    }
};
#endif

# if 0
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left)>>1);
            if (nums[mid] == target) {
                return mid;
            }
            //mid位于右半部分
            if (nums[mid] < nums[right]) {
                //target <= nums[right],说明target位于右半部分
                //nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
                if (target <= nums[right] && nums[mid] < target) {
                    left = mid + 1;
                }
                //target > nums[right],说明target位于左半部分,right = mid - 1
                //target < nums[mid],说明target位于右半部分的左半部分,right = mid - 1
                else {
                    right = mid - 1;
                }
            }
            //mid位于左半部分
            else if (nums[mid] >= nums[right]) {
                //nums[left] <= target,说明target位于左半部分
                //target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                //nums[left] > target,说明target位于右半部分,left = mid + 1
                //target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
#endif