class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        vector<vector<int>> res;
        // 按照数组的第一个元素从小到大排序
        // 排序好之后，根据前一个数组中的最后一个元素与后一个数组的第一个元素大小分情况讨论
        sort(intervals.begin(),intervals.end());
        // 设置两个指针，save用于最终储存数组，scan用于扫描整个数组
        int save = 0; int scan = 0;
        while (scan < intervals.size()){
            // save指针的最后一个元素比scan指针的第一个元素小，说明没有交集，可以把压入res数组中
            // 同时，更新save的位置到现在scan指针的位置
            // 否则证明有交集，比较save处的最后一个元素与scan位置的最后一个元素大小
            // 大的更新为save处的最后一个元素
            if (intervals[save][1] < intervals[scan][0]){
                res.push_back(intervals[save]);
                save = scan;
                scan++;
            } else {
                intervals[save][1] = max(intervals[save][1],intervals[scan][1]);
                scan++;
            }
        }
        // 循环到最后可能save处还有数组没有被压入到结果中，再压入一次。
        res.push_back(intervals[save]);
        return res;
    }
};