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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0,0}});
        int X_min = 0;
        int X_max = 0;
        int Y = 0;
        
        while(!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            Y = max(y, Y);
            nodes[x][y].insert(node->val);
            if(node->left) {
                todo.push({node->left,{x-1, y+1}});
                X_min = min(x-1, X_min);
            }
            if(node->right) {
                todo.push({node->right, {x+1, y+1}});
                X_max = max(x+1, X_max);
            }
        }

        vector<vector<int>> result;

        for(int i = X_min; i <= X_max; i++)
        {
            vector<int> column;
            for(int j = 0; j<=Y; j++)
            {
                column.insert(column.end(), nodes[i][j].begin(), nodes[i][j].end());
            }
            result.push_back(column);
        }

        //  OR THE BELOW FOR LOOP CAN BE USED

        // for(auto i:nodes)
        // {
        //     vector<int> column;
        //     for(auto j:i.second)
        //     {
        //         column.insert(column.end(), j.second.begin(), j.second.end());
        //     }
        //     result.push_back(column);
        // }

        
        return result;
    }
};