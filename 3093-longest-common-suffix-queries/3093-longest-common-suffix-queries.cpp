class TrieNode {
public:
    int index;
    int len;
    unordered_map<int, TrieNode*> children;
    TrieNode() {
        this->index = -1;
        this->len = INT_MAX;
    }
    ~TrieNode() {
        for(auto &it : children) {
            delete it.second;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode();
    }
    void insert(string &s, int ind) {
        TrieNode* node = root;
        int n = s.size();
        if(n < node->len || 
          (n == node->len && ind < node->index)) {
            node->len = n;
            node->index = ind;
        }
        for(int i = n-1; i >= 0; i--) {
            int ch = s[i] - 'a';
            if(node->children.count(ch) == 0) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            if(n < node->len || 
              (n == node->len && ind < node->index)) {
                node->len = n;
                node->index = ind;
            }
        }
    }

    int prefix(string &query) {
        TrieNode* node = root;
        int ans = root->index;
        for(int i = query.size()-1; i >= 0; i--)
        {
            int ch = query[i] - 'a';
            if(node->children.count(ch) == 0) {
                break;
            }
            node = node->children[ch];
            ans = node->index;
        }
        return ans;
    }

    ~Trie() {
        delete root;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        int w = wordsContainer.size();
        for(int i = 0; i < w; i++)
        {
            trie.insert(wordsContainer[i], i);
        }
        vector<int> ans(wordsQuery.size());
        for(int i = 0; i < wordsQuery.size(); i++) {

            ans[i] = trie.prefix(wordsQuery[i]);
        }
        return ans;
    }
};