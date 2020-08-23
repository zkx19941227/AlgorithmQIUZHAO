class Solution {
public:
    bool isstr(string s,int i,int j){
        while (i<j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int len = s.size();
        for (int i = 0,j = len-1; i<j; i++,j--){
            if (s[i] != s[j]){
                return (isstr(s,i+1,j) || isstr(s,i,j-1));
            }
        }
        return true;
    }
};