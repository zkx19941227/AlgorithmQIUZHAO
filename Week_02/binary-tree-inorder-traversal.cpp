// 递归
// 栈
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#if 0 // 方法一 递归
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};
#endif

#if 1 // 方法二 迭代，使用栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root || st.size()>0){
            while (root){
                st.push(root); 
                root = root->left;// 按照左-根-右的顺序，将结点压入栈，首次运行时一直运行到左下结点
            }
            root = st.top();// 到达左下结点，准备获取该结点的结点值
            st.pop();       // 获取结点信息后，弹出栈
            res.push_back(root->val);// 将刚才获取的信息压入数组中
            root = root->right;// 处理完左子树处理右子树
        }
        return res;
    }
};
#endif