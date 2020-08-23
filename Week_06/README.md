# 第六周学习笔记

### 刷题集合

#### 简单题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[1122.数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)|3|并查集|
|[242.有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)|5| 数组排序/哈希表|
|[387.字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)|3| 哈希表/字符串问题|
|[541.反转字符串-2](https://leetcode-cn.com/problems/reverse-string-ii/)|3|字符串问题|
|[557.反转字符串中的单词-3](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)|3|字符串问题/栈/双指针/与151题一致|
|[917.仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)|3|字符串问题/双指针/isalpha()函数验证是否是字符|
|[680.验证回文字符串-2](https://leetcode-cn.com/problems/valid-palindrome-ii/)|3|字符串问题/双指针|

#### 中等题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[151.翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)|3|栈/字符串（重点）|
|[56.合并区间](https://leetcode-cn.com/problems/merge-intervals/)|3|双指针/排序|
|[8.atoi字符串转换成整数](https://leetcode-cn.com/problems/string-to-integer-atoi/)|3|字符串问题（重点）|
|[438.找到字符串中所有的字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)|3|滑动窗口解决，参考labuladong|
|[5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)|3|动态规划/回文串|

#### 困难题集合
|   题号  | 刷题次数   |  技巧点  |
| --------   | -----:  | :----:|
|[32.最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)|3|动态规划|
|[44.通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)|3|二维数组动态规划|
|[115.不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)|3|动态规划|

### 初级排序-O（N^2）
1. 选择排序-每次找到最小值，然后放到待排序数组的起始位置
2. 插入排序-从前到后逐步构建有序序列。对于无序序列部分，在已排序序列部分中从后往前扫描，找到合适的位置插入元素
3. 冒泡排序-嵌套循环，每次查看相邻的元素如果逆序则交换。

### 高级排序-O（nlongn）
1. 快速排序-数组取标杆pivot，将小元素放在pivot左边，将大元素放在pivot右边。然后继续对左子数组和右子数组再进行快排。
2. 归并排序-把长度为n的输入序列分为两个长度为n/2的子序列。对两个子序列分别采取归并排序。将两个排序好的序列合并成一个完整的序列
3. 堆排序-数组元素建立大顶堆或小顶堆，依次取堆顶元素并删除

```cpp
/**
冒泡排序（O（N^2）稳定）
*/
vector<int> bubblesort(vector<int>& arr){
	int len = arr.size();
	for (int i = 0; i<len-1; i++){
		for (int j = 0; j<len-1-i; j++){
			if (arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr;
}
```

```cpp
/**
插入排序（O（N^2）稳定）
*/
vector<int> insectionsort(vector<int>& arr){
	int len = arr.size();
	int preIndex,current;
	for (int i = 1; i<len; i++){
		preIndex = i-1;
		current = arr[i];
		while (preIndex >=0 && a[preIndex] > current){
			a[preIndex+1] = a[preIndex];
			preIndex--;
		}
		a[preIndex+1] = current;
	}
	return arr;
}
```

```cpp
/**
选择排序（O（N^2）不稳定）
*/
vector<int> selectionsort(vector<int>& arr){
	int len = arr.size();
	int minIndex;
	for (int i = 0; i<len-1; i++){
		minIndex = i
		for (int j = i+1; j<len; j++){
			if (arr[j]>arr[minIndex]){
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = current;
	}
	return arr;
}
```

```cpp
/**
快速排序（O（NLOGN）不稳定）
*/
void quicksort(vector<int>& arr,int begin,int end){
	if (begin>=end) return;
	int pivot = partition(arr,begin,end);
	quicksort(arr,begin,pivot-1);
	quicksort(arr,pivot+1,end);
}
int partition(vector<int>& arr,int begin,int end){
	int pivot = end;
	int counter = begin;
	fot (int i = begin; i<end; i++){
		if (a[i]<a[pivot]){
			swap[a[i],a[counter]];
			counter++;
		}
	}
	swap(a[counter],a[pivot]);
	return counter;
}
```

```cpp
/**
归并排序（O（NLOGN）稳定）
*/
void mergesort(vector<int>& arr,int begin,int end){
	if (begin>=end) return;
	int mid = begin + (end-begin)/2;
	mergesort(arr,begin,mid);
	mergesort(arr,mid+1,end);
	merge(arr,begin,mid,end);
}
void merge(vector<int>& arr,int begin,int mid,int end){
	vector<int> temp(end-begin+1);
	int i = begin,j = mid + 1; k =0;
	while (i<=mid && j<=end) temp[k++] = arr[i]<arr[j] ? arr[i++]:a[j++];
	while (i<=mid) temp[k++] = arr[i++];
	while (j<=end) temp[k++] = arr[j++];
	for (int j = begin,k=0;j<=end;) arr[j++] = temp[k++];
}
```
**reverse函数用于反转在[first,last)范围内的顺序,sort函数也是左闭又开**
**字符串滑动窗口解题策略**
[滑动窗口解题方法](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/)
substr(0,m)复制字符串中索引从0开始，长度为m的内容

### LRU CACHE(最少最近被使用的元素)
- 两个要素：大小，替换策略
- 哈希表+双向链表
- O(1) 查询，修改，更新

LRU 缓存机制可以通过哈希表辅以双向链表实现，我们用一个哈希表和一个双向链表维护所有在缓存中的键值对。

- 双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。

- 哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的**位置**。

### 实现LRU Cache代码
```cpp
struct DLinkedNode{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0),value(0),prev(nullptr),next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key),value(_value),prev(nullptr),next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache; // 存储键值对
    DLinkedNode* head;                    // 虚拟头结点
    DLinkedNode* tail;                    // 虚拟尾结点
    int size;                             // 当前链表长度
    int capacity;                         // 链表容量长度

public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;                // 虚拟头尾结点初始化
    }
    
    // 步骤：查验目标是否存在，存在的话首先将目标移动到头节点，再返回value值
    // 移动结点包括两个步骤：1.删除该结点。2.将该结点添加到头结点位置
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode* node = cache[key];
        MoveToHead(node);
        return node->value;
    }
    
    // 步骤：若为新结点，为该结点建立新的DLinkedNode。放在链表头部。同时更新当前链表长度。若
    // 当前链表长度大于容量。删除尾结点(链表和哈希表中都要删除)，更新当前链表长度
    // 若插入的结点已经存在，更新该结点的value值，放到链表头部。
    void put(int key, int value) {
        if (!cache.count(key)){
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key] = node;
            addtoHead(node);
            ++size;
            if (size>capacity){
                DLinkedNode* removed = removetail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value =value;
            MoveToHead(node);
        }
    }

    void addtoHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removenode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void MoveToHead(DLinkedNode* node){
        removenode(node);
        addtoHead(node);
    }
    DLinkedNode* removetail(){
        DLinkedNode* node = tail->prev;
        removenode(node);
        return node;
    }
};
```
