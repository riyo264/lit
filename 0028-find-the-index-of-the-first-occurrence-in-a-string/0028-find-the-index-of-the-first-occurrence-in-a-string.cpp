class Solution {
    public : 
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        stack<int> ans;
        int j = 0;

        if(n < m)
        {
            return -1;
        }
        
        for(int i = 0; i <= n-m; i++)
        {
            for(int k = i; k < (i+m); k++)
            {
                if(haystack[k] == needle[j])
                {
                    if(ans.empty()==1)
                    {
                        ans.push(k);
                    }
                    j++;
                    if(k == ((i+m)-1))
                    {
                        return ans.top();
                    }
                }
                else
                {
                    j = 0;
                    if(ans.empty()==0)
                    {
                        ans.pop();
                    }
                    break;
                }
            }
        }
        if(ans.empty()==0)
        {
            return ans.top();
        }
        return -1;
    }    
};
