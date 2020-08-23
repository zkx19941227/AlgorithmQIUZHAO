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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */