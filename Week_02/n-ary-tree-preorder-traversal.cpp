/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (root == NULL){
            return res;
        }
        st.push(root);
        while (!st.empty()){
            Node* tem;
            tem = st.top();
            st.pop();
            res.push_back(tem->val);
            for(int i = tem->children.size() - 1;i>=0;i--){ // 从右往左将元素压入栈。
                if (tem->children.at(i)){
                    st.push(tem->children.at(i));
                }
            }
        }
        return res;
    }
};