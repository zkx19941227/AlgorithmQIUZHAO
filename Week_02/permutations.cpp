// 回溯法 时间复杂度O(N*N!) 空间复杂度O（n）
class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> &output,int index,int len){
        if (index == len){
            res.push_back(output);
            return;
        }
        for (int i = index;i<len;i++){
            swap(output[i],output[index]);
            backtrack(res,output,index + 1,len);
            swap(output[i],output[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0,nums.size());
        return res;
    }
};