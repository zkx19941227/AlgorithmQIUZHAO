class Solution {
public:
    int myAtoi(string str) {
        if (str.size()==0) return 0;
        // 定义索引号，符号位
        int index = 0,sign = 1;
        // 最终输出的结果
        long res = 0;
        // 去除空格的情况
        while (str[index] == ' ' && index < str.size()) index++;
        // 判断符号
        if (str[index] == '-' || str[index] == '+'){
            sign = str[index] == '+' ? 1:-1;
            index++;
        }
        while (index < str.size()){
            // 若不是数字，直接退出循环
            if (str[index] - '0' < 0 || str[index] - '0' > 9){
                break;
            }
            // 转换成整数
            res = res*10 + (str[index]-'0');
            if (res > INT_MAX && sign == 1) return INT_MAX;
            if (res > INT_MAX && sign == -1) return INT_MIN;
            index++;
        }
        // 最终跟符号位相乘得到最终结果
        return res*sign;
    }
};