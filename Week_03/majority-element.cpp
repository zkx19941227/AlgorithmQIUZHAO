// 优先队列
// 数组
#if 0 // 方法一：数组
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (auto s:nums){
            umap[s]++;
        }
        vector<pair<int,int>> hashtovec(umap.begin(),umap.end());
        sort(hashtovec.begin(),hashtovec.end(), [](pair<int,int>& a,pair<int,int>& b){return a.second>b.second;});
        return hashtovec.begin()->first;
    }
};
#endif

#if 1 // 方法二：优先队列
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        }
    };
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (auto s:nums){
            umap[s]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> qu(umap.begin(),umap.end());
        return qu.top().first;
    }
};
#endif