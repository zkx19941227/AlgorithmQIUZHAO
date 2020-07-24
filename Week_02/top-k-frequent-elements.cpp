// 方法一，哈希表存储元素频率，将map转换成数组vector，排序得到最终答案
// 方法二，堆
#if 0 // 方法一 时间复杂度O（nlogn）
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap; // 存储元素及其出现次数
        vector<int> res;
        for (auto num:nums){
            umap[num]++;
        }
        vector<pair<int,int>> hashtovec(umap.begin(),umap.end()); // 将map转换为vector
        sort(hashtovec.begin(),hashtovec.end(), [](pair<int,int>& a,pair<int,int>& b){return a.second > b.second; }); // 第三个参数规定了排序规则，根据pair的第二个参数从大到小排列，即按照元素出现的次数从大到小排序。牢记这种书写形式。
        auto a = hashtovec.begin();
        while (k--) {
            res.push_back(a->first); // 将前k频率的元素压入数组.出过错，不能是a.
            a++;
        }
        return res;
    }
};
#endif

#if 1 // 方法二 时间复杂度O(nlogk)
     // 小顶堆 满足条件后弹出较小的元素
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){return a.second > b.second;}
    };// second小的优先级高。  排序规则与sort规则相反，牢记！！！
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> umap;
        for (auto num:nums){
            umap[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> qu; // 将map压入优先队列，按照cmp排序。
        for (auto a:umap){
            qu.push(a);
            if (qu.size() > k){
                qu.pop();
            }
        }
        while(!qu.empty()){
            res.push_back(qu.top().first);
            qu.pop();
        }
        return res;
    }
};
#endif