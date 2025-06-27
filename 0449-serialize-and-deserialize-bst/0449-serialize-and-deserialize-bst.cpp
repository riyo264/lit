/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) {
            return s;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(node == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(node->val)+",");
            }
            if(node != NULL) {
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            }
            else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;