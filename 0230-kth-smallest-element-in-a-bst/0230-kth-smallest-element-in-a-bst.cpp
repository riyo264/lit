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
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];
    }
    void inorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};



// OPTIMAL APPROACH WITH TC-O(N) & SC-O(1) BUT LEETCODE IS CONFIHURED TO ACCEPT THE SOLUTION BY MORRIS TRAVERSAL

// int kthSmallest(TreeNode* root, int k) {
//         int cnt = 0;
//         TreeNode* cur = root;
//         while(cur != NULL) {
//             if(cur->left == NULL) {
//                 cnt++;
//                 if(cnt == k) {
//                     return cur->val;
//                 }
//                 cur = cur->right;
//             }
//             else {
//                 TreeNode* prev = cur->left;
//                 while(prev->right && prev->right != cur) 
//                 {
//                     prev = prev->right;
//                 }
//                 if(prev->right == NULL) {
//                     prev->right = cur;
//                     cur = cur->left;
//                 }
//                 else {
//                     prev->right = NULL;
//                     cnt++;
//                     if(cnt==k) {
//                         return cur->val;
//                     }
//                     cur = cur->right;
//                 }
//             }
//         } 
//         return -1;
//     }