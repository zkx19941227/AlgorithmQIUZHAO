/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 示意图
 // 前序列表：[根结点，[左子树]，[右子树]] 
 // 中序列表：[[左子树]，根结点，[右子树]]
class Solution {
private:
    unordered_map<int,int> umap; // 存储中序遍历列表的元素与角标值
public:
    // 第三个参数代表在前序列表中访问元素的左边界。第四个元素代表访问的右边界。均为索引值
    // 第五个参数代表在中序列表中访问元素的左边界。第六个元素代表访问的右边界。均为索引值
    // 左右边界是闭区间，即边界点可以取到
    TreeNode* myBuildTree(const vector<int>& preorder,const vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right){
        if (preorder_left > preorder_right){
            return NULL;
        }
        // 前序遍历中访问范围的第一个元素为当前范围的根结点
        int preorder_root = preorder[preorder_left];
        // 得到根结点在中序列表中的位置，根结点左侧为左子树范围，右侧为右子树范围
        int inorder_rootindex = umap[preorder[preorder_left]];
        // 构造当前范围下的根结点
        TreeNode* root = new TreeNode(preorder[preorder_left]);
        // 借助中序遍历确定左子树元素个数
        int left_size = inorder_rootindex - inorder_left; 
        // 构造左子树
        // 截取数组中的左子树区域出来构造左子树
        root->left = myBuildTree(preorder,inorder,preorder_left + 1,preorder_left + left_size,inorder_left,inorder_rootindex - 1);
        // 构造右子树
        // 截取数组中的右子树区域出来构造右子树
        root->right = myBuildTree(preorder,inorder,preorder_left + left_size + 1,preorder_right,inorder_rootindex+1,inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i =0;i<n;i++){
            umap[inorder[i]] = i;
        }
        return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
};