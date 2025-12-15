class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<char> st;
        queue<char> q;
        int vow = 0;
        int i = 0;
        string ans;

        while (i < n && s[i] != ' ') {
            ans.push_back(s[i]);
            if (string("aeiou").find(s[i]) != string::npos) vow++;
            i++;
        }
        if(i != n) {
            ans.push_back(' ');
        }
        i++;

        int check = 0;

        while (i < n) {

            if (string("aeiou").find(s[i]) != string::npos) check++;

            if (s[i] != ' ') {
                st.push(s[i]);
                q.push(s[i]);
            }

            if (s[i] == ' ' || i == n - 1) {
                if (check == vow) {
                    while (!st.empty()) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                } else {
                    while (!q.empty()) {
                        ans.push_back(q.front());
                        q.pop();
                    }
                }
                check = 0;
                while (!st.empty()) st.pop();
                while (!q.empty()) q.pop();

                if (i != n - 1) ans.push_back(' ');
            }

            i++;
        }
        return ans;
    }
};
