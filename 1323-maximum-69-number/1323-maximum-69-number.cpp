class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        int ans = 0;
        while(num > 1) 
        {
            int r = num % 10;
            st.push(r);
            num = num / 10;
        }
        bool flag = false;
        while(!st.empty())
        {
            int digit = st.top();
            st.pop();
            if(digit == 6 && flag == false) {
                digit = 9;
                flag = true;
            }
            ans = (ans * 10) + digit;
        }
        return ans;
    }
};