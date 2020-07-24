/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 利用队列，广度优先原则，一层一层解决问题。
# if 0 // 方法一
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; // 保存最后输出结果
        queue<Node*> qu;         // 保存当前所有的子结点
        if (root == NULL){
            return res;
        }
        qu.push(root);           // 首先将根结点压入队列
        while (!qu.empty()){
            vector<int> tem;    // 保存当前遍历层的结点值
            auto n = qu.size();
            for(int i =0;i<n;i++){// 注意，这里不能直接令i<qu的长度，因为循环最后qu长度已经有了变化，所以这里不能更改。    当前层的结点个数       
                auto node = qu.front();
                qu.pop();
                tem.push_back(node->val);
                for(auto x : node->children){
                    qu.push(x); // 循环当前结点的**所有子结点**，压入队列// 循环当前层的所有子结点
                }
            }
            res.push_back(tem); // 将得到的子数组，压入到结果数组中
        }
        return res;
    }
};
#endif