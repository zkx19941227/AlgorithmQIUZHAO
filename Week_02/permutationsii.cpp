// 方法一：回溯+暴力遍历
# if 0
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> tem;
        vector<vector<int>> res;
        backtrack(tem,nums,0,nums.size());
        sort(tem.begin(),tem.end());
        res.push_back(tem[0]);
        for (int i = 1;i<tem.size();i++){
            if (tem[i-1] != tem[i]){
                res.push_back(tem[i]);
            }
        }
        return res;
    }
};
#endif
// 方法二：回溯+set
#if 1
class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> &output,int index,int len){
        if (index == len){
            res.push_back(output);
            return;
        }
        unordered_set<int> uset;
        for (int i = index;i<len;i++){
            if (uset.count(output[i])){
                continue;
            }
            swap(output[i],output[index]);
            backtrack(res,output,index + 1,len);
            swap(output[i],output[index]);
            uset.insert(output[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0,nums.size());
        return res;
    }
};
#endif