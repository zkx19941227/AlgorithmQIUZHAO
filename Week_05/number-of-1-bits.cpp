class Solution {
public:
    int hammingWeight(uint32_t n) {
         int res = 0;
         while (n != 0){
             res++;
             // 清零最低位的1，每清零一个1，总数+1
             n &= (n-1);
         }
         return res;
    }
};