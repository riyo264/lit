/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    stack<TreeNode*> st;
    stack<TreeNode*> prev;
    void pushL(TreeNode* root) {
        while(root != NULL) 
        {
            st.push(root);
            root = root->left;   
        }
    }
    int next() {
        TreeNode* next = st.top();
        st.pop();
        pushL(next->right);
        return next->val;
    }

    void pushR(TreeNode* root) {
        while(root != NULL) 
        {
            prev.push(root);
            root = root->right;
        }
    }
    int pred() {
        TreeNode* pred = prev.top();
        prev.pop();
        pushR(pred->left);
        return pred->val;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        pushL(root);
        pushR(root);
        int l = next();
        int r = pred();
        while(l != r) 
        {
            if(l+r==k) {
                return true;
            }
            else if(l+r<k) {
                l = next();
            }
            else {
                r = pred();
            }
        }
        return false;
    }
};