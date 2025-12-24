class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0') idx++;
        ans = ans.substr(idx);

        if(ans == "") ans = "0";
        return ans;
    }
};