# 第一周学习笔记

### 五毒神掌刷题法

- 刷题第一遍：5分钟，读题和思考；直接看解法：注意多解法，比较优劣；背诵，默写最优解法
- 刷题第二遍：马上自己写，leetcode提交，比较优化。
- 刷题第三遍：一天后再重复做题，根据不同解法的熟练程度，做专项练习
- 刷题第四遍：一周之后，再次复习，反复练习相同的题目
- 刷题第五遍：面试前半个月进行恢复训练，再次做相同的题
**做题在于精，不在于多，重点是过遍数，滚瓜烂熟**

### 做题四步走
	
- 跟面试官沟通好题目细节
- 列出题目所有可能的解法，比较优劣，确定最优解法
- 编写代码
- 测试

### 数据结构总类

- 集合结构
- 线性结构
- 树形结构
- 图形结构

### 分析时间复杂度

- 用常数1取代运行时间中的所有加法常数
- 在修改后的运行次数中，只保留最高阶项
- 若最高阶项存在且不为1，去除与该项相乘的常数，得到最后的时间复杂度

### 部分常见操作的时间复杂度

- 一维数组二分查找 O（logn）
- 二叉树遍历 O(n)
- 图的遍历 O(n)
- BFS,DFS O(n)
- 线性阶O（1）
- 普通循环体 O（n）
- 普通嵌套循环O（n^2）

### 算法种类

- if-else switch ->branch
- for,while loop ->循环，迭代
- 递归
- 搜索：深度优先搜索，广度优先搜索，A*
- 动态规划（dp）
- 二分查找
- 贪心
- 数学，几何

### 顺序表与链表
#### 顺序存储：用一组地址连续的存储单元，依次存储线性表中的各个元素。
#### 链式存储：用一组任意的存储单元存储线性表的数据元素(这组存储单元可以是连续的,也可以是不连续的).

### 顺序表相关操作的时间复杂度
1. Prepend O(1)
2. Append O(1)
3. Lookup O(1)
4. Insert O(n)
5. Delete O(n)

### 链表相关操作的时间复杂度
1. Prepend O(1)
2. Append O(1)
3. Lookup O(n)
4. Insert O(1)
5. Delete O(1)

### 跳表
1. n/2,n/4,n/8,第k级索引节点的个数就是n/(2^k)
2. 假设索引有h级，最高级的索引有两个结点。n/(2^h)=2,从而求得h=log2(n)-1
3. 其中n为链表元素的个数
4. 查询某个元素的时间复杂度为O(logn)

### 栈和队列
- Stack:先入后出；添加，删除皆为O（1）
- Queue：先入先出；添加，删除皆为O（1）
- Deque：简单理解，两端可以进出的Queue；添加，删除皆为O（1）
- Priority Queue:插入操作O（1）；取出操作O(logN)-按照元素优先级取出


### 栈和队列相关API
#### 栈
- stack <int> stkInt; //一个存放int的stack容器。
- stack <float> stkFloat; //一个存放float的stack容器。
- stack <string> stkString; //一个存放string的stack容器。
- stack.push(elem); //往栈头添加元素
- stack.pop(); //从栈头移除第一个元素
- stack.top(); //返回最后一个栈顶元素
- stack.empty(); //判断堆栈是否为空
- stack.size(); //返回堆栈的大小

#### 队列
- queue<int> queInt; //一个存放int的queue容器。
- queue<float> queFloat; //一个存放float的queue容器。
- queue<string> queString; //一个存放string的queue容器。
- queue.push(elem); //往队尾添加元素
- queue.pop(); //从队头移除第一个元素
- queue.back(); //返回最后一个元素
- queue.front(); //返回第一个元素
- queue.empty(); //判断队列是否为空
- queue.size(); //返回队列的大小

### 哈希表，映射与集合
#### Map相关API
1. map容器是一种关联式容器，在插入数据时会根据键值进行排序插入。
2. map容器的每一个元素都是对组，pair<key, value>,其中第一个key为键值，第二个value为实值。
3. 键值不可以修改，实值可以修改，可以使用at（key）来访问实值.
4. map的迭代器不支持随机访问。
5. map的键值不允许重复,而multimap的键值可以重复.

- begin()         返回指向map头部的迭代器
- clear(）        删除所有元素
- count()         返回指定元素出现的次数
- empty()         如果map为空则返回true
- end()           返回指向map末尾的迭代器
- equal_range()   返回特殊条目的迭代器对
- erase()         删除一个元素
- find()          查找一个元素
- get_allocator() 返回map的配置器
- insert()        插入元素
- key_comp()      返回比较元素key的函
- lower_bound()   返回键值>=给定元素的第一个位置
- max_size()      返回可以容纳的最大元素个数
- rbegin()        返回一个指向map尾部的逆向迭代器
- rend()          返回一个指向map头部的逆向迭代器
- size()          返回map中元素的个数
- swap()           交换两个map
- upper_bound()    返回键值>给定元素的第一个位置
- value_comp()     返回比较元素value的函数

### Set相关API
- begin()     　　 ,返回set容器的第一个迭代器
- end() 　　　　 ,返回set容器的最后一个迭代
- clear()   　　     ,删除set容器中的所有的元素
- empty() 　　　,判断set容器是否为空
- max_size() 　 ,返回set容器可能包含的元素最大个数
- size() 　　　　 ,返回当前set容器中的元素个数
- rbegin　　　　 ,返回的值和end()相同
- rend()　　　　 ,返回的值和rbegin()相同
- count() 用来查找set中某个某个键值出现的次数。这个函数在set并不是很实用，因为一个键值在set只可能出现0或1次，这样就变成了判断某一键值是否在set出现过了。
- insert(key_value); 将key_value插入到set中 ，返回值是pair<set<int>::iterator,bool>，bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。

### 刷题集合

#### 简单题集合

|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[242.有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)|3| 数组排序/哈希表   |
|[1.两数之和](https://leetcode-cn.com/problems/two-sum/)|3| 数组循环/哈希表   |
|[206.翻转链表](https://leetcode-cn.com/problems/reverse-linked-list/)|3| 递归/迭代   |
|[141.环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)|3| 快慢指针   |
|[26.排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)|2| 数组遍历|
|[189.旋转数组](https://leetcode-cn.com/problems/rotate-array/)|2| 自顶向下编辑/数组元素交换|
|[21.合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)|3|递归|
|[88.合并两个数组](https://leetcode-cn.com/problems/merge-sorted-array/)|2|递归|
|[283.移动零](https://leetcode-cn.com/problems/move-zeroes/)|2|双指针/数组遍历|
|[66.加1](https://leetcode-cn.com/problems/plus-one/)|2|数组遍历|
#### 中等题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[49.异位词分组](https://leetcode-cn.com/problems/group-anagrams/)|3| 数组遍历/数组排序/哈希表   |
|[24.两两交换链表节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)|3| 栈/递归   |
|[142.环形链表2](https://leetcode-cn.com/problems/linked-list-cycle-ii/)|3| 哈希表 |
#### 困难题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[84.柱状图中的最大矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)|3| 单调递增栈 |
|[239.滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)|3| 双端队列 |
|[42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)|3| 单调递减栈   |
|[25.K个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)|4| 递归 |












