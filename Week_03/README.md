# 第三周学习笔记

### 刷题集合

#### 简单题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[392.判断子序列](https://leetcode-cn.com/problems/is-subsequence/)|3|双指针数组遍历|
|[169.多数元素](https://leetcode-cn.com/problems/majority-element/)|3|数组/优先队列| （347. 前 K 个高频元素）
|[面试题06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)|3|栈/数组反转|
|[455.分发饼干](https://leetcode-cn.com/problems/assign-cookies/)|3|贪心算法|
|[122.买卖股票的最佳时机-2](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)|3|贪心算法|
|[69.x的平方根](https://leetcode-cn.com/problems/sqrtx/)|1|二分法|
|[367.有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)|3|二分法|
|[118.杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)|1|动态规划|
|[119.杨辉三角-2](https://leetcode-cn.com/problems/pascals-triangle-ii/)|1|动态规划|
|[860.柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/)|3|贪心算法|

#### 中等题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[50.pow(x,n)](https://leetcode-cn.com/problems/powx-n/)|3|分治|（每天必看）
|[78.子集](https://leetcode-cn.com/problems/subsets/)|3|回溯|（每天必看）
|[17.电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)|3|回溯|（每天必看）
|[102.二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)|3|广度优先|（与N叉树层序遍历一致）
|[515.每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)|3|广度优先|（与N叉树层序遍历一致）
|[200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)|1|深度优先遍历|
|[127.单词接龙](https://leetcode-cn.com/problems/word-ladder/)|1|广度优先遍历|（每天必看）
|[433.最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)|1|广度优先遍历|（每天必看）
|[322.零钱兑换](https://leetcode-cn.com/problems/coin-change/)|3|贪心算法|（每天必看）
|[55.跳跃游戏](https://leetcode-cn.com/problems/jump-game/)|3|贪心算法|（每天必看）
|[33.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)|3|二分法|（每天必看）
|[153.寻找旋转排列数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)|3|二分法|（每天必看）

#### 困难题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[51.N皇后问题](https://leetcode-cn.com/problems/n-queens/)|3|回溯|（每天必看）
|[45.跳跃游戏-2](https://leetcode-cn.com/problems/jump-game-ii/)|3|贪心算法|（每天必看）

### 分治、回溯

#### 分治、回溯的实现及其特性

#### 分治代码模板
```cpp
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```
#### pow(x,n)问题整体思路
1. 首先考虑停止条件
2. 将大问题拆解成小的子问题。、
   例如，x^10可以拆成(x^5)^2，相当于求出x^5之后，再乘以自己，得出结果。时间复杂度为O(logn)
3. pow(x,n):
	subproblem:subresult = pow(x,n/2)
   merge:
     if (n%2 == 1){
		result = subresult*subresult*x;
	} else {
		result = subresult * subresult;
	}

#### 回溯算法思想
解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：
1. 路径：已经做出的选择
2. 选择列表：当前可以做的选择
3. 结束条件：到达决策树底部，无法再做出选择
**回溯算法整体框架**
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
路径一般是最终需要保存到结果中的数组。
选择列表一般从索引0开始
**其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」**
[回溯算法讲解labuladong](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)

#### N皇后问题思路
直接套用回溯算法模板，这里的路径代表当前行中选取某一列为当前的放置位置。选择列表依然从索引号0开始，按行索引。
结束条件：所有行都放置完目标后，结束。
这里需要多写一个辅助判断函数，来判断当前放置的目标是否符合要求。
**判断依据：**
1. 放置的当前位置所在列是否已经存在皇后
2. 放置的当前位置**右上角**是否已经存在皇后（右下角还没开始放置不考虑）
3. 放置的当前位置**左上角**是否已经存在皇后（左下角还没开始放置不考虑）
该问题的结果是三层数组。
建立二维数组时：vector<string> board(行数，列数)；
列数设置时，以字符串数组为例。string(n,'.'):即每一行都是n个.的字符数组。即这个二维数组有n列。


### 深度优先搜索和广度优先搜索

#### DFS模板（递归）
```cpp
map<int, int> visited;
void dfs(Node* root) {
  // terminator
  if (!root) return ;
  if (visited.count(root->val)) {
    // already visited
    return ;
  }
  visited[root->val] = 1;
  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```

#### DFS模板（非递归）
```cpp
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;
  stack<Node*> stackNode;
  stackNode.push(root);
  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;
    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }
  return ;
}
```

#### BFS模板
```cpp
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;
  queue<Node*> queueNode;
  queueNode.push(root);
  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;
    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }
  return ;
}
```

#### 岛屿问题思路
1. 嵌套循环遍历二维数组
2. 碰到‘1’时，将岛屿数量加1，同时将该岛屿，以及与该岛屿相连的部分全部置为0（深度优先原则/递归）
3. 需要一个辅助递归函数，将‘1’置为‘0’.

#### 单词接龙问题思路
1. 首先利用一个unordered_set将字典中的单词全部储存起来
2. 利用一个unordered_set visit存储已经在字典中访问的单词
3. 设定一个队列queue<string> qu,表示当前处理的单词（换单词中的其中某个字母，看是否与字典匹配）。首先，将beginword压入队列中。
4. 从beginword的第一个字母开始，循环到最后一个字母，依次从'a'换到'z'，查看是否与字典中的单词匹配，
   若匹配成功，将匹配到的单词放到visit中和qu队列中。代表该单词已经访问过，之后
   在循环到该单词时直接跳过。**放到队列中的单词代表下一阶段接受循环处理。**
5. 当前单词在循环变换字母的时候，可能与字典中的多个单词匹配到。因此下一节点，在处理完所有匹配成功的单词之后，
	才会进入新的阶段，这里不理解，可以暂时按照N叉树的层序遍历理解，一层所有的单词处理完之后，步数才+1。
	若当前单词处理过程中，跟endword匹配成功了，直接返回步数+1。前提是endword在字典中。

### 贪心算法
贪心算法是一种在每一步选择中都采取当前状态下最优或者最好的选择，从而使得最终的结果最优的解法。
**比较：**
1. 贪心算法：当下最优
2. 回溯：能够回退
3. 动态规划：最有判断+回退

#### 贪心算法适用的场景
问题可以分解成子问题来解决，子问题的最优解可以递推到最终问题的最优解

#### 硬币问题思路
1. 想要总硬币数最少，肯定是优先用大面值硬币，所以对 coins 按从大到小排序
2. 先丢大硬币，再丢会超过总额时，就可以递归下一层丢稍小面值的硬币
3. 优先丢大硬币进去尝试，也没必要一个一个丢，可以用乘法算一下最多能丢几个
4. k = amount / coins[c_index] 计算最大能投几个
	amount - k * coins[c_index] 减去扔了 k 个硬币的总额
	count + k 加 k 个硬币
5. 如果按照贪心算法取到最后一个面值的硬币，导致最后无法凑出总额，再回溯上一层减少硬币数量，再次进行循环
6. 最先找到的并不是最优解
   考虑到有 [1,7,10] 这种用例，按照贪心思路 10 + 1 + 1 + 1 + 1 会比 7 + 7 更早找到
    所以还是需要把所有情况都递归完
7. 贪心虽然得不到最优解，但也不是没用的
	我们快速算出一个贪心的 ans 之后，虽然还会有奇葩情况，但是绝大部分普通情况就可以疯狂剪枝了
**函数中形参代表的量，若在函数传递过程中会发生变化，则要设置成引用类型的形参**
若直接传入容器，实参的值依旧是默认初始化的值，而若用引用就可在函数内部直接改变main函数中容器的元素。

#### 跳跃游戏思路
循环遍历数组中的元素，若当前元素处在最大跳跃范围之内，则计算该元素对应的最大跳跃距离，进而更新新的跳跃距离。
更新后的跳跃距离大于最后一个元素的位置，return true。
当前遍历的元素已经超出了最大跳跃距离 return false。
所有元素全部遍历一遍，依然没有return true。则return false。

### 二分查找

#### 二分查找前提
1. 目标函数单调性（单调递增，单调递减）
2. 存在上下界（bounded）
3. 能够通过索引访问

#### 二分查找模板
版本一
```cpp
int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}
```

版本二
```cpp
int left=0;
int right=nums.size()-1;
while(left<right){
    int mid = left + (right - left)/ 2;
    if(nums[mid]>=target){
        right=mid;
    }
    else{
        left=mid+1;
    }
}
return left;
```

#### 搜索旋转数组思路
1. 画图辅助确定mid,target的位置，分情况缩小二分区间
2. 大的分情况讨论，是根据mid的位置判断的。
    nums[mid] > nums[right]mid在数组的左半区域
	num[mid] <= nums[right]mid在数组的右半区域
	**注意等号必须要有，因为中点位置可能跟right位置重合**
3. 根据Mid位置，再根据target的位置分情况讨论，按照target在mid的左右分情况讨论。
	**同样，target可能为数组边界的值，等号在判断时必不可少**
	
### 思考题
使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
方法一：暴力递归，依次循环数组中的每一个元素。找到有序数组中无序的地方，时间复杂度O（n）
方法二：二分法。从数组中我们可以发现，半有序数组是通过原来完整的有序数组通过移动部分元素得到。半有序数组在一定范围内是有序的。
		并且我们可以知道，数组的最小值为半有序数组的右半部分的头元素，它的左侧元素为左部分数组中的最大值，因此，查找半有序数组中无序的位置，可以转换成寻找整个数组的最小值	
		在哪。查找到的最小值所在处就是无序的所在处。时间复杂度O（logn）
		代码：
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left<right){
            int mid = left + (right - left)/2;
            if (nums[mid] <= nums[right]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
```
