// 方法一：动态规划 丑数乘以2,3,5还是丑数
// 思路：借助数组，先把较小的丑数压入数组。之后循环，利用数组中较小的丑数乘以2，3，5得到更多丑数
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res; // 这里出过错，若提前设定好res大小，即vector<int> res(n),后续可直接指定res的具体角标赋值。而如果没有设定大小，只能通过push_back的方式进行添加元素。
        int a =0;
        int b =0;
        int c =0;
        res.push_back(1); // 初始化数组第一个元素为1
        for (int i =1;i<n;i++){
            int a1 =res[a]*2;
            int b1 =res[b]*3;
            int c1 =res[c]*5; // 根据数组中的较小丑数求出较大丑数
            res.push_back(min(a1,min(b1,c1)));// 首先选择较小丑数压入数组
            if (res[i] == a1) a++;
            if (res[i] == b1) b++;
            if (res[i] == c1) c++;  // 三个判断条件，被选择压入数组的元素相应的索引号+1，其余不变，继续比较。
        }
        return res[n-1];
    }
};