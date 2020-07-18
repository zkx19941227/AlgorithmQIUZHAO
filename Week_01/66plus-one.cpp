class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len-1;i>=0;--i){
            if (digits[i] == 9){
                digits[i] = 0;
            } else{
                digits[i] = digits[i] +1;
                break;
            }
        }
        if (digits[0] == 0){
            digits[0] = 1;
            digits.push_back(0); // 应对99999999+1的情况
        }
        return digits;
    }
}；