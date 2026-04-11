class Solution {
public:
    string simplifyPath(string path) {
        // int n = path.size();
        // stack<char> st;
        // int dot_cnt = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     if(path[i] == '.' && (st.top() == '/' || dot_cnt != 0)) {
        //         dot_cnt++;
        //         if(dot_cnt > 2) {
        //             dot_cnt = 0;
        //         }
        //     }
        //     else if(path[i] != '/') {
        //         dot_cnt = 0;
        //     }
        //     else if(path[i]=='/' && dot_cnt == 1) {
        //         if(st.size() >= 2) {
        //             st.pop();
        //             st.pop();
        //         }
        //         else {
        //             while(!st.empty()) {
        //                 st.pop();
        //             }
        //         }
        //         dot_cnt = 0;
        //     }
        //     else if(path[i] == '/' && dot_cnt == 2) {
        //         if(st.size() >= 3) {
        //             st.pop();
        //             st.pop();
        //             st.pop();
        //         }
        //         while(!st.empty() && st.top() != '/') {
        //             st.pop();
        //         }
        //         if(!st.empty()) {
        //             st.pop();
        //         }
        //         dot_cnt = 0;
        //     }
        //     else if(!st.empty() && path[i] == '/' && st.top() == '/') {
        //         continue;
        //     }
        //     st.push(path[i]);
        // }
        // if(!st.empty() && st.top() == '.') {
        //     if(dot_cnt== 1) {
        //         if(st.size() > 2) {
        //             st.pop();
        //             st.pop();
        //         }
        //         else {
        //             st.pop();
        //         }
        //         dot_cnt = 0;
        //     }
        //     else if(dot_cnt == 2) {
        //         if(st.size() >= 3) {
        //             st.pop();
        //             st.pop();
        //             st.pop();
        //         }
        //         while(!st.empty() && st.top() != '/') {
        //             st.pop();
        //         }
        //         if(!st.empty()) {
        //             st.pop();
        //         }
        //         dot_cnt = 0;
        //     }
        // }
        // string ans;
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // if(ans.size() == 0) {
        //     ans = "/";
        // }
        // if(ans.size() > 1 && ans.back() == '/') {
        //     ans.pop_back();
        // }
        // return ans;

        string st[3005];
        int top  = 0 ;
        stringstream ss(path) ;
        string token ;
        while (getline(ss,token,'/')) {
            if (token==""||token==".") {
                continue;
            }
            else if (token=="..") {
                if (top>0) {
                    top--;
                }
            }
            else {
                st[top] = token;
                top++;
            }
        }
        string ans;
        if (top==0) {
            ans +="/";
            return ans;
        }
        for (int i = 0; i < top ;i++) {
            ans+="/"+st[i];
        }
        return ans;
    }
};