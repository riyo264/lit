/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void Parentcheck(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentCheck) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) 
        {
            TreeNode* tree = nodes.front();
            nodes.pop();
            if(tree->left) {
                parentCheck[tree->left] = tree;
                nodes.push(tree->left);
            }
            if(tree->right) {
                parentCheck[tree->right] = tree;
                nodes.push(tree->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentCheck;
        queue<TreeNode*> nodes;
        Parentcheck(root, parentCheck);
        
        unordered_map<TreeNode*, bool> visited;
        nodes.push(target);
        visited[target] = true;
        int distance = 0;
        vector<int> result;
        
        while(!nodes.empty()) 
        {
            int n = nodes.size();
            if(distance == k) break;
            distance++;
            
            for(int i = 0; i < n; i++) 
            {
                TreeNode* cur = nodes.front();
                nodes.pop();
                if(cur->left && visited[cur->left]==false) {
                    visited[cur->left]=true;
                    nodes.push(cur->left);
                }
                if(cur->right && visited[cur->right]==false) {
                    visited[cur->right]=true;
                    nodes.push(cur->right);
                }
                if(parentCheck[cur] && visited[parentCheck[cur]]==false) {
                    visited[parentCheck[cur]] = true;
                    nodes.push(parentCheck[cur]);
                }
            }
        }
        while(!nodes.empty()) 
        {
            result.push_back(nodes.front()->val);
            nodes.pop();
        }
        return result;
    }
};