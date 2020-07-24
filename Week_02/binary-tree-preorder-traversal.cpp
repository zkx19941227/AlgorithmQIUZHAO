// 方法一 递归
#if 0
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root) {
            res.push_back(root->val); 
            preorderTraversal(root->left); 
            preorderTraversal(root->right); 
        }
        return res;
    }
};
#endif
// 方法二 迭代
#if 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (root || st.size()>0){
            while(root){
                res.push_back(root->val); // 遇到根结点直接压入数组
                st.push(root->right);     // 右子树暂时不访问，压入栈
                root = root->left;        // 向左右
            }
            root = st.top();
            st.pop();
        }
        return res;
    }
};
#endif