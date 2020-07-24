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
// 借助栈和数组，依次将根，子结点压入数组，最后将数组reverse
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (root == NULL) {
            return res;
        }
        st.push(root);
        while(!st.empty()){
            auto tem = st.top();
            st.pop();
            res.push_back(tem->val);
            for (int i =0;i<tem->children.size();i++){ // 还可以写成 auto i:children
                if (tem->children.at(i)){
                    st.push(tem->children.at(i));
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;   
    }
};