// 方法一：暴力法
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> a;
        for(i = 0;i<nums.size();i++){
            for(j =i+1;j<nums.size();j++){
                if(target == nums[i] + nums[j]){
                    a.push_back(i);
                    a.push_back(j);
                }
            }
        }
    return a;
    }
};
#endif
// 方法二：哈希表方法
#if 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> temhash;
        for (int i =0 ;i<nums.size();i++){
            temhash[nums[i]] = i; // 利用一次for循环，将数组元素存入hash中,对应数组下标
        }
        for (int j =0; j<nums.size();j++){
            if (temhash[target - nums[j]] && (temhash[target - nums[j]] != j)) {
                res.push_back(j);
                res.push_back(temhash[target - nums[j]]);
                return res;
            }
        }
        return res;
    }
};
#endif