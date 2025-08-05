class Solution {
private:
    void par(string& s, vector<string>& store, int open, int close) {
        if(open == 0 && close == 0) {
            store.push_back(s);
        }
        if(open == close && open != 0) {
            s.push_back('(');
            par(s, store, open-1, close);
            s.pop_back();
        }
        else {
            if(open > 0) {
                s.push_back('(');
                par(s, store, open-1, close);
                s.pop_back();
            }
            if(close > 0) {
                s.push_back(')');
                par(s, store, open, close-1);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        par(s, result, n, n);
        return result;
    }
};