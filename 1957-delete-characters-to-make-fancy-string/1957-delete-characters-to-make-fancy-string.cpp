class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        stack<char> st;
        int cnt = 0;
        for(int i = s.size()-1; i > -1; i--)
        {
            if(st.empty()) {
                st.push(s[i]);
                cnt++;
            }
            else if(st.top() == s[i] && cnt == 2) {
                continue;
            }
            else if(st.top() == s[i] && cnt < 2) {
                st.push(s[i]);
                cnt++;
            }
            else {
                cnt = 0;
                st.push(s[i]);
                cnt++;
            }
        }

        while(!st.empty()) 
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

        // int l = 0;
        // int r = l+2;
        // while(r < s.size())
        // {
        //     char temp = s[l];
        //     for(int i = l; i <= r; i++)
        //     {
        //         temp = s[i];
        //         if(temp != s[l]) {
        //             l++;
        //             r = l+2;
        //             break;
        //         }
        //         else if(i == r) {
        //             s.erase(s.begin()+l);
        //         }
        //     }
        // }
        // return s;
    }
};