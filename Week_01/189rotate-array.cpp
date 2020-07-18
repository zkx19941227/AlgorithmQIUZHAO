class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k>=nums.size()){
            k%=nums.size();
        }
        if (k!=0){
            ReverseElement(nums,0,nums.size()-1-k);
            ReverseElement(nums,nums.size()-k,nums.size()-1);
            ReverseElement(nums,0,nums.size()-1);
        }
    }
    void ReverseElement(vector<int>& nums,int s,int e){
        while (s<e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
};