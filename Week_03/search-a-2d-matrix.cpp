// 暴力法
#if 0
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i =0;i<matrix.size();i++){
            for (int j =0;j<matrix[0].size();j++){
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};
#endif

#if 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int m=matrix[0].size(),n=matrix.size();
        int left=0;
        int right=m*n-1;
        while(left<right){
            int mid= left + (right - left)/2;
            if(matrix[mid/m][mid%m]>=target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        if(matrix[left/m][left%m]==target) return true;
        return false;
    }
};
#endif