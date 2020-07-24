/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);   // 查看左子树中是否有q或者q
        TreeNode* right = lowestCommonAncestor(root->right,p,q); // 查看右子树是否有p或者q
        if (left && right) return root; // 左右子树都存在，则当前根结点为公共祖先
        return left? left:right;        // 一棵为空一颗非空，证明p和q只在非空的一侧。
    }
};