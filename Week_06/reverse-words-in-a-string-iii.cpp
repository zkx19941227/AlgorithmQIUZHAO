#if 1
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end  = 0;
        int scan = 0;
        while (scan <= s.size()){
            if (s[scan] == ' ' || scan == s.size()){
                end = scan-1;
                while (start<end){
                    swap(s[start++],s[end--]);
                }
                start = end = scan+1;
            }
            scan++;
        }
        return s;
    }
};
#endif