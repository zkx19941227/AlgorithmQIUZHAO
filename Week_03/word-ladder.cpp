class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());  // 存储字典中的单词
        unordered_set<string> visited;                                // 存储访问过的单词
        queue<string> qu;                                             // 存储下一阶段需要处理的单词
        int res = 1;                                        // 步数
        if (!dict.count(endWord)) return 0;
        visited.insert(beginWord);
        qu.push(beginWord);
        while (!qu.empty()){
            auto n = qu.size();
            for (int i =0;i<n;i++){
                auto t = qu.front();
                qu.pop();
                for (int j =0;j<t.size();j++){
                    auto word = t;
                    for (auto ch = 'a';ch<='z';ch++){
                        word[j] = ch;
                        if (!dict.count(word) || visited.count(word)) continue;
                        if (word == endWord) return res+1;
                        visited.insert(word);
                        qu.push(word);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};