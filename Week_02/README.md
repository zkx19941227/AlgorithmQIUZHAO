# 第二周学习笔记

### 刷题集合

#### 简单题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[83.删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)|3|链表循环|
|[167.两数之和2 - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)|3|双指针夹逼/哈希表|
|[590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)|3|迭代|
|[589. N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)|3|迭代|
|[1021. 删除最外层括号](https://leetcode-cn.com/problems/remove-outermost-parentheses/)|3|数组遍历|
|[剑指offer40.最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)|3|堆/数组排序|
|[剑指offer11.旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)|3|二分法|
|[70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)|3|动态规划/递归|
|[226.翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/submissions/)|3|队列迭代/递归|
|[104.二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)|3|队列迭代/递归|
|[111.二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)|3|队列迭代/递归|
|[258.各位相加](https://leetcode-cn.com/problems/add-digits/)|1|循环/数字根|

#### 中等题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[94.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)|3|递归/迭代|（每天必看）
|[144.二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)|3|递归/迭代|（每天必看）
|[429.N叉树的层级遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)|3|队列/广度优先原则|
|[剑指offer49.丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)|3|堆/动态规划|
|[347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)|3|堆/哈希表/优先队列|（每天必看）
|[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/)|3|递归|
|[98.验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)|3|递归/二叉树的中序遍历|
|[64.最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)|3|动态规划|
|[236.最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)|3|递归|
|[105.从前序遍历和中序遍历构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|3|递归|（每天必看）
|[46.全排列](https://leetcode-cn.com/problems/permutations/)|3|回溯|（下周需再回顾）
|[47.全排列2](https://leetcode-cn.com/problems/permutations-ii/)|3|回溯+set|（下周需再回顾）
### 树，二叉树，二叉搜索树的实现及特性

#### 树结点的定义（C++）
```cpp
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}
```
#### 二叉树的遍历
1. 前序遍历：根-左-右
2. 中序遍历：左-根-右
3. 后序遍历：左-右-根

#### 二叉树遍历递归模板

#### 二叉树中序遍历模板

##### 中序遍历递归方法
```cpp
 vector<int> res;
 vector<int> inorderTraversal(TreeNode* root) {
        if (root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
 }
```
##### 中序遍历迭代方法
```cpp
while(root || st.size()>0){
            while (root){
                st.push(root); 	// 先不访问根结点，先将其压入栈。
                root = root->left;// 按照左-根-右的顺序，将结点压入栈，首次运行时一直运行到左下结点
            }
            root = st.top();// 到达左下结点，准备获取该结点的结点值
            st.pop();       // 获取结点信息后，弹出栈
            res.push_back(root->val);// 将刚才获取的信息压入数组中
            root = root->right;// 处理完左子树处理右子树
        }
```

#### 二叉树前序遍历模板

##### 前序遍历递归方法
```cpp
	vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root) {
            res.push_back(root->val); 
            preorderTraversal(root->left); 
            preorderTraversal(root->right); 
        }
        return res;
    }
```
##### 前序遍历迭代方法
```cpp
 while (root || st.size()>0){
            while(root){
                res.push_back(root->val); // 遇到根结点直接压入数组
                st.push(root->right);     // 右子树暂时不访问，压入栈
                root = root->left;        // 向左右
            }
            root = st.top();
            st.pop();
        }
```

#### 二叉树后序遍历模板

##### 后序遍历递归方法


1. 可以看出，中序遍历和前序遍历只是何时直接输出何时需要先压栈不同。
2. 中序遍历是一直向左访问，持续压栈中间节点，输出中间节点后处理右子树。
3. 前序遍历是遇到中间节点直接输出，持续压栈右子树

#### 二叉搜索树
1. 左子树上**所有结点**的值（不单单是左儿子结点）均小于根结点的值
2. 右子树上**所有结点**的值（不单单是右儿子结点）均大于根结点的值
3. 以此类推，左，右子树也分别为二叉搜索树。**（这就是重复性）**
**二叉搜索树中的中序遍历为升序遍历，以此可作为判断一棵树是否为二叉搜索树的依据**
#### 二叉搜索树相关操作的时间复杂度
1. 查询 O(log(n))
2. 插入 O(log(n))
3. 删除 O(log(n))

### 堆和二叉堆、图

#### 堆 Heap
Heap:可以迅速找到一堆数中的最大或最小值的数据结构。

#### 二叉堆性质
**二叉堆（大顶堆）满足以下性质：**
1. 是一棵完全树
2. 树中任意结点的值都>=其子结点的值

#### 二叉堆的插入操作(O(log(n)))
1. 新元素首先一律插到堆的尾部
2. 依次向上调整整个堆的结构

#### 二叉堆的删除堆顶操作(O(log(n)))
1. 将堆尾元素替换到堆顶（即堆顶元素被替换删除掉）
2. 依次从堆顶依次向下调整堆的结构（一直到堆尾即可）

#### C++中的堆排序
[C++中堆排序推理](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/shou-si-dui-pai-xu-yi-wen-kan-hui-dui-pai-xu-by-ti/)

#### 优先队列自定义排序与sort自定义排序相反

#### 将map转换成vector的方法
```cpp
map<int,int> map;
vector<pair<int,int>> maptovec(map.begin(),map.end()); // vector中的元素为map中的key-value对
```
#### 优先队列的自定义排序
```cpp
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> qu; // cmp是自定义排序准则，>代表指定值小的优先，<代表指定值大的优先，与sort相反。
``` 

### 泛型递归与树的递归

#### 递归代码模板
```cpp
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
    // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}
```
**1.不要人肉进行递归**
**2.找到最近最简方法，将其拆解成可重复解决的问题**
**3.数学归纳法思维**

### 刷题总结的经验 

#### 需要层级遍历处理树的子结点时的模板(队列迭代方法)
```cpp
queue<TreeNode*> qu;
if (NULL==root) return xxx;
qu.push(root);
while (!qu.empty()){
   auto n =qu.size();
   for (int i =0;i<n;i++){
      循环处理当前层的结点
   }
   相关值更新；
 }
```

#### 哈希表存储元素出现的频率模板
```cpp
unordered_map<int,int> umap;
for (auto num:nums){
            umap[num]++;
        }
```

#### 将哈希表中的元素插入到vector容器或者优先队列中
```cpp
vector<pair<int,int>> hashtovec(umap.begin(),umap.end());
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> qu;
```

#### 链表翻转递归方法模板
```cpp
if (!head || !head->next){
            return head;
        }
        ListNode* s = reverseList(head->next);  // 最后一次递归结束时，s运动到链表最后一个元素
        head->next->next = head;                // 当前节点（此刻的head节点）运动到最后一个元素之前一个元素
        head->next = NULL;
        return s; 
```

#### 查找最近公共祖先递归代码模板
```cpp
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
```