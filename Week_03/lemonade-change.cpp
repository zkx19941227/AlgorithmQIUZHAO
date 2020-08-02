// 利用哈希表，存储数组中各元素出现的频率。然后根据实际找零，对频率进行相关的加减操作。
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> map;
        for (auto i : bills){
            if (i == 5) map[5]++;
            else if (i == 10) {
                map[10]++;
                map[5]--;
            } else if (i == 20 && map[10]>0){
                map[10]--;
                map[5]--;
            } else{
                map [5] -=3; // (i == 20 && map[10] == 0) 若有10元钞票，就先用10元钞票找零，再用5元钞票找零，否则直接用5元钞票找零。
            }
            if (map[5] < 0){
                return false;
            }
        }
        return true;
    }
};