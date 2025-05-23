class Solution {
public:
    string reverseWords(string s) {
        stack<char> temp;
        string reverse;
        int n = s.size();
        
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i]==' ')
            {
                if(temp.empty()==1 || temp.top()==' ')
                {
                    continue;
                }
                else
                {
                    while(temp.empty()==0)
                    {
                        reverse.push_back(temp.top());
                        temp.pop();
                    }
                    temp.push(s[i]);
                }
            }
            else
            {
                if(temp.empty()==1 || temp.top()!=' ')
                {
                    temp.push(s[i]);
                    if(i == 0)
                    {
                        while(temp.empty()==0)
                        {
                            reverse.push_back(temp.top());
                            temp.pop();
                        }
                    }
                }
                else if(temp.top()==' ')
                {
                    reverse.push_back(temp.top());
                    temp.pop();
                    temp.push(s[i]);
                    if(i == 0)
                    {
                        reverse.push_back(temp.top());
                        temp.pop();
                    }
                }
            }
        }
        return reverse;
    }
};