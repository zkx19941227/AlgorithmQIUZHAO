# 第五周学习笔记

### 刷题集合

#### 简单题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[191.位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)|3|n &= (n-1)清零最低位的0|
|[231.2的幂](https://leetcode-cn.com/problems/power-of-two/)|3|位运算|
|[190.颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)|3|位运算|

#### 中等题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[547.朋友圈](https://leetcode-cn.com/problems/friend-circles/)|3|并查集|
|[200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)|3|深度优先遍历|
|[130.被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)|3|并查集|
|[338.比特位计数](https://leetcode-cn.com/problems/counting-bits/)|3|位运算|

#### 困难题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[51.N皇后问题](https://leetcode-cn.com/problems/n-queens/)|3|回溯|
|[52.N皇后问题-2](https://leetcode-cn.com/problems/n-queens-ii/)|3|回溯|

### AVL树
1. Balance Factor（平衡因子）：
	左子树的高度减去右子树的高度
	Balance Factor {-1,0,1}.

#### AVL树（平衡二叉搜索树）旋转方式
1. 子树形态：右右子树->左旋
2. 子树形态：左左子树->右旋
3. 子树形态：左右子树->左右旋
4. 子树形态：右左子树->右左旋

#### AVL树以及平衡因子由来
平衡因子由来：查询复杂度为树的深度，所以会记录深度差，得到深度差。平衡因子不平衡的话，就要进行四种基本的旋转操作
**不足：节点需要储存额外信息，且调整次数频繁**

### 红黑树
红黑树是一种近似平衡的二叉搜索树，它能够确保任何一个结点的左右子树的高度差小于两倍，其特点有：
1. 每个结点要么是红色，要么是黑色。
2. 根结点是黑色
3. 每个叶节点（NIL结点，空结点）是黑色
4. 不能有相邻的两个红结点
5. 从任一结点到其每个子结点的路径都包含相同数目的黑色结点

**AVL树与红黑树的比较**
1. AVL树查找速度比红黑树更快，因为AVL树是严格平衡的。
2. 红黑树提供更快的删除插入操作，因为它的旋转操作更少。
3. AVL要存储额外多的信息，比如平衡因子以及高度信息等。而红黑树存储的信息就少的多。只要一个bit，存储0或者1即可
4. 读操作多，写操作少的时候用AVL树。删除操作多用红黑树
**map和set底层用的是红黑树**

### 位运算

#### 实战位运算要点
- 判断奇偶
x%2 == 1 -> (x&1)==1
x%2 == 0 -> (x&1)==0

- x>>1 -> x/2
- X=X&(X-1) 清零最低位的1
- x&-x 得到最低位的1

### 字典树和并查集

#### 字典树的基本性质
1. 结点本身不存完整的单词
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串
3. 每个结点的子结点代表的字符各不相同
优点：最大限度减小无谓地字符串比较，查询效率比哈希表高

字典树的核心思想是空间换时间
利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的

#### 构造一棵字典树
```cpp
class Trie {
    struct TrieNode {
        map<char,TrieNode*>child_table; // 通过指定字符查找下一个结点的位置
        int end;						// 单词终止符；当前结点的end值为1，证明当前字符是某一路径上的最后一个字符，可构成完整单词。
        TrieNode(): end(0) {}
    };
private:
    TrieNode* root;
    // exact_match代表查找模式。exact_match为1代表查找一个完整的单词。exact_match为0代表查找指定字符，不必是完整的单词
	bool find(string s,int exact_match){
        TrieNode *cur = root;
        for (int i = 0 ;i<s.size(); i++){
            if (cur->child_table.count(s[i]) == 0){
                return false;
            } else {
                cur = cur->child_table[s[i]];
            }
        }
        // 根据不同的查找模式，查看end值是否满足不同的需求，得到不同结果。
		if (exact_match) {
            return (cur->end) ? true:false;
        } else {
            return true;
        }
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i<word.size(); i++){
            if (cur->child_table.count(word[i]) == 0){
                cur->child_table[word[i]] = new TrieNode();
            }
            cur = cur->child_table[word[i]];
        }
        cur->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word,1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix,0);
    }
};
```

### 并查集
解决组团以及配对问题

#### 基本操作
- makeSet(s):建立一个新的并查集，其中包含s个单元素集合。
- unionSet(x,y):把元素x和元素y所在的集合合并，要求x和y所在的集合不相交，否则不合并。 
- find(x):找到元素x所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，比较代表元素即可。

#### 并查集相关模板
```cpp
vector<int> fathers;
// 寻找指定元素对应的代表元素
int find(int i){
	while (fathers[i] != i){
		i = fathers[i];
	}
	return i;
}

// 满足条件时，将两个元素联合起来组成一个群体
void unit(int x,int y){
	int f1 = find(x);
	int f2 = find(y);
	fathers[f1] = f2; // 把f1群体挂到f2下，反过来道理一样
}

// 初始化时
fathers[i] = i;