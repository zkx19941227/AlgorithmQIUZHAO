class Trie {
    struct TrieNode {
        map<char,TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
private:
    TrieNode* root;
    bool find(string s,int exact_match){
        TrieNode *cur = root;
        for (int i = 0 ;i<s.size(); i++){
            if (cur->child_table.count(s[i]) == 0){
                return false;
            } else {
                cur = cur->child_table[s[i]];
            }
        }
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */