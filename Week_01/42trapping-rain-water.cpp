class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> rain; // 保存元素角标
        int len = height.size();
        int ans = 0; // 保存最后的结果
        for (int i = 0;i<len;i++){
            while (!rain.empty() && height[rain.top()] < height[i]){
                int cur = rain.top();
                rain.pop();
                if (rain.empty()) break;
                int l = rain.top();
                int h = min(height[i],height[l]) - height[cur];
                ans += (i - l -1)*h;
            }
            rain.push(i);
        }
        return ans;
    }
};