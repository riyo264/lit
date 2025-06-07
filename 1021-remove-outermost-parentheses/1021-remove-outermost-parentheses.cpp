class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        unordered_map<char, int> mpp = {{'(', 1}, {')', -1}};
        queue<char> parentheses;
        int sum = 1;
        parentheses.push('(');
            for(int i = 1; i < s.size(); i++)
            {
                if(sum == 0)
                {
                    parentheses.push(s[i]);
                    sum = sum + mpp[s[i]];
                    continue;
                }

                if(sum != 0)
                {
                    parentheses.push(s[i]);
                    sum = sum + mpp[s[i]];
                }

                if(sum == 0)
                {
                    parentheses.pop();
                    while(!parentheses.empty())
                    {
                        if(parentheses.size()==1)
                        {
                            parentheses.pop();
                        }
                        else {
                            ans.push_back(parentheses.front());
                            parentheses.pop();
                        }
                    }
                }
            }
            return ans;
        }
};